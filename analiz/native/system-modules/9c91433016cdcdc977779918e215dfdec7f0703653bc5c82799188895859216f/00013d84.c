
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Mdebug_UtopiaCECConfig() */

void Mdebug_UtopiaCECConfig(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 local_48;
  undefined *local_44;
  int local_40;
  undefined *local_3c;
  int local_38;
  undefined *local_34;
  undefined1 auStack_30 [8];
  
  iVar1 = (*(code *)PTR_operator_new_00032a38)(0x18);
  puVar6 = PTR__M_insert__00032b74;
  local_44 = PTR_LAB_00032a18;
  iVar5 = iVar1 + 4;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  local_44 = local_44 + 0x4e8;
  local_48 = 99;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(int *)(iVar1 + 0xc) = iVar5;
  *(int *)(iVar1 + 0x10) = iVar5;
  (*(code *)puVar6)(auStack_30,iVar1,0,iVar5,&local_48);
  iVar3 = *(int *)(iVar1 + 8);
  local_40 = 1;
  local_3c = PTR_LAB_00032a18 + 0xa5c;
  iVar4 = iVar5;
  if (iVar3 == 0) {
LAB_000140a4:
    if ((iVar4 == *(int *)(iVar1 + 0xc)) ||
       (iVar3 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar4), *(int *)(iVar3 + 0x10) < local_40
       )) {
LAB_000140d0:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar1,0,iVar4,&local_40);
    }
  }
  else {
    iVar2 = *(int *)(iVar3 + 0x10);
    iVar4 = iVar3;
    while( true ) {
      if (1 < iVar2) {
        iVar3 = *(int *)(iVar4 + 8);
      }
      else {
        iVar3 = *(int *)(iVar4 + 0xc);
      }
      if (iVar3 == 0) break;
      iVar2 = *(int *)(iVar3 + 0x10);
      iVar4 = iVar3;
    }
    if (1 < iVar2) goto LAB_000140a4;
    if (*(int *)(iVar4 + 0x10) < 1) goto LAB_000140d0;
  }
  iVar3 = *(int *)(iVar1 + 8);
  local_34 = PTR_LAB_00032a18 + 0xa7c;
  local_38 = 2;
  iVar4 = iVar5;
  if (iVar3 == 0) {
LAB_00014050:
    if ((iVar4 != *(int *)(iVar1 + 0xc)) &&
       (iVar3 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar4),
       local_38 <= *(int *)(iVar3 + 0x10))) goto LAB_00013f14;
  }
  else {
    iVar2 = *(int *)(iVar3 + 0x10);
    iVar4 = iVar3;
    while( true ) {
      if (iVar2 < 3) {
        iVar3 = *(int *)(iVar4 + 0xc);
      }
      else {
        iVar3 = *(int *)(iVar4 + 8);
      }
      if (iVar3 == 0) break;
      iVar2 = *(int *)(iVar3 + 0x10);
      iVar4 = iVar3;
    }
    if (iVar2 >= 3) goto LAB_00014050;
    if (1 < *(int *)(iVar4 + 0x10)) goto LAB_00013f14;
  }
  (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar1,0,iVar4,&local_38);
LAB_00013f14:
  puVar9 = PTR_LAB_00032a18 + 0x508;
  puVar10 = PTR_LAB_00032a18 + 0x53c;
  puVar6 = PTR_LAB_00032a18 + 0x530;
  puVar7 = PTR_LAB_00032a18 + 0x564;
  puVar8 = PTR_LAB_00032a18 + 0x584;
  while( true ) {
    while( true ) {
      (*(code *)PTR_puts_00032a50)(puVar9);
      for (iVar4 = *(int *)(iVar1 + 0xc); iVar4 != iVar5;
          iVar4 = (*(code *)PTR__Rb_tree_increment_00032a70)(iVar4)) {
        (*(code *)PTR_printf_00032ac0)
                  (puVar6,*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
      }
      (*(code *)PTR_puts_00032a50)(puVar10);
      (*(code *)PTR_printf_00032ac0)(puVar7);
      iVar4 = (*(code *)PTR_ReadDecimalKeyInput_00032b48)(puVar8);
      if (iVar4 != 2) break;
      (*(code *)PTR_MApi_DDC2BI_SetDbgLevel_00032a98)(0);
    }
    if (iVar4 == 99) break;
    if (iVar4 == 1) {
      (*(code *)PTR_MApi_DDC2BI_SetDbgLevel_00032a98)(1);
    }
  }
  (*(code *)PTR__M_erase_00032ab8)(iVar1,*(undefined4 *)(iVar1 + 8));
  (*(code *)PTR_operator_delete_00032b4c)(iVar1);
  return;
}

