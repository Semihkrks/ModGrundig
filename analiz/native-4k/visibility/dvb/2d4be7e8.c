
/* MSrv_ChannelManager_DVB::_GetProgramInfoByIndex(ST_CM_PROGRAM_INFO*, unsigned char) */

undefined4 __thiscall
MSrv_ChannelManager_DVB::_GetProgramInfoByIndex
          (MSrv_ChannelManager_DVB *this,ST_CM_PROGRAM_INFO *param_1,uchar param_2)

{
  MSrv_ChannelManager_DVB MVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  uint uVar7;
  char cVar8;
  code *pcVar9;
  undefined1 auStack_88 [4];
  uint local_84;
  int local_80;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined2 local_78;
  undefined2 local_76;
  undefined2 local_74;
  undefined2 local_64 [12];
  undefined4 local_4c;
  undefined4 local_48;
  
  if (param_1 == (ST_CM_PROGRAM_INFO *)0x0) {
    return 0;
  }
  cVar8 = this[0xdd] == (MSrv_ChannelManager_DVB)0x1;
  if (this[0xde] == (MSrv_ChannelManager_DVB)0x1) {
    cVar8 = cVar8 + '\x01';
    bVar6 = false;
    if (*(uint *)(this + 0x6c) <= *(uint *)param_1) {
      MVar1 = this[0xdc];
      goto joined_r0x2d4be9bc;
    }
  }
  MVar1 = this[0xdc];
  bVar6 = true;
joined_r0x2d4be9bc:
  if (MVar1 == (MSrv_ChannelManager_DVB)0x1) {
    cVar8 = cVar8 + '\x01';
    bVar6 = false;
  }
  if (cVar8 == '\x01') {
    if (bVar6) {
      local_4c = 0x2c828ac4;
      local_64[0] = (undefined2)*(undefined4 *)param_1;
      local_48 = local_4c;
                    /* try { // try from 2d4be9f4 to 2d4bea37 has its CatchHandler @ 2d4bea8c */
      piVar3 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
      iVar4 = (**(code **)(*piVar3 + 0x2fc))(piVar3,*(undefined4 *)param_1,local_64,param_2);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_2d4bcaa0(local_64,param_1);
      }
      (*(code *)0x2d4be3c0)(local_64);
      return uVar5;
    }
    piVar3 = (int *)(**(code **)(*(int *)this + 0x10c))(this);
    iVar4 = (**(code **)(*piVar3 + 0x924))(piVar3);
    if (iVar4 != 3) {
      if (this[0xde] == (MSrv_ChannelManager_DVB)0x1) {
        piVar3 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
        pcVar9 = *(code **)(*piVar3 + 0x44);
        uVar7 = *(int *)param_1 - *(int *)(this + 0x6c) & 0xffff;
      }
      else {
        piVar3 = (int *)MSrv_Control_TV::GetMSrvAtvDatabase();
        uVar7 = (uint)*(ushort *)param_1;
        pcVar9 = *(code **)(*piVar3 + 0x44);
      }
      uVar2 = (*pcVar9)(piVar3,4,uVar7,0,0);
      piVar3 = (int *)MSrv_Control_TV::GetMSrvAtv();
      iVar4 = (**(code **)(*piVar3 + 0x110))(piVar3,auStack_88,uVar2);
      if (iVar4 != 0) {
        param_1[0xc] = SUB41((uint)(local_80 << 0x13) >> 0x18,0);
        *(uint *)(param_1 + 4) = local_84 & 0xff;
        param_1[0xd] = SUB41((uint)(local_80 << 0x11) >> 0x1f,0);
        param_1[0xe] = SUB41((local_84 << 0xb) >> 0x1f,0);
        param_1[0x12] = SUB41((local_84 << 10) >> 0x1f,0);
        param_1[0x11] = (ST_CM_PROGRAM_INFO)0x1;
        param_1[0xf] = (ST_CM_PROGRAM_INFO)0x0;
        param_1[0x10] = (ST_CM_PROGRAM_INFO)0x0;
        param_1[0x13] = (ST_CM_PROGRAM_INFO)0x0;
        std::string::assign((char *)(param_1 + 0x18));
        *(undefined2 *)(param_1 + 0x2a) = local_7a;
        *(undefined2 *)(param_1 + 0x28) = local_7c;
        *(undefined2 *)(param_1 + 0x30) = local_74;
        *(undefined2 *)(param_1 + 0x2c) = local_78;
        *(undefined2 *)(param_1 + 0x2e) = local_76;
        return 1;
      }
    }
  }
  return 0;
}

