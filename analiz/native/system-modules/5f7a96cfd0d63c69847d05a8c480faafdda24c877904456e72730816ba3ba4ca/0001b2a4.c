
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = (*(code *)&platform_driver_register)(second_ehci_hcd_mstar_driver);
  if (-1 < iVar2) {
    iVar3 = (*(code *)&usb_disabled)();
    iVar2 = -0x13;
    if (iVar3 == 0) {
      (*(code *)&printk)("<6>%s: USB 2.0 \'Enhanced\' Host Controller (EHCI) Driver\n",hcd_name);
      uVar4 = _usb_hcds_loaded & 0xfffffffb | 4;
      if (((_usb_hcds_loaded & 1) != 0) ||
         (uVar1 = _usb_hcds_loaded & 2, _usb_hcds_loaded = uVar4, uVar1 != 0)) {
        _usb_hcds_loaded = uVar4;
        (*(code *)&printk)(
                          "<4>Warning! ehci_hcd should always be loaded before uhci_hcd and ohci_hcd, not after\n"
                          );
      }
      iVar2 = (*(code *)&platform_driver_register)(ehci_hcd_mstar_driver);
      if (iVar2 < 0) {
        _usb_hcds_loaded = _usb_hcds_loaded & 0xfffffffb;
      }
    }
  }
  return iVar2;
}

