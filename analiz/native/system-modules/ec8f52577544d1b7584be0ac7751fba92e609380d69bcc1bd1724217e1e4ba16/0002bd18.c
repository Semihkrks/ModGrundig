
undefined4 XmlInitEncodingNS(undefined4 *param_1,undefined4 *param_2,char *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  
  if (param_3 == (char *)0x0) {
    *(undefined1 *)((int)param_1 + 0x49) = 6;
    puVar1 = PTR_LAB_0004b7e8;
    *param_2 = param_1;
    *param_1 = puVar1 + -0x43e0;
    puVar2 = PTR_LAB_0004b7e8;
    param_1[1] = puVar1 + -0x4388;
    param_1[0xd] = puVar2 + -0x40c0;
    param_1[0x13] = param_2;
    return 1;
  }
  iVar8 = 0;
  puVar7 = (undefined4 *)(PTR_DAT_0004b7d8 + -0x5b18);
  do {
    pcVar6 = (char *)*puVar7;
    pcVar5 = param_3;
    while( true ) {
      cVar3 = *pcVar5;
      cVar4 = *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
      if ((byte)(cVar3 + 0x9fU) < 0x1a) {
        cVar3 = cVar3 + -0x20;
      }
      if ((byte)(cVar4 + 0x9fU) < 0x1a) {
        cVar4 = cVar4 + -0x20;
      }
      if (cVar3 != cVar4) break;
      if (cVar3 == '\0') {
        *(char *)((int)param_1 + 0x49) = (char)iVar8;
        puVar1 = PTR_LAB_0004b7e8;
        *param_2 = param_1;
        *param_1 = puVar1 + -0x43e0;
        puVar2 = PTR_LAB_0004b7e8;
        param_1[1] = puVar1 + -0x4388;
        param_1[0xd] = puVar2 + -0x40c0;
        param_1[0x13] = param_2;
        return 1;
      }
    }
    iVar8 = iVar8 + 1;
    puVar7 = puVar7 + 1;
    if (iVar8 == 6) {
      return 0;
    }
  } while( true );
}

