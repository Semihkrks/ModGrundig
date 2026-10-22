
/* mmrgDrawText_LookUp_Table::SetFontPath(std::string) */

void __thiscall
mmrgDrawText_LookUp_Table::SetFontPath(mmrgDrawText_LookUp_Table *this,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  undefined *puVar7;
  undefined1 local_120 [260];
  
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(PTR_DAT_2f099e1c,PTR_LAB_2f099a48 + 0x6b00);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6b18);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6c4c);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6eb4);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x68c8);
  uVar1 = (*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x6b24);
  piVar2 = (int *)(*(code *)PTR_operator<<_2f099d9c)(uVar1,PTR_LAB_2f099a48 + 0x68f8);
  piVar3 = (int *)(*(code *)PTR_operator<<_2f099eb4)(piVar2,0x165);
  piVar6 = *(int **)((int)piVar3 + *(int *)(*piVar3 + -0xc) + 0x7c);
  if (piVar6 != (int *)0x0) {
    iVar5 = 0;
    if ((char)piVar6[7] == '\0') {
      puVar4 = local_120;
      do {
        *puVar4 = (char)iVar5;
        iVar5 = iVar5 + 1;
        puVar4 = local_120 + iVar5;
      } while (iVar5 != 0x100);
      (**(code **)(*piVar6 + 0x1c))(piVar6,local_120,local_120 + 0x100,(int)piVar6 + 0x1d);
      *(undefined1 *)(piVar6 + 7) = 1;
      iVar5 = (*(code *)PTR_memcmp_2f099ea8)(local_120,(int)piVar6 + 0x1d,0x100);
      if (iVar5 != 0) {
        *(undefined1 *)(piVar6 + 7) = 2;
      }
      iVar5 = (**(code **)(*piVar6 + 0x18))(piVar6,10);
    }
    else {
      iVar5 = (int)*(char *)((int)piVar6 + 0x27);
    }
    uVar1 = (*(code *)PTR_put_2f099aa0)(piVar3,iVar5);
    (*(code *)PTR_flush_2f099be0)(uVar1);
    (*(code *)PTR_assign_2f099b9c)(this + 0xc,param_2);
    return;
  }
  puVar7 = PTR___throw_bad_cast_2f099e98;
  (*(code *)PTR___throw_bad_cast_2f099e98)();
  iVar5 = *(int *)(puVar7 + 0x18efc);
  piVar2[1] = 0;
  *piVar2 = iVar5 + 8;
  return;
}

