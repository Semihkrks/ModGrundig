
/* UsbDeviceManager::getUsbDeviceCount() const */

uint __thiscall UsbDeviceManager::getUsbDeviceCount(UsbDeviceManager *this)

{
  return (*(int *)(this + 4) - *(int *)this & 0x3ffU) >> 2;
}

