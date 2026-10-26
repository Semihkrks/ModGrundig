
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_entry_position
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3)

{
  undefined4 uVar1;
  
  uVar1 = MMainFrame::MoveWindowTo(boundary_a1,0);
  return uVar1;
}

