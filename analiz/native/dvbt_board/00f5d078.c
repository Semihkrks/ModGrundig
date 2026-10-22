
/* ToolsMenuFrame::OnNtyClicked_Digilink(void*, void*, void*) */

undefined4 ToolsMenuFrame::OnNtyClicked_Digilink(void *param_1,void *param_2,void *param_3)

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
  
  if (*(int *)((int)param_1 + 0x2e4) == 0) {
    (**(code **)(in_t9 + 0x16ed78))(auStack_30);
    iVar1 = (**(code **)(in_t9 + 0x16a888))(auStack_30);
    if (iVar1 == 0) {
      *(undefined4 *)((int)param_1 + 0x2e4) = 1;
      (**(code **)(in_t9 + 0x16bb70))();
      uVar2 = (**(code **)(in_t9 + 0x16e764))(0xde6);
      (**(code **)(in_t9 + 0x16c07c))(*(undefined4 *)(in_t9 + 0x16c2fc),uVar2);
      *(undefined4 *)(*(int *)(in_t9 + 0x16c2fc) + 8) = 0x28a;
      *(undefined4 *)(*(int *)(in_t9 + 0x16c2fc) + 0xc) = 300;
      *(undefined4 *)(*(int *)(in_t9 + 0x16c2fc) + 4) = 1;
      **(undefined1 **)(in_t9 + 0x16e26c) = 0;
      **(undefined4 **)(in_t9 + 0x16ecd4) = param_1;
      (**(code **)(in_t9 + 0x16b538))(0xe,0xc68);
      (**(code **)(in_t9 + 0x168918))(2);
      (**(code **)(in_t9 + 0x16f684))();
    }
    else {
      (**(code **)(in_t9 + 0x16fbac))(&uStack_38,auStack_30);
                    /* try { // try from 00f5d138 to 00f5d13f has its CatchHandler @ 00f5d438 */
      uVar2 = (**(code **)(in_t9 + 0x16e764))(0xe4c);
      (**(code **)(in_t9 + 0x1698a8))(auStack_40);
                    /* try { // try from 00f5d178 to 00f5d17f has its CatchHandler @ 00f5d260 */
      (**(code **)(in_t9 + 0x167f24))(auStack_3c,uVar2,auStack_40);
                    /* try { // try from 00f5d1a0 to 00f5d1a7 has its CatchHandler @ 00f5d204 */
      (**(code **)(in_t9 + 0x16ec54))(auStack_34,auStack_30,uStack_38,auStack_3c);
      puStack_20 = auStack_3c;
                    /* try { // try from 00f5d1bc to 00f5d1c3 has its CatchHandler @ 00f5d260 */
      (**(code **)(in_t9 + 0x167ff8))(puStack_20);
      (**(code **)(in_t9 + 0x1678d0))(auStack_40);
      *(undefined4 *)((int)param_1 + 0x2e4) = 2;
                    /* try { // try from 00f5d1f0 to 00f5d1f7 has its CatchHandler @ 00f5d438 */
      (**(code **)(in_t9 + 0x16bb70))();
                    /* try { // try from 00f5d24c to 00f5d40b has its CatchHandler @ 00f5d438 */
      uVar2 = (**(code **)(in_t9 + 0x16e764))(0x23);
      (**(code **)(in_t9 + 0x16c07c))(*(undefined4 *)(in_t9 + 0x16e05c),uVar2);
      (**(code **)(in_t9 + 0x16841c))(*(int *)(in_t9 + 0x16e05c) + 8,auStack_30);
      *(undefined4 *)(*(int *)(in_t9 + 0x16e05c) + 4) = 0;
      **(undefined4 **)(in_t9 + 0x16ecd4) = param_1;
      **(undefined1 **)(in_t9 + 0x16e26c) = 0;
      (**(code **)(in_t9 + 0x16b538))(7,0xf37);
      (**(code **)(in_t9 + 0x16b538))(0xe,0xc42);
      (**(code **)(in_t9 + 0x16b538))(3,0x79);
      (**(code **)(in_t9 + 0x168918))(1);
    }
    uStack_1c = 1;
    (**(code **)(in_t9 + 0x167e04))(auStack_30);
  }
  else {
    uStack_1c = 1;
  }
  return uStack_1c;
}

