
/* MMainFrame::OnKey(void*, void*, void*) */

void MMainFrame::OnKey(void *param_1,void *param_2,void *param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x2e232ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x10))(piVar1,0x14);
    return;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MMainFrame.cpp",
         "BOOL MMainFrame::OnKey(void*, void*, void*)",0x150);
                    /* WARNING: Subroutine does not return */
  abort();
}

