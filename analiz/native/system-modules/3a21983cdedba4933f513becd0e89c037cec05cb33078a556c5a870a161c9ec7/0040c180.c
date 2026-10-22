
void init_registers_mips64_linux(void)

{
  set_register_cache(regs_mips64_linux,0x49);
  gdbserver_expedite_regs = expedite_regs_mips64_linux;
  gdbserver_xmltarget = xmltarget_mips64_linux;
  return;
}

