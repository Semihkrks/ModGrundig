
undefined4
deflateInit2_(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,char *param_7
             ,int param_8)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  
  if (param_7 == (char *)0x0) {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0xfffffffa;
    if ((*param_7 == '1') && (uVar1 = 0xfffffffa, param_8 == 0x38)) {
      if (param_1 != 0) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        UNRECOVERED_JUMPTABLE = PTR_zcalloc_2f275828;
        if (*(int *)(param_1 + 0x20) == 0) {
          *(undefined4 *)(param_1 + 0x28) = 0;
          *(undefined **)(param_1 + 0x20) = UNRECOVERED_JUMPTABLE;
        }
        if (*(int *)(param_1 + 0x24) == 0) {
          *(undefined **)(param_1 + 0x24) = PTR_zcfree_2f27582c;
        }
        if (param_2 == -1) {
          param_2 = 6;
        }
        if ((int)param_4 < 0) {
          param_4 = -param_4;
          iVar6 = 0;
        }
        else {
          iVar6 = 1;
          if (0xf < (int)param_4) {
            param_4 = param_4 - 0x10;
            iVar6 = 2;
          }
        }
        if (8 < param_5 - 1U) {
          return 0xfffffffe;
        }
        if (param_3 != 8) {
          return 0xfffffffe;
        }
        if ((int)param_4 < 8) {
          return 0xfffffffe;
        }
        if (0xf < (int)param_4) {
          return 0xfffffffe;
        }
        if (param_2 < 0) {
          return 0xfffffffe;
        }
        if (9 < param_2) {
          return 0xfffffffe;
        }
        if (param_6 < 0) {
          return 0xfffffffe;
        }
        if (param_6 < 5) {
          if (param_4 == 8) {
            param_4 = 9;
          }
          piVar2 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16c4);
          if (piVar2 == (int *)0x0) {
            return 0xfffffffc;
          }
          iVar5 = 1 << (param_5 + 7U & 0x1f);
          iVar4 = 1 << (param_4 & 0x1f);
          uVar1 = *(undefined4 *)(param_1 + 0x28);
          pcVar7 = *(code **)(param_1 + 0x20);
          piVar2[0x14] = param_5 + 7U;
          piVar2[0x13] = iVar5;
          piVar2[0x15] = iVar5 + -1;
          piVar2[0xb] = iVar4;
          piVar2[6] = iVar6;
          piVar2[0xd] = iVar4 + -1;
          *(int **)(param_1 + 0x1c) = piVar2;
          *piVar2 = param_1;
          piVar2[0x16] = (param_5 + 9U) / 3;
          piVar2[7] = 0;
          piVar2[0xc] = param_4;
          iVar6 = (*pcVar7)(uVar1,iVar4,2);
          uVar1 = *(undefined4 *)(param_1 + 0x28);
          pcVar7 = *(code **)(param_1 + 0x20);
          piVar2[0xe] = iVar6;
          iVar6 = (*pcVar7)(uVar1,piVar2[0xb],2);
          uVar1 = *(undefined4 *)(param_1 + 0x28);
          pcVar7 = *(code **)(param_1 + 0x20);
          piVar2[0x10] = iVar6;
          iVar6 = (*pcVar7)(uVar1,piVar2[0x13],2);
          pcVar7 = *(code **)(param_1 + 0x20);
          uVar1 = *(undefined4 *)(param_1 + 0x28);
          iVar4 = 1 << (param_5 + 6U & 0x1f);
          piVar2[0x11] = iVar6;
          piVar2[0x5b0] = 0;
          piVar2[0x5a7] = iVar4;
          iVar6 = (*pcVar7)(uVar1,iVar4,4);
          uVar3 = piVar2[0x5a7];
          piVar2[3] = uVar3 << 2;
          piVar2[2] = iVar6;
          UNRECOVERED_JUMPTABLE = PTR_deflateReset_2f2758ac;
          if ((((piVar2[0xe] != 0) && (piVar2[0x10] != 0)) && (piVar2[0x11] != 0)) && (iVar6 != 0))
          {
            *(undefined1 *)(piVar2 + 9) = 8;
            piVar2[0x5a6] = iVar6 + uVar3 * 3;
            piVar2[0x21] = param_2;
            piVar2[0x22] = param_6;
            piVar2[0x5a9] = iVar6 + (uVar3 & 0xfffffffe);
                    /* WARNING: Could not recover jumptable at 0x2f253b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
            return uVar1;
          }
          piVar2[1] = 0x29a;
          UNRECOVERED_JUMPTABLE = PTR_deflateEnd_2f2758b0;
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(PTR_PTR_2f275830 + 0x18);
          (*(code *)UNRECOVERED_JUMPTABLE)(param_1);
          return 0xfffffffc;
        }
      }
      uVar1 = 0xfffffffe;
    }
  }
  return uVar1;
}

