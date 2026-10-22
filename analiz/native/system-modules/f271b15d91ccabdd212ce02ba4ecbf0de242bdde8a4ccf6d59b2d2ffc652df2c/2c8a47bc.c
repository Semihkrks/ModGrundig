
int iw_channel_to_freq(int channel,double *pfreq,iw_range *range)

{
  bool bVar1;
  iw_freq *piVar2;
  iw_range *piVar3;
  int iVar4;
  bool bVar5;
  double dVar6;
  
                    /* Unresolved local var: int has_freq@[???]
                       Unresolved local var: int k@[???] */
  bVar5 = false;
  iVar4 = 0;
  piVar3 = range;
  while (bVar1 = iVar4 < (int)(uint)range->num_frequency, iVar4 = iVar4 + 1, bVar1) {
    if ((piVar3->freq[0].e == 0) && (piVar3->freq[0].m < 0x3e9)) {
      piVar3 = (iw_range *)&piVar3->max_nwid;
    }
    else {
      bVar5 = true;
      piVar3 = (iw_range *)&piVar3->max_nwid;
    }
  }
  if (bVar5) {
    piVar3 = range;
    for (iVar4 = 0; iVar4 < (int)(uint)range->num_frequency; iVar4 = iVar4 + 1) {
      piVar2 = piVar3->freq;
      piVar3 = (iw_range *)&piVar3->max_nwid;
      if ((uint)piVar2->i == channel) {
        dVar6 = (double)(*(code *)PTR_iw_freq2float_2c8b82d0)(range->freq + iVar4);
        *pfreq = dVar6;
        return channel;
      }
    }
    iVar4 = -2;
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}

