
/* MSrv_MM_PlayerInterface::MM_Initialize(EN_MM_PLAYER_AP_TYPE) */

bool MSrv_MM_PlayerInterface::MM_Initialize(void)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  
  puVar4 = PTR_m_bMutexCreate_2f212ccc;
  if (*PTR_m_bMutexCreate_2f212ccc != '\0') {
    (*(code *)PTR_pthread_mutex_lock_tracker_2f212d58)
              (PTR_m_Mutex_2f212ca4,PTR_DAT_2f212c08 + 0x156c,0x244);
  }
  puVar5 = PTR_m_bInitialize_2f212e08;
  puVar3 = PTR_m_u32VideoItem_2f212cb0;
  if (*PTR_m_bInitialize_2f212e08 == '\x01') {
    cVar1 = *puVar4;
    bVar8 = false;
    *(int *)PTR_m_u32RefCount_2f212d20 = *(int *)PTR_m_u32RefCount_2f212d20 + 1;
    if (cVar1 != '\0') {
      (*(code *)PTR_pthread_mutex_unlock_tracker_2f212de0)(PTR_m_Mutex_2f212ca4);
    }
  }
  else {
    iVar7 = 0;
    *(undefined4 *)PTR_m_u32PhotoItem_2f212c68 = 0;
    *(undefined4 *)puVar3 = 0;
    puVar3 = PTR_m_u32AudioItem2_2f212d3c;
    *(undefined4 *)PTR_m_u32AudioItem_2f212e1c = 0;
    *(undefined4 *)puVar3 = 0;
    puVar3 = PTR_DAT_2f212bf8;
    do {
      puVar6 = (undefined4 *)(puVar3 + iVar7 * 0x18 + 12000);
      iVar2 = iVar7 + 0x2f40;
      iVar7 = iVar7 + 1;
      puVar6[5] = 0;
      puVar3[iVar2] = 0;
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
    } while (iVar7 != 4);
    iVar7 = (*(code *)PTR_MMSDK_Initialize_2f212d34)();
    (*(code *)PTR_MMSDK_DebugMSGLevel_2f212cb8)(3);
    puVar3 = PTR_m_u32RefCount_2f212d20;
    bVar8 = iVar7 == 0;
    if (bVar8) {
      (*(code *)PTR_MMSDK_Finalize_2f212e00)();
      puVar3 = PTR_m_u32RefCount_2f212d20;
      cVar1 = *puVar4;
      *puVar5 = 1;
      *(int *)puVar3 = *(int *)puVar3 + 1;
    }
    else {
      cVar1 = *puVar4;
      iVar7 = *(int *)PTR_m_u32RefCount_2f212d20;
      *puVar5 = 1;
      *(int *)puVar3 = iVar7 + 1;
    }
    if (cVar1 != '\0') {
      (*(code *)PTR_pthread_mutex_unlock_tracker_2f212de0)(PTR_m_Mutex_2f212ca4);
      return bVar8;
    }
  }
  return bVar8;
}

