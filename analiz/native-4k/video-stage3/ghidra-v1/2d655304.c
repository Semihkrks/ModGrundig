
/* WARNING: Removing unreachable block (ram,0x2d655598) */
/* WARNING: Removing unreachable block (ram,0x2d65559c) */

undefined4 MApi_VDEC_EX_V2_Init(int param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 uVar13;
  ushort uVar14;
  byte bVar15;
  int iVar16;
  char cVar17;
  undefined4 uVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int *piVar25;
  uint uVar26;
  ushort *puVar27;
  uint uVar28;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  char local_138 [16];
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  char *local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  uint local_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 local_cc;
  int local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  uint uStack_4c;
  char *local_48;
  char *local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  pcVar6 = pVdecExContext;
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    printf("ERROR!!! Input Null pointer at %s:%d","MApi_VDEC_EX_V2_Init",0x4de1);
    return 2;
  }
  uVar28 = *(uint *)(param_1 + 4);
  uVar26 = uVar28 >> 0x18;
  if (0xf < uVar26) {
    return 2;
  }
  if (pVdecExContext == (char *)0x0) {
    return 0;
  }
  cVar17 = pVdecExContext[0x19199];
  if (pVdecExContext[uVar26 * 0x11ac + 5] != '\0') {
    puts("VDEC Warn: re-init VDEC Driver");
    return 9;
  }
  local_40 = uVar26 * 4;
  piVar25 = (int *)(s32VdecExEventId + local_40);
  if (*piVar25 == -1) {
    iVar16 = MsOS_CreateEventGroup(pVdecExContext + uVar26 * 0x11ac + 0x10e2);
    *piVar25 = iVar16;
    if (iVar16 < 0) {
      puts("MsOS_CreateEventGroup failed!!");
      return 0;
    }
  }
  piVar25 = (int *)(s32VdecExTaskId + local_40);
  if (*piVar25 == -1) {
    pcVar6[uVar26 * 0x11ac + 0x10e0] = '\x01';
    iVar16 = MsOS_CreateTask(*(undefined4 *)(pcVar6 + uVar26 * 0x11ac + 0x1110),uVar26,0xc,1,
                             pcVar6 + uVar26 * 0x11ac + 0xe0,0x1000,
                             pcVar6 + uVar26 * 0x11ac + 0x10fc);
    *piVar25 = iVar16;
    if (iVar16 < 0) {
      puts("MsOS_CreateTask failed!!");
      MsOS_DeleteEventGroup(*(undefined4 *)(s32VdecExEventId + local_40));
      return 0;
    }
  }
  (*(code *)&UNK_2d645df0)(uVar26);
  pcVar6 = pVdecExContext;
  iVar16 = 0;
  pcVar3 = param_2;
  do {
    iVar10 = iVar16 + uVar26 * 0x11ac + 0x1114;
    iVar16 = iVar16 + 1;
    pcVar6[iVar10] = *pcVar3;
    pcVar3 = param_2 + iVar16;
  } while (iVar16 != 0x98);
  *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0xc) = *(undefined4 *)(param_2 + 4);
  if (*(uint *)(param_2 + 4) < 0x12) {
    uVar9 = 1 << (*(uint *)(param_2 + 4) & 0x1f);
    uVar4 = 1;
    if ((((uVar9 & 0x3de00) == 0) && (uVar4 = 2, (uVar9 & 0x2000) == 0)) &&
       (uVar4 = 3, (uVar9 & 0x1fe) != 0)) {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 3;
  }
  iVar16 = uVar26 * 0x11ac;
  *(undefined4 *)(pVdecExContext + iVar16 + 0x10) = uVar4;
  *(undefined4 *)(pVdecExContext + iVar16 + 0x14) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(pVdecExContext + iVar16 + 8) = *(undefined4 *)(param_2 + 0x38);
  if (cVar17 == '\x01') {
    local_34 = &s32VDECMutexID;
    local_30 = &local_160;
    MsOS_ObtainMutex(s32VDECMutexID,0xffffff00);
    puVar7 = local_30;
    do {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      local_3c = uVar26 * 0x10;
    } while (&local_14c != puVar7);
    local_38 = uVar26 * 0x40;
    if (pVdecExContext[uVar26 * 0x50 + 0x18cd0] == '\x01') {
      local_160 = CONCAT31(local_160._1_3_,1);
      local_15c = *(undefined4 *)(pVdecExContext + uVar26 * 0x50 + 0x18cd4);
      local_158 = *(undefined4 *)(pVdecExContext + uVar26 * 0x50 + 0x18cd8);
    }
    iVar16 = uVar26 * 0x11ac;
    local_48 = pVdecExContext;
    local_154 = *(undefined4 *)(pVdecExContext + iVar16 + 0x112c);
    local_150 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1130);
    pcVar6 = pVdecExContext + 0x193c8;
    iVar10 = FUN_2d646418(pcVar6);
    if (iVar10 != 1) {
      printf("[ALLOC][ERR][%s][%d] NDecAllocator_Init failed\n",
             "_VDEC_EX_NdecAllocator_MallocFrameBuffer",0xe92);
      goto LAB_2d656150;
    }
    cVar17 = pVdecExContext[0x19199];
    cVar1 = pVdecExContext[local_3c + local_38 + 0x18cbd];
    local_11c = *(int *)(pVdecExContext + iVar16 + 0xc);
    bVar15 = pVdecExContext[0x191f4];
    local_120 = *(undefined4 *)(pVdecExContext + iVar16 + 0x14);
    if (cVar17 == '\x01') {
      uVar13 = 0;
      if (cVar1 == '\x01') {
        cVar17 = '\0';
        goto LAB_2d656048;
      }
      if (cVar1 == '\0') {
        uVar13 = 1;
      }
    }
    else {
      if (uVar26 != 0) {
        bVar15 = 0;
      }
LAB_2d656048:
      uVar13 = 0;
    }
    local_128._0_2_ = (ushort)bVar15;
    local_128 = CONCAT13(uVar13,CONCAT12(cVar17,(ushort)local_128));
    local_124 = (uint)CONCAT21(local_124._2_2_,cVar1) << 8;
    local_118 = *(undefined4 *)(pVdecExContext + local_3c + local_38 + 0x18cc0);
    local_8c = (*(code *)&UNK_2d646fbc)(pcVar6,0,local_30,&local_128);
    if (0x7f < local_8c) {
      printf("[ALLOC][ERR][%s][%d] GetMainBlock failed\n","_VDEC_EX_NdecAllocator_MallocFrameBuffer"
             ,0xeae);
      goto LAB_2d656150;
    }
    iVar16 = (*(code *)&UNK_2d63c57c)(local_8c);
    if (local_128._3_1_ == '\0') {
      local_88 = 0xffff;
    }
    else {
      local_88 = (*(code *)&UNK_2d6474cc)(iVar16,0,local_30,&local_128);
      if (0x7f < local_88) {
        printf("[ALLOC][ERR][%s][%d] GetSubBlock failed\n",
               "_VDEC_EX_NdecAllocator_MallocFrameBuffer",0xec5);
        goto LAB_2d656150;
      }
      iVar16 = (*(code *)&UNK_2d63c57c)(local_88);
      if ((char)local_124 != '\0') {
        if (iVar16 == 0) {
          printf("[ALLOC][ERR][%s][%d] Invalid input\n","_VDEC_EX_NdecAllocator_GetThirdBlock",0xd9a
                );
        }
        else {
          uVar9 = FUN_2d646244(iVar16);
          if (uVar9 < 0x20) {
            if (*(ushort *)(pVdecExContext + uVar9 * 0x18 + 0x19e9e) < 0x80) {
              iVar16 = (*(code *)&UNK_2d63c57c)();
              goto LAB_2d6560e4;
            }
          }
          else {
            printf("[ALLOC][ERR][%s][%d] GetExtendAllocator failed\n",
                   "_VDEC_EX_NdecAllocator_GetThirdBlock",0xda1);
          }
        }
        printf("[ALLOC][ERR][%s][%d] NdecAllocator_GetThirdBlock failed\n",
               "_VDEC_EX_NdecAllocator_MallocFrameBuffer",0xedf);
        goto LAB_2d656150;
      }
    }
LAB_2d6560e4:
    pcVar6 = pVdecExContext;
    if (((char)local_128 == '\x01') && (local_128._1_1_ == '\0')) {
      uVar9 = *(uint *)(iVar16 + 0xc);
      local_90 = *(undefined4 *)(iVar16 + 0x10);
      if ((char)bCMAInitPool == '\0') {
        printf("[ALLOC][ERR][%s][%d] bCMAInit[%d] == FALSE\n","_VDEC_EX_NdecAllocator_CMAAlloc",
               0xbfc,0);
      }
      else {
        local_14c = 0;
        local_148 = 0;
        local_144 = 0;
        local_140 = 0;
        local_13c = 0;
        uVar19 = __hal_miu1_base();
        if (uVar19 <= uVar9) {
          iVar10 = __hal_miu1_base();
          uVar9 = uVar9 - iVar10;
        }
        if (uVar9 < *(uint *)(pcVar6 + 0x1a1a4)) {
          printf("[ALLOC][ERR][%s][%d] MApi_CMA_Pool_GetMem(%d) fail\n",
                 "_VDEC_EX_NdecAllocator_CMAAlloc",0xc0d,0);
        }
        else {
          iVar12 = *(int *)(pcVar6 + 0x1a18c);
          local_140 = 4;
          uVar18 = 4;
          iVar10 = uVar9 - *(int *)(pcVar6 + 0x1a1a4);
          local_144 = local_90;
          uVar4 = local_90;
          local_14c = iVar12;
          local_148 = iVar10;
          printf("[ALLOC][DBG][%s][%d] MApi_CMA_Pool_GetMem(%d): id=0x%lx, flags=0x%lx, offset_in_pool=0x%lx, length=0x%lx\n"
                 ,"_VDEC_EX_NdecAllocator_CMAAlloc",0xc18,0,iVar12,4,iVar10,local_90);
          iVar8 = MApi_CMA_Pool_GetMem(&local_14c);
          if (iVar8 != 0) {
            *(byte *)(iVar16 + 9) = *(byte *)(iVar16 + 9) | 2;
            goto LAB_2d6560f8;
          }
          printf("[ALLOC][ERR][%s][%d] MApi_CMA_Pool_GetMem(%d) fail\n",
                 "_VDEC_EX_NdecAllocator_CMAAlloc",0xc20,0,iVar12,uVar18,iVar10,uVar4);
        }
      }
      printf("[ALLOC][ERR][%s][%d] CMAAlloc failed\n","_VDEC_EX_NdecAllocator_MallocFrameBuffer",
             0xeff);
LAB_2d656150:
      MsOS_ReleaseMutex(*local_34);
      _MApi_VDEC_EX_ReturnCMABuffer(param_1);
      printf("[ALLOC][ERR][%s][%d][%d] Alloc Frame Buffer Fail\n","MApi_VDEC_EX_V2_Init",0x4e2a,
             uVar26);
      return 0;
    }
LAB_2d6560f8:
    iVar10 = local_3c - local_40;
    if ((*(short *)(local_48 + iVar10 + 0x193cc) != -1) ||
       (*(short *)(local_48 + iVar10 + 0x193ce) != -1)) {
      printf("[ALLOC][ERR][%s][%d] FB: stAllocatorRecord[%d] in used\n",
             "_VDEC_EX_NdecAllocator_MallocFrameBuffer",0xf0b,uVar26);
      goto LAB_2d656150;
    }
    *(short *)(local_48 + iVar10 + 0x193cc) = (short)local_8c;
    *(short *)(local_48 + iVar10 + 0x193ce) = (short)local_88;
    if ((local_128._2_1_ == '\0') && (local_128._1_1_ == '\x01')) {
      (local_48 + iVar10 + 0x193ce)[0] = -1;
      (local_48 + iVar10 + 0x193ce)[1] = -1;
    }
    *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x112c) = *(undefined4 *)(iVar16 + 0xc);
    *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1130) = *(undefined4 *)(iVar16 + 0x10);
    puVar5 = &local_ec;
    do {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while (&local_d8 != puVar5);
    iVar16 = local_3c + local_38;
    if (pVdecExContext[iVar16 + 0x18cc4] == '\x01') {
      local_ec = CONCAT31(local_ec._1_3_,1);
      local_e8 = *(uint *)(pVdecExContext + iVar16 + 0x18cc8);
      local_e4 = *(int *)(pVdecExContext + iVar16 + 0x18ccc);
    }
    iVar16 = uVar26 * 0x11ac;
    local_44 = pVdecExContext;
    local_e0 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1134);
    local_dc = *(undefined4 *)(pVdecExContext + iVar16 + 0x1138);
    pcVar6 = pVdecExContext + 0x193c8;
    iVar10 = FUN_2d646418(pcVar6);
    if (iVar10 != 1) {
      printf("[ALLOC][ERR][%s][%d] NDecAllocator_Init failed\n",
             "_VDEC_EX_NdecAllocator_MallocBitstreamBuffer",0xe19);
      goto LAB_2d6566b0;
    }
    cVar17 = pVdecExContext[0x19199];
    if (cVar17 == '\0') {
      if (pVdecExContext[local_3c + local_38 + 0x18cc4] == '\x01') {
        printf("[ALLOC][ERR][%s][%d] bSetTotalBuf only valid in NDecode\n",
               "_VDEC_EX_NdecAllocator_GetBitstreamBufferProperty",0xb4c);
        printf("[ALLOC][ERR][%s][%d] GetBitstreamBufferProperty failed\n",
               "_VDEC_EX_NdecAllocator_MallocBitstreamBuffer",0xe25);
        goto LAB_2d6566b0;
      }
LAB_2d6565dc:
      bVar2 = false;
    }
    else {
      if (cVar17 != '\x01') goto LAB_2d6565dc;
      if (pVdecExContext[local_3c + local_38 + 0x18cbc] == '\0') {
        bVar2 = true;
      }
      else {
        bVar2 = pVdecExContext[local_3c + local_38 + 0x18cc4] == '\x01';
      }
    }
    local_14c = (uint)CONCAT11(bVar2,cVar17) << 0x10;
    local_148 = (uint)CONCAT21(local_148._2_2_,pVdecExContext[local_3c + local_38 + 0x18cbc]) << 8;
    local_13c = 0;
    local_144 = *(undefined4 *)(pVdecExContext + iVar16 + 0x14);
    local_140 = *(undefined4 *)(pVdecExContext + iVar16 + 0xc);
    uVar9 = (*(code *)&UNK_2d646fbc)(pcVar6,2,&local_ec,&local_14c);
    if (0x7f < uVar9) {
      printf("[ALLOC][ERR][%s][%d] GetMainBlock failed\n",
             "_VDEC_EX_NdecAllocator_MallocBitstreamBuffer",0xe31);
LAB_2d6566b0:
      MsOS_ReleaseMutex(*local_34);
      _MApi_VDEC_EX_ReturnCMABuffer(param_1);
      printf("[ALLOC][ERR][%s][%d][%d] Alloc Bitstream Buffer Fail\n","MApi_VDEC_EX_V2_Init",0x4e45,
             uVar26);
      return 0;
    }
    iVar16 = (*(code *)&UNK_2d63c57c)(uVar9);
    if (local_14c._3_1_ == '\0') {
      uVar19 = 0xffff;
    }
    else {
      uVar19 = (*(code *)&UNK_2d6474cc)(iVar16,2,&local_ec,&local_14c);
      if (0x7f < uVar19) {
        printf("[ALLOC][ERR][%s][%d] GetSubBlock failed\n",
               "_VDEC_EX_NdecAllocator_MallocBitstreamBuffer",0xe48);
        goto LAB_2d6566b0;
      }
      iVar16 = (*(code *)&UNK_2d63c57c)(uVar19);
    }
    iVar10 = local_3c - local_40;
    if ((*(short *)(local_44 + iVar10 + 0x193d4) != -1) ||
       (*(short *)(local_44 + iVar10 + 0x193d6) != -1)) {
      printf("[ALLOC][ERR][%s][%d] BS: stAllocatorRecord[%d] in used\n",
             "_VDEC_EX_NdecAllocator_MallocBitstreamBuffer",0xe5e,uVar26);
      goto LAB_2d6566b0;
    }
    *(short *)(local_44 + iVar10 + 0x193d6) = (short)uVar19;
    *(short *)(local_44 + iVar10 + 0x193d4) = (short)uVar9;
    *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1134) = *(undefined4 *)(iVar16 + 0xc);
    *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1138) = *(undefined4 *)(iVar16 + 0x10);
    if (pVdecExContext[0x19199] == '\x01') {
      iVar16 = local_e4;
      uVar9 = local_e8;
      iVar10 = local_54;
      if ((local_ec & 0xff) != 1) {
        puVar27 = (ushort *)(pVdecExContext + 0x193d4);
        local_54 = 0;
        local_58 = 0;
        uVar9 = 0;
        uVar19 = 0;
        iVar16 = 0;
        do {
          uVar14 = puVar27[1];
          if (*puVar27 < 0x80) {
            if (0x7f < uVar14) {
              uVar14 = *puVar27;
            }
LAB_2d656944:
            iVar16 = (*(code *)&UNK_2d63c57c)(uVar14);
            if (local_58 == 0) {
              uVar9 = *(uint *)(iVar16 + 0xc);
              uVar19 = uVar9 + *(int *)(iVar16 + 0x10);
              local_58 = 1;
              iVar16 = uVar19 - uVar9;
            }
            else {
              uVar11 = *(uint *)(iVar16 + 0xc);
              if (uVar11 < uVar9) {
                printf("[ALLOC][ERR][%s][%d] Warnning: phyBSTotalAddrStart Changed !!",
                       "_VDEC_EX_NdecAllocator_GetBitstreamBufferTotalAddrSize",0xddf);
                uVar11 = *(uint *)(iVar16 + 0xc);
                uVar9 = uVar11;
              }
              uVar11 = uVar11 + *(int *)(iVar16 + 0x10);
              if (uVar11 <= uVar19) {
                uVar11 = uVar19;
              }
              iVar16 = uVar11 - uVar9;
              uVar19 = uVar11;
            }
          }
          else if (uVar14 < 0x80) goto LAB_2d656944;
          local_54 = local_54 + 1;
          puVar27 = puVar27 + 6;
        } while (local_54 != 0x10);
        iVar10 = 0x10;
        if (local_58 == 0) {
          MsOS_ReleaseMutex(*local_34);
          _MApi_VDEC_EX_ReturnCMABuffer(param_1);
          printf("[ALLOC][ERR][%s][%d][%d] Get Total BS AddrSize Fail\n","MApi_VDEC_EX_V2_Init",
                 0x4e5c,uVar26);
          return 0;
        }
      }
      local_54 = iVar10;
      if (pVdecExContext != (char *)0x0) {
        *(uint *)(pVdecExContext + 0x1919c) = uVar9;
        *(int *)(pVdecExContext + 0x191a0) = iVar16;
      }
      printf("[ALLOC][DBG][%s][%d][%d] BSTotalAddrStart=0x%lx, BSToltalSize=0x%x\n",
             "MApi_VDEC_EX_V2_Init",0x4e63,uVar26,uVar9,iVar16);
    }
    iVar16 = uVar26 * 0x11ac;
    printf("[ALLOC][DBG][%s][%d][%d] FB=0x%lx, Size=0x%x\n","MApi_VDEC_EX_V2_Init",0x4e66,uVar26,
           *(undefined4 *)(pVdecExContext + iVar16 + 0x112c),
           *(undefined4 *)(pVdecExContext + iVar16 + 0x1130));
    printf("[ALLOC][DBG][%s][%d][%d] BS=0x%lx, Size=0x%x\n","MApi_VDEC_EX_V2_Init",0x4e69,uVar26,
           *(undefined4 *)(pVdecExContext + iVar16 + 0x1134),
           *(undefined4 *)(pVdecExContext + iVar16 + 0x1138));
    MsOS_ReleaseMutex(*local_34);
  }
  else {
    local_34 = &s32VDECMutexID;
  }
  if ((param_2[0x7c] != '\0') && (iVar16 = HAL_VPU_EX_NotSupportDS(), iVar16 != 0)) {
    puts("VDEC_EX Warn: DS unsupported! Force EnableDynaScale as FALSE.");
    param_2[0x7c] = '\0';
    pVdecExContext[uVar26 * 0x11ac + 0x1190] = '\0';
  }
  (*(code *)&UNK_2d645b9c)(param_1,*(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 8));
  MDrv_MVD_LinkWeakSymbolPatch();
  MDrv_HVD_LinkWeakSymbolPatch();
  MsOS_ObtainMutex(*local_34,0xffffff00);
  local_50 = (uint)(pVdecExContext[1] != '\0');
  if (*pVdecExContext == '\x01') {
    if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x10) == 0) {
      MDrv_MVD_SetSingleDecodeMode(1);
    }
    else if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x10) == 1) {
      MDrv_HVD_SetSingleDecodeMode(1);
    }
  }
  uVar28 = uVar28 & 0xffffff;
  MsOS_ReleaseMutex(*local_34);
  iVar16 = uVar26 * 0x11ac;
  iVar10 = *(int *)(pVdecExContext + iVar16 + 0x10);
  if (iVar10 == 1) {
    local_3c = uVar26 * 0x10;
    local_38 = uVar26 * 0x40;
    if (pVdecExContext[uVar26 * 0x50 + 0x18c98] != '\0') {
      MDrv_HVD_EX_OnePendingBufferMode(uVar28);
    }
    if (pVdecExContext[local_3c + local_38 + 0x18ca0] != '\0') {
      MDrv_HVD_EX_TsInBbuMode(uVar28);
    }
    if (pVdecExContext[local_3c + local_38 + 0x18ca4] != '\0') {
      MDrv_HVD_EX_IapGnBufShareBWMode
                (uVar28,pVdecExContext[local_3c + local_38 + 0x18ca4],
                 *(undefined4 *)(pVdecExContext + local_3c + local_38 + 0x18ca8),
                 *(undefined4 *)(pVdecExContext + (local_40 + uVar26 + 1) * 0x10 + 0x18c9c));
    }
    iVar16 = local_3c + local_38;
    if (pVdecExContext[iVar16 + 0x18cb0] != '\0') {
      MDrv_HVD_EX_PreConnectDispPath
                (uVar28,pVdecExContext[iVar16 + 0x18cb0],pVdecExContext[iVar16 + 0x18cb4],
                 *(undefined4 *)(pVdecExContext + iVar16 + 0x18cb8));
    }
    local_60 = *(uint *)(pVdecExContext + uVar26 * 0x11ac + 0x1140);
    uVar9 = *(uint *)(pVdecExContext + uVar26 * 0x11ac + 0x1150);
    local_64 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x113c);
    local_68 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1138);
    local_6c = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1134);
    local_70 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1130);
    local_74 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x112c);
    local_78 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1128);
    local_7c = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0x1124);
    local_80 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1148);
    local_84 = *(uint *)(pVdecExContext + uVar26 * 0x11ac + 0x1144);
    uVar4 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1120);
    iVar16 = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0x111c);
    puVar5 = &local_ec;
    do {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while (&uStack_94 != puVar5);
    pcVar6 = (char *)&local_128;
    do {
      *pcVar6 = '\0';
      pcVar6 = pcVar6 + 1;
      pcVar3 = (char *)&local_14c;
    } while ((char *)&local_f8 != pcVar6);
    do {
      *pcVar3 = '\0';
      pcVar3 = pcVar3 + 1;
    } while ((char *)&local_128 != pcVar3);
    local_108 = (char *)&local_14c;
    local_ec = uVar9;
    local_e4 = iVar16;
    if (uVar9 - 1 < 2) {
      local_e8 = MsOS_PA2KSEG1();
    }
    local_d8 = local_84;
    local_e0 = uVar4;
    if (local_ec - 1 < 2) {
      local_dc = MsOS_PA2KSEG1(local_84);
    }
    local_d4 = local_80;
    local_c8 = local_7c;
    local_cc = MsOS_PA2KSEG1();
    local_c4 = local_78;
    local_bc = local_74;
    local_c0 = MsOS_PA2KSEG1();
    local_b0 = local_6c;
    local_b8 = local_70;
    local_b4 = MsOS_PA2KSEG1(local_6c);
    local_ac = local_68;
    local_a4 = local_64;
    local_a8 = MsOS_PA2KSEG1(local_64);
    uVar9 = local_110;
    local_a0 = local_60;
    if (pVdecExContext[0x19199] == '\0') {
      local_9c = local_6c;
      local_98 = local_68;
    }
    else {
      local_9c = *(undefined4 *)(pVdecExContext + 0x1919c);
      local_98 = *(undefined4 *)(pVdecExContext + 0x191a0);
    }
    iVar16 = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0xc);
    uVar19 = local_128;
    if (iVar16 != 0xb) {
      if (iVar16 == 0xc) {
        uVar19 = local_128 | 1;
      }
      else if (iVar16 - 9U < 2) {
        uVar19 = local_128 | 2;
      }
      else if (iVar16 == 0xe) {
        uVar19 = local_128 | 3;
      }
      else if (iVar16 == 0xf) {
        uVar19 = local_128 | 4;
      }
      else if (iVar16 == 0x10) {
        uVar19 = local_128 | 7;
      }
      else if (iVar16 == 0x11) {
        uVar19 = local_128 | 8;
      }
    }
    iVar16 = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14);
    if (iVar16 == 0) {
      local_11c = (uint)local_11c._2_2_ << 0x10;
      local_128 = uVar19 | 0x20;
    }
    else if ((iVar16 == 1) || (iVar16 == 3)) {
      local_128 = uVar19 | 0x10;
      local_11c = (uint)local_11c._2_2_ << 0x10;
      if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 3) {
        local_128 = uVar19 | 0x410;
      }
    }
    else if ((iVar16 == 2) || (local_128 = uVar19, iVar16 == 4)) {
      local_128 = uVar19 | 0x40;
      if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 4) {
        local_128 = uVar19 | 0x440;
      }
      iVar16 = *(int *)(param_2 + 0x44);
      if (iVar16 == 0) {
        local_11c = (uint)local_11c._2_2_ << 0x10;
      }
      else {
        if (((iVar16 != 3) && (iVar16 != 2)) && (iVar16 != 1)) {
          _MApi_VDEC_EX_ReturnCMABuffer(param_1);
          printf("Invalid sync type %d\n",*(undefined4 *)(param_2 + 0x44));
          return 0;
        }
        local_11c = (uint)CONCAT21(local_11c._2_2_,(char)iVar16) << 8;
      }
    }
    if (param_2[0x4c] != '\0') {
      local_128 = local_128 | 0x80;
    }
    local_124 = *(int *)(param_2 + 0x50);
    local_120 = *(undefined4 *)(param_2 + 0x54);
    if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 2) {
      local_11c = CONCAT31(local_11c._1_3_,2);
    }
    else {
      local_11c = (uint)local_11c._1_3_ << 8;
    }
    local_110 = CONCAT13(1,(undefined3)local_110);
    local_114 = CONCAT13(param_2[0x7c],CONCAT12(1,(undefined2)local_114));
    local_110 = CONCAT31(local_110._1_3_,1);
    uVar19 = local_110;
    if (local_50 != 0) {
      local_110._2_1_ = SUB41(uVar9,2);
      local_110._0_2_ = (undefined2)uVar19;
      local_110 = CONCAT13(1,CONCAT12(local_110._2_1_,(undefined2)local_110)) | 0x80000;
    }
    if (*(int *)(param_2 + 4) == 9) {
      local_14c = 0;
    }
    else if (*(int *)(param_2 + 4) == 10) {
      local_14c = 1;
    }
    local_14c = CONCAT22(*(undefined2 *)(param_2 + 0x78),(undefined2)local_14c);
    iVar16 = 0;
    pcVar6 = param_2 + 0x58;
    do {
      iVar10 = iVar16 + 4;
      iVar16 = iVar16 + 1;
      *(char *)((int)&local_14c + iVar10) = *pcVar6;
      pcVar6 = param_2 + 0x58 + iVar16;
    } while (iVar16 != 0x10);
    pcVar3 = param_2 + 0x68;
    pcVar6 = local_138;
    do {
      cVar17 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar6 = cVar17;
      pcVar6 = pcVar6 + 1;
    } while ((char *)&local_128 != pcVar6);
    local_164 = 0;
    local_168 = 0;
    iVar16 = MDrv_MMIO_GetBASE(&local_168,&local_164,0);
    if (iVar16 == 0) {
      _MApi_VDEC_EX_ReturnCMABuffer(param_1);
      puts("VDEC HVD Init Err: MMIO_GetBASE failure");
      return 0;
    }
    MDrv_HVD_EX_SetOSRegBase(local_168);
    MDrv_MVD_RegSetBase(local_168);
    iVar16 = MDrv_HVD_EX_Init(uVar28,&local_ec,&local_128,pVdecExContext[0x19198],
                              pVdecExContext[0x19199]);
    if (iVar16 == 1) {
      _VDEC_EX_Create_BBU_Task(*(undefined4 *)(param_1 + 4));
      if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 0) {
        local_154 = 16000000;
        local_15c = 0;
        local_160 = 0;
        local_158 = 0;
        MDrv_HVD_EX_SetDispInfoTH(uVar28,&local_160);
      }
      if (((param_2[0x7c] == '\0') ||
          (iVar16 = MDrv_HVD_EX_SetVirtualBox
                              (uVar28,*(undefined2 *)(param_2 + 0x84),
                               *(undefined2 *)(param_2 + 0x88)), iVar16 == 1)) &&
         (iVar16 = MDrv_HVD_EX_SetDispErrFrm(uVar28,param_2[0x7d]), iVar16 == 1)) {
        iVar16 = MDrv_HVD_EX_SetErrConceal(uVar28,param_2[0x7e] == '\0');
        if (iVar16 == 1) goto LAB_2d656260;
        goto LAB_2d6561e8;
      }
    }
  }
  else if (iVar10 == 0) {
    MVD_RecordStreamId(uVar28);
    local_3c = uVar26 * 0x10;
    local_38 = uVar26 * 0x40;
    if (pVdecExContext[uVar26 * 0x50 + 0x18c99] != '\0') {
      MDrv_MVD_HWBuffer_ReMappingMode(uVar28);
    }
    local_5c = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0x1138);
    uVar24 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1140);
    uVar23 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x113c);
    uVar22 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1134);
    uVar21 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1130);
    uVar20 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x112c);
    uVar19 = *(uint *)(pVdecExContext + uVar26 * 0x11ac + 0x1128);
    uVar18 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1124);
    uVar4 = *(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0x1120);
    iVar16 = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0x111c);
    uVar9 = *(uint *)(pVdecExContext + uVar26 * 0x11ac + 0x1150);
    switch(*(undefined4 *)(pVdecExContext + uVar26 * 0x11ac + 0xc)) {
    default:
      goto LAB_2d6561e4;
    case 1:
      iVar10 = 0x10;
      break;
    case 2:
      iVar10 = 1;
      break;
    case 3:
    case 5:
      iVar10 = 0;
      break;
    case 4:
      iVar10 = 2;
      break;
    case 6:
      iVar10 = 3;
      break;
    case 7:
      iVar10 = 4;
      break;
    case 8:
      iVar10 = 5;
    }
    if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 1) {
      iVar8 = 4;
    }
    else {
      iVar8 = 2;
      if (*(int *)(pVdecExContext + uVar26 * 0x11ac + 0x14) == 2) {
        iVar8 = 3;
      }
    }
    pcVar6 = (char *)&local_14c;
    do {
      *pcVar6 = '\0';
      pcVar6 = pcVar6 + 1;
    } while (local_138 + 0xc != pcVar6);
    puVar5 = &local_ec;
    do {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while (&local_a0 != puVar5);
    local_140 = *(undefined4 *)(param_2 + 0x8c);
    uStack_4c = (uint)*(byte *)((int)&bMvdParserDisable + iVar8);
    local_13c = *(undefined4 *)(param_2 + 0x90);
    local_a4 = CONCAT31(local_a4._1_3_,param_2[0x7c]);
    local_144 = CONCAT31(CONCAT21(local_144._2_2_,(char)local_50),
                         *(byte *)((int)&bMvdParserDisable + iVar8));
    local_164 = 0;
    local_14c = iVar10;
    local_148 = iVar8;
    local_ec = uVar9;
    local_e4 = iVar16;
    local_e0 = uVar4;
    local_dc = uVar18;
    local_d8 = uVar19;
    local_d4 = uVar20;
    uStack_d0 = uVar21;
    local_cc = uVar22;
    local_c8 = local_5c;
    local_c4 = uVar23;
    local_c0 = uVar24;
    iVar16 = MDrv_MMIO_GetBASE(&local_164,&local_168,0x10f);
    if (iVar16 == 0) {
      _MApi_VDEC_EX_ReturnCMABuffer(param_1);
      puts("_MVD_Init: IOMap failure");
      return 0;
    }
    MDrv_HVD_EX_SetOSRegBase(local_164);
    MDrv_MVD_RegSetBase(local_164);
    iVar16 = MDrv_MVD_SetCfg(uVar28,&local_14c,&local_ec);
    if ((iVar16 == 1) && (iVar16 = MDrv_MVD_Init(uVar28,local_14c), iVar16 != 0)) {
      MDrv_MVD_SetCodecInfo(uVar28,iVar10,iVar8,uStack_4c);
      if (iVar8 == 4) {
        MDrv_MVD_SetUnderflowTH(uVar28,(uint)(local_5c * 0xf) >> 4 & 0xfffffff8);
        MDrv_MVD_SetOverflowTH(uVar28,local_5c - 0x4000U & 0xfffffff8);
      }
      iVar16 = MDrv_MVD_DropErrorFrame(uVar28,param_2[0x7d] == '\0');
      if (iVar16 != 0) {
        pVdecExContext[uVar26 + 0x17394] = param_2[0x7d] == '\0';
        iVar16 = MDrv_MVD_DispRepeatField(uVar28,param_2[0x7f]);
        if (iVar16 != 0) {
          MDrv_MVD_DisableErrConceal(uVar28,param_2[0x7e] == '\0');
          MDrv_MVD_SetVirtualBox
                    (uVar28,*(undefined2 *)(param_2 + 0x84),*(undefined2 *)(param_2 + 0x88));
          if (iVar8 == 3) {
            iVar16 = *(int *)(param_2 + 0x44);
            if (iVar16 == 2) {
              uVar4 = 2;
            }
            else if (iVar16 == 1) {
              uVar4 = 1;
            }
            else if (iVar16 == 5) {
              uVar4 = 5;
            }
            else {
              uVar4 = 4;
              if (((iVar16 != 4) && (uVar4 = 6, iVar16 != 3)) && (uVar4 = 0, iVar16 != 0)) {
                _MApi_VDEC_EX_ReturnCMABuffer(param_1,0);
                printf("Invalid sync type %d for MVD\n",*(undefined4 *)(param_2 + 0x44));
                return 0;
              }
            }
            iVar16 = MDrv_MVD_SetFileModeAVSync(uVar28,uVar4);
            if (iVar16 == 0) goto LAB_2d6561e4;
code_r0x2d657130:
            iVar16 = *(int *)(pVdecExContext + uVar26 * 0x11ac + 0xc);
            if (iVar16 == 4) {
              MDrv_MVD_SetDivXCfg(uVar28,0,0);
            }
            else if (iVar16 == 5) {
              MDrv_MVD_SetDivXCfg(uVar28,0x11,1);
            }
            else if (iVar16 == 3) {
              MDrv_MVD_SetDivXCfg(uVar28,1,1);
            }
            if (iVar10 == 2) {
              puVar5 = &local_128;
              do {
                *(undefined1 *)puVar5 = 0;
                puVar5 = (uint *)((int)puVar5 + 1);
              } while (&local_f4 != puVar5);
              iVar16 = *(int *)(param_2 + 0x54);
              local_128 = CONCAT22(*(undefined2 *)(param_2 + 0x68),*(undefined2 *)(param_2 + 0x58));
              if (iVar16 == 0) {
                pcVar6 = "Invalid FrameRate base!";
code_r0x2d657270:
                puts(pcVar6);
                iVar16 = 1;
                param_2[0x54] = '\x01';
                param_2[0x55] = '\0';
                param_2[0x56] = '\0';
                param_2[0x57] = '\0';
              }
code_r0x2d6571ac:
              local_124 = FUN_2d6628b0((int)((ulonglong)*(uint *)(param_2 + 0x50) * 1000),
                                       (int)((ulonglong)*(uint *)(param_2 + 0x50) * 1000 >> 0x20),
                                       iVar16,0);
              MDrv_MVD_SetFrameInfo(uVar28,&local_128);
            }
            else {
              puVar5 = &local_128;
              if (iVar10 != 0x10) {
                do {
                  *(undefined1 *)puVar5 = 0;
                  puVar5 = (uint *)((int)puVar5 + 1);
                } while (&local_f4 != puVar5);
                iVar16 = *(int *)(param_2 + 0x54);
                if (iVar16 == 0) {
                  pcVar6 = "Invalid FrameRate base";
                  goto code_r0x2d657270;
                }
                goto code_r0x2d6571ac;
              }
            }
            iVar16 = MDrv_MVD_SkipToIFrame(uVar28);
            if (iVar16 != 1) goto LAB_2d6561e8;
          }
          else if (iVar8 - 3U < 2) goto code_r0x2d657130;
          iVar16 = local_3c + local_38;
          if (pVdecExContext[iVar16 + 0x18cb0] == '\x01') {
            MDrv_MVD_SetDynmcDispPath
                      (uVar28,pVdecExContext[iVar16 + 0x18cb4],
                       *(undefined4 *)(pVdecExContext + iVar16 + 0x18cb8),1);
          }
LAB_2d656260:
          iVar16 = uVar26 * 0x11ac;
          pVdecExContext[uVar26 + 0x11b04] = '\0';
          pVdecExContext[iVar16 + 5] = '\x01';
          pVdecExContext[iVar16 + 4] = '\x01';
          *(uint *)(pVdecExContext + iVar16 + 0x11ac) = uVar28;
          pVdecExContext[uVar26 + 0x17604] = '\x01';
          pVdecExContext[uVar26 + 0x175f4] = '\x01';
          return 1;
        }
      }
    }
  }
  else {
    if (iVar10 != 2) {
      if (*(int *)(pVdecExContext + iVar16 + 8) != 0) {
        printf("VDEC_EX Err(%d): Decoder is not supported!!\n",0x510e);
      }
      _MApi_VDEC_EX_ReturnCMABuffer(param_1);
      return 2;
    }
    MsOS_ObtainMutex(s32VDECMutexID,0xffffff00);
    local_128 = *(uint *)(pVdecExContext + iVar16 + 0x111c);
    local_f8 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1150);
    local_104 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1140);
    local_108 = *(char **)(pVdecExContext + iVar16 + 0x113c);
    local_10c = *(undefined4 *)(pVdecExContext + iVar16 + 0x1130);
    local_110 = *(uint *)(pVdecExContext + iVar16 + 0x112c);
    local_114 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1138);
    local_118 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1134);
    local_11c = *(int *)(pVdecExContext + iVar16 + 0x1128);
    uVar4 = *(undefined4 *)(pVdecExContext + iVar16 + 0x1124);
    local_124 = *(int *)(pVdecExContext + iVar16 + 0x1120);
    puVar5 = &local_128;
    do {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while (&local_ec != puVar5);
    local_fc = *(undefined4 *)(param_2 + 0x54);
    local_f0 = (uint)*(ushort *)(param_2 + 0x68);
    local_100 = *(undefined4 *)(param_2 + 0x50);
    local_f4 = (uint)*(ushort *)(param_2 + 0x58);
    local_120 = uVar4;
    MApi_MJPEG_EnableTurboFWMode(local_50);
    local_168 = 0;
    local_164 = 0;
    iVar16 = MDrv_MMIO_GetBASE(&local_164,&local_168,0);
    if (iVar16 != 0) {
      MDrv_HVD_EX_SetOSRegBase(local_164);
      MDrv_MVD_RegSetBase(local_164);
      MDrv_HVD_EX_SetCtrlsBase(uVar28);
      uVar4 = MsOS_PA2KSEG1(uVar4);
      MDrv_HVD_EX_MJPEG_InitSharemem
                (uVar28,uVar4,pVdecExContext[uVar26 * 0x50 + 0x18cb0],
                 pVdecExContext[uVar26 * 0x50 + 0x18cb4],
                 *(undefined4 *)(pVdecExContext + uVar26 * 0x50 + 0x18cb8));
      iVar16 = MApi_MJPEG_Init(uVar28,&local_128,pVdecExContext[0x19198]);
      if (iVar16 != 1) {
        MsOS_ReleaseMutex(*local_34);
        _MApi_VDEC_EX_ReturnCMABuffer(param_1);
        return 0;
      }
      MDrv_HVD_EX_SetBurstMode(uVar28,1);
      MsOS_ReleaseMutex(*local_34);
      goto LAB_2d656260;
    }
    puts("VDEC MJPEG Init Err: MMIO_GetBASE failure");
    MsOS_ReleaseMutex(*local_34);
  }
LAB_2d6561e4:
LAB_2d6561e8:
  _MApi_VDEC_EX_ReturnCMABuffer(param_1);
  return 0;
}

