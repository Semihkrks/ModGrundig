
/* MSrv_DTV_Player_DVB::_GetAvInfoFromProgramInfo(_DVB_PROGRAMINFO const&, unsigned char&,
   MW_DTV_AVInfo&) */

void __thiscall
MSrv_DTV_Player_DVB::_GetAvInfoFromProgramInfo
          (MSrv_DTV_Player_DVB *this,_DVB_PROGRAMINFO *param_1,uchar *param_2,MW_DTV_AVInfo *param_3
          )

{
  _DVB_PROGRAMINFO _Var1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  MW_DTV_AVInfo local_20 [8];
  
  sVar2 = *(short *)(param_1 + 0x30);
  if (sVar2 == 0x1fff) {
LAB_2d4d6a60:
    *(undefined4 *)param_3 = 0;
  }
  else {
    switch(param_1[0x19]) {
    default:
      goto LAB_2d4d6a60;
    case (_DVB_PROGRAMINFO)0x1:
      *(undefined4 *)param_3 = 1;
      break;
    case (_DVB_PROGRAMINFO)0x2:
      *(undefined4 *)param_3 = 2;
      break;
    case (_DVB_PROGRAMINFO)0x3:
      *(undefined4 *)param_3 = 3;
      break;
    case (_DVB_PROGRAMINFO)0x4:
      *(undefined4 *)param_3 = 4;
      break;
    case (_DVB_PROGRAMINFO)0x5:
      *(undefined4 *)param_3 = 7;
    }
  }
  *(short *)(param_3 + 0x10) = sVar2;
  local_20[0] = (MW_DTV_AVInfo)0xff;
  iVar4 = SearchAudESIndexForGivenAudioLangList(this,param_1);
  *param_2 = (uchar)iVar4;
  sVar2 = *(short *)(param_1 + iVar4 * 0xe + 0x54);
  if (sVar2 == 0x1fff) {
    *(undefined4 *)(param_3 + 4) = 0xff;
  }
  else {
    switch(param_1[iVar4 * 0xe + 0x56]) {
    case (_DVB_PROGRAMINFO)0x0:
      *(undefined4 *)(param_3 + 4) = 0;
      break;
    case (_DVB_PROGRAMINFO)0x1:
      *(undefined4 *)(param_3 + 4) = 1;
      break;
    default:
      *(undefined4 *)(param_3 + 4) = 0xff;
      break;
    case (_DVB_PROGRAMINFO)0x3:
    case (_DVB_PROGRAMINFO)0x5:
    case (_DVB_PROGRAMINFO)0x10:
    case (_DVB_PROGRAMINFO)0x11:
    case (_DVB_PROGRAMINFO)0x12:
    case (_DVB_PROGRAMINFO)0x13:
    case (_DVB_PROGRAMINFO)0x14:
      *(undefined4 *)(param_3 + 4) = 4;
      _Var1 = param_1[0x4c];
      goto joined_r0x2d4d6c94;
    case (_DVB_PROGRAMINFO)0x4:
      *(undefined4 *)(param_3 + 4) = 6;
      break;
    case (_DVB_PROGRAMINFO)0x15:
      *(undefined4 *)(param_3 + 4) = 0x12;
    }
    _Var1 = param_1[0x4c];
joined_r0x2d4d6c94:
    uVar6 = (uint)(byte)_Var1;
    if (uVar6 == 0xff) {
      _Var1 = param_1[iVar4 * 0xe + 0x51];
      if (_Var1 != (_DVB_PROGRAMINFO)0x1) {
        if (_Var1 == (_DVB_PROGRAMINFO)0x0) goto LAB_2d4d6dcc;
        uVar7 = 0;
        if (_Var1 == (_DVB_PROGRAMINFO)0x2) {
          uVar7 = 2;
        }
        goto LAB_2d4d6cc4;
      }
      *(undefined4 *)(param_3 + 8) = 1;
    }
    else {
      uVar7 = 1;
      if (uVar6 == 1) {
LAB_2d4d6cc4:
        *(undefined4 *)(param_3 + 8) = uVar7;
      }
      else if (uVar6 == 0) {
LAB_2d4d6dcc:
        *(undefined4 *)(param_3 + 8) = 0;
      }
      else {
        if (uVar6 != 2) {
          uVar6 = 0;
        }
        *(uint *)(param_3 + 8) = uVar6;
      }
    }
  }
  iVar5 = *(int *)this;
  *(short *)(param_3 + 0x12) = sVar2;
  iVar5 = (**(code **)(iVar5 + 0x82c))(this,param_1,iVar4,local_20);
  if (iVar5 != 0) {
    sVar2 = *(short *)(param_1 + (uint)(byte)local_20[0] * 0xe + 0x54);
    if (sVar2 == 0x1fff) {
LAB_2d4d6b94:
      *(undefined4 *)(param_3 + 0xc) = 0xff;
    }
    else {
      switch(param_1[(uint)(byte)local_20[0] * 0xe + 0x56]) {
      case (_DVB_PROGRAMINFO)0x0:
        *(undefined4 *)(param_3 + 0xc) = 5;
        break;
      case (_DVB_PROGRAMINFO)0x1:
        *(undefined4 *)(param_3 + 0xc) = 2;
        break;
      default:
        goto LAB_2d4d6b94;
      case (_DVB_PROGRAMINFO)0x3:
      case (_DVB_PROGRAMINFO)0x5:
      case (_DVB_PROGRAMINFO)0x10:
      case (_DVB_PROGRAMINFO)0x11:
      case (_DVB_PROGRAMINFO)0x12:
      case (_DVB_PROGRAMINFO)0x13:
      case (_DVB_PROGRAMINFO)0x14:
        *(undefined4 *)(param_3 + 0xc) = 8;
        break;
      case (_DVB_PROGRAMINFO)0x4:
        *(undefined4 *)(param_3 + 0xc) = 7;
        break;
      case (_DVB_PROGRAMINFO)0x15:
        *(undefined4 *)(param_3 + 0xc) = 0x13;
      }
    }
    *(short *)(param_3 + 0x14) = sVar2;
  }
  iVar4 = (**(code **)(*(int *)this + 0x758))(this,param_1,iVar4,local_20);
  if (iVar4 == 0) goto LAB_2d4d6c24;
  sVar2 = *(short *)(param_1 + (uint)(byte)local_20[0] * 0xe + 0x54);
  if (sVar2 == 0x1fff) {
    *(undefined4 *)(param_3 + 0xc) = 0xff;
    uVar6 = (uint)(byte)param_1[(uint)(byte)local_20[0] * 0xe + 0x56];
    bVar3 = uVar6 < 0x16;
joined_r0x2d4d6de0:
    if (bVar3) {
LAB_2d4d6d0c:
                    /* WARNING: Could not recover jumptable at 0x2d4d6d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&_gp + *(int *)(&UNK_2d596dd0 + uVar6 * 4)))();
      return;
    }
LAB_2d4d6c04:
    *(undefined4 *)(param_3 + 0x18) = 0xff;
  }
  else {
    uVar6 = (uint)(byte)param_1[(uint)(byte)local_20[0] * 0xe + 0x56];
    bVar3 = uVar6 < 0x16;
    switch(uVar6) {
    case 0:
      *(undefined4 *)(param_3 + 0xc) = 5;
      *(undefined4 *)(param_3 + 0x18) = 0;
      break;
    case 1:
      *(undefined4 *)(param_3 + 0xc) = 2;
      *(undefined4 *)(param_3 + 0x18) = 1;
      break;
    default:
      *(undefined4 *)(param_3 + 0xc) = 0xff;
      if (bVar3) goto LAB_2d4d6d0c;
      goto LAB_2d4d6c04;
    case 3:
    case 5:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
      *(undefined4 *)(param_3 + 0xc) = 8;
      goto joined_r0x2d4d6de0;
    case 4:
      *(undefined4 *)(param_3 + 0xc) = 7;
      *(undefined4 *)(param_3 + 0x18) = 6;
      break;
    case 0x15:
      *(undefined4 *)(param_3 + 0xc) = 0x13;
      *(undefined4 *)(param_3 + 0x18) = 0x12;
    }
  }
  param_3[0x1c] = local_20[0];
  *(short *)(param_3 + 0x16) = sVar2;
  printf("\nXXX stReturn.u16BmaAudioPID %hu \n");
LAB_2d4d6c24:
  *(undefined2 *)(param_3 + 0x1e) = *(undefined2 *)(param_1 + 0x2e);
  return;
}

