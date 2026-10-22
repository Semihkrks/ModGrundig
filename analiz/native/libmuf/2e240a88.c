
/* MResourcePkg::CheckInitialPath(std::string*, std::string const&) const */

void __thiscall MResourcePkg::CheckInitialPath(MResourcePkg *this,string *param_1,string *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  undefined1 auStack_30 [4];
  int local_2c;
  int local_28;
  undefined1 auStack_24 [8];
  
  if (this[0x2d] == (MResourcePkg)0x0) {
    return;
  }
  iVar1 = (**(code **)(in_t9 + 0x7415c))(*(undefined4 *)param_1,*(int *)(in_t9 + 0x72e80) + -0x5160)
  ;
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(*(int *)(in_t9 + 0x72e70) + 0x3a90);
    iVar1 = (**(code **)(in_t9 + 0x73cf4))(**(undefined4 **)(this + 0x28),uVar2);
    if (iVar1 == 0) {
      return;
    }
                    /* try { // try from 2e240b78 to 2e240b7f has its CatchHandler @ 2e240c68 */
    (**(code **)(in_t9 + 0x7384c))(&local_2c,*(int *)(in_t9 + 0x72e80) + -0x515c,auStack_30);
    iVar1 = (**(code **)(in_t9 + 0x73eec))(uVar2);
    local_28 = *(int *)(in_t9 + 0x74208) + 0xc;
                    /* try { // try from 2e240bb8 to 2e240beb has its CatchHandler @ 2e240cd8 */
    (**(code **)(in_t9 + 0x73cb0))(&local_28,iVar1 + *(int *)(local_2c + -0xc));
    (**(code **)(in_t9 + 0x73880))(&local_28,uVar2,iVar1);
    (**(code **)(in_t9 + 0x738fc))(&local_28,&local_2c);
                    /* try { // try from 2e240c00 to 2e240c07 has its CatchHandler @ 2e240ccc */
    uVar2 = *(undefined4 *)param_2;
    (**(code **)(in_t9 + 0x73ee8))(auStack_24,&local_28);
                    /* try { // try from 2e240c14 to 2e240c1b has its CatchHandler @ 2e240cc4 */
    (**(code **)(in_t9 + 0x73084))(auStack_24,uVar2);
                    /* try { // try from 2e240c28 to 2e240c2f has its CatchHandler @ 2e240c98 */
    (**(code **)(in_t9 + 0x73688))(param_1,auStack_24);
                    /* try { // try from 2e240c38 to 2e240c3f has its CatchHandler @ 2e240ccc */
    (**(code **)(in_t9 + 0x73354))(auStack_24);
                    /* try { // try from 2e240c48 to 2e240c4f has its CatchHandler @ 2e240c7c */
    (**(code **)(in_t9 + 0x73354))(&local_28);
                    /* try { // try from 2e240c58 to 2e240c5f has its CatchHandler @ 2e240c68 */
    (**(code **)(in_t9 + 0x73354))(&local_2c);
  }
  else {
    (**(code **)(in_t9 + 0x73c5c))(iVar1);
  }
  return;
}

