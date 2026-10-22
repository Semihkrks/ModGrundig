
void init_registers_mips_linux(void)

{
  set_register_cache(regs_mips_linux,0x49);
  gdbserver_expedite_regs = expedite_regs_mips_linux;
  gdbserver_xmltarget = xmltarget_mips_linux;
  return;
}

