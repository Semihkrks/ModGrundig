
/* MW_DTV_FREQUENCYTABLE_DVBS_Customer::LoadSatelliteListfromXML() */

undefined4 MW_DTV_FREQUENCYTABLE_DVBS_Customer::LoadSatelliteListfromXML(void)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  char acStack_60 [80];
  
  uVar1 = MW_FreqTable_XML_Builder::GetInstance();
  snprintf(acStack_60,0x50,"tar xzvf /applications/defaults/frequency_tables.tar.gz -C /USR_DB");
  iVar2 = system(acStack_60);
  snprintf(acStack_60,0x50,"tar xzvf /applications/defaults/frequency_tables.tar.gz -C /BACKUP_DB");
  iVar3 = system(acStack_60);
  if (iVar3 == 0 && iVar2 == 0) {
    puts("LoadSatelliteListfromXML OK");
    sync();
    MW_FreqTable_XML_Builder::Process_Loader(uVar1);
    return 1;
  }
  puts("\x1b[7m LoadSatelliteListfromXML NOK       \x1b[0m");
  MW_FreqTable_XML_Builder::Process_Loader(uVar1);
  return 1;
}

