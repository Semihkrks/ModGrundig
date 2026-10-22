
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* InitDebugLevels() */

void InitDebugLevels(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar1 = (*(code *)PTR_iniparser_load_2f7b6870)(PTR___DT_MIPS_BASE_ADDRESS_2f7b6824 + 0x5a48);
  if (iVar1 == 0) {
    return;
  }
  iVar7 = 0;
  piVar8 = (int *)PTR_LogTypesStr_2f7b68d4;
LAB_2f7a1e08:
  do {
    if (*piVar8 == 0) break;
    iVar2 = (*(code *)PTR_iniparser_getstring_2f7b68e4)(iVar1,*piVar8,0);
    if (iVar2 != 0) {
      iVar6 = 0;
      puVar5 = (undefined4 *)PTR_LogLevelStr_2f7b6858;
      do {
        uVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        iVar3 = (*(code *)PTR_strcmp_2f7b6840)(iVar2,uVar4);
        if (iVar3 == 0) {
          iVar2 = iVar7 + 1;
          (*(code *)PTR_SetDebugLevel_2f7b688c)(iVar7,iVar6);
          piVar8 = piVar8 + 1;
          iVar7 = iVar2;
          if (iVar2 == 0xb) goto LAB_2f7a1e6c;
          goto LAB_2f7a1e08;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 6);
    }
    iVar7 = iVar7 + 1;
    piVar8 = piVar8 + 1;
  } while (iVar7 != 0xb);
LAB_2f7a1e6c:
                    /* WARNING: Could not recover jumptable at 0x2f7a1e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_iniparser_freedict_2f7b68a4)(iVar1);
  return;
}

