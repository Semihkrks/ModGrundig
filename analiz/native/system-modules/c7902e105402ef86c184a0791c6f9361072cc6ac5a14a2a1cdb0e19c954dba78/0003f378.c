
/* WARNING: Control flow encountered bad instruction data */

void ntfs_volume_free(int param_1)

{
  if (param_1 == 0) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

