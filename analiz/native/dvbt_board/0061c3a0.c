
/* ArResourceManager::SetBrandOSDAndBootLogo(unsigned long) */

undefined4 ArResourceManager::SetBrandOSDAndBootLogo(ulong param_1)

{
  int *piVar1;
  int in_t9;
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
    (**(code **)(in_t9 + 0xaaa580))(auStack_40);
                    /* try { // try from 0061c5cc to 0061c5d3 has its CatchHandler @ 0061c6b8 */
    (**(code **)(in_t9 + 0xaa8bfc))(auStack_3c,*(int *)(in_t9 + 0xaa7fc0) + -0x5a4c,auStack_40);
                    /* try { // try from 0061c5e4 to 0061c5eb has its CatchHandler @ 0061c678 */
    (**(code **)(in_t9 + 0xaaebbc))(auStack_3c);
    puStack_24 = auStack_3c;
                    /* try { // try from 0061c600 to 0061c607 has its CatchHandler @ 0061c6b8 */
    (**(code **)(in_t9 + 0xaa8cd0))(puStack_24);
    (**(code **)(in_t9 + 0xaa85a8))(auStack_40);
    (**(code **)(in_t9 + 0xaac7c4))(*(int *)(in_t9 + 0xaa7fc0) + -0x5a34);
    piVar1 = (int *)(**(code **)(in_t9 + 0xaaf208))();
    (**(code **)(*piVar1 + 0x15c))(piVar1,2);
    return 1;
  }
  if ((int)param_1 < 3) {
    if (param_1 == 1) {
      (**(code **)(in_t9 + 0xaaa580))(auStack_38);
                    /* try { // try from 0061c468 to 0061c46f has its CatchHandler @ 0061c554 */
      (**(code **)(in_t9 + 0xaa8bfc))(auStack_34,*(int *)(in_t9 + 0xaa7fc0) + -0x5a74,auStack_38);
                    /* try { // try from 0061c480 to 0061c487 has its CatchHandler @ 0061c514 */
      (**(code **)(in_t9 + 0xaaebbc))(auStack_34);
      puStack_20 = auStack_34;
                    /* try { // try from 0061c49c to 0061c4a3 has its CatchHandler @ 0061c554 */
      (**(code **)(in_t9 + 0xaa8cd0))(puStack_20);
      (**(code **)(in_t9 + 0xaa85a8))(auStack_38);
      (**(code **)(in_t9 + 0xaac7c4))(*(int *)(in_t9 + 0xaa7fc0) + -0x5a60);
      piVar1 = (int *)(**(code **)(in_t9 + 0xaaf208))();
      (**(code **)(*piVar1 + 0x15c))(piVar1,3);
      return 1;
    }
  }
  else {
    if (param_1 == 3) {
      (**(code **)(in_t9 + 0xaaa580))(auStack_50);
                    /* try { // try from 0061c894 to 0061c89b has its CatchHandler @ 0061c980 */
      (**(code **)(in_t9 + 0xaa8bfc))(auStack_4c,*(int *)(in_t9 + 0xaa7fc0) + -0x5a74,auStack_50);
                    /* try { // try from 0061c8ac to 0061c8b3 has its CatchHandler @ 0061c940 */
      (**(code **)(in_t9 + 0xaaebbc))(auStack_4c);
      puStack_2c = auStack_4c;
                    /* try { // try from 0061c8c8 to 0061c8cf has its CatchHandler @ 0061c980 */
      (**(code **)(in_t9 + 0xaa8cd0))(puStack_2c);
      (**(code **)(in_t9 + 0xaa85a8))(auStack_50);
      (**(code **)(in_t9 + 0xaac7c4))(*(int *)(in_t9 + 0xaa7fc0) + -0x5a08);
      piVar1 = (int *)(**(code **)(in_t9 + 0xaaf208))();
      (**(code **)(*piVar1 + 0x15c))(piVar1,0);
      return 1;
    }
    if (param_1 == 4) {
      (**(code **)(in_t9 + 0xaaa580))(auStack_48);
                    /* try { // try from 0061c730 to 0061c737 has its CatchHandler @ 0061c81c */
      (**(code **)(in_t9 + 0xaa8bfc))(auStack_44,*(int *)(in_t9 + 0xaa7fc0) + -0x5a74,auStack_48);
                    /* try { // try from 0061c748 to 0061c74f has its CatchHandler @ 0061c7dc */
      (**(code **)(in_t9 + 0xaaebbc))(auStack_44);
      puStack_28 = auStack_44;
                    /* try { // try from 0061c764 to 0061c76b has its CatchHandler @ 0061c81c */
      (**(code **)(in_t9 + 0xaa8cd0))(puStack_28);
      (**(code **)(in_t9 + 0xaa85a8))(auStack_48);
      (**(code **)(in_t9 + 0xaac7c4))(*(int *)(in_t9 + 0xaa7fc0) + -0x5a1c);
      piVar1 = (int *)(**(code **)(in_t9 + 0xaaf208))();
      (**(code **)(*piVar1 + 0x15c))(piVar1,0);
      return 1;
    }
  }
  (**(code **)(in_t9 + 0xaaa580))(auStack_58);
                    /* try { // try from 0061c9f8 to 0061c9ff has its CatchHandler @ 0061caf4 */
  (**(code **)(in_t9 + 0xaa8bfc))(auStack_54,*(int *)(in_t9 + 0xaa7fc0) + -0x59f0,auStack_58);
                    /* try { // try from 0061ca10 to 0061ca17 has its CatchHandler @ 0061cab4 */
  (**(code **)(in_t9 + 0xaaebbc))(auStack_54);
  puStack_30 = auStack_54;
                    /* try { // try from 0061ca2c to 0061ca33 has its CatchHandler @ 0061caf4 */
  (**(code **)(in_t9 + 0xaa8cd0))(puStack_30);
  (**(code **)(in_t9 + 0xaa85a8))(auStack_58);
  (**(code **)(in_t9 + 0xaaa1fc))();
  (**(code **)(in_t9 + 0xaac7c4))(*(int *)(in_t9 + 0xaa7fc0) + -0x59e0);
  piVar1 = (int *)(**(code **)(in_t9 + 0xaaf208))();
  (**(code **)(*piVar1 + 0x15c))(piVar1,1);
  return 1;
}

