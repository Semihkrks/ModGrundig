00d569c0 lw v0,0x1a48(s8)
00d569c4 lw v0,0x26c(v0)
00d569c8 move a0,v1
00d569cc move a1,v0
00d569d0 jalr t9 ; [unknown]
00d569d4 _nop
00d569d8 lw gp,0x18(s8)
00d569dc lw v0,0x1a48(s8)
00d569e0 lw v0,0x18c(v0)
00d569e4 addiu v0,v0,0xb8
00d569e8 move a0,v0
00d569ec li a1,0x8
00d569f0 li a2,0x1
00d569f4 lw t9,-0x5244(gp)
00d569f8 jalr t9 ; MImg::SetFlag(unsigned char, unsigned char)
00d569fc _nop
00d56a00 lw gp,0x18(s8)
00d56a04 lw t9,0x5ac(gp)
00d56a08 jalr t9 ; ArServiceSettingsManager::getInstance()
00d56a0c _nop
00d56a10 lw gp,0x18(s8)
00d56a14 move a0,v0
00d56a18 lw t9,-0x2754(gp)
00d56a1c jalr t9 ; ArServiceSettingsManager::ArSourceConf_GetUsbAvailable()
00d56a20 _nop
00d56a24 lw gp,0x18(s8)
00d56a28 sltiu v0,v0,0x1
00d56a2c andi v0,v0,0xff
00d56a30 beq v0,zero,0x00d56b64
00d56a34 _nop
00d56a38 lw v0,0x1a48(s8)
00d56a3c lw v0,0x1b4(v0)
00d56a40 move a0,v0
00d56a44 li a1,0x1
00d56a48 clear a2
00d56a4c lw t9,-0x11d4(gp)
00d56a50 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56a54 _nop
00d56a58 lw gp,0x18(s8)
00d56a5c lw v0,0x1a48(s8)
00d56a60 lw v0,0x1b4(v0)
00d56a64 move a0,v0
00d56a68 li a1,0x2
00d56a6c clear a2
00d56a70 lw t9,-0x11d4(gp)
00d56a74 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56a78 _nop
00d56a7c lw gp,0x18(s8)
00d56a80 lw v0,0x1a48(s8)
00d56a84 lw v0,0x1b4(v0)
00d56a88 move a0,v0
00d56a8c lw t9,-0x72a8(gp)
00d56a90 jalr t9 ; MWidget::Hide()
00d56a94 _nop
00d56a98 lw gp,0x18(s8)
00d56a9c lw v0,0x1a48(s8)
00d56aa0 lw v0,0x1bc(v0)
00d56aa4 move a0,v0
00d56aa8 li a1,0x1
00d56aac clear a2
00d56ab0 lw t9,-0x11d4(gp)
00d56ab4 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56ab8 _nop
00d56abc lw gp,0x18(s8)
00d56ac0 lw v0,0x1a48(s8)
00d56ac4 lw v0,0x1bc(v0)
00d56ac8 move a0,v0
00d56acc li a1,0x2
00d56ad0 clear a2
00d56ad4 lw t9,-0x11d4(gp)
00d56ad8 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56adc _nop
00d56ae0 lw gp,0x18(s8)
00d56ae4 lw v0,0x1a48(s8)
00d56ae8 lw v0,0x1bc(v0)
00d56aec move a0,v0
00d56af0 lw t9,-0x72a8(gp)
00d56af4 jalr t9 ; MWidget::Hide()
00d56af8 _nop
00d56afc lw gp,0x18(s8)
00d56b00 lw v0,0x1a48(s8)
00d56b04 lw v0,0x1b8(v0)
00d56b08 move a0,v0
00d56b0c li a1,0x1
00d56b10 clear a2
00d56b14 lw t9,-0x11d4(gp)
00d56b18 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56b1c _nop
00d56b20 lw gp,0x18(s8)
00d56b24 lw v0,0x1a48(s8)
00d56b28 lw v0,0x1b8(v0)
00d56b2c move a0,v0
00d56b30 li a1,0x2
00d56b34 clear a2
00d56b38 lw t9,-0x11d4(gp)
00d56b3c jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56b40 _nop
00d56b44 lw gp,0x18(s8)
00d56b48 lw v0,0x1a48(s8)
00d56b4c lw v0,0x1b8(v0)
00d56b50 move a0,v0
00d56b54 lw t9,-0x72a8(gp)
00d56b58 jalr t9 ; MWidget::Hide()
00d56b5c _nop
00d56b60 lw gp,0x18(s8)
00d56b64 lw t9,0x5ac(gp)
00d56b68 jalr t9 ; ArServiceSettingsManager::getInstance()
00d56b6c _nop
00d56b70 lw gp,0x18(s8)
00d56b74 move a0,v0
00d56b78 lw t9,-0x3a38(gp)
00d56b7c jalr t9 ; ArServiceSettingsManager::ArTvConf_GetUsbRecording()
00d56b80 _nop
00d56b84 lw gp,0x18(s8)
00d56b88 sltiu v0,v0,0x1
00d56b8c andi v0,v0,0xff
00d56b90 beq v0,zero,0x00d56bfc
00d56b94 _nop
00d56b98 lw v0,0x1a48(s8)
00d56b9c lw v0,0x1b8(v0)
00d56ba0 move a0,v0
00d56ba4 li a1,0x1
00d56ba8 clear a2
00d56bac lw t9,-0x11d4(gp)
00d56bb0 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56bb4 _nop
00d56bb8 lw gp,0x18(s8)
00d56bbc lw v0,0x1a48(s8)
00d56bc0 lw v0,0x1b8(v0)
00d56bc4 move a0,v0
00d56bc8 li a1,0x2
00d56bcc clear a2
00d56bd0 lw t9,-0x11d4(gp)
00d56bd4 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56bd8 _nop
00d56bdc lw gp,0x18(s8)
00d56be0 lw v0,0x1a48(s8)
00d56be4 lw v0,0x1b8(v0)
00d56be8 move a0,v0
00d56bec lw t9,-0x72a8(gp)
00d56bf0 jalr t9 ; MWidget::Hide()
00d56bf4 _nop
00d56bf8 lw gp,0x18(s8)
00d56bfc lw v0,-0x3398(gp)
00d56c00 lw v0,0x0(v0)
00d56c04 bne v0,zero,0x00d56c54
00d56c08 _nop
00d56c0c lw t9,-0x1b28(gp)
00d56c10 jalr t9 ; DMPPhotoPlayerFrame::GetDMPPhotoPlayerFrame()
00d56c14 _nop
00d56c18 lw gp,0x18(s8)
00d56c1c bne v0,zero,0x00d56c54
00d56c20 _nop
00d56c24 lw t9,-0x4dc8(gp)
00d56c28 jalr t9 ; DMPMoviePlayerFrame::GetDMPMoviePlayerFrame()
00d56c2c _nop
00d56c30 lw gp,0x18(s8)
00d56c34 bne v0,zero,0x00d56c54
00d56c38 _nop
00d56c3c lw t9,-0x6db8(gp)
00d56c40 jalr t9 ; DMPMusicPlayerFrame::GetDMPMusicPlayerFrame()
00d56c44 _nop
00d56c48 lw gp,0x18(s8)
00d56c4c beq v0,zero,0x00d56c64
00d56c50 _nop
00d56c54 li a2,0x1
00d56c58 sw a2,0xc84(s8)
00d56c5c b 0x00d56c68
00d56c60 _nop
00d56c64 sw zero,0xc84(s8)
00d56c68 lw v0,0xc84(s8)
00d56c6c beq v0,zero,0x00d56cd8
00d56c70 _nop
00d56c74 lw v0,0x1a48(s8)
00d56c78 lw v0,0x1c8(v0)
00d56c7c move a0,v0
00d56c80 li a1,0x1
00d56c84 clear a2
00d56c88 lw t9,-0x11d4(gp)
00d56c8c jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56c90 _nop
00d56c94 lw gp,0x18(s8)
00d56c98 lw v0,0x1a48(s8)
00d56c9c lw v0,0x1c8(v0)
00d56ca0 move a0,v0
00d56ca4 li a1,0x2
00d56ca8 clear a2
00d56cac lw t9,-0x11d4(gp)
00d56cb0 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56cb4 _nop
00d56cb8 lw gp,0x18(s8)
00d56cbc lw v0,0x1a48(s8)
00d56cc0 lw v0,0x1c8(v0)
00d56cc4 move a0,v0
00d56cc8 lw t9,-0x72a8(gp)
00d56ccc jalr t9 ; MWidget::Hide()
00d56cd0 _nop
00d56cd4 lw gp,0x18(s8)
00d56cd8 lw t9,-0x5b24(gp)
00d56cdc jalr t9 ; ArTvManager::getInstance()
00d56ce0 _nop
00d56ce4 lw gp,0x18(s8)
00d56ce8 move a0,v0
00d56cec clear a1
00d56cf0 lw t9,-0xabc(gp)
00d56cf4 jalr t9 ; ArTvManager::IsActiveSource(unsigned long)
00d56cf8 _nop
00d56cfc lw gp,0x18(s8)
00d56d00 sltiu v0,v0,0x1
00d56d04 andi v0,v0,0xff
00d56d08 beq v0,zero,0x00d56d18
00d56d0c _nop
00d56d10 lw v0,0x1a48(s8)
00d56d14 sb zero,0x2b1(v0)
00d56d18 lw t9,0x60(gp)
00d56d1c jalr t9 ; MSrv_Control_common::GetMSrvChannelManager()
00d56d20 _nop
00d56d24 lw gp,0x18(s8)
00d56d28 sw v0,0xc7c(s8)
00d56d2c lw t0,0xc7c(s8)
00d56d30 bne t0,zero,0x00d56d44
00d56d34 _nop
00d56d38 sw zero,0xc80(s8)
00d56d3c b 0x00d56d68
00d56d40 _nop
00d56d44 lw a0,0xc7c(s8)
00d56d48 lw a1,0xad0(gp)
00d56d4c lw a2,-0x2998(gp)
00d56d50 clear a3
00d56d54 lw t9,-0x598c(gp)
00d56d58 jalr t9 ; __dynamic_cast
00d56d5c _nop
00d56d60 lw gp,0x18(s8)
00d56d64 sw v0,0xc80(s8)
00d56d68 lw v0,0xc80(s8)
00d56d6c sw v0,0x40(s8)
00d56d70 lw v0,0x1a48(s8)
00d56d74 addiu v0,v0,0x2a0
00d56d78 lw a0,0x40(s8)
00d56d7c move a1,v0
00d56d80 lw t9,-0x4194(gp)
00d56d84 jalr t9 ; MSrv_ChannelManager_DVB_Customer::GetServiceHistoryList(std::vector<ST_CM_SERVICE_HISTORY_INFO, std::allocator<ST_CM_SERVICE_HISTORY_INFO> >&)
00d56d88 _nop
00d56d8c lw gp,0x18(s8)
00d56d90 lw t9,-0x5b24(gp)
00d56d94 jalr t9 ; ArTvManager::getInstance()
00d56d98 _nop
00d56d9c lw gp,0x18(s8)
00d56da0 move a0,v0
00d56da4 lw t9,-0x1ae4(gp)
00d56da8 jalr t9 ; ArTvManager::GetCurrentInputSourceType()
00d56dac _nop
00d56db0 lw gp,0x18(s8)
00d56db4 sb v0,0x3c(s8)
00d56db8 lbu v1,0x3c(s8)
00d56dbc li v0,0x5
00d56dc0 bne v1,v0,0x00d56e20
00d56dc4 _nop
00d56dc8 lw t9,0x5ac(gp)
00d56dcc jalr t9 ; ArServiceSettingsManager::getInstance()
00d56dd0 _nop
00d56dd4 lw gp,0x18(s8)
00d56dd8 move a0,v0
00d56ddc lw t9,-0x474(gp)
00d56de0 jalr t9 ; ArServiceSettingsManager::ArTvConf_GetCec()
00d56de4 _nop
00d56de8 lw gp,0x18(s8)
00d56dec beq v0,zero,0x00d56e20
00d56df0 _nop
00d56df4 lw t9,-0x5b24(gp)
00d56df8 jalr t9 ; ArTvManager::getInstance()
00d56dfc _nop
00d56e00 lw gp,0x18(s8)
00d56e04 move a0,v0
00d56e08 lw t9,-0x217c(gp)
00d56e0c jalr t9 ; ArTvManager::GetDualWatchStatus()
00d56e10 _nop
00d56e14 lw gp,0x18(s8)
00d56e18 beq v0,zero,0x00d56e4c
00d56e1c _nop
00d56e20 lbu v1,0x3c(s8)
00d56e24 li v0,0x4
00d56e28 beq v1,v0,0x00d56e4c
00d56e2c _nop
00d56e30 lbu v0,0x3c(s8)
00d56e34 beq v0,zero,0x00d56e4c
00d56e38 _nop
00d56e3c lbu v1,0x3c(s8)
00d56e40 li v0,0x1
00d56e44 bne v1,v0,0x00d56e6c
00d56e48 _nop
00d56e4c lw v0,-0x1958(gp)
00d56e50 lw v0,0x0(v0)
00d56e54 bne v0,zero,0x00d56e6c
00d56e58 _nop
00d56e5c li v1,0x1
00d56e60 sw v1,0xc78(s8)
00d56e64 b 0x00d56e70
00d56e68 _nop
00d56e6c sw zero,0xc78(s8)
00d56e70 lw v0,0xc78(s8)
00d56e74 beq v0,zero,0x00d56ea8
00d56e78 _nop
00d56e7c lw v0,0x1a48(s8)
00d56e80 lw v0,0x20c(v0)
00d56e84 move a0,v0
00d56e88 li a1,0x2
00d56e8c li a2,0x1
00d56e90 lw t9,-0x11d4(gp)
00d56e94 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56e98 _nop
00d56e9c lw gp,0x18(s8)
00d56ea0 b 0x00d56ecc
00d56ea4 _nop
00d56ea8 lw v0,0x1a48(s8)
00d56eac lw v0,0x20c(v0)
00d56eb0 move a0,v0
00d56eb4 li a1,0x2
00d56eb8 clear a2
00d56ebc lw t9,-0x11d4(gp)
00d56ec0 jalr t9 ; MWidget::SetFlag(EN_WDG_FLAG, unsigned char)
00d56ec4 _nop
00d56ec8 lw gp,0x18(s8)
00d56ecc lw v0,0x1a48(s8)
00d56ed0 lw v0,0x1ac(v0)
00d56ed4 move a0,v0
00d56ed8 lw t9,-0x142c(gp)
00d56edc jalr t9 ; Container::GetVisibleChildCount()
00d56ee0 _nop
00d56ee4 lw gp,0x18(s8)
00d56ee8 sw v0,0x38(s8)
00d56eec lw v0,0x1a48(s8)
00d56ef0 lw v0,0x190(v0)
00d56ef4 move a0,v0
00d56ef8 lw t9,-0x142c(gp)
00d56efc jalr t9 ; Container::GetVisibleChildCount()
00d56f00 _nop
00d56f04 lw gp,0x18(s8)
00d56f08 sw v0,0x34(s8)
00d56f0c lw v0,0x38(s8)
00d56f10 addiu a3,v0,-0x1
00d56f14 move v0,a3
00d56f18 sw v0,0xc70(s8)
00d56f1c clear a0
00d56f20 sw a0,0xc74(s8)
00d56f24 lw v0,0xc70(s8)
00d56f28 lw v1,0xc74(s8)
00d56f2c sw v0,0xc70(s8)
00d56f30 sw v1,0xc74(s8)
00d56f34 li a0,-0x1
00d56f38 lw a1,0xc70(s8)
00d56f3c and v0,a1,a0
00d56f40 lw a2,0xc74(s8)
00d56f44 andi v1,a2,0xf
00d56f48 sw v0,0xc70(s8)
00d56f4c sw v1,0xc74(s8)
00d56f50 li a0,0x1
00d56f54 clear a1
00d56f58 lw t0,0xc70(s8)
00d56f5c addu v0,t0,a0
00d56f60 lw t0,0xc70(s8)
00d56f64 sltu a2,v0,t0
00d56f68 lw t0,0xc74(s8)
00d56f6c addu v1,t0,a1
00d56f70 addu a0,a2,v1
00d56f74 move v1,a0
00d56f78 sw v0,0xc68(s8)
00d56f7c sw v1,0xc6c(s8)
00d56f80 li a0,-0x1
00d56f84 lw a1,0xc68(s8)
00d56f88 and v0,a1,a0
00d56f8c lw a2,0xc6c(s8)
00d56f90 andi v1,a2,0xf
00d56f94 sw v0,0xc68(s8)
00d56f98 sw v1,0xc6c(s8)
00d56f9c lw t0,0xc68(s8)
00d56fa0 srl v0,t0,0x1b
00d56fa4 lw v1,0xc6c(s8)
00d56fa8 sll a1,v1,0x5
00d56fac or a1,v0,a1
00d56fb0 lw a2,0xc68(s8)
00d56fb4 sll a0,a2,0x5
00d56fb8 li a2,-0x1
00d56fbc and v0,a0,a2
00d56fc0 andi v1,a1,0xf
00d56fc4 move a0,v0
00d56fc8 move a1,v1
00d56fcc move v0,a3
00d56fd0 sw v0,0xc60(s8)
00d56fd4 clear t0
00d56fd8 sw t0,0xc64(s8)
00d56fdc lw v0,0xc60(s8)
00d56fe0 lw v1,0xc64(s8)
00d56fe4 sw v0,0xc60(s8)
00d56fe8 sw v1,0xc64(s8)
00d56fec li a0,-0x1
00d56ff0 lw a1,0xc60(s8)
00d56ff4 and v0,a1,a0
00d56ff8 lw a2,0xc64(s8)
00d56ffc andi v1,a2,0xf
00d57000 sw v0,0xc60(s8)
00d57004 sw v1,0xc64(s8)
00d57008 li a0,0x1
00d5700c clear a1
00d57010 lw t0,0xc60(s8)
00d57014 addu v0,t0,a0
00d57018 lw t0,0xc60(s8)
00d5701c sltu a2,v0,t0
00d57020 lw t0,0xc64(s8)
00d57024 addu v1,t0,a1
00d57028 addu a0,a2,v1
00d5702c move v1,a0
00d57030 sw v0,0xc58(s8)
00d57034 sw v1,0xc5c(s8)
00d57038 li a0,-0x1
00d5703c lw a1,0xc58(s8)
00d57040 and v0,a1,a0
00d57044 lw a2,0xc5c(s8)
00d57048 andi v1,a2,0xf
00d5704c sw v0,0xc58(s8)
00d57050 sw v1,0xc5c(s8)
00d57054 lw t0,0xc58(s8)
00d57058 srl v0,t0,0x1b
00d5705c lw v1,0xc5c(s8)
00d57060 sll a1,v1,0x5
00d57064 or a1,v0,a1
00d57068 lw a2,0xc58(s8)
00d5706c sll a0,a2,0x5
00d57070 li a2,-0x1
00d57074 and v0,a0,a2
00d57078 andi v1,a1,0xf
00d5707c move a0,v0
00d57080 move a1,v1
00d57084 move v0,a3
00d57088 addiu v0,v0,0x1
00d5708c sll v0,v0,0x2
00d57090 addiu v0,v0,0x7
00d57094 addiu v0,v0,0x7
00d57098 srl v0,v0,0x3
00d5709c sll v0,v0,0x3
00d570a0 subu sp,sp,v0
00d570a4 addiu t0,sp,0x18
00d570a8 sw t0,0xc50(s8)
00d570ac lw v1,0xc50(s8)
00d570b0 addiu v0,v1,0x7
00d570b4 srl v0,v0,0x3
00d570b8 sll v0,v0,0x3
00d570bc sw v0,0xc50(s8)
00d570c0 lw a0,0xc50(s8)
00d570c4 sw a0,0x48(s8)
00d570c8 sw zero,0x30(s8)
00d570cc sw zero,0x24(s8)
00d570d0 b 0x00d571c4
00d570d4 _nop
00d570d8 lw v0,0x1a48(s8)
00d570dc lw v0,0x1ac(v0)
00d570e0 lw v0,0x0(v0)
00d570e4 addiu v0,v0,0x40
00d570e8 lw t9,0x0(v0)
00d570ec lw v0,0x1a48(s8)
00d570f0 lw v0,0x1ac(v0)
00d570f4 lw v1,0x24(s8)
00d570f8 move a0,v0
00d570fc move a1,v1
00d57100 jalr t9 ; [unknown]
00d57104 _nop
00d57108 lw gp,0x18(s8)
00d5710c move a0,v0
00d57110 li a1,0x2
00d57114 lw t9,-0x1d9c(gp)
00d57118 jalr t9 ; MWidget::QueryFlag(unsigned char)
00d5711c _nop
00d57120 lw gp,0x18(s8)
00d57124 sltu v0,zero,v0
00d57128 andi v0,v0,0xff
00d5712c beq v0,zero,0x00d571b8
00d57130 _nop
00d57134 lw a1,0x30(s8)
00d57138 sw a1,0xc4c(s8)
00d5713c lw v0,0x1a48(s8)
00d57140 lw v0,0x1ac(v0)
00d57144 sw v0,0xc48(s8)
00d57148 lw v0,0x1a48(s8)
00d5714c lw v0,0x1ac(v0)
00d57150 lw v0,0x0(v0)
00d57154 addiu v0,v0,0x40
00d57158 lw t9,0x0(v0)
00d5715c lw v0,0x1a48(s8)
00d57160 lw v0,0x1ac(v0)
00d57164 lw v1,0x24(s8)
00d57168 move a0,v0
00d5716c move a1,v1
00d57170 jalr t9 ; [unknown]
00d57174 _nop
00d57178 lw gp,0x18(s8)
00d5717c lw a0,0xc48(s8)
00d57180 move a1,v0
00d57184 lw t9,-0x146c(gp)
00d57188 jalr t9 ; ScrollListContainer::GetChildIdx(MWidget*)
00d5718c _nop
00d57190 lw gp,0x18(s8)
00d57194 move a0,v0
00d57198 lw v1,0x48(s8)
00d5719c lw a2,0xc4c(s8)
00d571a0 sll v0,a2,0x2
00d571a4 addu v0,v1,v0
00d571a8 sw a0,0x0(v0)
00d571ac lw v0,0x30(s8)
00d571b0 addiu v0,v0,0x1
00d571b4 sw v0,0x30(s8)
00d571b8 lw v0,0x24(s8)
00d571bc addiu v0,v0,0x1
00d571c0 sw v0,0x24(s8)
00d571c4 lw v0,0x1a48(s8)
00d571c8 lw v0,0x1ac(v0)
00d571cc lw v0,0x0(v0)
00d571d0 addiu v0,v0,0x44
00d571d4 lw t9,0x0(v0)
00d571d8 lw v0,0x1a48(s8)
00d571dc lw v0,0x1ac(v0)
00d571e0 move a0,v0
00d571e4 jalr t9 ; [unknown]
00d571e8 _nop
00d571ec lw gp,0x18(s8)
00d571f0 move v1,v0
00d571f4 lw v0,0x24(s8)
00d571f8 slt v0,v0,v1
00d571fc andi v0,v0,0xff
00d57200 bne v0,zero,0x00d570d8
00d57204 _nop
00d57208 lw v0,0x34(s8)
00d5720c addiu a3,v0,-0x1
00d57210 move v0,a3
00d57214 sw v0,0xc40(s8)
00d57218 clear t0
00d5721c sw t0,0xc44(s8)
00d57220 lw v0,0xc40(s8)
00d57224 lw v1,0xc44(s8)
00d57228 sw v0,0xc40(s8)
00d5722c sw v1,0xc44(s8)
00d57230 li a0,-0x1
00d57234 lw a1,0xc40(s8)
00d57238 and v0,a1,a0
00d5723c lw a2,0xc44(s8)
00d57240 andi v1,a2,0xf
00d57244 sw v0,0xc40(s8)
00d57248 sw v1,0xc44(s8)
00d5724c li a0,0x1
00d57250 clear a1
00d57254 lw t0,0xc40(s8)
00d57258 addu v0,t0,a0
00d5725c lw t0,0xc40(s8)
00d57260 sltu a2,v0,t0
00d57264 lw t0,0xc44(s8)
00d57268 addu v1,t0,a1
00d5726c addu a0,a2,v1
00d57270 move v1,a0
00d57274 sw v0,0xc38(s8)
00d57278 sw v1,0xc3c(s8)
00d5727c li a0,-0x1
00d57280 lw a1,0xc38(s8)
00d57284 and v0,a1,a0
00d57288 lw a2,0xc3c(s8)
00d5728c andi v1,a2,0xf
00d57290 sw v0,0xc38(s8)
00d57294 sw v1,0xc3c(s8)
00d57298 lw t0,0xc38(s8)
00d5729c srl v0,t0,0x1b
00d572a0 lw v1,0xc3c(s8)
00d572a4 sll a1,v1,0x5
00d572a8 or a1,v0,a1
00d572ac lw a2,0xc38(s8)
00d572b0 sll a0,a2,0x5
00d572b4 li a2,-0x1
00d572b8 and v0,a0,a2
00d572bc andi v1,a1,0xf
00d572c0 move a0,v0
00d572c4 move a1,v1
00d572c8 move v0,a3
00d572cc sw v0,0xc30(s8)
00d572d0 clear t0
00d572d4 sw t0,0xc34(s8)
00d572d8 lw v0,0xc30(s8)
00d572dc lw v1,0xc34(s8)
00d572e0 sw v0,0xc30(s8)
00d572e4 sw v1,0xc34(s8)
00d572e8 li a0,-0x1
00d572ec lw a1,0xc30(s8)
00d572f0 and v0,a1,a0
00d572f4 lw a2,0xc34(s8)
00d572f8 andi v1,a2,0xf
00d572fc sw v0,0xc30(s8)
00d57300 sw v1,0xc34(s8)
00d57304 li a0,0x1
00d57308 clear a1
00d5730c lw t0,0xc30(s8)
00d57310 addu v0,t0,a0
00d57314 lw t0,0xc30(s8)
00d57318 sltu a2,v0,t0
00d5731c lw t0,0xc34(s8)
00d57320 addu v1,t0,a1
00d57324 addu a0,a2,v1
00d57328 move v1,a0
00d5732c sw v0,0xc28(s8)
00d57330 sw v1,0xc2c(s8)
00d57334 li a0,-0x1
00d57338 lw a1,0xc28(s8)
00d5733c and v0,a1,a0
00d57340 lw a2,0xc2c(s8)
00d57344 andi v1,a2,0xf
00d57348 sw v0,0xc28(s8)
00d5734c sw v1,0xc2c(s8)
00d57350 lw t0,0xc28(s8)
00d57354 srl v0,t0,0x1b
00d57358 lw v1,0xc2c(s8)
00d5735c sll a1,v1,0x5
00d57360 or a1,v0,a1
00d57364 lw a2,0xc28(s8)
00d57368 sll a0,a2,0x5
00d5736c li a2,-0x1
00d57370 and v0,a0,a2
00d57374 andi v1,a1,0xf
00d57378 move a0,v0
00d5737c move a1,v1
00d57380 move v0,a3
00d57384 addiu v0,v0,0x1
00d57388 sll v0,v0,0x2
00d5738c addiu v0,v0,0x7
00d57390 addiu v0,v0,0x7
00d57394 srl v0,v0,0x3
00d57398 sll v0,v0,0x3
00d5739c subu sp,sp,v0
00d573a0 addiu t0,sp,0x18
00d573a4 sw t0,0xc20(s8)
00d573a8 lw v1,0xc20(s8)
00d573ac addiu v0,v1,0x7
00d573b0 srl v0,v0,0x3
00d573b4 sll v0,v0,0x3
00d573b8 sw v0,0xc20(s8)
00d573bc lw a0,0xc20(s8)
00d573c0 sw a0,0x44(s8)
00d573c4 sw zero,0x30(s8)
00d573c8 sw zero,0x20(s8)
00d573cc b 0x00d574c0
00d573d0 _nop
00d573d4 lw v0,0x1a48(s8)
00d573d8 lw v0,0x190(v0)
00d573dc lw v0,0x0(v0)
00d573e0 addiu v0,v0,0x40
00d573e4 lw t9,0x0(v0)
00d573e8 lw v0,0x1a48(s8)
00d573ec lw v0,0x190(v0)
00d573f0 lw v1,0x20(s8)
00d573f4 move a0,v0
00d573f8 move a1,v1
00d573fc jalr t9 ; [unknown]
00d57400 _nop
00d57404 lw gp,0x18(s8)
00d57408 move a0,v0
00d5740c li a1,0x2
00d57410 lw t9,-0x1d9c(gp)
00d57414 jalr t9 ; MWidget::QueryFlag(unsigned char)
00d57418 _nop
00d5741c lw gp,0x18(s8)
00d57420 sltu v0,zero,v0
00d57424 andi v0,v0,0xff
00d57428 beq v0,zero,0x00d574b4
00d5742c _nop
00d57430 lw a1,0x30(s8)
00d57434 sw a1,0xc1c(s8)
00d57438 lw v0,0x1a48(s8)
00d5743c lw v0,0x190(v0)
00d57440 sw v0,0xc18(s8)
00d57444 lw v0,0x1a48(s8)
00d57448 lw v0,0x190(v0)
00d5744c lw v0,0x0(v0)
00d57450 addiu v0,v0,0x40
00d57454 lw t9,0x0(v0)
00d57458 lw v0,0x1a48(s8)
00d5745c lw v0,0x190(v0)
00d57460 lw v1,0x20(s8)
00d57464 move a0,v0
00d57468 move a1,v1
00d5746c jalr t9 ; [unknown]
00d57470 _nop
00d57474 lw gp,0x18(s8)
00d57478 lw a0,0xc18(s8)
00d5747c move a1,v0
00d57480 lw t9,-0x146c(gp)
00d57484 jalr t9 ; ScrollListContainer::GetChildIdx(MWidget*)
00d57488 _nop
00d5748c lw gp,0x18(s8)
00d57490 move a0,v0
00d57494 lw v1,0x44(s8)
00d57498 lw a2,0xc1c(s8)
00d5749c sll v0,a2,0x2
00d574a0 addu v0,v1,v0
00d574a4 sw a0,0x0(v0)
00d574a8 lw v0,0x30(s8)
00d574ac addiu v0,v0,0x1
00d574b0 sw v0,0x30(s8)
00d574b4 lw v0,0x20(s8)
00d574b8 addiu v0,v0,0x1
00d574bc sw v0,0x20(s8)
00d574c0 lw v0,0x1a48(s8)
00d574c4 lw v0,0x190(v0)
00d574c8 lw v0,0x0(v0)
00d574cc addiu v0,v0,0x44
00d574d0 lw t9,0x0(v0)
00d574d4 lw v0,0x1a48(s8)
00d574d8 lw v0,0x190(v0)
00d574dc move a0,v0
00d574e0 jalr t9 ; [unknown]
00d574e4 _nop
00d574e8 lw gp,0x18(s8)
00d574ec move v1,v0
00d574f0 lw v0,0x20(s8)
00d574f4 slt v0,v0,v1
00d574f8 andi v0,v0,0xff
00d574fc bne v0,zero,0x00d573d4
00d57500 _nop
00d57504 sw zero,0x2c(s8)
00d57508 sw zero,0x28(s8)
00d5750c b 0x00d57870
00d57510 _nop
00d57514 lw v0,0x1a48(s8)
00d57518 lw v0,0x1ac(v0)
00d5751c lw v0,0x0(v0)
00d57520 addiu v0,v0,0x40
00d57524 lw t9,0x0(v0)
00d57528 lw v0,0x1a48(s8)
00d5752c lw v0,0x1ac(v0)
00d57530 move a0,v0
00d57534 lw v0,0x28(s8)
00d57538 lw v1,0x48(s8)
00d5753c sll v0,v0,0x2
00d57540 addu v0,v1,v0
00d57544 lw v0,0x0(v0)
00d57548 move a1,v0
00d5754c jalr t9 ; [unknown]
00d57550 _nop
00d57554 lw gp,0x18(s8)
00d57558 sw v0,0xc14(s8)
00d5755c lw v0,0x1a48(s8)
00d57560 lw v0,0x1ac(v0)
00d57564 lw v0,0x0(v0)
00d57568 addiu v0,v0,0x40
00d5756c lw t9,0x0(v0)
00d57570 lw v0,0x1a48(s8)
00d57574 lw v0,0x1ac(v0)
00d57578 move a0,v0
00d5757c lw v0,0x28(s8)
00d57580 lw v1,0x48(s8)
00d57584 sll v0,v0,0x2
00d57588 addu v0,v1,v0
00d5758c lw v0,0x0(v0)
00d57590 move a1,v0
00d57594 jalr t9 ; [unknown]
00d57598 _nop
00d5759c lw gp,0x18(s8)
00d575a0 lw t0,0xc14(s8)
00d575a4 sw v0,0xb0(t0)
00d575a8 lw v1,0x2c(s8)
00d575ac lw v0,0x34(s8)
00d575b0 slt v0,v1,v0
00d575b4 beq v0,zero,0x00d577cc
00d575b8 _nop
00d575bc lw v0,0x1a48(s8)
00d575c0 lw v0,0x1ac(v0)
00d575c4 lw v0,0x0(v0)
00d575c8 addiu v0,v0,0x40
00d575cc lw t9,0x0(v0)
00d575d0 lw v0,0x1a48(s8)
00d575d4 lw v0,0x1ac(v0)
00d575d8 move a0,v0
00d575dc lw v0,0x28(s8)
00d575e0 lw v1,0x48(s8)
00d575e4 sll v0,v0,0x2
00d575e8 addu v0,v1,v0
00d575ec lw v0,0x0(v0)
00d575f0 move a1,v0
00d575f4 jalr t9 ; [unknown]
00d575f8 _nop
00d575fc lw gp,0x18(s8)
00d57600 sw v0,0xc10(s8)
00d57604 lw v0,0x1a48(s8)
00d57608 lw v0,0x190(v0)
00d5760c lw v0,0x0(v0)
00d57610 addiu v0,v0,0x40
00d57614 lw t9,0x0(v0)
00d57618 lw v0,0x1a48(s8)
00d5761c lw v0,0x190(v0)
00d57620 move a0,v0
00d57624 lw v0,0x2c(s8)
00d57628 lw v1,0x44(s8)
00d5762c sll v0,v0,0x2
00d57630 addu v0,v1,v0
00d57634 lw v0,0x0(v0)
00d57638 move a1,v0
00d5763c jalr t9 ; [unknown]
00d57640 _nop
00d57644 lw gp,0x18(s8)
00d57648 lw v1,0xc10(s8)
00d5764c sw v0,0xb4(v1)
00d57650 lw v0,0x1a48(s8)
00d57654 lw v0,0x190(v0)
00d57658 lw v0,0x0(v0)
00d5765c addiu v0,v0,0x40
00d57660 lw t9,0x0(v0)
00d57664 lw v0,0x1a48(s8)
00d57668 lw v0,0x190(v0)
00d5766c move a0,v0
00d57670 lw v0,0x2c(s8)
00d57674 lw v1,0x44(s8)
00d57678 sll v0,v0,0x2
00d5767c addu v0,v1,v0
00d57680 lw v0,0x0(v0)
00d57684 move a1,v0
00d57688 jalr t9 ; [unknown]
00d5768c _nop
00d57690 lw gp,0x18(s8)
00d57694 sw v0,0xc0c(s8)
00d57698 lw v0,0x1a48(s8)
00d5769c lw v0,0x1ac(v0)
00d576a0 lw v0,0x0(v0)
00d576a4 addiu v0,v0,0x40
00d576a8 lw t9,0x0(v0)
00d576ac lw v0,0x1a48(s8)
00d576b0 lw v0,0x1ac(v0)
00d576b4 move a0,v0
00d576b8 lw v0,0x28(s8)
00d576bc lw v1,0x48(s8)
00d576c0 sll v0,v0,0x2
00d576c4 addu v0,v1,v0
00d576c8 lw v0,0x0(v0)
00d576cc move a1,v0
00d576d0 jalr t9 ; [unknown]
00d576d4 _nop
00d576d8 lw gp,0x18(s8)
00d576dc lw a0,0xc0c(s8)
00d576e0 sw v0,0xb0(a0)
00d576e4 lw v0,0x2c(s8)
00d576e8 addiu v1,v0,0x1
00d576ec lw v0,0x34(s8)
00d576f0 slt v0,v1,v0
00d576f4 beq v0,zero,0x00d57794
00d576f8 _nop
00d576fc lw v0,0x1a48(s8)
00d57700 lw v0,0x190(v0)
00d57704 lw v0,0x0(v0)
00d57708 addiu v0,v0,0x40
00d5770c lw t9,0x0(v0)
00d57710 lw v0,0x1a48(s8)
00d57714 lw v0,0x190(v0)
00d57718 move a0,v0
00d5771c lw v0,0x2c(s8)
00d57720 addiu v0,v0,0x1
00d57724 lw v1,0x44(s8)
00d57728 sll v0,v0,0x2
00d5772c addu v0,v1,v0
00d57730 lw v0,0x0(v0)
00d57734 move a1,v0
00d57738 jalr t9 ; [unknown]
00d5773c _nop
00d57740 lw gp,0x18(s8)
00d57744 sw v0,0xc08(s8)
00d57748 lw v0,0x1a48(s8)
00d5774c lw v0,0x1ac(v0)
00d57750 lw v0,0x0(v0)
00d57754 addiu v0,v0,0x40
00d57758 lw t9,0x0(v0)
00d5775c lw v0,0x1a48(s8)
00d57760 lw v0,0x1ac(v0)
00d57764 move a0,v0
00d57768 lw v0,0x28(s8)
00d5776c lw v1,0x48(s8)
00d57770 sll v0,v0,0x2
00d57774 addu v0,v1,v0
00d57778 lw v0,0x0(v0)
00d5777c move a1,v0
00d57780 jalr t9 ; [unknown]
00d57784 _nop
00d57788 lw gp,0x18(s8)
00d5778c lw a1,0xc08(s8)
00d57790 sw v0,0xb0(a1)
00d57794 lw v0,0x28(s8)
00d57798 andi v0,v0,0x1
00d5779c bne v0,zero,0x00d577b8
00d577a0 _nop
00d577a4 lw v0,0x2c(s8)
00d577a8 addiu v0,v0,0x1
00d577ac sw v0,0x2c(s8)
00d577b0 b 0x00d57864
00d577b4 _nop
00d577b8 lw v0,0x2c(s8)
00d577bc addiu v0,v0,0x2
00d577c0 sw v0,0x2c(s8)
00d577c4 b 0x00d57864
00d577c8 _nop
00d577cc lw v0,0x1a48(s8)
00d577d0 lw v0,0x1ac(v0)
00d577d4 lw v0,0x0(v0)
00d577d8 addiu v0,v0,0x40
00d577dc lw t9,0x0(v0)
00d577e0 lw v0,0x1a48(s8)
00d577e4 lw v0,0x1ac(v0)
00d577e8 move a0,v0
00d577ec lw v0,0x28(s8)
00d577f0 lw v1,0x48(s8)
00d577f4 sll v0,v0,0x2
00d577f8 addu v0,v1,v0
00d577fc lw v0,0x0(v0)
00d57800 move a1,v0
00d57804 jalr t9 ; [unknown]
00d57808 _nop
00d5780c lw gp,0x18(s8)
00d57810 sw v0,0xc04(s8)
00d57814 lw v0,0x1a48(s8)
00d57818 lw v0,0x190(v0)
00d5781c lw v0,0x0(v0)
00d57820 addiu v0,v0,0x40
00d57824 lw t9,0x0(v0)
00d57828 lw v0,0x1a48(s8)
00d5782c lw v0,0x190(v0)
00d57830 move a0,v0
00d57834 lw v0,0x34(s8)
00d57838 addiu v0,v0,-0x1
00d5783c lw v1,0x44(s8)
00d57840 sll v0,v0,0x2
00d57844 addu v0,v1,v0
00d57848 lw v0,0x0(v0)
00d5784c move a1,v0
00d57850 jalr t9 ; [unknown]
00d57854 _nop
00d57858 lw gp,0x18(s8)
00d5785c lw a2,0xc04(s8)
00d57860 sw v0,0xb4(a2)
00d57864 lw v0,0x28(s8)
00d57868 addiu v0,v0,0x1
00d5786c sw v0,0x28(s8)
00d57870 lw v0,0x28(s8)
00d57874 lw v1,0x38(s8)
00d57878 slt v0,v0,v1
00d5787c bne v0,zero,0x00d57514
00d57880 _nop
00d57884 lw v0,0x1a48(s8)
00d57888 lw v0,0x1ac(v0)
00d5788c lw v0,0x0(v0)
00d57890 addiu v0,v0,0x48
00d57894 lw t9,0x0(v0)
00d57898 lw v0,0x1a48(s8)
00d5789c lw v0,0x1ac(v0)
00d578a0 move a0,v0
00d578a4 jalr t9 ; [unknown]
00d578a8 _nop
00d578ac lw gp,0x18(s8)
00d578b0 lw v0,0xaf4(s8)
00d578b4 move v1,v0
00d578b8 lw v0,0x1a48(s8)
00d578bc sw v1,0x27c(v0)
00d578c0 lw v0,0xaf8(s8)
00d578c4 move v1,v0
00d578c8 lw v0,0x1a48(s8)
00d578cc sw v1,0x280(v0)
00d578d0 lw v0,0x1a48(s8)
00d578d4 lw v0,0x190(v0)
00d578d8 lw v0,0x0(v0)
00d578dc addiu v0,v0,0x48
00d578e0 lw t9,0x0(v0)
00d578e4 lw v0,0x1a48(s8)
00d578e8 lw v0,0x190(v0)
00d578ec move a0,v0
00d578f0 jalr t9 ; [unknown]
00d578f4 _nop
00d578f8 lw gp,0x18(s8)
00d578fc lw v0,0xaf4(s8)
00d57900 move v1,v0
00d57904 lw v0,0x1a48(s8)
00d57908 sw v1,0x288(v0)
00d5790c lw v0,0xaf8(s8)
00d57910 move v1,v0
00d57914 lw v0,0x1a48(s8)
00d57918 sw v1,0x28c(v0)
00d5791c lw v0,0x1a48(s8)
00d57920 lw v0,0x1fc(v0)
00d57924 lw v0,0x0(v0)
00d57928 addiu v0,v0,0x48
00d5792c lw t9,0x0(v0)
00d57930 lw v0,0x1a48(s8)
00d57934 lw v0,0x1fc(v0)
00d57938 move a0,v0
00d5793c jalr t9 ; [unknown]
00d57940 _nop
00d57944 lw gp,0x18(s8)
00d57948 lw v0,0xaf4(s8)
00d5794c move v1,v0
00d57950 lw v0,0x1a48(s8)
00d57954 sw v1,0x294(v0)
00d57958 lw v0,0xaf8(s8)
00d5795c move v1,v0
00d57960 lw v0,0x1a48(s8)
00d57964 sw v1,0x298(v0)
00d57968 lw v0,0x1a48(s8)
00d5796c lw v0,0x194(v0)
00d57970 move a0,v0
00d57974 lw t9,-0x72a8(gp)
00d57978 jalr t9 ; MWidget::Hide()
00d5797c _nop
00d57980 lw gp,0x18(s8)
00d57984 lw v0,0x1a48(s8)
00d57988 lw v0,0x198(v0)
00d5798c move a0,v0
00d57990 lw t9,-0x72a8(gp)
00d57994 jalr t9 ; MWidget::Hide()
00d57998 _nop
00d5799c lw gp,0x18(s8)
00d579a0 lw a0,0x1a48(s8)
00d579a4 lw t9,-0x78a0(gp)
00d579a8 jalr t9 ; HomePageFrame::LayoutItems()
00d579ac _nop
00d579b0 lw gp,0x18(s8)
00d579b4 lw a0,0x1a48(s8)
00d579b8 ori a1,zero,0xf002
00d579bc li a2,0x1
00d579c0 li a3,0x3d
00d579c4 lw t9,-0x5a54(gp)
00d579c8 jalr t9 ; HomePageFrame::HandleFocus(unsigned long, unsigned char, unsigned long)
00d579cc _nop
00d579d0 lw gp,0x18(s8)
00d579d4 lw v0,0x1a48(s8)
00d579d8 lw v0,0x1b0(v0)
00d579dc move v1,v0
00d579e0 lw v0,0x1a48(s8)
00d579e4 sw v1,0x270(v0)
00d579e8 lw t9,-0x5b24(gp)
00d579ec jalr t9 ; ArTvManager::getInstance()
00d579f0 _nop
00d579f4 lw gp,0x18(s8)
00d579f8 move a0,v0
00d579fc lw t9,-0xd7c(gp)
00d57a00 jalr t9 ; ArTvManager::LockParental()
00d57a04 _nop
00d57a08 lw gp,0x18(s8)
00d57a0c lw t9,-0x230(gp)
00d57a10 jalr t9 ; ArChannelManager::ControlAllRecordProcess()
00d57a14 _nop
00d57a18 lw gp,0x18(s8)
00d57a1c xori v0,v0,0x1
00d57a20 sltiu v0,v0,0x1
00d57a24 andi v0,v0,0xff
00d57a28 beq v0,zero,0x00d57a4c
00d57a2c _nop
00d57a30 lw v0,0x1a48(s8)
00d57a34 lw v0,0x20c(v0)
00d57a38 move a0,v0
00d57a3c lw t9,-0x72a8(gp)
00d57a40 jalr t9 ; MWidget::Hide()
00d57a44 _nop
00d57a48 lw gp,0x18(s8)
00d57a4c lw v0,0x1a48(s8)
00d57a50 lw v0,0x220(v0)
00d57a54 addiu v1,s8,0xafc
00d57a58 move a0,v0
00d57a5c move a1,v1
00d57a60 lw t9,-0x6b0c(gp)
00d57a64 jalr t9 ; MWnd::GetRect(_Rect&)
00d57a68 _nop
00d57a6c lw gp,0x18(s8)
00d57a70 lw v0,0x1a48(s8)
00d57a74 lw v0,0x224(v0)
00d57a78 addiu v1,s8,0xb0c
00d57a7c move a0,v0
00d57a80 move a1,v1
00d57a84 lw t9,-0x6b0c(gp)
00d57a88 jalr t9 ; MWnd::GetRect(_Rect&)
00d57a8c _nop
00d57a90 lw gp,0x18(s8)
00d57a94 lw t9,0x5ac(gp)
00d57a98 jalr t9 ; ArServiceSettingsManager::getInstance()
00d57a9c _nop
00d57aa0 lw gp,0x18(s8)
00d57aa4 move a0,v0
00d57aa8 lw t9,0x804(gp)
00d57aac jalr t9 ; ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled()
00d57ab0 _nop
00d57ab4 lw gp,0x18(s8)
00d57ab8 xori v0,v0,0x1
00d57abc sltiu v0,v0,0x1
00d57ac0 andi v0,v0,0xff
00d57ac4 beq v0,zero,0x00d57f7c
00d57ac8 _nop
00d57acc lw v0,0x1a48(s8)
00d57ad0 lw v0,0x228(v0)
00d57ad4 move a0,v0
00d57ad8 lw t9,0x67c(gp)
00d57adc jalr t9 ; MWidget::Show()
00d57ae0 _nop
00d57ae4 lw gp,0x18(s8)
00d57ae8 lw t9,0x5ac(gp)
00d57aec jalr t9 ; ArServiceSettingsManager::getInstance()
00d57af0 _nop
00d57af4 lw gp,0x18(s8)
00d57af8 move a0,v0
00d57afc lw t9,-0x2f10(gp)
00d57b00 jalr t9 ; ArServiceSettingsManager::ArTvConf_GetBasicMode()
00d57b04 _nop
00d57b08 lw gp,0x18(s8)
00d57b0c move v1,v0
00d57b10 li v0,0x1
00d57b14 bne v1,v0,0x00d57b60
00d57b18 _nop
00d57b1c lw t9,0xf60(gp)
00d57b20 jalr t9 ; ArTvSettingsManager::getInstance()
00d57b24 _nop
00d57b28 lw gp,0x18(s8)
00d57b2c move a0,v0
00d57b30 lw t9,-0x402c(gp)
00d57b34 jalr t9 ; ArTvSettingsManager::GetBasicMode()
00d57b38 _nop
00d57b3c lw gp,0x18(s8)
00d57b40 move v1,v0
00d57b44 li v0,0x1
00d57b48 bne v1,v0,0x00d57b60
00d57b4c _nop
00d57b50 li t0,0x1
00d57b54 sw t0,0xc00(s8)
00d57b58 b 0x00d57b64
00d57b5c _nop
00d57b60 sw zero,0xc00(s8)
00d57b64 lw v0,0xc00(s8)
00d57b68 beq v0,zero,0x00d57d0c
00d57b6c _nop
00d57b70 lw t9,0x5ac(gp)
00d57b74 jalr t9 ; ArServiceSettingsManager::getInstance()
00d57b78 _nop
00d57b7c lw gp,0x18(s8)
00d57b80 move a0,v0
00d57b84 lw t9,-0x2754(gp)
00d57b88 jalr t9 ; ArServiceSettingsManager::ArSourceConf_GetUsbAvailable()
00d57b8c _nop
00d57b90 lw gp,0x18(s8)
00d57b94 sltiu v0,v0,0x1
00d57b98 andi v0,v0,0xff
00d57b9c beq v0,zero,0x00d57c58
00d57ba0 _nop
00d57ba4 lw v0,0xafc(s8)
00d57ba8 addiu v0,v0,-0x2a0
00d57bac sw v0,0xafc(s8)
00d57bb0 lw v0,0xb14(s8)
00d57bb4 addiu v0,v0,-0xe0
00d57bb8 sw v0,0xb04(s8)
00d57bbc lw v0,0xb14(s8)
00d57bc0 addiu v0,v0,-0x2a0
00d57bc4 sw v0,0xb14(s8)
00d57bc8 lw v0,0x1a48(s8)
00d57bcc lw v0,0x220(v0)
00d57bd0 lw v0,0x0(v0)
00d57bd4 addiu v0,v0,0x24
00d57bd8 lw t9,0x0(v0)
00d57bdc lw v0,0x1a48(s8)
00d57be0 lw v0,0x220(v0)
00d57be4 move a0,v0
00d57be8 lw v0,0xafc(s8)
00d57bec move v1,v0
00d57bf0 lw v0,0xb00(s8)
00d57bf4 addiu a3,s8,0xafc
00d57bf8 move a1,v1
00d57bfc move a2,v0
00d57c00 jalr t9 ; [unknown]
00d57c04 _nop
00d57c08 lw gp,0x18(s8)
00d57c0c lw v0,0x1a48(s8)
00d57c10 lw v0,0x224(v0)
00d57c14 lw v0,0x0(v0)
00d57c18 addiu v0,v0,0x24
00d57c1c lw t9,0x0(v0)
00d57c20 lw v0,0x1a48(s8)
00d57c24 lw v0,0x224(v0)
00d57c28 move a0,v0
00d57c2c lw v0,0xb0c(s8)
00d57c30 move v1,v0
00d57c34 lw v0,0xb10(s8)
00d57c38 addiu a3,s8,0xb0c
00d57c3c move a1,v1
00d57c40 move a2,v0
00d57c44 jalr t9 ; [unknown]
00d57c48 _nop
00d57c4c lw gp,0x18(s8)
00d57c50 b 0x00d58438
00d57c54 _nop
00d57c58 lw v0,0xafc(s8)
00d57c5c addiu v0,v0,-0x1c0
00d57c60 sw v0,0xafc(s8)
00d57c64 lw v0,0xb14(s8)
00d57c68 addiu v0,v0,-0x1c0
00d57c6c sw v0,0xb04(s8)
00d57c70 lw v0,0xb14(s8)
00d57c74 addiu v0,v0,-0x1c0
00d57c78 sw v0,0xb14(s8)
00d57c7c lw v0,0x1a48(s8)
00d57c80 lw v0,0x220(v0)
00d57c84 lw v0,0x0(v0)
00d57c88 addiu v0,v0,0x24
00d57c8c lw t9,0x0(v0)
00d57c90 lw v0,0x1a48(s8)
00d57c94 lw v0,0x220(v0)
00d57c98 move a0,v0
00d57c9c lw v0,0xafc(s8)
00d57ca0 move v1,v0
00d57ca4 lw v0,0xb00(s8)
00d57ca8 addiu a3,s8,0xafc
00d57cac move a1,v1
00d57cb0 move a2,v0
00d57cb4 jalr t9 ; [unknown]
00d57cb8 _nop
00d57cbc lw gp,0x18(s8)
00d57cc0 lw v0,0x1a48(s8)
00d57cc4 lw v0,0x224(v0)
00d57cc8 lw v0,0x0(v0)
00d57ccc addiu v0,v0,0x24
00d57cd0 lw t9,0x0(v0)
00d57cd4 lw v0,0x1a48(s8)
00d57cd8 lw v0,0x224(v0)
00d57cdc move a0,v0
00d57ce0 lw v0,0xb0c(s8)
00d57ce4 move v1,v0
00d57ce8 lw v0,0xb10(s8)
00d57cec addiu a3,s8,0xb0c
00d57cf0 move a1,v1
00d57cf4 move a2,v0
00d57cf8 jalr t9 ; [unknown]
00d57cfc _nop
00d57d00 lw gp,0x18(s8)
00d57d04 b 0x00d58438
00d57d08 _nop
00d57d0c lw t9,0x5ac(gp)
00d57d10 jalr t9 ; ArServiceSettingsManager::getInstance()
00d57d14 _nop
00d57d18 lw gp,0x18(s8)
00d57d1c move a0,v0
00d57d20 lw t9,-0x2754(gp)
00d57d24 jalr t9 ; ArServiceSettingsManager::ArSourceConf_GetUsbAvailable()
00d57d28 _nop
00d57d2c lw gp,0x18(s8)
00d57d30 sltiu v0,v0,0x1
00d57d34 andi v0,v0,0xff
00d57d38 beq v0,zero,0x00d57df4
00d57d3c _nop
00d57d40 lw v0,0xafc(s8)
00d57d44 addiu v0,v0,-0x1c0
00d57d48 sw v0,0xafc(s8)
00d57d4c lw v0,0xb14(s8)
00d57d50 addiu v0,v0,-0x1c0
00d57d54 sw v0,0xb04(s8)
00d57d58 lw v0,0xb14(s8)
00d57d5c addiu v0,v0,-0x1c0
00d57d60 sw v0,0xb14(s8)
00d57d64 lw v0,0x1a48(s8)
00d57d68 lw v0,0x220(v0)
00d57d6c lw v0,0x0(v0)
00d57d70 addiu v0,v0,0x24
00d57d74 lw t9,0x0(v0)
00d57d78 lw v0,0x1a48(s8)
00d57d7c lw v0,0x220(v0)
00d57d80 move a0,v0
00d57d84 lw v0,0xafc(s8)
00d57d88 move v1,v0
00d57d8c lw v0,0xb00(s8)
00d57d90 addiu a3,s8,0xafc
00d57d94 move a1,v1
00d57d98 move a2,v0
00d57d9c jalr t9 ; [unknown]
00d57da0 _nop
00d57da4 lw gp,0x18(s8)
00d57da8 lw v0,0x1a48(s8)
00d57dac lw v0,0x224(v0)
00d57db0 lw v0,0x0(v0)
00d57db4 addiu v0,v0,0x24
00d57db8 lw t9,0x0(v0)
00d57dbc lw v0,0x1a48(s8)
00d57dc0 lw v0,0x224(v0)
00d57dc4 move a0,v0
00d57dc8 lw v0,0xb0c(s8)
00d57dcc move v1,v0
00d57dd0 lw v0,0xb10(s8)
00d57dd4 addiu a3,s8,0xb0c
00d57dd8 move a1,v1
00d57ddc move a2,v0
00d57de0 jalr t9 ; [unknown]
00d57de4 _nop
00d57de8 lw gp,0x18(s8)
00d57dec b 0x00d58438
00d57df0 _nop
00d57df4 lw t9,0x5ac(gp)
00d57df8 jalr t9 ; ArServiceSettingsManager::getInstance()
00d57dfc _nop
00d57e00 lw gp,0x18(s8)
00d57e04 move a0,v0
00d57e08 lw t9,-0x3a38(gp)
00d57e0c jalr t9 ; ArServiceSettingsManager::ArTvConf_GetUsbRecording()
00d57e10 _nop
00d57e14 lw gp,0x18(s8)
00d57e18 sltiu v0,v0,0x1
00d57e1c andi v0,v0,0xff
00d57e20 beq v0,zero,0x00d57edc
00d57e24 _nop
00d57e28 lw v0,0xafc(s8)
00d57e2c addiu v0,v0,-0xe0
00d57e30 sw v0,0xafc(s8)
00d57e34 lw v0,0xb14(s8)
00d57e38 addiu v0,v0,-0x2a0
00d57e3c sw v0,0xb04(s8)
00d57e40 lw v0,0xb14(s8)
00d57e44 addiu v0,v0,-0xe0
00d57e48 sw v0,0xb14(s8)
00d57e4c lw v0,0x1a48(s8)
00d57e50 lw v0,0x220(v0)
00d57e54 lw v0,0x0(v0)
00d57e58 addiu v0,v0,0x24
00d57e5c lw t9,0x0(v0)
00d57e60 lw v0,0x1a48(s8)
00d57e64 lw v0,0x220(v0)
00d57e68 move a0,v0
00d57e6c lw v0,0xafc(s8)
00d57e70 move v1,v0
00d57e74 lw v0,0xb00(s8)
00d57e78 addiu a3,s8,0xafc
00d57e7c move a1,v1
00d57e80 move a2,v0
00d57e84 jalr t9 ; [unknown]
00d57e88 _nop
00d57e8c lw gp,0x18(s8)
00d57e90 lw v0,0x1a48(s8)
00d57e94 lw v0,0x224(v0)
00d57e98 lw v0,0x0(v0)
00d57e9c addiu v0,v0,0x24
00d57ea0 lw t9,0x0(v0)
00d57ea4 lw v0,0x1a48(s8)
00d57ea8 lw v0,0x224(v0)
00d57eac move a0,v0
00d57eb0 lw v0,0xb0c(s8)
00d57eb4 move v1,v0
00d57eb8 lw v0,0xb10(s8)
00d57ebc addiu a3,s8,0xb0c
00d57ec0 move a1,v1
00d57ec4 move a2,v0
00d57ec8 jalr t9 ; [unknown]
00d57ecc _nop
00d57ed0 lw gp,0x18(s8)
00d57ed4 b 0x00d58438
00d57ed8 _nop
00d57edc lw v0,0xafc(s8)
00d57ee0 sw v0,0xafc(s8)
00d57ee4 lw v0,0xb14(s8)
00d57ee8 sw v0,0xb14(s8)
00d57eec lw v0,0x1a48(s8)
00d57ef0 lw v0,0x220(v0)
00d57ef4 lw v0,0x0(v0)
00d57ef8 addiu v0,v0,0x24
00d57efc lw t9,0x0(v0)
00d57f00 lw v0,0x1a48(s8)
00d57f04 lw v0,0x220(v0)
00d57f08 move a0,v0
00d57f0c lw v0,0xafc(s8)
00d57f10 move v1,v0
00d57f14 lw v0,0xb00(s8)
00d57f18 addiu a3,s8,0xafc
00d57f1c move a1,v1
00d57f20 move a2,v0
00d57f24 jalr t9 ; [unknown]
00d57f28 _nop
00d57f2c lw gp,0x18(s8)
00d57f30 lw v0,0x1a48(s8)
00d57f34 lw v0,0x224(v0)
00d57f38 lw v0,0x0(v0)
00d57f3c addiu v0,v0,0x24
00d57f40 lw t9,0x0(v0)
00d57f44 lw v0,0x1a48(s8)
00d57f48 lw v0,0x224(v0)
00d57f4c move a0,v0
00d57f50 lw v0,0xb0c(s8)
00d57f54 move v1,v0
00d57f58 lw v0,0xb10(s8)
00d57f5c addiu a3,s8,0xb0c
00d57f60 move a1,v1
00d57f64 move a2,v0
00d57f68 jalr t9 ; [unknown]
00d57f6c _nop
00d57f70 lw gp,0x18(s8)
00d57f74 b 0x00d58438
00d57f78 _nop
00d57f7c lw t9,0x5ac(gp)
00d57f80 jalr t9 ; ArServiceSettingsManager::getInstance()
00d57f84 _nop
00d57f88 lw gp,0x18(s8)
00d57f8c move a0,v0
00d57f90 lw t9,-0x2f10(gp)
00d57f94 jalr t9 ; ArServiceSettingsManager::ArTvConf_GetBasicMode()
00d57f98 _nop
00d57f9c lw gp,0x18(s8)
00d57fa0 move v1,v0
00d57fa4 li v0,0x1
00d57fa8 bne v1,v0,0x00d57ff4
00d57fac _nop
00d57fb0 lw t9,0xf60(gp)
00d57fb4 jalr t9 ; ArTvSettingsManager::getInstance()
00d57fb8 _nop
00d57fbc lw gp,0x18(s8)
00d57fc0 move a0,v0
00d57fc4 lw t9,-0x402c(gp)
00d57fc8 jalr t9 ; ArTvSettingsManager::GetBasicMode()
00d57fcc _nop
00d57fd0 lw gp,0x18(s8)
00d57fd4 move v1,v0
00d57fd8 li v0,0x1
00d57fdc bne v1,v0,0x00d57ff4
00d57fe0 _nop
00d57fe4 li v0,0x1
00d57fe8 sw v0,0xbfc(s8)
00d57fec b 0x00d57ff8
00d57ff0 _nop
00d57ff4 sw zero,0xbfc(s8)
00d57ff8 lw v0,0xbfc(s8)
00d57ffc beq v0,zero,0x00d58288
00d58000 _nop
00d58004 lw t9,0x5ac(gp)
00d58008 jalr t9 ; ArServiceSettingsManager::getInstance()
00d5800c _nop
00d58010 lw gp,0x18(s8)
00d58014 move a0,v0
00d58018 lw t9,-0x2754(gp)
00d5801c jalr t9 ; ArServiceSettingsManager::ArSourceConf_GetUsbAvailable()
00d58020 _nop
00d58024 lw gp,0x18(s8)
00d58028 sltiu v0,v0,0x1
00d5802c andi v0,v0,0xff
00d58030 beq v0,zero,0x00d58160
00d58034 _nop
00d58038 lw v0,0x1a48(s8)
00d5803c lw v0,0x228(v0)
00d58040 addiu v1,s8,0xb1c
00d58044 move a0,v0
00d58048 move a1,v1
00d5804c lw t9,-0x6b0c(gp)
00d58050 jalr t9 ; MWnd::GetRect(_Rect&)
00d58054 _nop
00d58058 lw gp,0x18(s8)
00d5805c lw v0,0xafc(s8)
00d58060 addiu v0,v0,-0x2a0
00d58064 sw v0,0xafc(s8)
00d58068 lw v0,0xb04(s8)
00d5806c addiu v0,v0,-0xe0
00d58070 sw v0,0xb04(s8)
00d58074 lw v0,0xb14(s8)
00d58078 addiu v0,v0,-0x2a0
00d5807c sw v0,0xb14(s8)
00d58080 lw v0,0x1a48(s8)
00d58084 lw v0,0x220(v0)
00d58088 lw v0,0x0(v0)
00d5808c addiu v0,v0,0x24
00d58090 lw t9,0x0(v0)
00d58094 lw v0,0x1a48(s8)
00d58098 lw v0,0x220(v0)
00d5809c move a0,v0
00d580a0 lw v0,0xafc(s8)
00d580a4 move v1,v0
00d580a8 lw v0,0xb00(s8)
00d580ac addiu a3,s8,0xafc
00d580b0 move a1,v1
00d580b4 move a2,v0
00d580b8 jalr t9 ; [unknown]
00d580bc _nop
00d580c0 lw gp,0x18(s8)
00d580c4 lw v0,0x1a48(s8)
00d580c8 lw v0,0x224(v0)
00d580cc lw v0,0x0(v0)
00d580d0 addiu v0,v0,0x24
00d580d4 lw t9,0x0(v0)
00d580d8 lw v0,0x1a48(s8)
00d580dc lw v0,0x224(v0)
00d580e0 move a0,v0
00d580e4 lw v0,0xb0c(s8)
00d580e8 move v1,v0
00d580ec lw v0,0xb10(s8)
00d580f0 addiu a3,s8,0xb0c
00d580f4 move a1,v1
00d580f8 move a2,v0
00d580fc jalr t9 ; [unknown]
00d58100 _nop
00d58104 lw gp,0x18(s8)
00d58108 lw v0,0xb24(s8)
00d5810c addiu v0,v0,-0x1c0
00d58110 sw v0,0xb24(s8)
00d58114 lw v0,0x1a48(s8)
00d58118 lw v0,0x228(v0)
00d5811c lw v0,0x0(v0)
00d58120 addiu v0,v0,0x24
00d58124 lw t9,0x0(v0)
00d58128 lw v0,0x1a48(s8)
00d5812c lw v0,0x228(v0)
00d58130 move a0,v0
00d58134 lw v0,0xb1c(s8)
00d58138 move v1,v0
00d5813c lw v0,0xb20(s8)
00d58140 addiu a3,s8,0xb1c
00d58144 move a1,v1
00d58148 move a2,v0
00d5814c jalr t9 ; [unknown]
00d58150 _nop
00d58154 lw gp,0x18(s8)
00d58158 b 0x00d58438
00d5815c _nop
00d58160 lw v0,0x1a48(s8)
00d58164 lw v0,0x228(v0)
00d58168 addiu v1,s8,0xb1c
00d5816c move a0,v0
00d58170 move a1,v1
00d58174 lw t9,-0x6b0c(gp)
00d58178 jalr t9 ; MWnd::GetRect(_Rect&)
00d5817c _nop
00d58180 lw gp,0x18(s8)
00d58184 lw v0,0xafc(s8)
00d58188 addiu v0,v0,-0x1c0
00d5818c sw v0,0xafc(s8)
00d58190 lw v0,0xb04(s8)
00d58194 addiu v0,v0,-0xe0
00d58198 sw v0,0xb04(s8)
00d5819c lw v0,0xb14(s8)
00d581a0 addiu v0,v0,-0x1c0
00d581a4 sw v0,0xb14(s8)
00d581a8 lw v0,0x1a48(s8)
00d581ac lw v0,0x220(v0)
00d581b0 lw v0,0x0(v0)
00d581b4 addiu v0,v0,0x24
00d581b8 lw t9,0x0(v0)
00d581bc lw v0,0x1a48(s8)
00d581c0 lw v0,0x220(v0)
00d581c4 move a0,v0
00d581c8 lw v0,0xafc(s8)
00d581cc move v1,v0
00d581d0 lw v0,0xb00(s8)
00d581d4 addiu a3,s8,0xafc
00d581d8 move a1,v1
00d581dc move a2,v0
00d581e0 jalr t9 ; [unknown]
00d581e4 _nop
00d581e8 lw gp,0x18(s8)
00d581ec lw v0,0x1a48(s8)
00d581f0 lw v0,0x224(v0)
00d581f4 lw v0,0x0(v0)
00d581f8 addiu v0,v0,0x24
00d581fc lw t9,0x0(v0)
00d58200 lw v0,0x1a48(s8)
00d58204 lw v0,0x224(v0)
00d58208 move a0,v0
00d5820c lw v0,0xb0c(s8)
00d58210 move v1,v0
00d58214 lw v0,0xb10(s8)
00d58218 addiu a3,s8,0xb0c
00d5821c move a1,v1
00d58220 move a2,v0
00d58224 jalr t9 ; [unknown]
00d58228 _nop
00d5822c lw gp,0x18(s8)
00d58230 lw v0,0xb24(s8)
00d58234 addiu v0,v0,-0x1c0
00d58238 sw v0,0xb24(s8)
00d5823c lw v0,0x1a48(s8)
00d58240 lw v0,0x228(v0)
00d58244 lw v0,0x0(v0)
00d58248 addiu v0,v0,0x24
00d5824c lw t9,0x0(v0)
00d58250 lw v0,0x1a48(s8)
00d58254 lw v0,0x228(v0)
00d58258 move a0,v0
00d5825c lw v0,0xb1c(s8)
00d58260 move v1,v0
00d58264 lw v0,0xb20(s8)
00d58268 addiu a3,s8,0xb1c
00d5826c move a1,v1
00d58270 move a2,v0
00d58274 jalr t9 ; [unknown]
00d58278 _nop
00d5827c lw gp,0x18(s8)
00d58280 b 0x00d58438
00d58284 _nop
00d58288 lw t9,0x5ac(gp)
00d5828c jalr t9 ; ArServiceSettingsManager::getInstance()
00d58290 _nop
00d58294 lw gp,0x18(s8)
00d58298 move a0,v0
00d5829c lw t9,-0x2754(gp)
00d582a0 jalr t9 ; ArServiceSettingsManager::ArSourceConf_GetUsbAvailable()
00d582a4 _nop
00d582a8 lw gp,0x18(s8)
00d582ac sltiu v0,v0,0x1
00d582b0 andi v0,v0,0xff
00d582b4 beq v0,zero,0x00d58364
00d582b8 _nop
00d582bc lw v0,0xafc(s8)
00d582c0 addiu v0,v0,-0x1c0
00d582c4 sw v0,0xafc(s8)
00d582c8 lw v0,0xb14(s8)
00d582cc addiu v0,v0,-0x1c0
00d582d0 sw v0,0xb14(s8)
00d582d4 lw v0,0x1a48(s8)
00d582d8 lw v0,0x220(v0)
00d582dc lw v0,0x0(v0)
00d582e0 addiu v0,v0,0x24
00d582e4 lw t9,0x0(v0)
00d582e8 lw v0,0x1a48(s8)
00d582ec lw v0,0x220(v0)
00d582f0 move a0,v0
00d582f4 lw v0,0xafc(s8)
00d582f8 move v1,v0
00d582fc lw v0,0xb00(s8)
00d58300 addiu a3,s8,0xafc
00d58304 move a1,v1
00d58308 move a2,v0
00d5830c jalr t9 ; [unknown]
00d58310 _nop
00d58314 lw gp,0x18(s8)
00d58318 lw v0,0x1a48(s8)
00d5831c lw v0,0x224(v0)
00d58320 lw v0,0x0(v0)
00d58324 addiu v0,v0,0x24
00d58328 lw t9,0x0(v0)
00d5832c lw v0,0x1a48(s8)
00d58330 lw v0,0x224(v0)
00d58334 move a0,v0
00d58338 lw v0,0xb0c(s8)
00d5833c move v1,v0
00d58340 lw v0,0xb10(s8)
00d58344 addiu a3,s8,0xb0c
00d58348 move a1,v1
00d5834c move a2,v0
00d58350 jalr t9 ; [unknown]
00d58354 _nop
00d58358 lw gp,0x18(s8)
00d5835c b 0x00d58438
00d58360 _nop
00d58364 lw t9,0x5ac(gp)
00d58368 jalr t9 ; ArServiceSettingsManager::getInstance()
00d5836c _nop
00d58370 lw gp,0x18(s8)
00d58374 move a0,v0
00d58378 lw t9,-0x3a38(gp)
00d5837c jalr t9 ; ArServiceSettingsManager::ArTvConf_GetUsbRecording()
00d58380 _nop
00d58384 lw gp,0x18(s8)
00d58388 sltiu v0,v0,0x1
00d5838c andi v0,v0,0xff
00d58390 beq v0,zero,0x00d58438
00d58394 _nop
00d58398 lw v0,0xafc(s8)
00d5839c addiu v0,v0,-0xe0
00d583a0 sw v0,0xafc(s8)
00d583a4 lw v0,0xb14(s8)
00d583a8 addiu v0,v0,-0xe0
00d583ac sw v0,0xb14(s8)
00d583b0 lw v0,0x1a48(s8)
00d583b4 lw v0,0x220(v0)
00d583b8 lw v0,0x0(v0)
00d583bc addiu v0,v0,0x24
00d583c0 lw t9,0x0(v0)
00d583c4 lw v0,0x1a48(s8)
00d583c8 lw v0,0x220(v0)
00d583cc move a0,v0
00d583d0 lw v0,0xafc(s8)
00d583d4 move v1,v0
00d583d8 lw v0,0xb00(s8)
00d583dc addiu a3,s8,0xafc
00d583e0 move a1,v1
00d583e4 move a2,v0
00d583e8 jalr t9 ; [unknown]
00d583ec _nop
00d583f0 lw gp,0x18(s8)
00d583f4 lw v0,0x1a48(s8)
00d583f8 lw v0,0x224(v0)
00d583fc lw v0,0x0(v0)
00d58400 addiu v0,v0,0x24
00d58404 lw t9,0x0(v0)
00d58408 lw v0,0x1a48(s8)
00d5840c lw v0,0x224(v0)
00d58410 move a0,v0
00d58414 lw v0,0xb0c(s8)
00d58418 move v1,v0
00d5841c lw v0,0xb10(s8)
00d58420 addiu a3,s8,0xb0c
00d58424 move a1,v1
00d58428 move a2,v0
00d5842c jalr t9 ; [unknown]
00d58430 _nop
00d58434 lw gp,0x18(s8)
00d58438 lw t9,-0x2488(gp)
00d5843c jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d58440 _nop
00d58444 lw gp,0x18(s8)
00d58448 lw v0,0x1cc(v0)
00d5844c move a0,v0
00d58450 lw t9,-0x1c7c(gp)
00d58454 jalr t9 ; HelpWidget::HideAllButtons()
00d58458 _nop
00d5845c lw gp,0x18(s8)
00d58460 lw t9,-0x2488(gp)
00d58464 jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d58468 _nop
00d5846c lw gp,0x18(s8)
00d58470 lw v0,0x1cc(v0)
00d58474 move a0,v0
00d58478 li a1,0xe
00d5847c li a2,0xc42
00d58480 lw t9,-0xe3c(gp)
00d58484 jalr t9 ; HelpWidget::ShowButton(unsigned long, unsigned long)
00d58488 _nop
00d5848c lw gp,0x18(s8)
00d58490 lw t9,-0x2488(gp)
00d58494 jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d58498 _nop
00d5849c lw gp,0x18(s8)
00d584a0 lw v0,0x1cc(v0)
00d584a4 move a0,v0
00d584a8 li a1,0xf
00d584ac li a2,0xd41
00d584b0 lw t9,-0xe3c(gp)
00d584b4 jalr t9 ; HelpWidget::ShowButton(unsigned long, unsigned long)
00d584b8 _nop
00d584bc lw gp,0x18(s8)
00d584c0 lw t9,0x5ac(gp)
00d584c4 jalr t9 ; ArServiceSettingsManager::getInstance()
00d584c8 _nop
00d584cc lw gp,0x18(s8)
00d584d0 move a0,v0
00d584d4 lw t9,-0x2f10(gp)
00d584d8 jalr t9 ; ArServiceSettingsManager::ArTvConf_GetBasicMode()
00d584dc _nop
00d584e0 lw gp,0x18(s8)
00d584e4 xori v0,v0,0x1
00d584e8 sltiu v0,v0,0x1
00d584ec andi v0,v0,0xff
00d584f0 beq v0,zero,0x00d58594
00d584f4 _nop
00d584f8 lw t9,0xf60(gp)
00d584fc jalr t9 ; ArTvSettingsManager::getInstance()
00d58500 _nop
00d58504 lw gp,0x18(s8)
00d58508 move a0,v0
00d5850c lw t9,-0x402c(gp)
00d58510 jalr t9 ; ArTvSettingsManager::GetBasicMode()
00d58514 _nop
00d58518 lw gp,0x18(s8)
00d5851c sltiu v0,v0,0x1
00d58520 andi v0,v0,0xff
00d58524 beq v0,zero,0x00d58564
00d58528 _nop
00d5852c lw t9,-0x2488(gp)
00d58530 jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d58534 _nop
00d58538 lw gp,0x18(s8)
00d5853c lw v0,0x1cc(v0)
00d58540 move a0,v0
00d58544 li a1,0x3
00d58548 li a2,0x1082
00d5854c lw t9,-0xe3c(gp)
00d58550 jalr t9 ; HelpWidget::ShowButton(unsigned long, unsigned long)
00d58554 _nop
00d58558 lw gp,0x18(s8)
00d5855c b 0x00d58594
00d58560 _nop
00d58564 lw t9,-0x2488(gp)
00d58568 jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d5856c _nop
00d58570 lw gp,0x18(s8)
00d58574 lw v0,0x1cc(v0)
00d58578 move a0,v0
00d5857c li a1,0x3
00d58580 li a2,0x1081
00d58584 lw t9,-0xe3c(gp)
00d58588 jalr t9 ; HelpWidget::ShowButton(unsigned long, unsigned long)
00d5858c _nop
00d58590 lw gp,0x18(s8)
00d58594 lw t9,-0x2488(gp)
00d58598 jalr t9 ; MenuBackgroundFrame::getMenuBackgroundFrame()
00d5859c _nop
00d585a0 lw gp,0x18(s8)
00d585a4 lw v0,0x1cc(v0)
00d585a8 move a0,v0
00d585ac lw t9,-0x6788(gp)
00d585b0 jalr t9 ; HelpWidget::Refresh()
00d585b4 _nop
00d585b8 lw gp,0x18(s8)
00d585bc li v0,0x40
00d585c0 sw v0,0xb2c(s8)
00d585c4 li v0,0x1094
00d585c8 sw v0,0xb30(s8)
00d585cc lw v0,0x1a48(s8)
00d585d0 addiu v0,v0,0x10c
00d585d4 addiu v1,s8,0xb2c
00d585d8 move a0,v0
00d585dc move a1,v1
00d585e0 lw t9,0x21c(gp)
00d585e4 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d585e8 _nop
00d585ec lw gp,0x18(s8)
00d585f0 li v0,0x42
00d585f4 sw v0,0xb34(s8)
00d585f8 li v0,0x1087
00d585fc sw v0,0xb38(s8)
00d58600 lw v0,0x1a48(s8)
00d58604 addiu v0,v0,0x10c
00d58608 addiu v1,s8,0xb34
00d5860c move a0,v0
00d58610 move a1,v1
00d58614 lw t9,0x21c(gp)
00d58618 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d5861c _nop
00d58620 lw gp,0x18(s8)
00d58624 li v0,0x43
00d58628 sw v0,0xb3c(s8)
00d5862c li v0,0x10bb
00d58630 sw v0,0xb40(s8)
00d58634 lw v0,0x1a48(s8)
00d58638 addiu v0,v0,0x10c
00d5863c addiu v1,s8,0xb3c
00d58640 move a0,v0
00d58644 move a1,v1
00d58648 lw t9,0x21c(gp)
00d5864c jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58650 _nop
00d58654 lw gp,0x18(s8)
00d58658 lw t9,0x5ac(gp)
00d5865c jalr t9 ; ArServiceSettingsManager::getInstance()
00d58660 _nop
00d58664 lw gp,0x18(s8)
00d58668 move a0,v0
00d5866c lw t9,-0x358c(gp)
00d58670 jalr t9 ; ArServiceSettingsManager::ArNetworkConf_GetNetFlixVisible()
00d58674 _nop
00d58678 lw gp,0x18(s8)
00d5867c xori v0,v0,0x1
00d58680 sltiu v0,v0,0x1
00d58684 andi v0,v0,0xff
00d58688 beq v0,zero,0x00d586cc
00d5868c _nop
00d58690 li v0,0x44
00d58694 sw v0,0xb9c(s8)
00d58698 li v0,0x109f
00d5869c sw v0,0xba0(s8)
00d586a0 lw v0,0x1a48(s8)
00d586a4 addiu v0,v0,0x10c
00d586a8 addiu v1,s8,0xb9c
00d586ac move a0,v0
00d586b0 move a1,v1
00d586b4 lw t9,0x21c(gp)
00d586b8 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d586bc _nop
00d586c0 lw gp,0x18(s8)
00d586c4 b 0x00d58700
00d586c8 _nop
00d586cc li v0,0x44
00d586d0 sw v0,0xba4(s8)
00d586d4 li v0,0x10a1
00d586d8 sw v0,0xba8(s8)
00d586dc lw v0,0x1a48(s8)
00d586e0 addiu v0,v0,0x10c
00d586e4 addiu v1,s8,0xba4
00d586e8 move a0,v0
00d586ec move a1,v1
00d586f0 lw t9,0x21c(gp)
00d586f4 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d586f8 _nop
00d586fc lw gp,0x18(s8)
00d58700 li v0,0x41
00d58704 sw v0,0xb44(s8)
00d58708 li v0,0x10b8
00d5870c sw v0,0xb48(s8)
00d58710 lw v0,0x1a48(s8)
00d58714 addiu v0,v0,0x10c
00d58718 addiu v1,s8,0xb44
00d5871c move a0,v0
00d58720 move a1,v1
00d58724 lw t9,0x21c(gp)
00d58728 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d5872c _nop
00d58730 lw gp,0x18(s8)
00d58734 li v0,0x49
00d58738 sw v0,0xb4c(s8)
00d5873c li v0,0x109b
00d58740 sw v0,0xb50(s8)
00d58744 lw v0,0x1a48(s8)
00d58748 addiu v0,v0,0x10c
00d5874c addiu v1,s8,0xb4c
00d58750 move a0,v0
00d58754 move a1,v1
00d58758 lw t9,0x21c(gp)
00d5875c jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58760 _nop
00d58764 lw gp,0x18(s8)
00d58768 li v0,0x48
00d5876c sw v0,0xb54(s8)
00d58770 li v0,0x10aa
00d58774 sw v0,0xb58(s8)
00d58778 lw v0,0x1a48(s8)
00d5877c addiu v0,v0,0x10c
00d58780 addiu v1,s8,0xb54
00d58784 move a0,v0
00d58788 move a1,v1
00d5878c lw t9,0x21c(gp)
00d58790 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58794 _nop
00d58798 lw gp,0x18(s8)
00d5879c li v0,0x4a
00d587a0 sw v0,0xb5c(s8)
00d587a4 li v0,0x10ab
00d587a8 sw v0,0xb60(s8)
00d587ac lw v0,0x1a48(s8)
00d587b0 addiu v0,v0,0x10c
00d587b4 addiu v1,s8,0xb5c
00d587b8 move a0,v0
00d587bc move a1,v1
00d587c0 lw t9,0x21c(gp)
00d587c4 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d587c8 _nop
00d587cc lw gp,0x18(s8)
00d587d0 li v0,0x47
00d587d4 sw v0,0xb64(s8)
00d587d8 li v0,0x10b1
00d587dc sw v0,0xb68(s8)
00d587e0 lw v0,0x1a48(s8)
00d587e4 addiu v0,v0,0x10c
00d587e8 addiu v1,s8,0xb64
00d587ec move a0,v0
00d587f0 move a1,v1
00d587f4 lw t9,0x21c(gp)
00d587f8 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d587fc _nop
00d58800 lw gp,0x18(s8)
00d58804 li v0,0x46
00d58808 sw v0,0xb6c(s8)
00d5880c li v0,0x10b3
00d58810 sw v0,0xb70(s8)
00d58814 lw v0,0x1a48(s8)
00d58818 addiu v0,v0,0x10c
00d5881c addiu v1,s8,0xb6c
00d58820 move a0,v0
00d58824 move a1,v1
00d58828 lw t9,0x21c(gp)
00d5882c jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58830 _nop
00d58834 lw gp,0x18(s8)
00d58838 li v0,0x45
00d5883c sw v0,0xb74(s8)
00d58840 li v0,0x10b4
00d58844 sw v0,0xb78(s8)
00d58848 lw v0,0x1a48(s8)
00d5884c addiu v0,v0,0x10c
00d58850 addiu v1,s8,0xb74
00d58854 move a0,v0
00d58858 move a1,v1
00d5885c lw t9,0x21c(gp)
00d58860 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58864 _nop
00d58868 lw gp,0x18(s8)
00d5886c li v0,0x4c
00d58870 sw v0,0xb7c(s8)
00d58874 li v0,0x10ac
00d58878 sw v0,0xb80(s8)
00d5887c lw v0,0x1a48(s8)
00d58880 addiu v0,v0,0x10c
00d58884 addiu v1,s8,0xb7c
00d58888 move a0,v0
00d5888c move a1,v1
00d58890 lw t9,0x21c(gp)
00d58894 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58898 _nop
00d5889c lw gp,0x18(s8)
00d588a0 li v0,0x4b
00d588a4 sw v0,0xb84(s8)
00d588a8 li v0,0x10b2
00d588ac sw v0,0xb88(s8)
00d588b0 lw v0,0x1a48(s8)
00d588b4 addiu v0,v0,0x10c
00d588b8 addiu v1,s8,0xb84
00d588bc move a0,v0
00d588c0 move a1,v1
00d588c4 lw t9,0x21c(gp)
00d588c8 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d588cc _nop
00d588d0 lw gp,0x18(s8)
00d588d4 li v0,0x52
00d588d8 sw v0,0xb8c(s8)
00d588dc li v0,0x1095
00d588e0 sw v0,0xb90(s8)
00d588e4 lw v0,0x1a48(s8)
00d588e8 addiu v0,v0,0x10c
00d588ec addiu v1,s8,0xb8c
00d588f0 move a0,v0
00d588f4 move a1,v1
00d588f8 lw t9,0x21c(gp)
00d588fc jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58900 _nop
00d58904 lw gp,0x18(s8)
00d58908 li v0,0x4d
00d5890c sw v0,0xb94(s8)
00d58910 li v0,0x10b5
00d58914 sw v0,0xb98(s8)
00d58918 lw v0,0x1a48(s8)
00d5891c addiu v0,v0,0x10c
00d58920 addiu v1,s8,0xb94
00d58924 move a0,v0
00d58928 move a1,v1
00d5892c lw t9,0x21c(gp)
00d58930 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58934 _nop
00d58938 lw gp,0x18(s8)
00d5893c lw t9,0x5ac(gp)
00d58940 jalr t9 ; ArServiceSettingsManager::getInstance()
00d58944 _nop
00d58948 lw gp,0x18(s8)
00d5894c move a0,v0
00d58950 lw t9,-0x6218(gp)
00d58954 jalr t9 ; ArServiceSettingsManager::ArSystemConf_GetHotel()
00d58958 _nop
00d5895c lw gp,0x18(s8)
00d58960 beq v0,zero,0x00d589a4
00d58964 _nop
00d58968 lw t9,0xf60(gp)
00d5896c jalr t9 ; ArTvSettingsManager::getInstance()
00d58970 _nop
00d58974 lw gp,0x18(s8)
00d58978 move a0,v0
00d5897c lw t9,-0x2684(gp)
00d58980 jalr t9 ; ArTvSettingsManager::GetHotelAdmin()
00d58984 _nop
00d58988 lw gp,0x18(s8)
00d5898c bne v0,zero,0x00d589a4
00d58990 _nop
00d58994 li v1,0x1
00d58998 sw v1,0xbf8(s8)
00d5899c b 0x00d589a8
00d589a0 _nop
00d589a4 sw zero,0xbf8(s8)
00d589a8 lw v0,0xbf8(s8)
00d589ac beq v0,zero,0x00d58adc
00d589b0 _nop
00d589b4 lw v0,0x1a48(s8)
00d589b8 lw v0,0x26c(v0)
00d589bc sw v0,0xbf4(s8)
00d589c0 li a0,0x54
00d589c4 lw t9,-0x5868(gp)
00d589c8 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d589cc _nop
00d589d0 lw gp,0x18(s8)
00d589d4 lw a0,0xbf4(s8)
00d589d8 sw v0,0x7c(a0)
00d589dc lw v0,0x1a48(s8)
00d589e0 lw v0,0x26c(v0)
00d589e4 sw v0,0xbf0(s8)
00d589e8 li a0,0x54
00d589ec lw t9,-0x5868(gp)
00d589f0 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d589f4 _nop
00d589f8 lw gp,0x18(s8)
00d589fc lw a1,0xbf0(s8)
00d58a00 sw v0,0x80(a1)
00d58a04 lw v0,0x1a48(s8)
00d58a08 lw v0,0x26c(v0)
00d58a0c sw v0,0xbec(s8)
00d58a10 li a0,0x54
00d58a14 lw t9,-0x5868(gp)
00d58a18 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d58a1c _nop
00d58a20 lw gp,0x18(s8)
00d58a24 lw a2,0xbec(s8)
00d58a28 sw v0,0x84(a2)
00d58a2c lw v0,0x1a48(s8)
00d58a30 lw v0,0x250(v0)
00d58a34 sw v0,0xbe8(s8)
00d58a38 li a0,0x54
00d58a3c lw t9,-0x5868(gp)
00d58a40 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d58a44 _nop
00d58a48 lw gp,0x18(s8)
00d58a4c lw t0,0xbe8(s8)
00d58a50 sw v0,0x7c(t0)
00d58a54 lw v0,0x1a48(s8)
00d58a58 lw v0,0x250(v0)
00d58a5c sw v0,0xbe4(s8)
00d58a60 li a0,0x54
00d58a64 lw t9,-0x5868(gp)
00d58a68 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d58a6c _nop
00d58a70 lw gp,0x18(s8)
00d58a74 lw v1,0xbe4(s8)
00d58a78 sw v0,0x80(v1)
00d58a7c lw v0,0x1a48(s8)
00d58a80 lw v0,0x250(v0)
00d58a84 sw v0,0xbe0(s8)
00d58a88 li a0,0x54
00d58a8c lw t9,-0x5868(gp)
00d58a90 jalr t9 ; GetRcEngine::RcGetColor(unsigned int)
00d58a94 _nop
00d58a98 lw gp,0x18(s8)
00d58a9c lw a0,0xbe0(s8)
00d58aa0 sw v0,0x84(a0)
00d58aa4 lw v0,0x1a48(s8)
00d58aa8 lw v0,0x26c(v0)
00d58aac move a0,v0
00d58ab0 lw t9,-0x74e8(gp)
00d58ab4 jalr t9 ; MWidget::Invalidate()
00d58ab8 _nop
00d58abc lw gp,0x18(s8)
00d58ac0 lw v0,0x1a48(s8)
00d58ac4 lw v0,0x250(v0)
00d58ac8 move a0,v0
00d58acc lw t9,-0x74e8(gp)
00d58ad0 jalr t9 ; MWidget::Invalidate()
00d58ad4 _nop
00d58ad8 lw gp,0x18(s8)
00d58adc lw t9,0x5ac(gp)
00d58ae0 jalr t9 ; ArServiceSettingsManager::getInstance()
00d58ae4 _nop
00d58ae8 lw gp,0x18(s8)
00d58aec move a0,v0
00d58af0 lw t9,-0x2f10(gp)
00d58af4 jalr t9 ; ArServiceSettingsManager::ArTvConf_GetBasicMode()
00d58af8 _nop
00d58afc lw gp,0x18(s8)
00d58b00 move v1,v0
00d58b04 li v0,0x1
00d58b08 bne v1,v0,0x00d58b44
00d58b0c _nop
00d58b10 lw t9,0xf60(gp)
00d58b14 jalr t9 ; ArTvSettingsManager::getInstance()
00d58b18 _nop
00d58b1c lw gp,0x18(s8)
00d58b20 move a0,v0
00d58b24 lw t9,-0x402c(gp)
00d58b28 jalr t9 ; ArTvSettingsManager::GetBasicMode()
00d58b2c _nop
00d58b30 lw gp,0x18(s8)
00d58b34 move v1,v0
00d58b38 li v0,0x1
00d58b3c beq v1,v0,0x00d58b70
00d58b40 _nop
00d58b44 lw t9,0x5ac(gp)
00d58b48 jalr t9 ; ArServiceSettingsManager::getInstance()
00d58b4c _nop
00d58b50 lw gp,0x18(s8)
00d58b54 move a0,v0
00d58b58 lw t9,0x804(gp)
00d58b5c jalr t9 ; ArServiceSettingsManager::ArTvConf_GetNonConnectedEnabled()
00d58b60 _nop
00d58b64 lw gp,0x18(s8)
00d58b68 beq v0,zero,0x00d58b80
00d58b6c _nop
00d58b70 li a1,0x1
00d58b74 sw a1,0xbdc(s8)
00d58b78 b 0x00d58b84
00d58b7c _nop
00d58b80 sw zero,0xbdc(s8)
00d58b84 lw v0,0xbdc(s8)
00d58b88 beq v0,zero,0x00d58d10
00d58b8c _nop
00d58b90 lw t9,0x5ac(gp)
00d58b94 jalr t9 ; ArServiceSettingsManager::getInstance()
00d58b98 _nop
00d58b9c lw gp,0x18(s8)
00d58ba0 move a0,v0
00d58ba4 lw t9,-0x6218(gp)
00d58ba8 jalr t9 ; ArServiceSettingsManager::ArSystemConf_GetHotel()
00d58bac _nop
00d58bb0 lw gp,0x18(s8)
00d58bb4 sltiu v0,v0,0x1
00d58bb8 andi v0,v0,0xff
00d58bbc beq v0,zero,0x00d58c60
00d58bc0 _nop
00d58bc4 li v0,0x3d
00d58bc8 sw v0,0xbbc(s8)
00d58bcc li v0,0x10a7
00d58bd0 sw v0,0xbc0(s8)
00d58bd4 lw v0,0x1a48(s8)
00d58bd8 addiu v0,v0,0x10c
00d58bdc addiu v1,s8,0xbbc
00d58be0 move a0,v0
00d58be4 move a1,v1
00d58be8 lw t9,0x21c(gp)
00d58bec jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58bf0 _nop
00d58bf4 lw gp,0x18(s8)
00d58bf8 li v0,0x3e
00d58bfc sw v0,0xbc4(s8)
00d58c00 li v0,0x10a7
00d58c04 sw v0,0xbc8(s8)
00d58c08 lw v0,0x1a48(s8)
00d58c0c addiu v0,v0,0x10c
00d58c10 addiu v1,s8,0xbc4
00d58c14 move a0,v0
00d58c18 move a1,v1
00d58c1c lw t9,0x21c(gp)
00d58c20 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58c24 _nop
00d58c28 lw gp,0x18(s8)
00d58c2c li v0,0x3f
00d58c30 sw v0,0xbcc(s8)
00d58c34 li v0,0x10a7
00d58c38 sw v0,0xbd0(s8)
00d58c3c lw v0,0x1a48(s8)
00d58c40 addiu v0,v0,0x10c
00d58c44 addiu v1,s8,0xbcc
00d58c48 move a0,v0
00d58c4c move a1,v1
00d58c50 lw t9,0x21c(gp)
00d58c54 jalr t9 ; std::vector<bubblehelppair, std::allocator<bubblehelppair> >::push_back(bubblehelppair const&)
00d58c58 _nop
00d58c5c lw gp,0x18(s8)
00d58c60 lw v0,0x1a48(s8)
00d58c64 lw v0,0x244(v0)
00d58c68 addiu v0,v0,0x170
00d58c6c move a0,v0
00d58c70 li a1,0x1109
00d58c74 lw t9,-0x6114(gp)
00d58c78 jalr t9 ; MString::Set(unsigned short)
00d58c7c _nop
00d58c80 lw gp,0x18(s8)
00d58c84 lw v0,0x1a48(s8)
00d58c88 lw v0,0x240(v0)
00d58c8c addiu v0,v0,0x170
00d58c90 move a0,v0
00d58c94 li a1,0x1148
00d58c98 lw t9,-0x6114(gp)
00d58c9c jalr t9 ; MString::Set(unsigned short)
00d58ca0 _nop
00d58ca4 lw gp,0x18(s8)
00d58ca8 lw v0,0x1a48(s8)
00d58cac lw v0,0x234(v0)
00d58cb0 addiu v1,s8,0xbac
00d58cb4 move a0,v0
00d58cb8 move a1,v1
00d58cbc lw t9,-0x6b0c(gp)
00d58cc0 jalr t9 ; MWnd::GetRect(_Rect&)
00d58cc4 _nop
00d58cc8 lw gp,0x18(s8)
00d58ccc lw v0,0x1a48(s8)
00d58cd0 lw v0,0x260(v0)
00d58cd4 lw v0,0x0(v0)
00d58cd8 addiu v0,v0,0x24
00d58cdc lw t9,0x0(v0)
00d58ce0 lw v0,0x1a48(s8)
00d58ce4 lw v0,0x260(v0)
00d58ce8 move a0,v0
00d58cec lw v0,0xbac(s8)
00d58cf0 move v1,v0
00d58cf4 lw v0,0xbb0(s8)
00d58cf8 addiu a3,s8,0xbac
00d58cfc move a1,v1
00d58d00 move a2,v0
00d58d04 jalr t9 ; [unknown]
00d58d08 _nop
00d58d0c lw gp,0x18(s8)
00d58d10 clear v0
00d58d14 lw sp,0xbd8(s8)
00d58d18 move sp,s8
00d58d1c lw ra,0x1a44(sp)
00d58d20 lw s8,0x1a40(sp)
00d58d24 lw s1,0x1a3c(sp)
00d58d28 lw s0,0x1a38(sp)
00d58d2c addiu sp,sp,0x1a48
00d58d30 jr ra
00d58d34 _nop
00d58d38 lw gp,0x18(s8)
00d58d3c sw a0,0x1a30(s8)
00d58d40 sw a1,0x1a2c(s8)
00d58d44 lw v1,0x1a2c(s8)
00d58d48 lw v0,0x1a30(s8)
00d58d4c lw sp,0xbd8(s8)
00d58d50 sw v0,0x1a30(s8)
00d58d54 sw v1,0x1a2c(s8)
00d58d58 lw a0,0x1a30(s8)
00d58d5c lw t9,-0x3184(gp)
00d58d60 jalr t9 ; _Unwind_Resume
00d58d64 _nop