
/* MWidget::CalculateTextDrawFlags(_Rect*, EN_WDG_ALIGN, unsigned long, long&, long&,
   DFBSurfaceTextFlags&) */

void __thiscall
MWidget::CalculateTextDrawFlags
          (MWidget *this,int *param_1,undefined4 param_3,int param_4,int *param_5,int *param_6,
          uint *param_7)

{
  MSystem *pMVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    puts("MWidget::CalculateTextDrawFlags, NULL widget rect");
    return;
  }
  switch(param_3) {
  default:
    *param_5 = param_1[2] / 2 + *param_1;
    iVar2 = param_1[3];
    iVar3 = param_1[1];
    *param_7 = 5;
    goto code_r0x2e24fec0;
  case 1:
  case 0x21:
    pMVar1 = (MSystem *)MSystem::GetInstance();
    iVar2 = MSystem::GetRightToLeftLang(pMVar1);
    if (iVar2 == 0) goto code_r0x2e25006c;
code_r0x2e2500ac:
    iVar2 = *param_1;
    iVar3 = param_1[2];
    *param_7 = 6;
    *param_5 = iVar3 + iVar2;
    iVar2 = param_1[3];
    iVar3 = param_1[1];
    goto code_r0x2e24fec0;
  case 4:
  case 0x24:
    pMVar1 = (MSystem *)MSystem::GetInstance();
    iVar2 = MSystem::GetRightToLeftLang(pMVar1);
    if (iVar2 == 0) goto code_r0x2e2500ac;
code_r0x2e25006c:
    iVar2 = *param_1;
    *param_7 = 4;
    *param_5 = iVar2;
    iVar2 = param_1[3];
    iVar3 = param_1[1];
code_r0x2e24fec0:
    *param_6 = (iVar2 - param_4) / 2 + iVar3;
    break;
  case 0x10:
  case 0x12:
    *param_5 = param_1[2] / 2 + *param_1;
    iVar2 = param_1[1];
    *param_7 = 5;
    *param_6 = iVar2;
    break;
  case 0x11:
    iVar2 = *param_1;
    *param_7 = 4;
    *param_5 = iVar2;
    *param_6 = param_1[1];
    break;
  case 0x14:
    iVar2 = param_1[2];
    iVar3 = *param_1;
    *param_7 = 6;
    *param_5 = iVar2 + iVar3;
    *param_6 = param_1[1];
    break;
  case 0x40:
  case 0x42:
    iVar3 = param_1[1];
    iVar2 = param_1[3];
    *param_7 = 9;
    *param_6 = iVar2 + iVar3;
    *param_5 = param_1[2] / 2 + *param_1;
    break;
  case 0x41:
    iVar2 = *param_1;
    *param_7 = 8;
    *param_5 = iVar2;
    *param_6 = param_1[3] + param_1[1];
    break;
  case 0x44:
    iVar3 = *param_1;
    iVar2 = param_1[2];
    *param_7 = 10;
    *param_5 = iVar2 + iVar3;
    *param_6 = param_1[3] + param_1[1];
  }
  iVar2 = QueryVisualState(this);
  if (*(short *)(this + iVar2 * 0xc + 0x138) != 5) {
    *param_7 = *param_7 | 0x20;
  }
  return;
}

