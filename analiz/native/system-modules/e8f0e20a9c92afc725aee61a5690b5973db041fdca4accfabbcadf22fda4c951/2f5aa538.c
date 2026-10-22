
void msVifAdcInitial(void)

{
  undefined *puVar1;
  int iVar2;
  byte *pbVar3;
  
  if (*(int *)(PTR_DAT_2f5bda48 + -0x25cc) != 0) {
    iVar2 = *(int *)(PTR_DAT_2f5bda48 + -0x25d0);
    *(byte *)(iVar2 + 0x3c71) = *(byte *)(iVar2 + 0x3c71) & 0xfc;
    *(undefined1 *)(iVar2 + 0x6628) = 4;
    *(undefined1 *)(iVar2 + 0x6629) = 0;
    *(undefined1 *)(iVar2 + 0x6634) = 4;
    *(undefined1 *)(iVar2 + 0x6635) = 0;
    *(undefined1 *)(iVar2 + 0x6640) = 4;
    *(undefined1 *)(iVar2 + 0x6641) = 0;
    *(undefined1 *)(iVar2 + 0x23e14) = 0;
    *(undefined1 *)(iVar2 + 0x23e15) = 0;
    *(undefined1 *)(iVar2 + 0x23e38) = 0;
    *(undefined1 *)(iVar2 + 0x23e39) = 0;
    *(undefined1 *)(iVar2 + 0x23fc4) = 1;
    *(undefined1 *)(iVar2 + 0x23fc5) = 0x10;
    *(undefined1 *)(iVar2 + 0x23ef0) = 0;
    *(undefined1 *)(iVar2 + 0x23ef1) = 0;
    *(undefined1 *)(iVar2 + 0x23e48) = 1;
    *(undefined1 *)(iVar2 + 0x23e49) = 8;
    *(undefined1 *)(iVar2 + 0x23e54) = 0;
    *(undefined1 *)(iVar2 + 0x23e55) = 0;
    *(undefined1 *)(iVar2 + 0xa5320) = 0;
    puVar1 = PTR_VIFInitialIn_inst_2f5bdbb0;
    *(undefined1 *)(iVar2 + 0xa5321) = 1;
    *(undefined1 *)(iVar2 + 0x24f80) = 0;
    *(undefined1 *)(iVar2 + 0x24f81) = 0;
    *(undefined1 *)(iVar2 + 0x24f84) = 0;
    *(undefined1 *)(iVar2 + 0x24f85) = 0;
    *(undefined1 *)(iVar2 + 0x24f88) = 0;
    *(undefined1 *)(iVar2 + 0x24f89) = 0;
    *(undefined1 *)(iVar2 + 0x24f8c) = 0;
    *(undefined1 *)(iVar2 + 0x24f8d) = 0;
    *(undefined1 *)(iVar2 + 0x24f90) = 0;
    *(undefined1 *)(iVar2 + 0x24f91) = 0;
    *(undefined1 *)(iVar2 + 0x24120) = 0xb8;
    *(undefined1 *)(iVar2 + 0x24121) = 0xbb;
    *(undefined1 *)(iVar2 + 0x24fc0) = 0x70;
    *(undefined1 *)(iVar2 + 0x24fc1) = 0;
    *(undefined1 *)(iVar2 + 0x24fc4) = 0;
    *(undefined1 *)(iVar2 + 0x24fc5) = 0;
    *(undefined1 *)(iVar2 + 0x24fc8) = 0;
    *(undefined1 *)(iVar2 + 0x24fc9) = 0;
    *(undefined1 *)(iVar2 + 0x24fcc) = 0;
    *(undefined1 *)(iVar2 + 0x24fcd) = 0;
    *(undefined1 *)(iVar2 + 0x24fd0) = 0;
    *(undefined1 *)(iVar2 + 0x24fd1) = 0;
    *(undefined1 *)(iVar2 + 0x24004) = 0x74;
    *(undefined1 *)(iVar2 + 0x24005) = 0;
    *(undefined1 *)(iVar2 + 0x24004) = 0x14;
    *(undefined1 *)(iVar2 + 0x24005) = 0;
    *(undefined1 *)(iVar2 + 0x24008) = 0x22;
    *(undefined1 *)(iVar2 + 0x24009) = 0;
    *(undefined1 *)(iVar2 + 0x240c0) = 4;
    *(undefined1 *)(iVar2 + 0x240c1) = 0;
    *(undefined1 *)(iVar2 + 0x240c8) = 0;
    *(undefined1 *)(iVar2 + 0x240c9) = 0;
    *(undefined1 *)(iVar2 + 0x240cc) = 0;
    *(undefined1 *)(iVar2 + 0x240cd) = 0;
    *(undefined1 *)(iVar2 + 0x24140) = 1;
    *(undefined1 *)(iVar2 + 0x2515c) = 0;
    *(undefined1 *)(iVar2 + 0x2515d) = 0;
    *(undefined1 *)(iVar2 + 0x25160) = 0;
    *(undefined1 *)(iVar2 + 0x25161) = 0;
    *(undefined1 *)(iVar2 + 0x25164) = 0x11;
    *(undefined1 *)(iVar2 + 0x25165) = 0;
    *(undefined1 *)(iVar2 + 0x250d4) = 0x83;
    *(undefined1 *)(iVar2 + 0x250d5) = 0;
    *(undefined1 *)(iVar2 + 0x250d4) = 3;
    *(undefined1 *)(iVar2 + 0x250d5) = 0;
    *(undefined1 *)(iVar2 + 0x250cc) = 1;
    *(undefined1 *)(iVar2 + 0x250cd) = 0x12;
    *(undefined1 *)(iVar2 + 0x250c0) = 0;
    *(undefined1 *)(iVar2 + 0x250c1) = 0x12;
    *(undefined1 *)(iVar2 + 0x25068) = 0x10;
    *(undefined1 *)(iVar2 + 0x25004) = 0x40;
    *(undefined1 *)(iVar2 + 0x25005) = 4;
    *(undefined1 *)(iVar2 + 0x25030) = 2;
    *(undefined1 *)(iVar2 + 0x25031) = 0;
    *(undefined1 *)(iVar2 + 0x25080) = 0;
    *(undefined1 *)(iVar2 + 0x25081) = 0;
    *(undefined1 *)(iVar2 + 0x2502c) = 5;
    *(undefined1 *)(iVar2 + 0x2502d) = 5;
    *(undefined1 *)(iVar2 + 0x2503c) = 0x80;
    *(undefined1 *)(iVar2 + 0x2503d) = 0;
    *(undefined1 *)(iVar2 + 0x25060) = 1;
    *(undefined1 *)(iVar2 + 0x25061) = 0;
    if (puVar1[3] == '\x05') {
      puVar1[3] = 3;
    }
    (*(code *)PTR_MAsm_CPU_DelayMs_2f5bdb60)(1);
    iVar2 = *(int *)(PTR_DAT_2f5bda48 + -0x25d0);
    pbVar3 = (byte *)(iVar2 + 0x250d8);
    *pbVar3 = *pbVar3 & 0xf3;
    *pbVar3 = *pbVar3 & 0x3f;
    *pbVar3 = *pbVar3 & 0xfd;
    *pbVar3 = *pbVar3 & 0xdf;
    if (((byte)(puVar1[3] - 2) < 2) || (puVar1[3] == '\x06')) {
      *pbVar3 = *pbVar3 & 0xfe;
    }
    else {
      *pbVar3 = *pbVar3 | 1;
    }
    puVar1 = PTR_msWriteBit_2f5bdab4;
    *pbVar3 = *pbVar3 | 0x10;
    (*(code *)puVar1)(0x12117,1,0x40);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12117,1,0x80);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12116,1,0x10);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,0x20);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12115,1,0x40);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12115,1,0x80);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12114,1,0x10);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,0x40);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,8);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,4);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,2);
    (*(code *)PTR_msWriteBit_2f5bdab4)(0x12119,0,1);
    puVar1 = PTR_msWriteBit_2f5bdab4;
    *(undefined1 *)(iVar2 + 0x251a4) = 1;
    *(undefined1 *)(iVar2 + 0x24009) = 1;
    *(undefined1 *)(iVar2 + 0x2400d) = 7;
    *(undefined1 *)(iVar2 + 0x251a4) = 0;
    *(undefined1 *)(iVar2 + 0x24009) = 0;
    *(undefined1 *)(iVar2 + 0x2400d) = 0;
    (*(code *)puVar1)(0x12396,1,1);
  }
  return;
}

