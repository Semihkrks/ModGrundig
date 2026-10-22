
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Mdebug_UtopiaFLASHConfig() */

void Mdebug_UtopiaFLASHConfig(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined4 local_80;
  undefined *local_7c;
  int local_78;
  undefined *local_74;
  int local_70;
  undefined *local_6c;
  int local_68;
  undefined *local_64;
  int local_60;
  undefined *local_5c;
  int local_58;
  undefined *local_54;
  int local_50;
  undefined *local_4c;
  int local_48;
  undefined *local_44;
  int local_40;
  undefined *local_3c;
  int local_38;
  undefined *local_34;
  undefined1 auStack_30 [8];
  
  iVar2 = (*(code *)PTR_operator_new_00032a38)(0x18);
  puVar1 = PTR__M_insert__00032b74;
  local_7c = PTR_LAB_00032a18;
  iVar7 = iVar2 + 4;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  local_7c = local_7c + 0x4e8;
  local_80 = 99;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(int *)(iVar2 + 0xc) = iVar7;
  *(int *)(iVar2 + 0x10) = iVar7;
  (*(code *)puVar1)(auStack_30,iVar2,0,iVar7,&local_80);
  iVar5 = *(int *)(iVar2 + 8);
  local_78 = 1;
  local_74 = PTR_LAB_00032a18 + 0xd80;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_00016414:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_78
       )) {
LAB_00016440:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_78);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 2) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 2) goto LAB_00016414;
    if (*(int *)(iVar6 + 0x10) < 1) goto LAB_00016440;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_6c = PTR_LAB_00032a18 + 0xdb8;
  local_70 = 2;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_000163c0:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_70
       )) {
LAB_000163ec:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_70);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 3) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 3) goto LAB_000163c0;
    if (*(int *)(iVar6 + 0x10) < 2) goto LAB_000163ec;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_64 = PTR_LAB_00032a18 + 0xdf0;
  local_68 = 3;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_0001636c:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_68
       )) {
LAB_00016398:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_68);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 4) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 4) goto LAB_0001636c;
    if (*(int *)(iVar6 + 0x10) < 3) goto LAB_00016398;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_5c = PTR_LAB_00032a18 + 0xe28;
  local_60 = 4;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_00016318:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_60
       )) {
LAB_00016344:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_60);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 5) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 5) goto LAB_00016318;
    if (*(int *)(iVar6 + 0x10) < 4) goto LAB_00016344;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_54 = PTR_LAB_00032a18 + 0xe60;
  local_58 = 5;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_000162c4:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_58
       )) {
LAB_000162f0:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_58);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 6) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 6) goto LAB_000162c4;
    if (*(int *)(iVar6 + 0x10) < 5) goto LAB_000162f0;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_4c = PTR_LAB_00032a18 + 0xe94;
  local_50 = 6;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_00016270:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_50
       )) {
LAB_0001629c:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_50);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 7) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 7) goto LAB_00016270;
    if (*(int *)(iVar6 + 0x10) < 6) goto LAB_0001629c;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_44 = PTR_LAB_00032a18 + 0xecc;
  local_48 = 7;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_0001621c:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_48
       )) {
LAB_00016248:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_48);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 8) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 8) goto LAB_0001621c;
    if (*(int *)(iVar6 + 0x10) < 7) goto LAB_00016248;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_3c = PTR_LAB_00032a18 + 0xf04;
  local_40 = 8;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_000161c8:
    if ((iVar6 == *(int *)(iVar2 + 0xc)) ||
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6), *(int *)(iVar5 + 0x10) < local_40
       )) {
LAB_000161f4:
      (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_40);
    }
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 9) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 9) goto LAB_000161c8;
    if (*(int *)(iVar6 + 0x10) < 8) goto LAB_000161f4;
  }
  iVar5 = *(int *)(iVar2 + 8);
  local_34 = PTR_LAB_00032a18 + 0xf3c;
  local_38 = 9;
  iVar6 = iVar7;
  if (iVar5 == 0) {
LAB_00016174:
    if ((iVar6 != *(int *)(iVar2 + 0xc)) &&
       (iVar5 = (*(code *)PTR__Rb_tree_decrement_00032a5c)(iVar6),
       local_38 <= *(int *)(iVar5 + 0x10))) goto LAB_00015f9c;
  }
  else {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar6 = iVar5;
    while( true ) {
      if (iVar3 < 10) {
        iVar5 = *(int *)(iVar6 + 0xc);
      }
      else {
        iVar5 = *(int *)(iVar6 + 8);
      }
      if (iVar5 == 0) break;
      iVar3 = *(int *)(iVar5 + 0x10);
      iVar6 = iVar5;
    }
    if (iVar3 >= 10) goto LAB_00016174;
    if (8 < *(int *)(iVar6 + 0x10)) goto LAB_00015f9c;
  }
  (*(code *)PTR__M_insert__00032b74)(auStack_30,iVar2,0,iVar6,&local_38);
LAB_00015f9c:
  puVar1 = PTR_LAB_00032a18;
  puVar9 = PTR_LAB_00032a18 + 0x508;
  puVar8 = PTR_LAB_00032a18 + 0x530;
  puVar10 = PTR_LAB_00032a18 + 0x53c;
  puVar11 = PTR_LAB_00032a18 + 0x564;
  puVar12 = PTR_LAB_00032a18 + 0x584;
  do {
    (*(code *)PTR_puts_00032a50)(puVar9);
    for (iVar6 = *(int *)(iVar2 + 0xc); iVar6 != iVar7;
        iVar6 = (*(code *)PTR__Rb_tree_increment_00032a70)(iVar6)) {
      (*(code *)PTR_printf_00032ac0)
                (puVar8,*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x14));
    }
    (*(code *)PTR_puts_00032a50)(puVar10);
    (*(code *)PTR_printf_00032ac0)(puVar11);
    uVar4 = (*(code *)PTR_ReadDecimalKeyInput_00032b48)(puVar12);
  } while (99 < uVar4);
                    /* WARNING: Could not emulate address calculation at 0x00016054 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(puVar1 + uVar4 * 4 + 0xf74) + 0x3a9f0))();
  return;
}

