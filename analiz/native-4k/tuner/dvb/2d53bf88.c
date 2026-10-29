
/* MW_DVB_SI_PSI_Parser::_UpdateVideo(MAPI_SI_VIDEO_INFO*, MAPI_SI_VIDEO_INFO*) */

void __thiscall
MW_DVB_SI_PSI_Parser::_UpdateVideo
          (MW_DVB_SI_PSI_Parser *this,MAPI_SI_VIDEO_INFO *param_1,MAPI_SI_VIDEO_INFO *param_2)

{
  MAPI_SI_VIDEO_INFO MVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  MAPI_SI_VIDEO_INFO MVar7;
  MAPI_SI_VIDEO_INFO MVar8;
  
  uVar4 = *(ushort *)(param_2 + 2);
  uVar6 = (uint)(byte)*param_2;
  MVar7 = param_2[6];
  *param_1 = (MAPI_SI_VIDEO_INFO)0x0;
  MVar8 = param_2[5];
  if (uVar4 == 0) {
    *(undefined2 *)(param_1 + 2) = 0x1fff;
    return;
  }
  if ((*(int *)(this + 0x168) == 0xc) || (cVar3 = '\0', *(int *)(this + 0x168) == 0x16)) {
    uVar2 = *(ushort *)(param_2 + 10);
    uVar5 = uVar4;
    if ((uVar2 < uVar4) && ((uVar2 != 0x1fff && (uVar2 != 0)))) {
      MVar7 = param_2[0xe];
      uVar6 = (uint)(byte)param_2[8];
      uVar5 = uVar2;
    }
    uVar4 = *(ushort *)(param_2 + 0x12);
    if (((uVar5 <= uVar4) || (uVar4 == 0x1fff)) || (uVar4 == 0)) {
      param_1[6] = MVar7;
      *(ushort *)(param_1 + 2) = uVar5;
      goto joined_r0x2d53c0ac;
    }
    uVar6 = (uint)(byte)param_2[0x10];
    MVar7 = param_2[0x16];
  }
  else {
    do {
      if (uVar6 == 0x1b) {
        if ((byte)MVar8 < (byte)param_2[5]) {
          MVar1 = *param_2;
          goto LAB_2d53bfcc;
        }
      }
      else {
        MVar1 = *param_2;
LAB_2d53bfcc:
        if ((MVar1 == (MAPI_SI_VIDEO_INFO)0x1b) && (*(ushort *)(param_2 + 2) != 0)) {
          MVar8 = param_2[5];
          MVar7 = param_2[6];
          uVar6 = 0x1b;
          uVar4 = *(ushort *)(param_2 + 2);
        }
      }
      cVar3 = cVar3 + '\x01';
      param_2 = param_2 + 8;
    } while (cVar3 != '\x03');
  }
  param_1[6] = MVar7;
  *(ushort *)(param_1 + 2) = uVar4;
joined_r0x2d53c0ac:
  if (uVar6 == 0x1b) {
    *param_1 = (MAPI_SI_VIDEO_INFO)0x2;
    return;
  }
  if (uVar6 < 0x1c) {
    if (uVar6 - 1 < 2) {
      *param_1 = (MAPI_SI_VIDEO_INFO)0x1;
      return;
    }
  }
  else {
    if (uVar6 == 0x42) {
      *param_1 = (MAPI_SI_VIDEO_INFO)0x3;
      return;
    }
    if (uVar6 == 0xea) {
      *param_1 = (MAPI_SI_VIDEO_INFO)0x4;
      return;
    }
    if (uVar6 == 0x24) {
      *param_1 = (MAPI_SI_VIDEO_INFO)0x5;
      return;
    }
  }
  return;
}

