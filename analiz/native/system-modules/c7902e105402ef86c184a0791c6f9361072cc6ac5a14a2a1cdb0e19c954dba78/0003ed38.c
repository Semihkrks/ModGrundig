
void ntfs_mount(void)

{
  (*(code *)&mount_bdev)();
  return;
}

