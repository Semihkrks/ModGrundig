
/* std::vector<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO,
   std::allocator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO>
   >::_M_insert_aux(__gnu_cxx::__normal_iterator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO*,
   std::vector<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO,
   std::allocator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO> > >, MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO
   const&) */

void __thiscall
std::
vector<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO,std::allocator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO>>
::_M_insert_aux(vector<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO,std::allocator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO>>
                *this,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 local_48 [8];
  undefined4 auStack_28 [2];
  
  puVar14 = *(undefined4 **)(this + 4);
  if (puVar14 != *(undefined4 **)(this + 8)) {
    puVar11 = puVar14 + -9;
    if (puVar14 != (undefined4 *)0x0) {
      puVar13 = puVar14;
      do {
        uVar2 = *puVar11;
        uVar5 = puVar11[1];
        uVar6 = puVar11[2];
        uVar9 = puVar11[3];
        puVar11 = puVar11 + 4;
        *puVar13 = uVar2;
        puVar13[1] = uVar5;
        puVar13[2] = uVar6;
        puVar13[3] = uVar9;
        puVar13 = puVar13 + 4;
      } while (puVar11 != puVar14 + -1);
      *puVar13 = *puVar11;
    }
    puVar12 = local_48;
    *(undefined4 **)(this + 4) = puVar14 + 9;
    puVar13 = param_3 + 8;
    puVar11 = puVar12;
    do {
      uVar2 = *param_3;
      uVar5 = param_3[1];
      uVar6 = param_3[2];
      uVar9 = param_3[3];
      param_3 = param_3 + 4;
      *puVar11 = uVar2;
      puVar11[1] = uVar5;
      puVar11[2] = uVar6;
      puVar11[3] = uVar9;
      puVar11 = puVar11 + 4;
    } while (param_3 != puVar13);
    *puVar11 = *param_3;
    (*(code *)PTR_memmove_2f1afd60)(puVar14 + -((int)puVar14 + (-0x24 - (int)param_2) >> 2),param_2)
    ;
    do {
      uVar2 = *puVar12;
      uVar5 = puVar12[1];
      uVar6 = puVar12[2];
      uVar9 = puVar12[3];
      puVar12 = puVar12 + 4;
      *param_2 = uVar2;
      param_2[1] = uVar5;
      param_2[2] = uVar6;
      param_2[3] = uVar9;
      param_2 = param_2 + 4;
    } while (puVar12 != auStack_28);
    *param_2 = *puVar12;
    return;
  }
  iVar7 = (int)puVar14 - *(int *)this >> 2;
  uVar10 = iVar7 * 8;
  uVar1 = iVar7 * 0x38e38e39;
  if (uVar1 == 0x71c71c7) {
    uVar4 = (*(code *)PTR___throw_length_error_2f1b0190)(PTR_DAT_2f1afcd4 + -0x3de4);
LAB_2f19a960:
    iVar7 = -4;
    if (uVar4 <= uVar10) goto LAB_2f19a7dc;
    iVar7 = uVar10 << 5;
  }
  else {
    uVar10 = 1;
    if (uVar1 != 0) {
      uVar10 = iVar7 * 0x71c71c72;
      uVar4 = 0x71c71c8;
      if (uVar10 < uVar1) {
        iVar7 = -4;
        goto LAB_2f19a7dc;
      }
      goto LAB_2f19a960;
    }
    iVar7 = 0x20;
  }
  iVar7 = uVar10 * 4 + iVar7;
LAB_2f19a7dc:
  iVar3 = (*(code *)PTR_operator_new_2f1b0314)(iVar7);
  iVar8 = ((int)param_2 - *(int *)this >> 2) * 4;
  puVar14 = (undefined4 *)(iVar3 + iVar8);
  (*(code *)PTR_memmove_2f1afd60)(iVar3,*(int *)this,iVar8);
  if (puVar14 != (undefined4 *)0x0) {
    puVar13 = param_3 + 8;
    puVar11 = puVar14;
    do {
      uVar2 = *param_3;
      uVar5 = param_3[1];
      uVar6 = param_3[2];
      uVar9 = param_3[3];
      param_3 = param_3 + 4;
      *puVar11 = uVar2;
      puVar11[1] = uVar5;
      puVar11[2] = uVar6;
      puVar11[3] = uVar9;
      puVar11 = puVar11 + 4;
    } while (param_3 != puVar13);
    *puVar11 = *param_3;
  }
  iVar8 = *(int *)(this + 4) - (int)param_2 >> 2;
  (*(code *)PTR_memmove_2f1afd60)(puVar14 + 9,param_2,iVar8 * 4);
  if (*(int *)this != 0) {
    (*(code *)PTR_operator_delete_2f1b003c)();
  }
  *(int *)(this + 8) = iVar3 + iVar7;
  *(undefined4 **)(this + 4) = puVar14 + 9 + iVar8;
  *(int *)this = iVar3;
  return;
}

