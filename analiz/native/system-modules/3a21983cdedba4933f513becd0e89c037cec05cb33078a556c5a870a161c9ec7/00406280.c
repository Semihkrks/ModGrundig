
void initialize_async_io(void)

{
  undefined1 auStack_88 [128];
  
  async_io_enabled = 1;
  disable_async_io();
  (*(code *)&UNK_004030f0)(auStack_88);
  (*(code *)&UNK_004034b0)(auStack_88,0x16);
  (*(code *)&UNK_00403470)(2,auStack_88,0);
  return;
}

