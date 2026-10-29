
/* MW_DTV_FREQUENCYTABLE_DVBS_Customer::ResetSatDB() */

undefined4 __thiscall
MW_DTV_FREQUENCYTABLE_DVBS_Customer::ResetSatDB(MW_DTV_FREQUENCYTABLE_DVBS_Customer *this)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  ushort uVar12;
  int iVar13;
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_9c;
  byte local_90 [4];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  uint local_74 [6];
  undefined2 local_5a;
  undefined2 local_58;
  byte local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_4f;
  undefined1 local_4d;
  short local_4c;
  uint local_44;
  undefined4 local_40;
  uint local_3c;
  char *local_38;
  uint *local_34;
  uint *local_30;
  byte *local_2c;
  
  if (((int)(vSatList._4_4_ - vSatList._0_4_) >> 3) * 0x55555555 == 0) {
    LoadSatelliteListfromXML();
  }
  uVar2 = *(undefined4 *)(this + 0x94);
  iVar8 = *(int *)(this + 0xf0);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(this + 0xac);
  **(undefined4 **)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0x98) = uVar2;
  iVar5 = 0;
  do {
    puVar3 = (undefined4 *)(iVar8 + iVar5);
    iVar5 = iVar5 + 4;
    *puVar3 = 0;
  } while (iVar5 != 0x178);
  mapi_storage::Clear();
  mapi_storage::Clear();
  WriteDatabase(this,0,&_fdata,4);
  (**(code **)(*(int *)this + 0xc0))(this,0);
  (**(code **)(*(int *)this + 0xc0))(this,1);
  local_90[0] = 0;
  if (((int)(vSatList._4_4_ - vSatList._0_4_) >> 3) * 0x55555555 != 0) {
    local_38 = (char *)&local_7c;
    local_34 = local_74;
    local_30 = &local_d8;
    local_2c = local_90;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    do {
      memset(local_38,0,0x44);
      strncpy(local_38,*(char **)(vSatList._0_4_ + (uint)local_90[0] * 0x18 + 4),0x20);
      local_54 = 1;
      iVar5 = (uint)local_90[0] * 0x18;
      local_4f = 1;
      uVar4 = *(uint *)(vSatList._0_4_ + iVar5);
      local_52 = 1;
      local_55 = 0;
      local_56 = (byte)((uVar4 << 0x1f) >> 0x1f);
      local_51 = 1;
      if ((uVar4 & 1) == 1) {
        local_5a = 0x2616;
        local_58 = 0x2968;
        local_40 = CONCAT22(0x2616,(undefined2)local_40);
        local_3c = CONCAT22(local_3c._2_2_,0x2968);
      }
      else {
        local_5a = 0x141e;
        local_58 = 0x141e;
        local_40 = CONCAT22(0x141e,(undefined2)local_40);
        local_3c = CONCAT22(local_3c._2_2_,0x141e);
      }
      puVar10 = (uint *)(vSatList._0_4_ + iVar5);
      local_4d = (undefined1)((*puVar10 & 0xffff) / 0xe10);
      local_3c._0_3_ = (uint3)(ushort)local_3c;
      local_4c = ((ushort)*puVar10 >> 1) + (short)((*puVar10 & 0xffff) / 0xe10) * -0x708;
      if (local_90[0] == 0x18) {
        printf("Add sat %s failed\n",puVar10[1]);
        break;
      }
      iVar5 = *(int *)this;
      local_9c = 0;
      puVar10 = local_34;
      puVar1 = local_30;
      do {
        puVar11 = puVar1;
        uVar4 = *puVar10;
        uVar6 = puVar10[1];
        uVar7 = puVar10[2];
        uVar9 = puVar10[3];
        puVar10 = puVar10 + 4;
        *puVar11 = uVar4;
        puVar11[1] = uVar6;
        puVar11[2] = uVar7;
        puVar11[3] = uVar9;
        puVar1 = puVar11 + 4;
      } while (puVar10 != &local_44);
      puVar11[5] = local_40;
      puVar11[6] = local_3c;
      puVar11[4] = local_44;
      (**(code **)(iVar5 + 0x40))(this,local_2c,local_7c,local_78);
      uVar4 = (uint)local_90[0];
      iVar5 = vSatList._0_4_ + uVar4 * 0x18;
      if (*(short *)(iVar5 + 8) != 0) {
        uVar12 = 0;
        iVar13 = 0;
        iVar8 = 0;
        do {
          puVar3 = (undefined4 *)(*(int *)(iVar5 + 0xc) + iVar8);
          uVar6 = local_88 & 0xfffffffe;
          local_88._2_2_ = (undefined2)(uVar6 >> 0x10);
          local_88._0_2_ = CONCAT11((char)uVar4,(byte)uVar6 | *(byte *)((int)puVar3 + 6) & 1);
          local_80 = CONCAT31(local_80._1_3_,1);
          local_8c = CONCAT22(*(undefined2 *)(puVar3 + 1),(short)*puVar3);
          local_d8 = local_88;
          local_d4 = local_84;
          local_d0 = local_80;
          local_cc = 0;
          (**(code **)(*(int *)this + 0x44))(this,uVar4,iVar13,local_8c);
          uVar4 = (uint)local_90[0];
          uVar12 = uVar12 + 1;
          iVar5 = vSatList._0_4_ + uVar4 * 0x18;
          iVar13 = iVar13 + 1;
          iVar8 = iVar8 + 0xc;
          if (*(ushort *)(iVar5 + 8) <= uVar12) goto LAB_2e966ab8;
        } while (uVar12 != 0xfe);
        printf("Add sat %s failed\n",*(undefined4 *)(iVar5 + 4));
      }
LAB_2e966ab8:
      local_90[0] = local_90[0] + 1;
    } while ((uint)local_90[0] < (uint)(((int)(vSatList._4_4_ - vSatList._0_4_) >> 3) * -0x55555555)
            );
  }
  SaveAll(this);
  (**(code **)(*(int *)this + 0x6c))(this,0);
  (**(code **)(*(int *)this + 0x78))(this,0);
  return 1;
}

