
int sawman_initialize(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined1 auStack_f0 [116];
  int local_7c;
  undefined4 *local_30;
  
  iVar3 = (*(code *)PTR_fusion_call_init_0002c094)
                    (param_1 + 0x1f,PTR_DAT_0002c048 + -0x7a14,param_1,param_2);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = (*(code *)PTR_fusion_shm_pool_create_0002c198)
                    (param_2,PTR_DAT_0002c048 + -0x4934,0x100000,
                     *(undefined1 *)(*(int *)PTR_fusion_config_0002c18c + 0xc),param_1 + 0x1c);
  puVar14 = PTR_DAT_0002c038;
  puVar15 = PTR_DAT_0002c038;
  if (iVar3 == 0) {
    local_30 = param_1 + 2;
    (*(code *)PTR_fusion_skirmish_init_0002c108)(local_30,PTR_DAT_0002c048 + -0x4928,param_2);
    (*(code *)PTR_fusion_vector_init_0002c11c)(param_1 + 0x16,8,param_1[0x1c]);
    (*(code *)PTR_dfb_gfxcard_get_device_info_0002c0dc)(auStack_f0);
    if (local_7c << 0xe < 0) {
      param_1[0x24] = 1;
    }
    puVar14 = PTR_fusion_skirmish_prevail_0002c120;
    param_1[0x6c] = 0xffffffff;
    *param_1 = 0x4d39001e;
    param_1[0x30] = 0xffffffff;
    param_1[0x34] = 0xffffffff;
    param_1[0x38] = 0xffffffff;
    param_1[0x3c] = 0xffffffff;
    param_1[0x40] = 0xffffffff;
    param_1[0x44] = 0xffffffff;
    param_1[0x48] = 0xffffffff;
    param_1[0x4c] = 0xffffffff;
    param_1[0x50] = 0xffffffff;
    param_1[0x54] = 0xffffffff;
    param_1[0x58] = 0xffffffff;
    param_1[0x5c] = 0xffffffff;
    param_1[0x60] = 0xffffffff;
    param_1[100] = 0xffffffff;
    param_1[0x68] = 0xffffffff;
    (*(code *)puVar14)(local_30);
    puVar15 = PTR_dfb_config_0002c098;
    iVar4 = 0;
    do {
      uVar10 = *(uint *)(*(int *)puVar15 + iVar4 * 0x50 + 0xfc);
      if (uVar10 != 0) {
        iVar3 = param_1[0x1b];
        if (iVar3 == 0) {
LAB_00018418:
          puVar5 = (undefined4 *)
                   (*(code *)PTR_fusion_dbg_shcalloc_0002c10c)
                             (param_1[0x1c],PTR_DAT_0002c048 + -0x4a74,0x19d,
                              PTR_DAT_0002c048 + -0x4abc,1,0x17c);
          puVar14 = PTR_dfb_updates_init_0002c128;
          if (puVar5 != (undefined4 *)0x0) {
            puVar5[5] = uVar10;
            puVar5[4] = iVar4;
            (*(code *)puVar14)(puVar5 + 0x15,puVar5 + 0x1d,8);
            iVar3 = param_1[0x1b];
            puVar5[3] = 0x13283e35;
            puVar5[1] = 0;
            if (iVar3 == 0) {
              puVar5[2] = puVar5;
              param_1[0x1b] = puVar5;
            }
            else {
              iVar6 = *(int *)(iVar3 + 8);
              puVar5[2] = iVar6;
              *(undefined4 **)(iVar6 + 4) = puVar5;
              *(undefined4 **)(iVar3 + 8) = puVar5;
            }
            *puVar5 = 0x80b1b25;
            goto LAB_000184a0;
          }
          (*(code *)PTR_direct_messages_warn_0002c114)
                    (PTR_DAT_0002c048 + -0x4abc,PTR_DAT_0002c048 + -0x4a74,0x19f,
                     PTR_DAT_0002c048 + -0x4c84);
          iVar3 = 0xb;
        }
        else {
          uVar9 = *(uint *)(iVar3 + 0x14);
          if ((uVar9 & uVar10) == 0) {
            if (*(int *)(iVar3 + 0x10) != iVar4) {
              while (iVar3 = *(int *)(iVar3 + 4), iVar3 != 0) {
                uVar9 = *(uint *)(iVar3 + 0x14);
                if ((uVar9 & uVar10) != 0) goto LAB_00018508;
                if (*(int *)(iVar3 + 0x10) == iVar4) {
                  puVar8 = *(uint **)PTR_direct_config_0002c0f4;
                  goto LAB_0001852c;
                }
              }
              goto LAB_00018418;
            }
            puVar8 = *(uint **)PTR_direct_config_0002c0f4;
            iVar4 = *(int *)(iVar3 + 0x10);
LAB_0001852c:
            if ((*puVar8 & 8) != 0) goto LAB_0001851c;
            iVar3 = 0x10;
            (*(code *)PTR_direct_messages_error_0002c184)(PTR_DAT_0002c048 + -0x48b8,iVar4);
          }
          else {
LAB_00018508:
            if ((**(uint **)PTR_direct_config_0002c0f4 & 8) == 0) {
              (*(code *)PTR_direct_messages_error_0002c184)
                        (PTR_DAT_0002c048 + -0x4920,iVar4,uVar10,*(undefined4 *)(iVar3 + 0x10),uVar9
                        );
              iVar3 = 0x10;
            }
            else {
LAB_0001851c:
              iVar3 = 0x10;
            }
          }
        }
        puVar15 = PTR_DAT_0002c038;
        (*(code *)PTR_fusion_skirmish_dismiss_0002c15c)(local_30);
        *param_1 = 0;
        puVar14 = PTR_DAT_0002c038;
        goto LAB_00018208;
      }
LAB_000184a0:
      puVar11 = PTR_0002c044;
      puVar14 = PTR_DAT_0002c038;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x10);
    *(undefined4 **)(PTR_DAT_0002c038 + -0x3dd0) = param_1;
    *(undefined4 *)(puVar14 + -0x3dc8) = param_2;
    iVar3 = (*(code *)(puVar11 + 0x7d4c))(param_1,1,param_2);
    if (iVar3 == 0) {
      (*(code *)PTR_fusion_skirmish_dismiss_0002c15c)(local_30);
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      *param_3 = *(undefined4 *)(PTR_DAT_0002c038 + -0x3dcc);
      return 0;
    }
    (*(code *)PTR_fusion_skirmish_dismiss_0002c15c)(local_30);
    *param_1 = 0;
    puVar15 = puVar14;
  }
LAB_00018208:
  iVar4 = param_1[0x1b];
  if (iVar4 != 0) {
    puVar13 = PTR_DAT_0002c048 + -0x4870;
    puVar12 = PTR_DAT_0002c048 + -0x4a74;
    puVar11 = PTR_DAT_0002c048 + -0x4ad0;
    iVar6 = *(int *)(iVar4 + 4);
    while (iVar1 = iVar6, puVar2 = PTR_fusion_dbg_shfree_0002c1dc, iVar4 != 0) {
      uVar7 = param_1[0x1c];
      *(undefined4 *)(iVar4 + 0xc) = 0;
      (*(code *)puVar2)(uVar7,puVar12,0x1ff,puVar11,puVar13,iVar4);
      if (iVar1 == 0) break;
      iVar6 = *(int *)(iVar1 + 4);
      iVar4 = iVar1;
    }
  }
  (*(code *)PTR_fusion_call_destroy_0002c064)(param_1 + 0x1f);
  *(undefined4 *)(puVar15 + -0x3dd0) = 0;
  puVar15 = PTR_DAT_0002c038;
  *(undefined4 *)(puVar14 + -0x3dc8) = 0;
  *(undefined4 *)(puVar15 + -0x3dcc) = 0;
  return iVar3;
}

