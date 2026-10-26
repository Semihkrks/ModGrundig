"""Contract tests for bounded original-instruction painting, not TV validation."""
import unittest
from unittest.mock import patch
import native_frame_rehost as rehost
from PIL import Image, ImageFont


class NativeFrameTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original,cls.original_evidence=rehost.render('original',35)
        cls.modern,cls.modern_evidence=rehost.render('v3',35)

    def test_executes_all_five_native_functions(self):
        evidence=self.modern_evidence
        for name in rehost.FUNCTIONS:
            self.assertGreater(evidence['native_functions'][name]['unique_executed_instructions'],10,name)
        self.assertTrue(any(c['boundary']=='StretchBlit' for c in evidence['callbacks']))
        draw=next(c for c in evidence['callbacks'] if c['boundary']=='SurfaceDrawString')
        self.assertEqual((draw['text'],draw['flags']),('35',5))

    def test_original_instruction_bytes_are_unchanged_in_guest(self):
        painter=rehost.NativePainter()
        for name,addresses in painter.function_addresses.items():
            for address in addresses:
                segment=next(s for s in painter.segments if s['va']<=address<s['va']+s['file_size'])
                offset=segment['file_offset']+address-segment['va']
                self.assertEqual(bytes(painter.uc.mem_read(address,4)),painter.raw[offset:offset+4],(name,hex(address)))

    def test_geometry_uses_panel_parent_and_candidate_border(self):
        geom=self.modern_evidence['surface_geometry']
        self.assertEqual(geom['panel'],(0,170,76,500))
        self.assertEqual(geom['speaker'],(23,614,30,30))
        self.assertEqual(geom['track'],(35,262,6,320))
        self.assertEqual(self.modern_evidence['text_geometry'],(0,188,76,55))
        self.assertFalse(any(c['boundary']=='FillRectangle' and c['widget']=='speaker' for c in self.modern_evidence['callbacks']))
        self.assertTrue(any(c['boundary']=='FillRectangle' and c['widget']=='speaker' for c in self.original_evidence['callbacks']))
        underline=next(c for c in self.original_evidence['callbacks'] if c['boundary']=='FillRectangle' and c['widget']=='speaker')
        # Native DrawBorders receives h-1 and thickness1 for this 1920x1080 OSD.
        self.assertEqual(underline['args'][1:5],[0,99,100,1])

    def test_real_refresh_selects_zero_and_mute_images(self):
        for variant,mute,expected in [('original',False,682),('v3',False,680),('v3',True,680)]:
            _,evidence=rehost.render(variant,0,mute)
            state=evidence['native_volume_state']
            self.assertTrue(state['native']['returned'])
            self.assertEqual(state['state']['image_sets'][0]['resource_id'],expected)
            self.assertEqual(state['state']['progress_value'],0)

    def test_rendered_pixels_follow_resources_and_native_calls(self):
        self.assertEqual(self.modern.size,(1920,1080))
        self.assertEqual(self.modern.getpixel((1,171)),(25,32,42,255))
        self.assertEqual(self.modern.getpixel((38,400)),(172,172,172,255))
        self.assertEqual(self.modern.getpixel((38,580)),(0,130,212,255))
        self.assertNotEqual(self.original.tobytes(),self.modern.tobytes())

    def test_numeric_native_bottom_center_case_and_font(self):
        _,evidence=rehost.render_numeric('v3','123')
        draw=next(c for c in evidence['callbacks'] if c['boundary']=='SurfaceDrawString')
        self.assertEqual((draw['text'],draw['x'],draw['y'],draw['flags']),('123',127,69,9))
        self.assertIn('0x2e24ffa0',evidence['native_functions']['CalculateTextDrawFlags']['executed_addresses'])
        self.assertEqual(evidence['surface_geometry']['background'],(1538,64,310,112))

    def test_watchdog_and_unknown_callbacks_fail_closed(self):
        painter=rehost.NativePainter(instruction_budget=10)
        with self.assertRaises(RuntimeError):
            painter.paint('bounded',(0,0,20,20),color=0xffffffff)
        with self.assertRaises(RuntimeError):
            painter.callback('UnknownDriver',[0]*6)
        with self.assertRaises(ValueError):
            rehost.render('v3',101)
        with self.assertRaises(ValueError):
            rehost.render_numeric('v3','../x')

    def test_hash_mismatch_rejected_before_mapping(self):
        with patch.object(rehost,'sha',return_value='mismatch'):
            with self.assertRaisesRegex(ValueError,'SHA256 mismatch'):
                rehost.NativePainter()

    def test_v4_reads_local_font_color_arguments_from_pinned_candidate(self):
        image,evidence=rehost.render('v4',35)
        style=evidence['volume_style']
        self.assertEqual((style['font_resource_id'],style['color_resource_id']),(0x4af,0))
        self.assertEqual(style['elf_sha256'],rehost.V4_ELF_SHA)
        self.assertEqual(len(style['local_instructions']),8)
        self.assertEqual(evidence['font_sha256'],rehost.FONT_SHA[0x4af])
        self.assertIn('Lucida Sans Bold.ttf',evidence['font_path'])
        number=image.crop((0,188,76,243)).convert('RGB')
        pixels=(number.getpixel((x,y)) for y in range(number.height) for x in range(number.width))
        self.assertGreater(sum(r<80 and g<80 and b<80 for r,g,b in pixels),200)
        draw=next(c for c in evidence['callbacks'] if c['boundary']=='SurfaceDrawString')
        self.assertEqual((draw['text'],draw['flags']),('35',5))
        self.assertEqual(draw['font_metrics']['modeled_GetHeight'],21)

    def test_v4_actual_native_icon_has_larger_ink_and_all_numbers_fit(self):
        image,evidence=rehost.render('v4',100)
        self.assertEqual(evidence['native_volume_state']['state']['text'],'100')
        def ink_box(frame):
            icon=frame.crop((23,614,53,644)).convert('RGB')
            mask=Image.new('1',icon.size)
            pixels=(icon.getpixel((x,y)) for y in range(icon.height) for x in range(icon.width))
            mask.putdata([b>r+30 and b>g+10 for r,g,b in pixels])
            return mask.getbbox()
        old_box,new_box=ink_box(self.modern),ink_box(image)
        self.assertGreater(new_box[2]-new_box[0],old_box[2]-old_box[0])
        self.assertGreaterEqual(new_box[2]-new_box[0],21)
        font=ImageFont.truetype(str(rehost.ROOT/evidence['font_path']),36)
        self.assertLessEqual(font.getlength('100'),76)
        for volume,mute in ((0,False),(35,True)):
            _,state=rehost.render('v4',volume,mute)
            self.assertEqual(state['native_volume_state']['state']['image_sets'][0]['resource_id'],680)
        with patch.dict(rehost.V4_ICON_SHA,{682:'mismatch'}):
            with self.assertRaisesRegex(ValueError,'v4 icon SHA256 mismatch'):
                rehost.render('v4',35)

    def test_v5_restores_font_compacts_panel_and_enlarges_icon(self):
        image,evidence=rehost.render('v5',35)
        self.assertEqual(evidence['volume_style']['font_resource_id'],0x4ae)
        self.assertEqual(evidence['surface_geometry']['panel'],(0,170,68,450))
        self.assertEqual(evidence['surface_geometry']['speaker'],(13,564,42,42))
        self.assertEqual(evidence['surface_geometry']['track'],(31,256,6,276))
        self.assertEqual(evidence['text_geometry'],(0,188,68,55))
        icon=image.crop((13,564,55,606)).convert('RGB')
        mask=Image.new('1',icon.size)
        pixels=(icon.getpixel((x,y)) for y in range(icon.height) for x in range(icon.width))
        mask.putdata([b>r+30 and b>g+10 for r,g,b in pixels])
        box=mask.getbbox()
        self.assertGreaterEqual(box[2]-box[0],29)
        _,zero=rehost.render('v5',0)
        self.assertEqual(zero['native_volume_state']['state']['image_sets'][0]['resource_id'],680)
        self.assertEqual(zero['input_assets'][2]['image_id'],680)

    def test_v5_numeric_uses_actual_rounded_resource_and_modern_font(self):
        image,evidence=rehost.render_numeric('v5','123')
        self.assertEqual(evidence['numeric_style']['font_resource_id'],0x4b0)
        self.assertEqual(evidence['background_input']['image_id'],2179)
        self.assertEqual(image.getpixel((1538,64)),(25,32,42,255))
        self.assertEqual(image.getpixel((1693,74)),(245,245,245,255))
        self.assertTrue(any(c['boundary']=='StretchBlit' and c['widget']=='numeric rounded image resource 2179' for c in evidence['callbacks']))
        self.assertEqual(evidence['font_sha256'],rehost.FONT_SHA[0x4b0])
        self.assertEqual(rehost.image_table('v5')[2179]['resource_path'],'../rc/ARimages/Grundig/modern/numeric_bg.png')
        for value in ('0','10000'):
            _,frame=rehost.render_numeric('v5',value)
            self.assertEqual(next(c['text'] for c in frame['callbacks'] if c['boundary']=='SurfaceDrawString'),value)

    def test_v6_rich_card_matches_demo_channel_through_native_text(self):
        image,evidence=rehost.render_numeric('v6','12')
        self.assertEqual(evidence['surface_geometry']['background'],(1538,64,310,224))
        self.assertEqual((evidence['numeric_style']['font_size'],evidence['numeric_style']['alignment']),(58,0x11))
        draw=[c for c in evidence['callbacks'] if c['boundary']=='SurfaceDrawString']
        self.assertEqual([c['text'] for c in draw],['12','TRT Müzik'])
        self.assertEqual(draw[0]['flags'],4)
        resolution=evidence['channel_resolution']
        self.assertTrue(resolution['matched'])
        self.assertFalse(resolution['native_name_bridge_installed'])
        self.assertFalse(resolution['native_widget_created'])
        self.assertEqual(image.getpixel((1538,64)),(25,32,42,255))
        self.assertIn('0x2e24fffc',evidence['native_functions']['CalculateTextDrawFlags']['executed_addresses'])

    def test_v6_unmatched_name_ellipsis_and_slight_icon_increase(self):
        _,evidence=rehost.render_numeric('v6','999')
        self.assertFalse(evidence['channel_resolution']['matched'])
        self.assertEqual(evidence['channel_resolution']['display_name'],'Kayıtlı kanal yok')
        import native_numeric_model
        with patch.object(native_numeric_model,'channels',return_value=[{'number':12,'name':'W'*80}]):
            _,long_name=rehost.render_numeric('v6','12')
        shortened=long_name['channel_resolution']['display_name']
        self.assertTrue(shortened.endswith('…'))
        self.assertLess(len(shortened),80)
        font=ImageFont.truetype(str(rehost.ROOT/long_name['font_path']),26)
        self.assertLessEqual(font.getlength(shortened),254)
        _,volume=rehost.render('v6',0)
        self.assertEqual(volume['surface_geometry']['panel'],(0,170,68,450))
        self.assertEqual(volume['surface_geometry']['speaker'],(12,563,44,44))
        self.assertEqual(volume['native_volume_state']['state']['image_sets'][0]['resource_id'],680)

    def test_v7_spacing_keeps_digit_and_proposed_name_rectangles_separate(self):
        _,evidence=rehost.render_numeric('v7','12')
        text=evidence['surface_geometry']['text']
        name=evidence['channel_resolution']['proposed_widget_rect']
        self.assertEqual(text,(1566,118,254,78))
        self.assertEqual(name,(1566,206,254,38))
        self.assertGreaterEqual(name[1]-(text[1]+text[3]),10)

    def test_v7_tv_uses_real_candidate_without_proposed_channel_name_widget(self):
        _,numeric=rehost.render_numeric('v7-tv','12')
        self.assertIsNone(numeric['channel_resolution'])
        self.assertEqual(numeric['surface_geometry']['text'],(1566,118,254,78))
        self.assertEqual(numeric['numeric_style']['font_size'],58)
        self.assertFalse(any(c.get('widget','').startswith('matched name') for c in numeric['callbacks']))
        _,volume=rehost.render('v7-tv',0)
        self.assertEqual(volume['native_volume_state']['state']['image_sets'][0]['resource_id'],680)
        self.assertEqual(volume['surface_geometry']['speaker'],(12,723,44,44))

    @unittest.skip('V8 menu experiment cancelled by user; original menus retained')
    def test_v8_private_menu_resources_are_painted_by_original_muf(self):
        from native_v8_resource_frame import render_resources
        image,evidence=render_resources()
        self.assertEqual(image.size,(1920,1080))
        self.assertEqual(evidence['libmuf_sha256'],rehost.LIB_SHA)
        self.assertGreater(evidence['native_functions']['RenderImageToSurface']['unique_executed_instructions'],100)
        self.assertGreater(evidence['native_functions']['DrawString']['unique_executed_instructions'],100)
        self.assertFalse(evidence['full_native_menu_executed'])
        self.assertFalse(evidence['channel_database_used'])
        self.assertIn('host-arranged',evidence['specimen_layout'])


if __name__=='__main__':
    unittest.main()
