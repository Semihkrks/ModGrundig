
/* profiler::init() */

void __thiscall profiler::init(profiler *this)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [8];
  
  piVar7 = *(int **)(this + 0xc);
  piVar6 = *(int **)(this + 0x10);
  *(undefined4 *)this = 1;
  *(undefined4 *)(this + 4) = 0;
  puVar2 = PTR_pthread_cancel_2f7b6874;
  puVar1 = PTR_DAT_2f7b685c;
  if (piVar7 != piVar6) {
    piVar5 = piVar7;
    do {
      iVar3 = piVar5[2];
      if ((undefined *)(iVar3 + -0xc) != puVar1) {
        if (puVar2 == (undefined *)0x0) {
          iVar4 = *(int *)(iVar3 + -4);
          *(int *)(iVar3 + -4) = iVar4 + -1;
        }
        else {
          SYNC(0);
          iVar4 = *(int *)(iVar3 + -4);
          *(int *)(iVar3 + -4) = iVar4 + -1;
          SYNC(0);
        }
        if (iVar4 < 1) {
          (*(code *)PTR__M_destroy_2f7b68dc)((undefined *)(iVar3 + -0xc),auStack_30);
        }
      }
      iVar3 = *piVar5;
      if ((undefined *)(iVar3 + -0xc) != puVar1) {
        if (puVar2 == (undefined *)0x0) {
          iVar4 = *(int *)(iVar3 + -4);
          *(int *)(iVar3 + -4) = iVar4 + -1;
        }
        else {
          SYNC(0);
          iVar4 = *(int *)(iVar3 + -4);
          *(int *)(iVar3 + -4) = iVar4 + -1;
          SYNC(0);
        }
        if (iVar4 < 1) {
          (*(code *)PTR__M_destroy_2f7b68dc)((undefined *)(iVar3 + -0xc),auStack_2c);
        }
      }
      piVar5 = piVar5 + 5;
    } while (piVar6 != piVar5);
  }
  *(int **)(this + 0x10) = piVar7;
  *(undefined4 *)this = 0;
  return;
}

