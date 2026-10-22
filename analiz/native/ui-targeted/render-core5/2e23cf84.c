
/* MResourceManager::RenderImageToSurface(unsigned long, _IDirectFBSurface*, DFBRectangle*) */

undefined4 __thiscall
MResourceManager::RenderImageToSurface
          (MResourceManager *this,ulong param_1,_IDirectFBSurface *param_2,DFBRectangle *param_3)

{
  int iVar1;
  int iVar2;
  uint local_48;
  _IDirectFBSurface *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (param_2 != (_IDirectFBSurface *)0x0) {
    local_44 = (_IDirectFBSurface *)0x0;
    iVar1 = FindCachedSurface(this,param_1,&local_44,&local_48);
    if ((iVar1 != 0) ||
       (iVar2 = DoRenderImageToSurface(this,param_1,&local_44,&local_48), iVar2 == 1)) {
      if (local_48 == 0xffffffff) {
        (**(code **)(param_2 + 0x5c))(param_2,5);
        (**(code **)(param_2 + 0x60))(param_2,6);
        (**(code **)(param_2 + 0x78))(param_2,1);
        (**(code **)(param_2 + 0x100))(param_2,1);
      }
      else {
        (**(code **)(local_44 + 0x68))
                  (local_44,(local_48 & 0xffffff) >> 0x10,(local_48 & 0xffff) >> 8,local_48 & 0xff);
        (**(code **)(param_2 + 0x78))(param_2,8);
      }
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      if (param_3 != (DFBRectangle *)0x0) {
        local_34 = *(int *)(param_3 + 0xc);
        local_40 = *(int *)param_3;
        local_3c = *(int *)(param_3 + 4);
        local_38 = *(int *)(param_3 + 8);
      }
      (**(code **)(local_44 + 0x18))(local_44,&local_28,&local_24);
      if (local_40 < 0) {
        local_30 = (-local_40 * local_28) / local_38;
        if (local_38 == 0) {
          trap(7);
        }
      }
      else {
        local_30 = 0;
      }
      if (local_3c < 0) {
        local_2c = (-local_3c * local_24) / local_34;
        if (local_34 == 0) {
          trap(7);
        }
      }
      else {
        local_2c = 0;
      }
      local_40 = 0;
      local_3c = 0;
      (**(code **)(param_2 + 0x88))(param_2,local_44,&local_30,&local_40);
      (**(code **)(param_2 + 0xd8))(param_2);
      if (iVar1 == 0) {
        UpdateImageCache(this,param_1,local_44,local_48);
      }
      return 1;
    }
  }
  return 0;
}

