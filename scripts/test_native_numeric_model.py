import unittest
from unittest.mock import patch
import native_numeric_model as model

class NumericModelTests(unittest.TestCase):
    def test_typed_destination_is_matched_not_current_channel(self):
        self.assertEqual(model.resolve('12')['name'],'TRT Müzik')
        self.assertEqual(model.resolve('1')['name'],'TRT 1')
        self.assertEqual(model.resolve('012')['name'],'TRT Müzik')
        self.assertFalse(model.resolve('12')['device_database'])
        self.assertFalse(model.resolve('12')['native_name_bridge_installed'])

    def test_unregistered_and_zero_do_not_reuse_old_name(self):
        for value in ('0','999','10000'):
            result=model.resolve(value)
            self.assertFalse(result['matched'])
            self.assertEqual(result['name'],'Kayıtlı kanal yok')

    def test_invalid_input_rejected(self):
        for value in ('','123456','１２','1\n','../12',12):
            with self.subTest(value=value), self.assertRaises(ValueError):model.resolve(value)

    def test_fixture_markers_duplicates_and_control_text_checked(self):
        for content in (
            '{"demo":false,"device_data_verified":false,"channels":[]}',
            '{"demo":true,"device_data_verified":true,"channels":[]}',
            '{"demo":true,"device_data_verified":false,"channels":[{"number":1,"name":"A"},{"number":1,"name":"B"}]}',
            '{"demo":true,"device_data_verified":false,"channels":[{"number":1,"name":"A\\nB"}]}',
        ):
            with patch.object(type(model.FIXTURE),'read_text',return_value=content):
                with self.assertRaises(ValueError):model.channels()

if __name__=='__main__':unittest.main()
