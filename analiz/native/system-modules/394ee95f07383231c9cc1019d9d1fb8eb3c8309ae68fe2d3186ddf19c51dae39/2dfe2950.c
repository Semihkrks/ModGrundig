
/* UsbDevice::getDiskPartitionCount() const */

uint __thiscall UsbDevice::getDiskPartitionCount(UsbDevice *this)

{
  return (*(int *)(this + 0xc) - *(int *)(this + 8) & 0x3ffU) >> 2;
}

