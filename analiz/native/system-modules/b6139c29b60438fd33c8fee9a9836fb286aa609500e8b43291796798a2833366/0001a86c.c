
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MSystem_Init() */

void MSystem_Init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int iVar9;
  
  puVar4 = PTR_real_malloc_0002125c;
  if ((PTR_m_PoolArea_9816948__00020f48[0x3cdd] == '\0') &&
     (((((PTR_m_PoolArea_9816948__00020f48[0x3cdd] = 1, puVar7 = PTR_real_calloc_000212d4,
         puVar6 = PTR_real_realloc_000212b0, puVar3 = PTR_real_free_0002124c, *(int *)puVar4 == 0 ||
         (*(int *)PTR_real_free_0002124c == 0)) || (*(int *)PTR_real_calloc_000212d4 == 0)) ||
       ((*(int *)PTR_real_realloc_000212b0 == 0 || (*(int *)PTR_real_memalign_00021374 == 0)))) ||
      ((*(int *)PTR_real_mmap_00021294 == 0 || (*(int *)PTR_real_munmap_0002123c == 0)))))) {
    while( true ) {
      puVar5 = PTR_real_memalign_00021374;
      puVar1 = PTR_real_mmap_00021294;
      puVar2 = PTR_real_munmap_0002123c;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1330);
      *(undefined4 *)puVar4 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1328);
      *(undefined4 *)puVar3 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1320);
      *(undefined4 *)puVar7 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1318);
      *(undefined4 *)puVar6 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1310);
      *(undefined4 *)puVar5 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x1304);
      *(undefined4 *)puVar1 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x12fc);
      puVar5 = PTR_dlsym_000212a8;
      puVar1 = PTR_cie_00020000_00020f38;
      *(undefined4 *)PTR_real_mmap2_000211a4 = uVar8;
      uVar8 = (*(code *)puVar5)(0xffffffff,puVar1 + -0x12f4);
      puVar5 = PTR_dlsym_000212a8;
      puVar1 = PTR_cie_00020000_00020f38;
      *(undefined4 *)PTR_real_mmap64_0002132c = uVar8;
      uVar8 = (*(code *)puVar5)(0xffffffff,puVar1 + -0x12ec);
      *(undefined4 *)puVar2 = uVar8;
      uVar8 = (*(code *)PTR_dlsym_000212a8)(0xffffffff,PTR_cie_00020000_00020f38 + -0x12e4);
      puVar2 = PTR_dlsym_000212a8;
      puVar1 = PTR_cie_00020000_00020f38;
      *(undefined4 *)PTR_real_sbrk_000211dc = uVar8;
      uVar8 = (*(code *)puVar2)(0xffffffff,puVar1 + -0x12dc);
      puVar2 = PTR_dlsym_000212a8;
      puVar1 = PTR_cie_00020000_00020f38;
      *(undefined4 *)PTR_real_valloc_000211bc = uVar8;
      uVar8 = (*(code *)puVar2)(0xffffffff,puVar1 + -0x12d4);
      puVar2 = PTR_dlsym_000212a8;
      puVar1 = PTR_cie_00020000_00020f38;
      *(undefined4 *)PTR_real_pvalloc_00021254 = uVar8;
      uVar8 = (*(code *)puVar2)(0xffffffff,puVar1 + -0x12cc);
      iVar9 = *(int *)puVar4;
      *(undefined4 *)PTR_real_posix_memalign_00021290 = uVar8;
      if ((((iVar9 != 0) && (*(int *)PTR_real_free_0002124c != 0)) &&
          (*(int *)PTR_real_calloc_000212d4 != 0)) &&
         ((*(int *)PTR_real_realloc_000212b0 != 0 && (*(int *)PTR_real_memalign_00021374 != 0))))
      break;
      uVar8 = (*(code *)PTR_dlerror_000211f8)();
      (*(code *)PTR_printf_00021250)(PTR_cie_00020000_00020f38 + -0x12bc,uVar8);
      (*(code *)PTR_exit_00021170)(1);
    }
    (*(code *)PTR_gAlloced_ListP_000211d8)();
    (*(code *)PTR_FilterFromMMAP_00021160)(0,1);
    return;
  }
  return;
}

