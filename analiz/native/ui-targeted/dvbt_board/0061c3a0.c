
/* ArResourceManager::SetBrandOSDAndBootLogo(unsigned long) */

undefined4 ArResourceManager::SetBrandOSDAndBootLogo(ulong param_1)

{
  int *piVar1;
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  ulong uStack_1c;
  
  uStack_1c = param_1;
  if (param_1 == 2) {
    (*(code *)PTR_allocator_010c6920)(auStack_40);
                    /* try { // try from 0061c5cc to 0061c5d3 has its CatchHandler @ 0061c6b8 */
    (*(code *)PTR_string_010c4f9c)(auStack_3c,PTR_s_13AutoSearchApp_010c4360 + -0x5a4c,auStack_40);
                    /* try { // try from 0061c5e4 to 0061c5eb has its CatchHandler @ 0061c678 */
    (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_3c);
    puStack_24 = auStack_3c;
                    /* try { // try from 0061c600 to 0061c607 has its CatchHandler @ 0061c6b8 */
    (*(code *)PTR__string_010c5070)(puStack_24);
    (*(code *)PTR__allocator_010c4948)(auStack_40);
    (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a34);
    piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
    (**(code **)(*piVar1 + 0x15c))(piVar1,2);
    return 1;
  }
  if ((int)param_1 < 3) {
    if (param_1 == 1) {
      (*(code *)PTR_allocator_010c6920)(auStack_38);
                    /* try { // try from 0061c468 to 0061c46f has its CatchHandler @ 0061c554 */
      (*(code *)PTR_string_010c4f9c)(auStack_34,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_38)
      ;
                    /* try { // try from 0061c480 to 0061c487 has its CatchHandler @ 0061c514 */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_34);
      puStack_20 = auStack_34;
                    /* try { // try from 0061c49c to 0061c4a3 has its CatchHandler @ 0061c554 */
      (*(code *)PTR__string_010c5070)(puStack_20);
      (*(code *)PTR__allocator_010c4948)(auStack_38);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a60);
      piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
      (**(code **)(*piVar1 + 0x15c))(piVar1,3);
      return 1;
    }
  }
  else {
    if (param_1 == 3) {
      (*(code *)PTR_allocator_010c6920)(auStack_50);
                    /* try { // try from 0061c894 to 0061c89b has its CatchHandler @ 0061c980 */
      (*(code *)PTR_string_010c4f9c)(auStack_4c,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_50)
      ;
                    /* try { // try from 0061c8ac to 0061c8b3 has its CatchHandler @ 0061c940 */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_4c);
      puStack_2c = auStack_4c;
                    /* try { // try from 0061c8c8 to 0061c8cf has its CatchHandler @ 0061c980 */
      (*(code *)PTR__string_010c5070)(puStack_2c);
      (*(code *)PTR__allocator_010c4948)(auStack_50);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a08);
      piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
      (**(code **)(*piVar1 + 0x15c))(piVar1,0);
      return 1;
    }
    if (param_1 == 4) {
      (*(code *)PTR_allocator_010c6920)(auStack_48);
                    /* try { // try from 0061c730 to 0061c737 has its CatchHandler @ 0061c81c */
      (*(code *)PTR_string_010c4f9c)(auStack_44,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_48)
      ;
                    /* try { // try from 0061c748 to 0061c74f has its CatchHandler @ 0061c7dc */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_44);
      puStack_28 = auStack_44;
                    /* try { // try from 0061c764 to 0061c76b has its CatchHandler @ 0061c81c */
      (*(code *)PTR__string_010c5070)(puStack_28);
      (*(code *)PTR__allocator_010c4948)(auStack_48);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a1c);
      piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
      (**(code **)(*piVar1 + 0x15c))(piVar1,0);
      return 1;
    }
  }
  (*(code *)PTR_allocator_010c6920)(auStack_58);
                    /* try { // try from 0061c9f8 to 0061c9ff has its CatchHandler @ 0061caf4 */
  (*(code *)PTR_string_010c4f9c)(auStack_54,PTR_s_13AutoSearchApp_010c4360 + -0x59f0,auStack_58);
                    /* try { // try from 0061ca10 to 0061ca17 has its CatchHandler @ 0061cab4 */
  (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_54);
  puStack_30 = auStack_54;
                    /* try { // try from 0061ca2c to 0061ca33 has its CatchHandler @ 0061caf4 */
  (*(code *)PTR__string_010c5070)(puStack_30);
  (*(code *)PTR__allocator_010c4948)(auStack_58);
  (*(code *)PTR_SetOSDLanguageRCPath_010c659c)();
  (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x59e0);
  piVar1 = (int *)(*(code *)PTR_GetInstance_010cb5a8)();
  (**(code **)(*piVar1 + 0x15c))(piVar1,1);
  return 1;
}

