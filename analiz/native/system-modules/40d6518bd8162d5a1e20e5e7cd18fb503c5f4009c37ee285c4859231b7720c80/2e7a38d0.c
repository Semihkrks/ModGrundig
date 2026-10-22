
/* TestSuite_Network_Cmd::~TestSuite_Network_Cmd() */

void __thiscall TestSuite_Network_Cmd::~TestSuite_Network_Cmd(TestSuite_Network_Cmd *this)

{
  undefined *puVar1;
  
  puVar1 = PTR__TestSuite_2e7d26e4;
  *(undefined **)this = PTR_vtable_2e7d2d6c + 8;
  (*(code *)puVar1)();
                    /* WARNING: Could not recover jumptable at 0x2e7a3918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_operator_delete_2e7d28b4)(this);
  return;
}

