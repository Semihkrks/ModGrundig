
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_normal_cleanup
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined4 uVar1;
  
  std::vector<ScrollListContainer*,std::allocator<ScrollListContainer*>>::~vector
            ((vector<ScrollListContainer*,std::allocator<ScrollListContainer*>> *)
             (original_frame_context + 0x124c));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))(original_frame_context + 0x1240);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))
                    (original_frame_context + 0x11f4);
  return uVar1;
}

