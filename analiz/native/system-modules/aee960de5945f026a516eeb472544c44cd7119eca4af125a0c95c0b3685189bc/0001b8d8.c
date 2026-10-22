
undefined4 g_initially_unowned_get_type(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_0006c718;
  iVar2 = (*(code *)PTR_g_atomic_pointer_get_0006ca78)(PTR_DAT_0006c718 + -0x3340);
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_g_once_init_enter_impl_0006cb50)(puVar1 + -0x3340);
    if (iVar2 != 0) {
      uVar3 = (*(code *)PTR_g_intern_static_string_0006cc10)(PTR_LAB_0006c728 + 0x52b0);
      uVar3 = (*(code *)PTR_g_type_register_static_simple_0006c7ac)
                        (0x50,uVar3,0x44,PTR_LAB_0006c7a8 + -0x45f0,0xc,PTR_LAB_0006c7a8 + -0x43f0,0
                        );
      (*(code *)PTR_g_once_init_leave_0006ca74)(puVar1 + -0x3340,uVar3);
      return *(undefined4 *)(puVar1 + -0x3340);
    }
  }
  return *(undefined4 *)(puVar1 + -0x3340);
}

