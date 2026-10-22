
int g_io_channel_get_type(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_0006c718;
  iVar2 = *(int *)(PTR_DAT_0006c718 + -0x329c);
  if (iVar2 == 0) {
    uVar3 = (*(code *)PTR_g_boxed_type_register_static_0006c764)
                      (PTR_DAT_0006c888 + -0x733c,PTR_g_io_channel_ref_0006cc3c,
                       PTR_g_io_channel_unref_0006caac);
    *(undefined4 *)(puVar1 + -0x329c) = uVar3;
    iVar2 = *(int *)(puVar1 + -0x329c);
  }
  return iVar2;
}

