
/* QuickSettingsFrame::OnNtyClick_Digilink(void*, void*, void*) */

undefined4 QuickSettingsFrame::OnNtyClick_Digilink(void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined4 uStack_38;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [16];
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  
  (**(code **)(in_t9 + 0x225da8))(*(int *)(in_t9 + 0x2216a4) + -0x70ac);
  if (*(int *)((int)param_1 + 0x1a8) == 0) {
    (**(code **)(in_t9 + 0x229034))(auStack_30);
    iVar1 = (**(code **)(in_t9 + 0x224b44))(auStack_30);
    if (iVar1 == 0) {
      *(undefined4 *)((int)param_1 + 0x1a8) = 1;
      (**(code **)(in_t9 + 0x225e2c))();
      uVar2 = (**(code **)(in_t9 + 0x228a20))(0xde6);
      (**(code **)(in_t9 + 0x226338))(*(undefined4 *)(in_t9 + 0x2265b8),uVar2);
      *(undefined4 *)(*(int *)(in_t9 + 0x2265b8) + 8) = 0x28a;
      *(undefined4 *)(*(int *)(in_t9 + 0x2265b8) + 0xc) = 300;
      *(undefined4 *)(*(int *)(in_t9 + 0x2265b8) + 4) = 1;
      **(undefined1 **)(in_t9 + 0x228528) = 0;
      **(undefined4 **)(in_t9 + 0x228f90) = param_1;
      (**(code **)(in_t9 + 0x2257f4))(0xe,0xc68);
      (**(code **)(in_t9 + 0x222bd4))(2);
      (**(code **)(in_t9 + 0x229940))();
    }
    else {
      (**(code **)(in_t9 + 0x229e68))(&uStack_38,auStack_30);
                    /* try { // try from 00ea2e94 to 00ea2e9b has its CatchHandler @ 00ea3194 */
      uVar2 = (**(code **)(in_t9 + 0x228a20))(0xe4c);
      (**(code **)(in_t9 + 0x223b64))(auStack_40);
                    /* try { // try from 00ea2ed4 to 00ea2edb has its CatchHandler @ 00ea2fbc */
      (**(code **)(in_t9 + 0x2221e0))(auStack_3c,uVar2,auStack_40);
                    /* try { // try from 00ea2efc to 00ea2f03 has its CatchHandler @ 00ea2f60 */
      (**(code **)(in_t9 + 0x228f10))(auStack_34,auStack_30,uStack_38,auStack_3c);
      puStack_20 = auStack_3c;
                    /* try { // try from 00ea2f18 to 00ea2f1f has its CatchHandler @ 00ea2fbc */
      (**(code **)(in_t9 + 0x2222b4))(puStack_20);
      (**(code **)(in_t9 + 0x221b8c))(auStack_40);
      *(undefined4 *)((int)param_1 + 0x1a8) = 2;
                    /* try { // try from 00ea2f4c to 00ea2f53 has its CatchHandler @ 00ea3194 */
      (**(code **)(in_t9 + 0x225e2c))();
                    /* try { // try from 00ea2fa8 to 00ea3167 has its CatchHandler @ 00ea3194 */
      uVar2 = (**(code **)(in_t9 + 0x228a20))(0x23);
      (**(code **)(in_t9 + 0x226338))(*(undefined4 *)(in_t9 + 0x228318),uVar2);
      (**(code **)(in_t9 + 0x2226d8))(*(int *)(in_t9 + 0x228318) + 8,auStack_30);
      *(undefined4 *)(*(int *)(in_t9 + 0x228318) + 4) = 0;
      **(undefined4 **)(in_t9 + 0x228f90) = param_1;
      **(undefined1 **)(in_t9 + 0x228528) = 0;
      (**(code **)(in_t9 + 0x2257f4))(7,0xf37);
      (**(code **)(in_t9 + 0x2257f4))(0xe,0xc42);
      (**(code **)(in_t9 + 0x2257f4))(3,0x79);
      (**(code **)(in_t9 + 0x222bd4))(1);
    }
    uStack_1c = 1;
    (**(code **)(in_t9 + 0x2220c0))(auStack_30);
  }
  else {
    uStack_1c = 1;
  }
  return uStack_1c;
}

