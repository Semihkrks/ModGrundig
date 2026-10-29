
/* MW_DVB_SI_PSI_Parser_Customer::_ParserPMT(unsigned char*) */

void __thiscall
MW_DVB_SI_PSI_Parser_Customer::_ParserPMT(MW_DVB_SI_PSI_Parser_Customer *this,uchar *param_1)

{
  byte bVar1;
  byte bVar2;
  uchar uVar3;
  uchar uVar4;
  MW_DVB_SI_PSI_Parser_Customer MVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  ushort uVar15;
  
  bVar1 = param_1[1];
  bVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  pbVar13 = param_1 + ((param_1[10] & 0xf) << 8 | (uint)param_1[0xb]) + 0xc;
  while( true ) {
    if (param_1 + (((bVar1 & 0xf) << 8 | (uint)bVar2) - 1) <= pbVar13) {
      return;
    }
    bVar6 = *pbVar13;
    uVar14 = (pbVar13[3] & 0xf) << 8 | (uint)pbVar13[4];
    if ((9 < bVar6) &&
       (((bVar6 < 0xf || (bVar6 == 0x80)) &&
        (uVar15 = (pbVar13[1] & 0x1f) << 8 | (ushort)pbVar13[2], uVar14 != 0)))) break;
LAB_2e1922c0:
    pbVar13 = pbVar13 + uVar14 + 5;
  }
  pbVar11 = pbVar13 + 5;
  bVar6 = *pbVar11;
  uVar12 = 0;
  if (bVar6 == 0x52) goto LAB_2e192358;
  do {
    if (bVar6 == 0x66) {
      uVar10 = (uint)pbVar11[1];
      if (uVar10 < 3) goto LAB_2e192334;
      if (CONCAT11(pbVar11[2],pbVar11[3]) != 10) goto LAB_2e192334;
      if (pbVar11[5] != 0) goto LAB_2e192334;
      if (pbVar11[6] == 0x11) {
        iVar8 = uVar10 + 2;
        if (pbVar11[7] != 0xe1) {
          uVar7 = iVar8 + uVar12;
          goto LAB_2e19233c;
        }
      }
      else {
        iVar8 = uVar10 + 2;
        if (pbVar11[6] != 1) goto LAB_2e192338;
        uVar7 = iVar8 + uVar12;
        if (pbVar11[7] != 0x5a) goto LAB_2e19233c;
      }
      piVar9 = *(int **)(this + 4);
      if (piVar9 == (int *)0x0) goto LAB_2e192334;
      if (*(int *)(this + 0x1d8) != 3) goto LAB_2e192334;
      (**(code **)(*piVar9 + 0x20))(piVar9,uVar15,10,pbVar11 + 4,0x66,CONCAT11(uVar3,uVar4));
      uVar10 = (uint)pbVar11[1];
      goto LAB_2e192334;
    }
LAB_2e192330:
    while( true ) {
      uVar10 = (uint)pbVar11[1];
LAB_2e192334:
      iVar8 = uVar10 + 2;
LAB_2e192338:
      uVar7 = iVar8 + uVar12;
LAB_2e19233c:
      uVar12 = uVar7 & 0xffff;
      pbVar11 = pbVar11 + iVar8;
      if (uVar14 <= uVar12) goto LAB_2e1922c0;
      bVar6 = *pbVar11;
      if (bVar6 != 0x52) break;
LAB_2e192358:
      piVar9 = *(int **)(this + 4);
      if (piVar9 == (int *)0x0) goto LAB_2e19249c;
      iVar8 = *(int *)(this + 0x1d8);
      if (iVar8 == 3) {
        (**(code **)(*piVar9 + 0x20))(piVar9,uVar15,10,pbVar11 + 2,0x52,CONCAT11(uVar3,uVar4));
        iVar8 = *(int *)(this + 0x1d8);
      }
      if (iVar8 == 8) {
        MVar5 = this[0xd3884];
        goto LAB_2e19237c;
      }
    }
  } while( true );
LAB_2e19249c:
  if (*(int *)(this + 0x1d8) == 8) {
    MVar5 = this[0xd3884];
LAB_2e19237c:
    if (MVar5 == (MW_DVB_SI_PSI_Parser_Customer)0x1) {
      *(ushort *)(this + 0xd388c) = uVar15;
    }
  }
  goto LAB_2e192330;
}

