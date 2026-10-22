
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* __write_to_log_initialize() */

int __write_to_log_initialize(void)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  uint *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined2 local_80;
  undefined1 auStack_7e [4];
  undefined1 auStack_7a [4];
  undefined1 auStack_76 [4];
  undefined1 auStack_72 [4];
  undefined2 local_6e;
  
  puVar6 = PTR_close_2f5f41ec;
  puVar5 = PTR_DAT_2f5f4168;
  if (-1 < *(int *)(PTR_DAT_2f5f4168 + 0x4134)) {
    *(undefined4 *)(PTR_DAT_2f5f4168 + 0x4134) = 0xffffffff;
    (*(code *)puVar6)();
  }
  iVar8 = (*(code *)PTR_socket_2f5f4220)(1,0x80001,0);
  if (-1 < iVar8) {
    iVar9 = (*(code *)PTR_fcntl_2f5f41a8)(iVar8,4,0x80);
    if (-1 < iVar9) {
      (*(code *)PTR_memset_2f5f4244)(&local_80,0,0x6e);
      uVar12 = *(uint *)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x4060);
      uVar13 = *(uint *)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x4064);
      uVar14 = *(uint *)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x4068);
      uVar15 = *(uint *)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x406c);
      uVar2 = *(undefined2 *)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x4070);
      puVar1 = auStack_7e + 3;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | uVar12 >> (3 - uVar3) * 8;
      puVar1 = auStack_7e + 7;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | uVar13 >> (3 - uVar3) * 8;
      puVar1 = auStack_7e + 0xb;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | uVar14 >> (3 - uVar3) * 8;
      puVar1 = auStack_7e + 0xf;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | uVar15 >> (3 - uVar3) * 8;
      local_6e = uVar2;
      uVar3 = (uint)auStack_7e & 3;
      puVar4 = (uint *)(auStack_7e + -uVar3);
      *puVar4 = *puVar4 & 0xffffffffU >> (4 - uVar3) * 8 | uVar12 << uVar3 * 8;
      puVar1 = auStack_7e + 4;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (4 - uVar3) * 8 | uVar13 << uVar3 * 8;
      local_80 = 1;
      puVar1 = auStack_7e + 8;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (4 - uVar3) * 8 | uVar14 << uVar3 * 8;
      puVar1 = auStack_7e + 0xc;
      uVar3 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar3) =
           *(uint *)(puVar1 + -uVar3) & 0xffffffffU >> (4 - uVar3) * 8 | uVar15 << uVar3 * 8;
      iVar10 = (*(code *)PTR_connect_2f5f427c)(iVar8,&local_80,0x6e);
      iVar9 = 0;
      iVar16 = iVar8;
      if (iVar10 < 0) {
        piVar11 = (int *)(*(code *)PTR___errno_location_2f5f428c)();
        iVar9 = -*piVar11;
        iVar16 = -1;
        (*(code *)PTR_close_2f5f41ec)(iVar8);
      }
      *(int *)(puVar5 + 0x4134) = iVar16;
      return iVar9;
    }
    piVar11 = (int *)(*(code *)PTR___errno_location_2f5f428c)();
    iVar9 = *piVar11;
    (*(code *)PTR_close_2f5f41ec)(iVar8);
    *(undefined4 *)(puVar5 + 0x4134) = 0xffffffff;
    *(undefined **)(PTR_DAT_2f5f4168 + 0x4148) = PTR___write_to_log_kernel_2f5f41c4;
    return -iVar9;
  }
  piVar11 = (int *)(*(code *)PTR___errno_location_2f5f428c)();
  puVar7 = PTR___write_to_log_kernel_2f5f41c4;
  puVar6 = PTR_DAT_2f5f4168;
  iVar9 = *piVar11;
  *(int *)(puVar5 + 0x4134) = iVar8;
  *(undefined **)(puVar6 + 0x4148) = puVar7;
  return -iVar9;
}

