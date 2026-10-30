
undefined4 HAL_MAD_GetAudioInfo2(int param_1,undefined4 param_2,uint *param_3)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint3 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  
  uVar5 = HAL_AUDIO_Convert_DecId_to_ADECId();
  uVar5 = uVar5 & 0xff;
  if (g_AudioVars2 == 0) {
    printf("[[utopia]]      %s() : Warning! g_AudioVars2 should not be NULL !!!\n",
           "HAL_MAD_GetAudioInfo2");
    printf("[[utopia]]      %s() : Perform SHM Init here !!!\n","HAL_MAD_GetAudioInfo2");
    iVar6 = HAL_AUDIO_InitialVars();
    if (iVar6 == 0) {
      printf("\x1b[35m UTOPIA ASSERT: %s, %s %s %d\x1b[35m\n",&UNK_2d09023c,
             "/home/jenkins/workspace/AB_C_Beko_CoremaxM1_EU_SN_G9__Marlon_Linux_MIPS/c/UTPA2-300.0.x/build/../mxlib/hal/marlon/audio/halMAD.c"
             ,"HAL_MAD_GetAudioInfo2",0x1362);
    }
  }
  switch(param_2) {
  case 0:
    iVar6 = HAL_DEC_R2_Get_SHM_INFO(1,uVar5);
    if (iVar6 == 0) {
code_r0x2d073038:
      *(undefined1 *)param_3 = 0;
      return 1;
    }
    goto code_r0x2d072f70;
  case 1:
    uVar5 = HAL_DEC_R2_Get_SHM_INFO(3,uVar5);
    *param_3 = 0;
    if (uVar5 == 24000) {
      *param_3 = 6;
      return 1;
    }
    if (uVar5 < 0x5dc1) {
      if (uVar5 == 12000) {
        *param_3 = 3;
        return 1;
      }
      if (uVar5 < 0x2ee1) {
        if (uVar5 == 8000) goto code_r0x2d0733f8;
        if (uVar5 == 0x2b11) {
          *param_3 = 2;
          return 1;
        }
      }
      else {
        if (uVar5 == 16000) {
          *param_3 = 4;
          return 1;
        }
        if (uVar5 == 0x5622) {
          *param_3 = 5;
          return 1;
        }
      }
    }
    else {
      if (uVar5 == 48000) {
        *param_3 = 9;
        return 1;
      }
      if (uVar5 < 0xbb81) {
        if (uVar5 == 32000) {
          *param_3 = 7;
          return 1;
        }
        if (uVar5 == 0xac44) {
          *param_3 = 8;
          return 1;
        }
      }
      else {
        if (uVar5 == 0x15888) {
          *param_3 = 0xb;
          return 1;
        }
        if (uVar5 == 96000) {
          *param_3 = 0xc;
          return 1;
        }
        if (uVar5 == 64000) {
          *param_3 = 10;
          return 1;
        }
      }
    }
code_r0x2d073014:
    *param_3 = 0;
    uVar9 = 1;
    break;
  case 2:
    uVar2 = HAL_AUDIO_ReadReg(0x2d30);
    uVar9 = 1;
    *(ushort *)param_3 = uVar2 & 3;
    break;
  case 3:
    pcVar10 = _GetAudioCaps;
    goto code_r0x2d072f84;
  case 4:
    if (param_1 == 2) {
      uVar9 = 0x112e9b;
    }
    else {
      uVar9 = 0x112e99;
    }
    cVar1 = HAL_AUDIO_AbsReadByte(uVar9);
    if (cVar1 < '\0') goto code_r0x2d073038;
    goto code_r0x2d072f70;
  default:
    printf("[[utopia]]      %s: cmd not Supported\n","HAL_MAD_GetAudioInfo2");
    uVar9 = 0;
    break;
  case 8:
    uVar9 = 0x23;
    goto code_r0x2d072e0c;
  case 9:
    uVar5 = HAL_DEC_R2_Get_SHM_INFO(0x2a,uVar5);
    uVar9 = 1;
    *param_3 = uVar5 / 0x2d;
    break;
  case 10:
    iVar6 = HAL_DEC_R2_Get_SHM_INFO(0x2a,uVar5);
    uVar9 = 1;
    *param_3 = iVar6 << 1;
    param_3[1] = 0;
    break;
  case 0xc:
    if (param_1 == 2) {
      cVar1 = *(char *)(g_AudioVars2 + 5);
    }
    else {
      cVar1 = *(char *)(g_AudioVars2 + 4);
    }
    if (cVar1 != '\0') {
      uVar5 = HAL_DEC_R2_Get_SHM_INFO(0x10,0);
      param_3[1] = uVar5;
      iVar6 = HAL_DEC_R2_Get_SHM_PARAM(0,0,0);
      iVar7 = HAL_AUDIO_GetDspMadBaseAddr(1);
      *param_3 = iVar6 + iVar7 + 0x54000;
      return 1;
    }
code_r0x2d0733dc:
    uVar9 = 0;
    break;
  case 0xd:
    uVar9 = 0x10;
    goto code_r0x2d072e0c;
  case 0xe:
    iVar6 = HAL_DEC_R2_Get_SHM_PARAM(0,0,0);
    goto code_r0x2d07315c;
  case 0xf:
  case 0x16:
    uVar9 = 0xc;
    goto code_r0x2d072e0c;
  case 0x10:
  case 0x15:
    uVar9 = 0xd;
    goto code_r0x2d072e0c;
  case 0x11:
    uVar5 = 2;
    if (param_1 == 2) goto code_r0x2d0733f8;
    if (param_1 == 0) {
      *param_3 = 0;
      return 1;
    }
    goto code_r0x2d072f90;
  case 0x12:
    goto code_r0x2d072e68;
  case 0x14:
    uVar8 = HAL_AUDIO_GetUniDecodeFrameCnt(param_1);
    iVar6 = g_AudioVars2 + (param_1 + 0xc) * 2;
    if (*(ushort *)(iVar6 + 2) != uVar8) {
      uVar3 = HAL_AUDIO_GetUniDecodeFrameCnt(param_1);
      *(undefined2 *)(iVar6 + 2) = uVar3;
      iVar6 = HAL_AUDIO_GetDspMadBaseAddr(1);
      iVar7 = HAL_DEC_R2_Get_SHM_INFO(0x2e,uVar5);
      param_3[1] = iVar6 + iVar7 + 0x2b4000;
      uVar5 = HAL_DEC_R2_Get_SHM_INFO(0x2f,uVar5);
      param_3[2] = uVar5;
      printf("[[utopia]]      \r\n===== Audio_infoType_UNI_PCM1_Info  addr :0x%X     size:0x%X==========\r\n"
             ,param_3[1],uVar5);
    }
    uVar9 = 1;
    *param_3 = (uint)*(ushort *)(g_AudioVars2 + (param_1 + 0xc) * 2 + 2);
    break;
  case 0x17:
    if (param_1 == 2) {
      iVar6 = HAL_AUDIO_GetDspMadBaseAddr(1);
      *param_3 = iVar6 + 0x64000;
      return 1;
    }
    iVar6 = HAL_AUDIO_GetDspMadBaseAddr(1);
code_r0x2d07315c:
    uVar9 = 1;
    *param_3 = iVar6 + 0x54000;
    break;
  case 0x18:
    *param_3 = 0x10000;
    uVar9 = 1;
    break;
  case 0x19:
    iVar6 = HAL_AUDIO_GetDspMadBaseAddr(1);
    uVar9 = 1;
    *param_3 = iVar6 + 0x2b4000;
    break;
  case 0x1a:
    *param_3 = 0x36000;
    uVar9 = 1;
    break;
  case 0x1c:
    uVar9 = 0x11;
code_r0x2d072e0c:
    uVar5 = HAL_DEC_R2_Get_SHM_INFO(uVar9,uVar5);
    *param_3 = uVar5;
    return 1;
  case 0x1d:
    pcVar10 = HAL_AUDIO_GetDspMadBaseAddr;
    param_1 = 2;
code_r0x2d072f84:
    uVar5 = (*pcVar10)(param_1);
code_r0x2d072f90:
    *param_3 = uVar5;
    uVar9 = 1;
    break;
  case 0x1e:
    uVar5 = HAL_MAD2_Read_DSP_sram(0x1907,0);
    uVar8 = *param_3;
    param_3[1] = 1;
    if (uVar8 == 0x200) {
code_r0x2d073548:
      if ((uVar5 & 0x10) == 0) {
        return 1;
      }
      if ((uVar5 & 0x300) != 0x300) {
        return 1;
      }
    }
    else {
      if (0x200 < uVar8) {
        if (uVar8 == 0x1000) {
          if ((uVar5 & 0x10000) == 0) {
            return 1;
          }
          param_3[1] = 0;
          return 1;
        }
        if (uVar8 < 0x1001) {
          if ((uVar8 != 0x400) && (uVar8 != 0x800)) {
            return 1;
          }
          if ((uVar5 & 0x20) == 0) {
            return 1;
          }
          param_3[1] = 0;
          return 1;
        }
        if (uVar8 == 0x2000) {
          if ((uVar5 & 0x20008) != 0x20008) {
            return 1;
          }
          param_3[1] = 0;
          return 1;
        }
        if (uVar8 != 0x100000) {
          return 1;
        }
        if ((uVar5 & 0x40) != 0) {
          param_3[1] = 0;
          return 1;
        }
        return 1;
      }
      if (uVar8 == 0x40) goto code_r0x2d073548;
      if (0x40 < uVar8) {
        if ((uVar8 != 0x80) && (uVar8 != 0x100)) {
          return 1;
        }
        goto code_r0x2d073548;
      }
      if (uVar8 == 0x10) {
        if ((uVar5 & 1) == 0) {
          return 1;
        }
      }
      else {
        if (uVar8 != 0x20) {
          return 1;
        }
        if ((uVar5 & 2) == 0) {
          return 1;
        }
      }
      if ((uVar5 & 0x40200) != 0x40200) {
        return 1;
      }
    }
    if ((uVar5 & 0x280000) == 0x280000) {
      param_3[1] = 0;
      return 1;
    }
code_r0x2d072e68:
    return 1;
  case 0x22:
    if (*(char *)(g_AudioVars2 + 0x1ed) == '\0') {
      *(undefined1 *)param_3 = 0;
      return 1;
    }
code_r0x2d072f70:
    *(undefined1 *)param_3 = 1;
    uVar9 = 1;
    break;
  case 0x2f:
    if (uVar5 == 0) {
      cVar1 = *(char *)(g_AudioVars2 + 0x14);
code_r0x2d073184:
      if ((cVar1 == '\r') || (cVar1 == '\x13')) {
        uVar4 = HAL_DEC_R2_Get_SHM_INFO(0x3c,uVar5);
        if (uVar4 == 3) {
code_r0x2d0733f8:
          *param_3 = 1;
          return 1;
        }
        if (uVar4 < 4) {
          if (uVar4 != 0) goto code_r0x2d073014;
        }
        else if (uVar4 == 4) {
          *param_3 = 2;
          return 1;
        }
        goto code_r0x2d0733dc;
      }
    }
    else if (uVar5 == 1) {
      cVar1 = *(char *)(g_AudioVars2 + 0x15);
      goto code_r0x2d073184;
    }
    printf("[[utopia]]      %s: invalid ID (%d, %d)\n","HAL_MAD_GetAudioInfo2",param_1,uVar5);
    uVar9 = 0;
  }
  return uVar9;
}

