
/* WARNING: Removing unreachable block (ram,0x2d4c0c88) */
/* WARNING: Removing unreachable block (ram,0x2d4c0c98) */
/* MSrv_ChannelManager_DVB::_GetProgramInfoByNumber(ST_CM_PROGRAM_INFO*) */

undefined4 __thiscall
MSrv_ChannelManager_DVB::_GetProgramInfoByNumber
          (MSrv_ChannelManager_DVB *this,ST_CM_PROGRAM_INFO *param_1)

{
  ST_CM_PROGRAM_INFO SVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_80 [4];
  uint local_7c;
  int local_78;
  undefined2 local_74;
  undefined2 local_72;
  undefined2 local_70;
  undefined2 local_6e;
  undefined2 local_6c;
  undefined1 auStack_5c [24];
  int local_44;
  int local_40;
  
  if (param_1 != (ST_CM_PROGRAM_INFO *)0x0) {
    SVar1 = param_1[0x13];
    if (((byte)((char)SVar1 - 1U) < 3) || (SVar1 == (ST_CM_PROGRAM_INFO)0x6)) {
      local_44 = 0x2c828ac4;
      local_40 = local_44;
                    /* try { // try from 2d4c0ad8 to 2d4c0b1b has its CatchHandler @ 2d4c0ca8 */
      piVar3 = (int *)(**(code **)(*(int *)this + 0x10c))();
      iVar4 = (**(code **)(*piVar3 + 0x1a8))
                        (piVar3,*(undefined2 *)(param_1 + 4),param_1[0x13],auStack_5c);
      if (iVar4 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_2d4bcaa0(auStack_5c,param_1);
      }
      if ((allocator *)(local_40 + -0xc) != (allocator *)&DAT_2c828ab8) {
        SYNC(0);
        iVar4 = *(int *)(local_40 + -4);
        *(int *)(local_40 + -4) = iVar4 + -1;
        SYNC(0);
        if (iVar4 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_40 + -0xc));
        }
      }
      if ((allocator *)(local_44 + -0xc) == (allocator *)&DAT_2c828ab8) {
        return uVar2;
      }
      SYNC(0);
      iVar4 = *(int *)(local_44 + -4);
      *(int *)(local_44 + -4) = iVar4 + -1;
      SYNC(0);
      if (0 < iVar4) {
        return uVar2;
      }
      std::string::_Rep::_M_destroy((allocator *)(local_44 + -0xc));
      return uVar2;
    }
    if (SVar1 == (ST_CM_PROGRAM_INFO)0x0) {
      piVar3 = (int *)MSrv_Control_TV::GetMSrvAtv();
      iVar4 = (**(code **)(*piVar3 + 0x110))(piVar3,auStack_80,param_1[4]);
      if (iVar4 != 0) {
        param_1[0xc] = SUB41((uint)(local_78 << 0x13) >> 0x18,0);
        *(uint *)(param_1 + 4) = local_7c & 0xff;
        param_1[0xd] = SUB41((uint)(local_78 << 0x11) >> 0x1f,0);
        param_1[0xe] = SUB41((local_7c << 0xb) >> 0x1f,0);
        param_1[0x12] = SUB41((local_7c << 10) >> 0x1f,0);
        param_1[0x11] = (ST_CM_PROGRAM_INFO)0x1;
        param_1[0xf] = (ST_CM_PROGRAM_INFO)0x0;
        param_1[0x10] = (ST_CM_PROGRAM_INFO)0x0;
        param_1[0x13] = (ST_CM_PROGRAM_INFO)0x0;
        std::string::assign((char *)(param_1 + 0x18));
        *(undefined2 *)(param_1 + 0x2a) = local_72;
        *(undefined2 *)(param_1 + 0x28) = local_74;
        *(undefined2 *)(param_1 + 0x30) = local_6c;
        *(undefined2 *)(param_1 + 0x2c) = local_70;
        *(undefined2 *)(param_1 + 0x2e) = local_6e;
        return 1;
      }
    }
  }
  return 0;
}

