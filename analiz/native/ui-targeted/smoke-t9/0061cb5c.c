
/* ArResourceManager::SetBrandOSD(unsigned long) */

undefined4 ArResourceManager::SetBrandOSD(ulong param_1)

{
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
                    /* try { // try from 0061cd54 to 0061cd5b has its CatchHandler @ 0061ce0c */
    (*(code *)PTR_string_010c4f9c)(auStack_3c,PTR_s_13AutoSearchApp_010c4360 + -0x5a4c,auStack_40);
                    /* try { // try from 0061cd6c to 0061cd73 has its CatchHandler @ 0061cdcc */
    (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_3c);
    puStack_24 = auStack_3c;
                    /* try { // try from 0061cd88 to 0061cd8f has its CatchHandler @ 0061ce0c */
    (*(code *)PTR__string_010c5070)(puStack_24);
    (*(code *)PTR__allocator_010c4948)(auStack_40);
    (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a34);
    return 1;
  }
  if ((int)param_1 < 3) {
    if (param_1 == 1) {
      (*(code *)PTR_allocator_010c6920)(auStack_38);
                    /* try { // try from 0061cc24 to 0061cc2b has its CatchHandler @ 0061ccdc */
      (*(code *)PTR_string_010c4f9c)(auStack_34,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_38)
      ;
                    /* try { // try from 0061cc3c to 0061cc43 has its CatchHandler @ 0061cc9c */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_34);
      puStack_20 = auStack_34;
                    /* try { // try from 0061cc58 to 0061cc5f has its CatchHandler @ 0061ccdc */
      (*(code *)PTR__string_010c5070)(puStack_20);
      (*(code *)PTR__allocator_010c4948)(auStack_38);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a60);
      return 1;
    }
  }
  else {
    if (param_1 == 3) {
      (*(code *)PTR_allocator_010c6920)(auStack_50);
                    /* try { // try from 0061cfb4 to 0061cfbb has its CatchHandler @ 0061d06c */
      (*(code *)PTR_string_010c4f9c)(auStack_4c,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_50)
      ;
                    /* try { // try from 0061cfcc to 0061cfd3 has its CatchHandler @ 0061d02c */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_4c);
      puStack_2c = auStack_4c;
                    /* try { // try from 0061cfe8 to 0061cfef has its CatchHandler @ 0061d06c */
      (*(code *)PTR__string_010c5070)(puStack_2c);
      (*(code *)PTR__allocator_010c4948)(auStack_50);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a08);
      return 1;
    }
    if (param_1 == 4) {
      (*(code *)PTR_allocator_010c6920)(auStack_48);
                    /* try { // try from 0061ce84 to 0061ce8b has its CatchHandler @ 0061cf3c */
      (*(code *)PTR_string_010c4f9c)(auStack_44,PTR_s_13AutoSearchApp_010c4360 + -0x5a74,auStack_48)
      ;
                    /* try { // try from 0061ce9c to 0061cea3 has its CatchHandler @ 0061cefc */
      (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_44);
      puStack_28 = auStack_44;
                    /* try { // try from 0061ceb8 to 0061cebf has its CatchHandler @ 0061cf3c */
      (*(code *)PTR__string_010c5070)(puStack_28);
      (*(code *)PTR__allocator_010c4948)(auStack_48);
      (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x5a1c);
      return 1;
    }
  }
  (*(code *)PTR_allocator_010c6920)(auStack_58);
                    /* try { // try from 0061d0e4 to 0061d0eb has its CatchHandler @ 0061d1ac */
  (*(code *)PTR_string_010c4f9c)(auStack_54,PTR_s_13AutoSearchApp_010c4360 + -0x59f0,auStack_58);
                    /* try { // try from 0061d0fc to 0061d103 has its CatchHandler @ 0061d16c */
  (*(code *)PTR_ChangeRcPath_010caf5c)(auStack_54);
  puStack_30 = auStack_54;
                    /* try { // try from 0061d118 to 0061d11f has its CatchHandler @ 0061d1ac */
  (*(code *)PTR__string_010c5070)(puStack_30);
  (*(code *)PTR__allocator_010c4948)(auStack_58);
  (*(code *)PTR_SetOSDLanguageRCPath_010c659c)();
  (*(code *)PTR_puts_010c8b64)(PTR_s_13AutoSearchApp_010c4360 + -0x59e0);
  return 1;
}

