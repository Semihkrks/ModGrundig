
/* CusInfo::initCustomerInfo() */

undefined4 __thiscall CusInfo::initCustomerInfo(CusInfo *this)

{
  CusInfo CVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  CusInfo *pCVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = 0;
  do {
    pCVar5 = this + iVar6;
    iVar6 = iVar6 + 1;
    *pCVar5 = (CusInfo)0x0;
  } while (iVar6 != 0x31);
  local_8 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x1094);
  local_4 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x1098);
  local_10 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x108c);
  local_c = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x1090);
  pbVar8 = PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x1042;
  pbVar11 = PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x104a;
  pCVar5 = this;
  do {
    CVar1 = *(CusInfo *)((int)&local_10 + (pbVar8[1] & 0xf));
    *pCVar5 = *(CusInfo *)((int)&local_10 + (uint)(pbVar8[1] >> 4));
    pCVar5[1] = CVar1;
    bVar2 = *pbVar8;
    pbVar8 = pbVar8 + 2;
    pCVar5[2] = *(CusInfo *)((int)&local_10 + (uint)(bVar2 >> 4));
    pCVar5[3] = *(CusInfo *)((int)&local_10 + (bVar2 & 0xf));
    puVar3 = PTR___DT_MIPS_BASE_ADDRESS_2f6b1244;
    pCVar5 = pCVar5 + 4;
  } while (pbVar8 != pbVar11);
  uVar7 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x1060);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_2f6b1244 + 0x105c);
  puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f6b1244;
  uVar10 = *(undefined4 *)(puVar3 + 0x1068);
  *(undefined4 *)(this + 0x14) = uVar7;
  uVar9 = *(undefined4 *)(puVar3 + 0x106c);
  *(undefined4 *)(this + 0x18) = uVar10;
  uVar7 = *(undefined4 *)(puVar4 + 0x1074);
  *(undefined4 *)(this + 0x1c) = uVar9;
  puVar3 = PTR___DT_MIPS_BASE_ADDRESS_2f6b1244;
  uVar9 = *(undefined4 *)(puVar4 + 0x1078);
  *(undefined4 *)(this + 0x20) = uVar7;
  *(undefined4 *)(this + 0x24) = uVar9;
  uVar7 = *(undefined4 *)(puVar3 + 0x1084);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(puVar3 + 0x1080);
  *(undefined4 *)(this + 0x2c) = uVar7;
  this[0x30] = (CusInfo)0x0;
  return 1;
}

