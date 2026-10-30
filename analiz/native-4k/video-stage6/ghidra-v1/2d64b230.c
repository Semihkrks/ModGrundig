
/* WARNING: Type propagation algorithm not settling */

undefined4 _MApi_VDEC_EX_V2_GetErrCode(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_28 [2];
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    printf("ERROR!!! Input Null pointer at %s:%d","_MApi_VDEC_EX_V2_GetErrCode",0x3480);
    return 2;
  }
  uVar7 = *(uint *)(param_1 + 4) >> 0x18;
  iVar3 = uVar7 * 0x11ac;
  iVar5 = *(int *)(pVdecExContext + iVar3 + 0x10);
  uVar6 = *(uint *)(param_1 + 4) & 0xffffff;
  if (iVar5 != 1) {
    if (iVar5 == 0) {
      local_28[0] = 0;
      local_28[1] = 0;
      MDrv_MVD_GetErrInfo(uVar6,local_28,local_28 + 1);
      *(int *)(pVdecExContext + iVar3 + 0x18) = local_28[0] + 0x2000000;
      if (local_28[0] == 0) {
        iVar5 = MDrv_MVD_GetFrmRateIsSupported(uVar6);
        if (iVar5 == 0) {
          *(undefined4 *)(pVdecExContext + iVar3 + 0x18) = 0x1000003;
        }
        if ((bIsSupportDivx == '\0') && (iVar3 = MDrv_MVD_GetDivxVer(uVar6), iVar3 != 0)) {
          *(undefined4 *)(uVar7 * 0x11ac + pVdecExContext + 0x18) = 0x1000004;
        }
      }
    }
    else if (iVar5 == 2) {
      MsOS_ObtainMutex(s32VDECMutexID,0xffffff00);
      iVar5 = pVdecExContext;
      iVar1 = MApi_MJPEG_GetErrCode(uVar6);
      *(int *)(iVar5 + iVar3 + 0x18) = iVar1 + 0x5000000;
      MsOS_ReleaseMutex(s32VDECMutexID);
    }
    else {
      *(undefined4 *)(pVdecExContext + iVar3 + 0x18) = 0;
    }
    goto LAB_2d64b2f4;
  }
  uVar2 = MDrv_HVD_EX_GetErrCode(uVar6);
  if (uVar2 == 0x1005) {
    uVar4 = 0x3001005;
  }
  else if (uVar2 < 0x1006) {
    if (uVar2 == 6) {
      uVar4 = 0x3000006;
    }
    else if (uVar2 < 7) {
      if (uVar2 == 3) {
        uVar4 = 0x3000003;
      }
      else if (uVar2 < 4) {
        if (uVar2 == 1) {
          uVar4 = 0x3000001;
        }
        else {
          if (uVar2 != 2) {
LAB_2d64b4c8:
            *(undefined4 *)(pVdecExContext + uVar7 * 0x11ac + 0x18) = 0x3000000;
            if ((uVar2 == 0) && (iVar3 = MDrv_HVD_EX_GetFrmRateIsSupported(uVar6), iVar3 == 0)) {
              *(undefined4 *)(pVdecExContext + uVar7 * 0x11ac + 0x18) = 0x1000003;
            }
            goto LAB_2d64b2f4;
          }
          uVar4 = 0x3000002;
        }
      }
      else if (uVar2 == 4) {
        uVar4 = 0x3000004;
      }
      else {
        if (uVar2 != 5) goto LAB_2d64b4c8;
        uVar4 = 0x3000005;
      }
    }
    else if (uVar2 == 0x1001) {
      uVar4 = 0x3001001;
    }
    else if (uVar2 < 0x1002) {
      if (uVar2 == 7) {
        uVar4 = 0x3000007;
      }
      else {
        if (uVar2 != 8) goto LAB_2d64b4c8;
        uVar4 = 0x1000004;
      }
    }
    else if (uVar2 == 0x1003) {
      uVar4 = 0x3001003;
    }
    else if (uVar2 < 0x1004) {
      uVar4 = 0x3001002;
    }
    else {
      uVar4 = 0x3001004;
    }
  }
  else if (uVar2 == 0x3003) {
    uVar4 = 0x3003003;
  }
  else if (uVar2 < 0x3004) {
    if (uVar2 == 0x2001) {
      uVar4 = 0x3002001;
    }
    else if (uVar2 < 0x2002) {
      if (uVar2 == 0x1006) {
        uVar4 = 0x3001006;
      }
      else {
        if (uVar2 != 0x1007) goto LAB_2d64b4c8;
        uVar4 = 0x3001007;
      }
    }
    else if (uVar2 == 0x3001) {
      uVar4 = 0x3003001;
    }
    else {
      if (uVar2 != 0x3002) goto LAB_2d64b4c8;
      uVar4 = 0x3003002;
    }
  }
  else if (uVar2 == 0x3006) {
    uVar4 = 0x3003006;
  }
  else if (uVar2 < 0x3007) {
    if (uVar2 == 0x3004) {
      uVar4 = 0x3003004;
    }
    else {
      if (uVar2 != 0x3005) goto LAB_2d64b4c8;
      uVar4 = 0x3003005;
    }
  }
  else if (uVar2 == 0x3008) {
    uVar4 = 0x3003008;
  }
  else if (uVar2 < 0x3008) {
    uVar4 = 0x3003007;
  }
  else {
    if (uVar2 != 0x3009) goto LAB_2d64b4c8;
    uVar4 = 0x3003009;
  }
  *(undefined4 *)(uVar7 * 0x11ac + pVdecExContext + 0x18) = uVar4;
LAB_2d64b2f4:
  iVar3 = uVar7 * 0x11ac + pVdecExContext;
  if ((*(uint *)(iVar3 + 0x18) & 0xffffff) == 0) {
    *(undefined4 *)(iVar3 + 0x18) = 0;
  }
  *param_2 = *(undefined4 *)(uVar7 * 0x11ac + pVdecExContext + 0x18);
  return 1;
}

