
void hid_debug_init(void)

{
  hid_debug_root = (*(code *)&debugfs_create_dir)(&_LC0,0);
  return;
}

