
int usb_ehci_mstar_probe(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  uint *puVar10;
  char *pcVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  undefined4 local_20 [3];
  
  pcVar11 = (char *)*param_3;
  pcVar14 = "Mstar-ehci-1";
  local_20[0] = 0;
  cVar2 = *pcVar11;
  pcVar7 = pcVar14;
  pcVar8 = pcVar11;
  do {
    cVar3 = *pcVar7;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    cVar4 = cVar2;
    if (cVar3 != cVar2) break;
    bVar1 = cVar2 != '\0';
    cVar2 = *pcVar8;
    cVar4 = cVar3;
  } while (bVar1);
  if (cVar4 == cVar3) {
    (*(code *)&printk)("Mstar-ehci-1 H.W init\n");
    DPDM_swap_setting_ehc(local_20,1);
    Titania3_series_start_ehc(0xbf207500,0xbf200e00,0xbf204800,local_20[0]);
  }
  else {
    pcVar7 = "Mstar-ehci-2";
    cVar2 = *pcVar11;
    do {
      cVar3 = *pcVar7;
      pcVar11 = pcVar11 + 1;
      pcVar7 = pcVar7 + 1;
      cVar4 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar11;
      cVar4 = cVar3;
    } while (bVar1);
    if (cVar4 == cVar3) {
      (*(code *)&printk)("Mstar-ehci-2 H.W init\n");
      DPDM_swap_setting_ehc(local_20,2);
      Titania3_series_start_ehc(0xbf207400,0xbf200f00,0xbf201a00,local_20[0]);
    }
  }
  iVar5 = (*(code *)&usb_create_hcd)(param_1,param_3 + 2,"mstar");
  iVar13 = -0xc;
  if (iVar5 != 0) {
    iVar13 = -0xc;
    uVar12 = *(uint *)(param_3[0x33] + 0x1c);
    *(undefined4 *)(iVar5 + 0xa4) = 0;
    *(uint *)(iVar5 + 0xa0) = uVar12;
    iVar9 = *(int *)(param_3[0x33] + 0x1c);
    iVar6 = *(int *)(param_3[0x33] + 0x20);
    *(undefined4 *)(iVar5 + 0xac) = 0;
    *(uint *)(iVar5 + 0x98) = uVar12;
    *(int *)(iVar5 + 0xa8) = iVar6 - iVar9;
    if (uVar12 != 0) {
      *(uint *)(iVar5 + 0x108) = uVar12;
      puVar10 = (uint *)((uVar12 + 4 & 0xff) * 2 + (uVar12 + 4 & 0xffffff00));
      *(uint *)(iVar5 + 0x10c) =
           *(int *)(iVar5 + 0x98) + (*(uint *)((uVar12 & 0xff) * 2 + (uVar12 & 0xffffff00)) & 0xff);
      *(uint *)(iVar5 + 0x114) = puVar10[1] << 0x10 | *puVar10 & 0xffff;
      pcVar8 = (char *)*param_3;
      cVar2 = *pcVar8;
      pcVar7 = pcVar8;
      do {
        cVar3 = *pcVar14;
        pcVar7 = pcVar7 + 1;
        pcVar14 = pcVar14 + 1;
        cVar4 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar7;
        cVar4 = cVar3;
      } while (bVar1);
      if (cVar4 == cVar3) {
        *(undefined1 *)(iVar5 + 0xd4) = 1;
        *(undefined4 *)(iVar5 + 0xd8) = 0xbf207500;
        *(undefined4 *)(iVar5 + 0xdc) = 0xbf204800;
        *(undefined4 *)(iVar5 + 0xe0) = 0xbf200e00;
        *(undefined4 *)(iVar5 + 0xe4) = 0xbf246c00;
      }
      else {
        pcVar7 = "Mstar-ehci-2";
        cVar2 = *pcVar8;
        do {
          cVar3 = *pcVar7;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
          cVar4 = cVar2;
          if (cVar3 != cVar2) break;
          bVar1 = cVar2 != '\0';
          cVar2 = *pcVar8;
          cVar4 = cVar3;
        } while (bVar1);
        if (cVar4 == cVar3) {
          *(undefined1 *)(iVar5 + 0xd4) = 2;
          *(undefined4 *)(iVar5 + 0xd8) = 0xbf207400;
          *(undefined4 *)(iVar5 + 0xdc) = 0xbf201a00;
          *(undefined4 *)(iVar5 + 0xe0) = 0xbf200f00;
          *(undefined4 *)(iVar5 + 0xe4) = 0xbf246c40;
        }
      }
      (*(code *)&usb_bc_enable)(iVar5,0);
      (*(code *)&usb_power_saving_enable)(iVar5,1);
      iVar13 = (*(code *)&usb_add_hcd)(iVar5,*(undefined4 *)(param_3[0x33] + 0x38),0x20);
      *(undefined4 *)(iVar5 + 0xf4) = 0;
      *(undefined1 *)(iVar5 + 0xf8) = 0;
      *(undefined1 *)(iVar5 + 0xf9) = 0;
      *(undefined1 *)(iVar5 + 0xfa) = 0;
      if (iVar13 == 0) {
        return 0;
      }
    }
    (*(code *)&usb_put_hcd)(iVar5);
  }
  return iVar13;
}

