
int iw_freq_to_channel(double freq,iw_range *range)

{
  int iVar1;
  int iVar2;
  undefined4 in_a0;
  int iVar3;
  undefined4 in_a1;
  
                    /* Unresolved local var: double ref_freq@[???]
                       Unresolved local var: int k@[???] */
  iVar1 = (*(code *)PTR___ltdf2_2c8b8254)
                    (in_a0,in_a1,*(undefined4 *)(PTR_DAT_2c8b8238 + -0x7f78),
                     *(undefined4 *)(PTR_DAT_2c8b8238 + -0x7f74));
  iVar3 = -1;
  if (-1 < iVar1) {
    iVar3 = 0x26;
    iVar1 = 0;
    while( true ) {
      if ((int)(uint)range->num_frequency <= iVar1) break;
      (*(code *)PTR_iw_freq2float_2c8b82d0)(range->event_capa + iVar3 * 2 + -3);
      iVar2 = (*(code *)PTR___eqdf2_2c8b8258)();
      if (iVar2 == 0) {
        return (uint)*(byte *)((int)range->event_capa + iVar3 * 8 + -6);
      }
      iVar3 = iVar1 + 0x27;
      iVar1 = iVar1 + 1;
    }
    iVar3 = -2;
  }
  return iVar3;
}

