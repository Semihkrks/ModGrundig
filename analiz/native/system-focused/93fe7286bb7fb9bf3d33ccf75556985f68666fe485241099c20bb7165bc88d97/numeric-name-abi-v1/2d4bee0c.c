
/* WARNING: Removing unreachable block (ram,0x2d4beff4) */
/* MSrv_ChannelManager_DVB::GetProgramInfo(MS_CM_GET_SERVICE_INFO*) */

undefined4 __thiscall
MSrv_ChannelManager_DVB::GetProgramInfo
          (MSrv_ChannelManager_DVB *this,MS_CM_GET_SERVICE_INFO *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  MS_CM_GET_SERVICE_INFO local_40;
  MS_CM_GET_SERVICE_INFO local_3f;
  MS_CM_GET_SERVICE_INFO local_3e;
  MS_CM_GET_SERVICE_INFO local_3d;
  MS_CM_GET_SERVICE_INFO local_3c;
  MS_CM_GET_SERVICE_INFO local_3b;
  MS_CM_GET_SERVICE_INFO local_3a;
  MS_CM_GET_SERVICE_INFO local_39;
  int local_34 [4];
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  local_4c = *(undefined4 *)param_1;
  local_40 = param_1[0x10];
  local_48 = *(undefined4 *)(param_1 + 4);
  local_3f = param_1[0x11];
  local_3e = param_1[0x12];
  local_3d = param_1[0x13];
  local_3c = param_1[0x14];
  local_3b = param_1[0x15];
  local_3a = param_1[0x16];
  local_39 = param_1[0x17];
  local_44 = *(undefined4 *)(param_1 + 0xc);
  local_34[0] = 0x2c828ac4;
                    /* try { // try from 2d4beeb4 to 2d4bef43 has its CatchHandler @ 2d4bf004 */
  std::string::assign((string *)local_34);
  uVar1 = (**(code **)(*(int *)this + 0x3c))(this,3,&local_4c);
  *(undefined4 *)(param_1 + 4) = local_48;
  *(undefined4 *)(param_1 + 0xc) = local_44;
  *(undefined4 *)param_1 = local_4c;
  param_1[0x10] = local_40;
  param_1[0x11] = local_3f;
  param_1[0x12] = local_3e;
  param_1[0x13] = local_3d;
  param_1[0x14] = local_3c;
  param_1[0x15] = local_3b;
  param_1[0x16] = local_3a;
  param_1[0x17] = local_39;
  std::string::assign((string *)(param_1 + 0x1c));
  *(undefined2 *)(param_1 + 0x20) = local_24;
  *(undefined2 *)(param_1 + 0x2a) = local_1a;
  *(undefined2 *)(param_1 + 0x22) = local_22;
  *(undefined2 *)(param_1 + 0x24) = local_20;
  *(undefined2 *)(param_1 + 0x26) = local_1e;
  *(undefined2 *)(param_1 + 0x28) = local_1c;
  if ((allocator *)(local_34[0] + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_34[0] + -4);
    *(int *)(local_34[0] + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_34[0] + -0xc));
    }
  }
  return uVar1;
}

