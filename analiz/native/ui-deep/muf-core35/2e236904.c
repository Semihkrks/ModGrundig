
/* MMainFrame::StartAnimation() */

void __thiscall MMainFrame::StartAnimation(MMainFrame *this)

{
  undefined1 uVar1;
  int iVar2;
  Container *this_00;
  MRegion *pMVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  MWidget *pMVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  _Rect *p_Var11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  void *local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  MRegion aMStack_50 [28];
  undefined1 local_34;
  vector *local_30;
  vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *local_2c;
  
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = (undefined4 *)0x0;
  local_68 = (undefined4 *)0x0;
  local_64 = (undefined4 *)0x0;
  if (*(short *)(this + 0x8a) < 0) {
    local_30 = (vector *)&local_78;
    local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
                    /* try { // try from 2e236fe0 to 2e23702f has its CatchHandler @ 2e237040 */
    MSystem::GetInstance();
    local_30 = (vector *)&local_78;
    local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
    iVar10 = MSystem::GetMWindowManager();
    if (*(uchar *)(iVar10 + 0xd8) != 0xff) {
      local_30 = (vector *)&local_78;
      local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
      SetFrameOpacity(this,*(uchar *)(iVar10 + 0xd8));
    }
  }
  local_30 = (vector *)&local_78;
  local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
                    /* try { // try from 2e236988 to 2e236a07 has its CatchHandler @ 2e237040 */
  RecursiveQueryAnimationWidget(this,*(Container **)(this + 0x38),(MRegion *)(this + 0x40),local_30)
  ;
  local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
  uVar14 = (local_74 - local_78 >> 2) * 0x38e38e39;
  if (uVar14 != 0) {
    local_2c = (vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)&local_6c;
    uVar9 = 0;
    do {
      iVar10 = local_74;
      local_54 = *(undefined4 *)(local_74 + -0x24);
      MRegion::MRegion(aMStack_50,(MRegion *)(local_74 + -0x20));
      puVar6 = local_68;
      local_34 = *(undefined1 *)(iVar10 + -4);
      if (local_68 == local_64) {
                    /* try { // try from 2e236aa0 to 2e236aa7 has its CatchHandler @ 2e236ab0 */
        std::vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>>::_M_insert_aux
                  (local_2c,local_68,&local_54);
      }
      else {
        if (local_68 != (undefined4 *)0x0) {
          *local_68 = local_54;
                    /* try { // try from 2e236a34 to 2e236a3b has its CatchHandler @ 2e237038 */
          MRegion::MRegion((MRegion *)(local_68 + 1),aMStack_50);
          *(undefined1 *)(puVar6 + 8) = local_34;
        }
        local_68 = local_68 + 9;
      }
                    /* try { // try from 2e236a64 to 2e236a6b has its CatchHandler @ 2e236ab0 */
      pMVar3 = (MRegion *)(local_74 + -0x20);
      local_74 = local_74 + -0x24;
      MRegion::~MRegion(pMVar3);
                    /* try { // try from 2e236a74 to 2e236a7b has its CatchHandler @ 2e237040 */
      MRegion::~MRegion(aMStack_50);
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar14);
  }
  uVar14 = ((int)local_68 - (int)local_6c >> 2) * 0x38e38e39;
  puVar6 = local_6c;
  if (uVar14 != 0) {
    uVar9 = 0;
    iVar10 = 0;
    do {
      pMVar7 = *(MWidget **)((int)puVar6 + iVar10);
      if (pMVar7 != (MWidget *)0x0) {
        pMVar7[0x224] = (MWidget)0x1;
        *(undefined1 *)(*(int *)(pMVar7 + 0x1e4) + 0x14) = 1;
                    /* try { // try from 2e236b64 to 2e236d2b has its CatchHandler @ 2e237040 */
        MWidget::SetFlag(pMVar7,0x10,0);
        MWidget::GetAbsRect(pMVar7,(_Rect *)(pMVar7 + 0x228));
        MWidget::CaptureSnapshot(pMVar7);
        puVar6 = local_6c;
      }
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 + 0x24;
    } while (uVar9 < uVar14);
  }
  this[0x8c] = (MMainFrame)0x1;
  if (local_68 != puVar6) {
    iVar10 = 1;
    uVar14 = 0x32;
    while( true ) {
      uVar9 = ((int)local_68 - (int)puVar6 >> 2) * 0x38e38e39;
      uVar13 = 0;
      if (uVar9 != 0) {
        iVar12 = 0;
        do {
          pMVar7 = *(MWidget **)((int)puVar6 + iVar12);
          *(undefined1 *)((undefined4 *)((int)puVar6 + iVar12) + 8) = 0;
          if (pMVar7 != (MWidget *)0x0) {
            MWidget::Invalidate(pMVar7);
            MWidget::ClearDFBSurface(pMVar7,(_Rect *)0x0);
            p_Var11 = (_Rect *)(pMVar7 + 0x228);
            MWidget::GetAbsRect(pMVar7,p_Var11);
            iVar2 = MWidget::QueryFlag(pMVar7,'\x02');
            if (iVar2 == 0) {
              piVar4 = *(int **)(pMVar7 + 0x1e4);
              if ((uint)piVar4[3] < uVar14) {
                MWidget::SetFlag(pMVar7,2,1);
                MWidget::GetAbsRect(pMVar7,p_Var11);
                MWidget::CaptureSnapshot(pMVar7);
                piVar4 = *(int **)(pMVar7 + 0x1e4);
              }
            }
            else {
              piVar4 = *(int **)(pMVar7 + 0x1e4);
            }
            puVar6 = local_6c;
            uVar1 = (**(code **)(*piVar4 + 8))(piVar4,iVar10,pMVar7 + 0x1f0,p_Var11,pMVar7 + 0x1c);
            *(undefined1 *)((int)puVar6 + iVar12 + 0x20) = uVar1;
            MWidget::Invalidate(pMVar7);
          }
          uVar13 = uVar13 + 1;
          iVar12 = iVar12 + 0x24;
          puVar6 = local_6c;
        } while (uVar13 < uVar9);
      }
      OnPaint(this,(void *)0x0,(void *)0x0);
      iVar12 = (int)local_68 - (int)local_6c >> 2;
      iVar2 = iVar12 * 0x38e38e39 + -1;
      puVar6 = local_6c;
      if (-1 < iVar2) {
        iVar12 = iVar12 * 4;
        do {
          iVar12 = iVar12 + -0x24;
          if ((char)((int *)((int)puVar6 + iVar12))[8] != '\0') {
            iVar5 = *(int *)((int)puVar6 + iVar12);
            if (iVar5 == 0) {
              local_60 = (void *)0x0;
              local_5c = 0;
              local_58 = 0;
            }
            else {
              this_00 = (Container *)__dynamic_cast(iVar5,&MWidget::typeinfo,&Container::typeinfo,0)
              ;
              local_60 = (void *)0x0;
              local_5c = 0;
              local_58 = 0;
              if (this_00 != (Container *)0x0) {
                    /* try { // try from 2e236dd0 to 2e236eff has its CatchHandler @ 2e236fa8 */
                Container::RecursiveTraverseChild(this_00,this_00,(vector *)&local_60);
              }
            }
            uVar9 = local_5c - (int)local_60 >> 2;
            if (uVar9 != 0) {
              uVar13 = 0;
              do {
                pMVar7 = *(MWidget **)(local_5c + -4);
                MWidget::RecreateDFBSurface(pMVar7);
                (**(code **)(*(int *)pMVar7 + 0x28))(pMVar7);
                uVar13 = uVar13 + 1;
                local_5c = local_5c + -4;
              } while (uVar13 < uVar9);
            }
            MWidget::FinalizeAnimation(*(MWidget **)((int)local_6c + iVar12),true);
            puVar6 = (undefined4 *)((int)local_6c + iVar12) + 9;
            if ((puVar6 != local_68) &&
               (iVar5 = ((int)local_68 - (int)puVar6 >> 2) * 0x38e38e39,
               puVar8 = (undefined4 *)((int)local_6c + iVar12), 0 < iVar5)) {
              while( true ) {
                *puVar8 = puVar8[9];
                MRegion::operator=((MRegion *)(puVar8 + 1),(MRegion *)(puVar8 + 10));
                iVar5 = iVar5 + -1;
                *(undefined1 *)(puVar8 + 8) = *(undefined1 *)(puVar8 + 0x11);
                if (iVar5 < 1) break;
                puVar8 = puVar6;
                puVar6 = puVar6 + 9;
              }
            }
            pMVar3 = (MRegion *)(local_68 + -8);
            local_68 = local_68 + -9;
            MRegion::~MRegion(pMVar3);
            puVar6 = local_6c;
            if (local_60 != (void *)0x0) {
              operator_delete(local_60);
              puVar6 = local_6c;
            }
          }
          iVar2 = iVar2 + -1;
        } while (-1 < iVar2);
      }
      uVar14 = uVar14 + 0x32;
      if (puVar6 == local_68) break;
      iVar10 = iVar10 + 1;
    }
  }
                    /* try { // try from 2e236f5c to 2e236f63 has its CatchHandler @ 2e236fc4 */
  this[0x8c] = (MMainFrame)0x0;
  std::vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>>::~vector(local_2c);
  std::vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>>::~vector
            ((vector<ST_INVWDG_DATUM,std::allocator<ST_INVWDG_DATUM>> *)local_30);
  return;
}

