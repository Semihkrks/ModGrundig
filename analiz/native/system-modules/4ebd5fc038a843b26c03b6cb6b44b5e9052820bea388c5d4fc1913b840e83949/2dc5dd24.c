
/* drvTAS5753_SetVolumeSlewRate(enumTAS5753_VOLSLEWRATE) */

void drvTAS5753_SetVolumeSlewRate(undefined1 param_1)

{
  (*(code *)PTR_drvTAS5753_WriteBitsInRegister_OneByte_2dd0f090)(0xe,param_1);
  return;
}

