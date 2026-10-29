
/* MSrv_DTV_Player_DVB::_DoInit_EpgAndCmdbAndSiParser() */

void __thiscall MSrv_DTV_Player_DVB::_DoInit_EpgAndCmdbAndSiParser(MSrv_DTV_Player_DVB *this)

{
  MSrv_DTV_Player_DVB MVar1;
  uchar uVar2;
  uint uVar3;
  MW_DTV_EPG_DVB_PARSER_Customer *this_00;
  mapi_event<MSrv_DTV_Player_DVB::MS_DTV_EPGInfo> *this_01;
  mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> *this_02;
  MW_DVB_SI_PSI_Parser_Customer *this_03;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  MSrv_EPG_Adaptation_Customer *this_04;
  MW_DVB_SI_PSI_Parser *this_05;
  code *pcVar8;
  int *piVar9;
  uchar auStack_48 [4];
  undefined1 auStack_44 [18];
  char local_32;
  
  if (*(int **)(this + 0x10c) == (int *)0x0) {
    iVar7 = MW_DTV_EPG_DVB::GetInstance();
    *(int *)(this + 0x10c) = iVar7;
    if (iVar7 == 0) {
      uVar4 = 0x283f;
      goto LAB_2d4d3768;
    }
    MVar1 = this[0x2c0];
    piVar9 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
    uVar3 = (**(code **)(*piVar9 + 0x8c))(piVar9);
    if ((byte)MVar1 != uVar3) {
      (**(code **)(**(int **)(this + 0x10c) + 0x20))();
    }
    this_00 = operator_new(0x5c,(nothrow_t *)&DAT_2c7f5bd0);
    if (this_00 != (MW_DTV_EPG_DVB_PARSER_Customer *)0x0) {
                    /* try { // try from 2d4d33e4 to 2d4d33eb has its CatchHandler @ 2d4d38bc */
      MW_DTV_EPG_DVB_PARSER_Customer::MW_DTV_EPG_DVB_PARSER_Customer(this_00);
    }
    *(MW_DTV_EPG_DVB_PARSER_Customer **)(this + 0x110) = this_00;
    if (this_00 == (MW_DTV_EPG_DVB_PARSER_Customer *)0x0) {
      uVar4 = 0x2856;
      goto LAB_2d4d3768;
    }
    (**(code **)(*(int *)this_00 + 8))
              (this_00,*(undefined4 *)(this + 0x108),*(undefined4 *)(this + 0x114));
    this_01 = operator_new(0x50,(nothrow_t *)&DAT_2c7f5bd0);
    if (this_01 == (mapi_event<MSrv_DTV_Player_DVB::MS_DTV_EPGInfo> *)0x0) {
      *(undefined4 *)(this + 0xf0) = 0;
      uVar4 = 0x285a;
      goto LAB_2d4d3768;
    }
                    /* try { // try from 2d4d3434 to 2d4d343b has its CatchHandler @ 2d4d3894 */
    mapi_event<MSrv_DTV_Player_DVB::MS_DTV_EPGInfo>::mapi_event(this_01);
    *(mapi_event<MSrv_DTV_Player_DVB::MS_DTV_EPGInfo> **)(this + 0xf0) = this_01;
    (**(code **)(**(int **)(this + 0x110) + 0x1c))(*(int **)(this + 0x110),EPGMonitorNotify,this);
  }
  else {
    (**(code **)(**(int **)(this + 0x10c) + 0x20))();
  }
  if (*(int *)(this + 0x548) == 0) {
    this_04 = operator_new(0xc);
                    /* try { // try from 2d4d3708 to 2d4d370f has its CatchHandler @ 2d4d38c4 */
    MSrv_EPG_Adaptation_Customer::MSrv_EPG_Adaptation_Customer(this_04,this);
    *(MSrv_EPG_Adaptation_Customer **)(this + 0x548) = this_04;
  }
  if (*(int *)(this + 0x130) == 0) {
    pcVar8 = *(code **)(*(int *)this + 0x8c8);
    uVar4 = _GetCountry();
    (*pcVar8)(this,uVar4);
  }
  if (*(int *)(this + 0xfc) != 0) {
    return;
  }
  this_02 = operator_new(0x50,(nothrow_t *)&DAT_2c7f5bd0);
  if (this_02 == (mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> *)0x0) {
    *(undefined4 *)(this + 0xd4) = 0;
    uVar4 = 0x286e;
  }
  else {
                    /* try { // try from 2d4d3484 to 2d4d348b has its CatchHandler @ 2d4d38e8 */
    mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo>::mapi_event(this_02);
    *(mapi_event<MSrv_DTV_Player_DVB::MS_DTV_SIInfo> **)(this + 0xd4) = this_02;
    this_03 = operator_new(0xd3920,(nothrow_t *)&DAT_2c7f5bd0);
    if (this_03 != (MW_DVB_SI_PSI_Parser_Customer *)0x0) {
                    /* try { // try from 2d4d34b8 to 2d4d34bf has its CatchHandler @ 2d4d38e0 */
      MW_DVB_SI_PSI_Parser_Customer::MW_DVB_SI_PSI_Parser_Customer(this_03);
    }
    *(MW_DVB_SI_PSI_Parser_Customer **)(this + 0xfc) = this_03;
    if (this_03 != (MW_DVB_SI_PSI_Parser_Customer *)0x0) {
      piVar9 = (int *)0x0;
      pcVar8 = *(code **)(*(int *)this_03 + 8);
      uVar4 = mapi_interface_TV::Get_mapi_si_psi();
      (*pcVar8)(this_03,uVar4,*(undefined4 *)(this + 0x114),this,
                CIAdaptation::staticCiNotifyPmtUpdate,0,CIAdaptation::staticCIProtectionNotify,
                SI_EventHandler,*(undefined4 *)(this + 0x9c));
      this_05 = *(MW_DVB_SI_PSI_Parser **)(this + 0xfc);
      uVar2 = (**(code **)(*(int *)this + 0x710))(this);
      MW_DVB_SI_PSI_Parser::SetOPVariableInit(this_05,uVar2,*(void **)(this + 0x114));
      if (*(int *)(this + 0xfc) != 0) {
        piVar9 = (int *)__dynamic_cast(*(int *)(this + 0xfc),&MW_DVB_SI_PSI_Parser::typeinfo,
                                       &MW_DVB_SI_PSI_Parser_Customer::typeinfo,0);
      }
      pcVar8 = *(code **)(*piVar9 + 0xc);
      uVar4 = _GetCountry();
      uVar5 = _GetTimeZone();
      uVar6 = _GetLanguage();
      (*pcVar8)(piVar9,uVar4,uVar5,1,0x7b2,uVar6);
      piVar9 = (int *)0x0;
      if (*(int *)(this + 0xfc) != 0) {
        piVar9 = (int *)__dynamic_cast(*(int *)(this + 0xfc),&MW_DVB_SI_PSI_Parser::typeinfo,
                                       &MW_DVB_SI_PSI_Parser_Customer::typeinfo,0);
      }
      (**(code **)(*piVar9 + 0x20))(piVar9,SIMonitorNotify,this);
      piVar9 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      (**(code **)(*piVar9 + 0x90))(piVar9,auStack_44);
      piVar9 = (int *)0x0;
      if (*(int *)(this + 0xfc) != 0) {
        piVar9 = (int *)__dynamic_cast(*(int *)(this + 0xfc),&MW_DVB_SI_PSI_Parser::typeinfo,
                                       &MW_DVB_SI_PSI_Parser_Customer::typeinfo,0);
      }
      (**(code **)(*piVar9 + 0x354))(piVar9,local_32 == '\x01');
      piVar9 = *(int **)(this + 0xfc);
      pcVar8 = *(code **)(*piVar9 + 0x24);
      uVar4 = _GetClockMode();
      (*pcVar8)(piVar9,uVar4);
      MW_DVB_SI_PSI_Parser::SetDynamicRescanOff(*(MW_DVB_SI_PSI_Parser **)(this + 0xfc),'\x01');
      iVar7 = (**(code **)(*(int *)this + 0x710))(this);
      if (iVar7 == 0) {
        iVar7 = *(int *)this;
      }
      else {
        MW_DVB_SI_PSI_Parser::SetOPVariableInit
                  (*(MW_DVB_SI_PSI_Parser **)(this + 0xfc),'\x01',*(void **)(this + 0x114));
        pcVar8 = *(code **)(*(int *)this + 0x6f8);
        uVar4 = (**(code **)(*(int *)this + 0x700))(this);
        iVar7 = (*pcVar8)(this,uVar4,auStack_48);
        uVar4 = 0x31;
        if (iVar7 == 1) {
          uVar4 = mapi_dvb_utility::SI_GetISO639LangCode(auStack_48);
        }
        (**(code **)(**(int **)(this + 0xfc) + 0x10))(*(int **)(this + 0xfc),uVar4);
        iVar7 = *(int *)this;
      }
      (**(code **)(iVar7 + 0x840))(this);
      return;
    }
    uVar4 = 0x2871;
  }
LAB_2d4d3768:
  printf("ASSERT FAIL: %s %s %d\n",&UNK_2d593dc0,&UNK_2d597c00,uVar4);
                    /* WARNING: Subroutine does not return */
  abort();
}

