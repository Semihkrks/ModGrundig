
void usb_stor_pad12_command(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  code *pcVar8;
  byte *pbVar9;
  uint *puVar10;
  int unaff_gp;
  byte bStack_88;
  char cStack_87;
  char cStack_86;
  char cStack_85;
  undefined1 auStack_80 [80];
  int iStack_30;
  
  uVar6 = *(ushort *)(param_1 + 0x2a);
  while (uVar6 < 0xc) {
    *(undefined1 *)(*(int *)(param_1 + 0x30) + (uint)uVar6) = 0;
    uVar6 = *(short *)(param_1 + 0x2a) + 1;
    *(ushort *)(param_1 + 0x2a) = uVar6;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  puVar10 = (uint *)(param_2 + 0x1c);
  iStack_30 = (**(code **)(param_2 + 0x48))();
  if ((*(uint *)(param_2 + 0x1c) & 0x20) == 0) {
    if (iStack_30 == 3) {
      *(undefined4 *)(param_1 + 0x8c) = 0x70000;
    }
    else {
      if (iStack_30 == 2) {
        *(undefined4 *)(param_1 + 0x8c) = 2;
        goto LAB_00011b64;
      }
      *(undefined4 *)(param_1 + 0x8c) = 0;
      if ((*(char *)(param_2 + 0x41) == '\x01') ||
         (bVar3 = false, *(char *)(param_2 + 0x41) == -0x10)) {
        bVar3 = *(int *)(param_1 + 0x2c) != 2;
      }
      cVar1 = **(char **)(param_1 + 0x30);
      if (iStack_30 == 1) {
        bVar3 = true;
      }
      if (((cVar1 == -0x7b) || (cVar1 == -0x5f)) && (iStack_30 == 0)) {
        uVar7 = *(uint *)(param_2 + 0x18);
        if (((uVar7 & 0x28000) == 0) && (((*(char **)(param_1 + 0x30))[2] & 0x20U) == 0)) {
          uVar7 = uVar7 | 0x8000;
          *(uint *)(param_2 + 0x18) = uVar7;
        }
      }
      else {
        uVar7 = *(uint *)(param_2 + 0x18);
      }
      if (!bVar3) {
LAB_00011e38:
        if (((int)(uVar7 << 0xb) < 0) && (**(char **)(param_1 + 0x30) == '(')) {
          if (*(int *)(param_1 + 0x8c) == 0) {
            *puVar10 = *puVar10 & 0xfffffeff | 0x100;
          }
          else if ((*(uint *)(param_2 + 0x1c) & 0x100) != 0) {
            *puVar10 = *puVar10 & 0xfffffeff;
            *puVar10 = *puVar10 & 0xffffff7f | 0x80;
          }
          if ((*(uint *)(param_2 + 0x1c) & 0x80) != 0) {
            *puVar10 = *puVar10 & 0xffffff7f;
            *(undefined4 *)(param_1 + 0x8c) = 0xc0000;
            **(undefined1 **)(param_1 + 0x58) = 0;
          }
        }
        if (((*(int *)(param_1 + 0x8c) == 0) || (*(char *)(*(int *)(param_1 + 0x58) + 2) == '\0'))
           && ((uint)(*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x44)) <
               *(uint *)(param_1 + 0x4c))) {
          *(undefined4 *)(param_1 + 0x8c) = 0x70000;
        }
        goto LAB_00011b64;
      }
      if ((uVar7 & 0x8000) == 0) {
        iVar4 = 0x12;
      }
      else {
        iVar4 = -1;
      }
      while( true ) {
        (*(code *)&scsi_eh_prep_cmnd)(param_1,auStack_80,0,0,iVar4);
        cVar1 = *(char *)(param_2 + 0x40);
        if (((cVar1 == '\x01') || (cVar1 == '\x06')) || (cVar1 == -0xf)) {
          *(undefined2 *)(param_1 + 0x2a) = 6;
        }
        else {
          *(undefined2 *)(param_1 + 0x2a) = 0xc;
        }
        *(undefined4 *)(param_1 + 0x44) = 0;
        iVar5 = (**(code **)(param_2 + 0x48))(*(undefined4 *)(param_2 + 0x54),param_2);
        (*(code *)&scsi_eh_restore_cmnd)(param_1,auStack_80);
        if ((*puVar10 & 0x20) != 0) {
          *(undefined4 *)(param_1 + 0x8c) = 0x50000;
          if (iVar4 != 0x12) {
            *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xffff7fff | 0x20000;
          }
          goto LAB_00011a78;
        }
        if (iVar5 != 1) break;
        if (iVar4 == 0x12) goto LAB_00011f3c;
        iVar4 = 0x12;
        *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xffff7fff | 0x20000;
      }
      if (iVar5 == 0) {
        pbVar9 = *(byte **)(param_1 + 0x58);
        if (10 < pbVar9[7]) {
          uVar7 = *(uint *)(param_2 + 0x18);
          if ((((uVar7 & 0x8000) == 0) && (-1 < (int)(uVar7 << 0xe))) && ((*pbVar9 & 0x7c) == 0x70))
          {
            *(uint *)(param_2 + 0x18) = uVar7 | 0x8000;
            *(undefined1 *)(*(int *)(param_1 + 0x58) + 7) = 10;
            pbVar9 = *(byte **)(param_1 + 0x58);
          }
        }
        (*(code *)&scsi_normalize_sense)(pbVar9,0x60,&bStack_88);
        *(undefined4 *)(param_1 + 0x8c) = 2;
        iVar4 = (*(code *)&scsi_sense_desc_find)(*(undefined4 *)(param_1 + 0x58),0x60,4);
        if (iVar4 == 0) {
          bVar2 = *(byte *)(*(int *)(param_1 + 0x58) + 2);
        }
        else {
          bVar2 = *(byte *)(iVar4 + 3);
        }
        if (((cStack_87 == '\0') && (cStack_86 == '\0')) &&
           ((bVar2 & 0xa0) == 0 && cStack_85 == '\0')) {
          if (iStack_30 == 0) {
            *(undefined4 *)(param_1 + 0x8c) = 0;
            **(undefined1 **)(param_1 + 0x58) = 0;
            uVar7 = *(uint *)(param_2 + 0x18);
            goto LAB_00011e38;
          }
          *(undefined4 *)(param_1 + 0x8c) = 0x70000;
          if ((bStack_88 & 0x72) == 0x72) {
            *(undefined1 *)(*(int *)(param_1 + 0x58) + 1) = 4;
            uVar7 = *(uint *)(param_2 + 0x18);
            goto LAB_00011e38;
          }
          *(undefined1 *)(*(int *)(param_1 + 0x58) + 2) = 4;
        }
        uVar7 = *(uint *)(param_2 + 0x18);
        goto LAB_00011e38;
      }
LAB_00011f3c:
      *(undefined4 *)(param_1 + 0x8c) = 0x70000;
      if ((*(uint *)(param_2 + 0x18) & 4) != 0) {
        return;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x8c) = 0x50000;
    if (**(char **)(param_1 + 0x30) == '\x12') {
      *(undefined4 *)(*(int *)(param_2 + 0xc) + 8) = 1;
    }
  }
LAB_00011a78:
  Status = Status & 0xfffffffe;
  (*(code *)&trace_hardirqs_off)();
  (*(code *)&add_preempt_count)(1);
  *puVar10 = *puVar10 & 0xffffffef | 0x10;
  *puVar10 = *puVar10 & 0xfffffffb;
  (*(code *)&trace_hardirqs_on)();
  Status = Status | 1;
  (*(code *)&sub_preempt_count)(1);
  if ((*(uint *)(unaff_gp + 8) & 4) == 0) {
    iVar4 = *(int *)(param_2 + 0xc);
  }
  else {
    (*(code *)&preempt_schedule)();
    iVar4 = *(int *)(param_2 + 0xc);
  }
  if ((*(int *)(iVar4 + 8) == 1) &&
     ((**(char **)(param_1 + 0x30) == '\0' || (**(char **)(param_1 + 0x30) == '\x12')))) {
    (*(code *)&printk)("Retry for bad device\n");
  }
  else {
    (*(code *)&mutex_unlock)(param_2);
    iVar4 = usb_stor_port_reset(param_2);
    (*(code *)&mutex_lock)(param_2);
    if (iVar4 < 0) {
      Status = Status & 0xfffffffe;
      (*(code *)&trace_hardirqs_off)();
      (*(code *)&add_preempt_count)(1);
      usb_stor_report_device_reset(param_2);
      (*(code *)&trace_hardirqs_on)();
      Status = Status | 1;
      (*(code *)&sub_preempt_count)(1);
      if ((*(uint *)(unaff_gp + 8) & 4) == 0) {
        pcVar8 = *(code **)(param_2 + 0x4c);
      }
      else {
        (*(code *)&preempt_schedule)();
        pcVar8 = *(code **)(param_2 + 0x4c);
      }
      (*pcVar8)(param_2);
    }
  }
  *puVar10 = *puVar10 & 0xffffffef;
LAB_00011b64:
  last_sector_hacks(param_2,param_1);
  return;
}

