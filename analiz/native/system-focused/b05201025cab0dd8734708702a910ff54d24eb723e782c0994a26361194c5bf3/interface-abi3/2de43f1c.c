
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int IDirectFB_Construct(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_b8;
  uint local_b4;
  int local_b0;
  int *local_ac;
  int *local_a8;
  undefined1 auStack_a4 [4];
  uint local_a0;
  uint local_90 [3];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  uint *local_34;
  int **local_30;
  
  puVar8 = (undefined4 *)*param_1;
  if (puVar8 == (undefined4 *)0x0) {
    puVar8 = calloc(1,0x18c);
    *param_1 = puVar8;
  }
  *puVar8 = 1;
  puVar8[1] = param_2;
  puVar8[2] = 0;
  iVar1 = dfb_layer_num();
  if (iVar1 < 1) {
    iVar6 = 5;
    if ((*_DAT_2f12a230 & 8) == 0) {
      direct_messages_error("%s: No layers available! Missing driver?\n","IDirectFB_Construct");
      return 5;
    }
  }
  else {
    uVar2 = dfb_layer_at_translated(0);
    puVar8[3] = uVar2;
    dfb_boot_getTime("DF_BOOT_LAYER_GET_PRIMARY_CONTEXT",0x22,0,2);
    iVar1 = dfb_layer_get_primary_context(puVar8[3],1,puVar8 + 4);
    dfb_boot_getTime("DF_BOOT_LAYER_GET_PRIMARY_CONTEXT",0x22,1,2);
    if (iVar1 != 0) {
      if ((*_DAT_2f12a230 & 8) == 0) {
        direct_messages_error
                  ("%s: Could not get default context of primary layer!\n","IDirectFB_Construct");
      }
LAB_2de440b0:
      if ((void *)*param_1 != (void *)0x0) {
        free((void *)*param_1);
        *param_1 = 0;
      }
      param_1[1] = 0;
      free(param_1);
      return iVar1;
    }
    dfb_boot_getTime("DF_BOOT_LAYER_CONTEXT_WINDOWSTACK",0x23,0,2);
    iVar6 = 0;
    uVar2 = dfb_layer_context_windowstack(puVar8[4]);
    puVar8[5] = uVar2;
    dfb_boot_getTime("DF_BOOT_LAYER_CONTEXT_WINDOWSTACK",0x23,1,2);
    param_1[2] = FUN_2de44d74;
    param_1[3] = FUN_2de4b79c;
    param_1[4] = &UNK_2de4ac84;
    param_1[6] = FUN_2de4aac4;
    param_1[7] = &UNK_2de4a77c;
    param_1[5] = &UNK_2de4a4fc;
    param_1[8] = FUN_2de4948c;
    param_1[9] = &UNK_2de49118;
    param_1[10] = &UNK_2de48ce0;
    param_1[0xb] = FUN_2de48ab8;
    param_1[0xc] = &UNK_2de48708;
    param_1[0xd] = FUN_2de483f0;
    param_1[0xe] = &UNK_2de47cd8;
    param_1[0xf] = &UNK_2de4800c;
    param_1[0x10] = &UNK_2de47844;
    param_1[0x11] = &UNK_2de47a54;
    param_1[0x12] = &UNK_2de47608;
    param_1[0x13] = &UNK_2de473cc;
    param_1[0x14] = &UNK_2de470dc;
    param_1[0x15] = &UNK_2de46df4;
    param_1[0x16] = &UNK_2de46bd0;
    param_1[0x17] = &UNK_2de469c4;
    param_1[0x18] = &UNK_2de467d0;
    param_1[0x19] = &UNK_2de4660c;
    param_1[0x1a] = &UNK_2de46448;
    param_1[0x1b] = &UNK_2de46288;
    param_1[0x1c] = &UNK_2de460c4;
    param_1[0x1d] = &UNK_2de45e14;
    param_1[0x1e] = &UNK_2de45c28;
    param_1[0x1f] = &UNK_2de45a3c;
    param_1[0x20] = &UNK_2de45850;
    param_1[0x21] = &UNK_2de45644;
    param_1[0x22] = &UNK_2de45480;
    param_1[0x23] = &UNK_2de452bc;
    param_1[0x24] = &UNK_2de450f8;
    param_1[0x25] = &UNK_2de44f34;
    iVar1 = dfb_core_is_master(param_2);
    if (iVar1 != 0) {
      dfb_boot_getTime("DF_BOOT_INITLAYERS",0x24,0,2);
      local_48 = dfb_layer_num();
      if (0 < local_48) {
        local_38 = &local_b8;
        local_34 = &local_b4;
        local_30 = &local_ac;
        iVar6 = 0;
        puVar9 = puVar8;
        local_50 = puVar8;
        do {
          local_44 = dfb_layer_at_translated(iVar6);
          iVar7 = dfb_config;
          iVar5 = dfb_config + iVar6 * 0x50;
          if (*(char *)(iVar5 + 0xbc) != '\0') {
            iVar1 = dfb_layer_get_primary_context(local_44,0,local_38);
            if (iVar1 == 0) {
              local_40 = dfb_layer_context_windowstack(local_b8);
              if ((*(uint *)(iVar5 + 0xc0) & 8) == 0) {
                dfb_gfxcard_get_capabilities(auStack_a4);
                uVar2 = 4;
                if ((local_a0 & 0x10000) != 0) {
                  uVar2 = 2;
                }
                *(uint *)(iVar5 + 0xc0) = *(uint *)(iVar5 + 0xc0) | 8;
                *(undefined4 *)(iVar7 + (iVar6 * 5 + 1) * 0x10 + 0xc0) = uVar2;
              }
              local_4c = iVar7 + iVar6 * 0x50 + 0xc0;
              iVar1 = dfb_layer_context_test_configuration(local_b8,local_4c,local_34);
              if (iVar1 != 0) {
                if ((local_b4 & 3) != 0) {
                  iVar1 = iVar7 + iVar6 * 0x50;
                  if ((*_DAT_2f12a230 & 8) == 0) {
                    direct_messages_error
                              ("DirectFB/DirectFBCreate: Setting desktop resolution to %dx%d failed!\n     -> Using default resolution.\n"
                               ,*(undefined4 *)(iVar1 + 0xc4),*(undefined4 *)(iVar1 + 200));
                  }
                  iVar1 = iVar7 + iVar6 * 0x50;
                  *(uint *)(iVar1 + 0xc0) = *(uint *)(iVar1 + 0xc0) & 0xfffffffc;
                }
                if ((local_b4 & 4) != 0) {
                  if ((*_DAT_2f12a230 & 8) == 0) {
                    direct_messages_error
                              (
                              "DirectFB/DirectFBCreate: Setting desktop format failed!\n     -> Using default format.\n"
                              );
                  }
                  iVar1 = iVar7 + iVar6 * 0x50;
                  *(uint *)(iVar1 + 0xc0) = *(uint *)(iVar1 + 0xc0) & 0xfffffffb;
                }
                if ((local_b4 & 8) != 0) {
                  if ((*_DAT_2f12a230 & 8) == 0) {
                    direct_messages_error
                              (
                              "DirectFB/DirectFBCreate: Setting desktop buffer mode failed!\n     -> No virtual resolution support or not enough memory?\n        Falling back to system back buffer.\n"
                              );
                  }
                  *(undefined4 *)(iVar7 + (iVar6 * 5 + 1) * 0x10 + 0xc0) = 4;
                  iVar1 = dfb_layer_context_test_configuration(local_b8,local_4c,local_34);
                  if (iVar1 != 0) {
                    if ((*_DAT_2f12a230 & 8) == 0) {
                      direct_messages_error
                                (
                                "DirectFB/DirectFBCreate: Setting system memory desktop back buffer failed!\n     -> Using front buffer only mode.\n"
                                );
                    }
                    iVar1 = iVar7 + iVar6 * 0x50;
                    *(uint *)(iVar1 + 0xc0) = *(uint *)(iVar1 + 0xc0) & 0xfffffff7;
                  }
                }
              }
              if (*(int *)(iVar7 + iVar6 * 0x50 + 0xc0) == 0) {
LAB_2de445bc:
                local_3c = iVar6 << 2;
                dfb_layer_context_get_configuration(local_b8,local_4c);
                iVar5 = local_3c + iVar6 * 0x10;
                iVar1 = dfb_layer_context_get_primary_region(local_b8,1,(int)puVar8 + iVar5 + 0x54);
                if (iVar1 == 0) {
                  iVar1 = dfb_layer_region_get_surface(puVar9[0x15],(int)puVar8 + iVar5 + 0x58);
                  if (iVar1 == 0) {
                    iVar1 = iVar7 + iVar6 * 0x50;
                    if (*(char *)(iVar1 + 0x104) != '\0') {
                      uVar2 = puVar9[0x16];
                      iVar5 = dfb_palette_create(puVar8[1],0x100,&local_b0);
                      if (iVar5 == 0) {
                        (*_DAT_2f12a330)(*(undefined4 *)(local_b0 + 0xb0),
                                         *(undefined4 *)(iVar1 + 0x100),0x400);
                        iVar1 = dfb_surface_set_palette(uVar2,local_b0);
                        if (iVar1 == 0) {
                          puVar9[0x17] = local_b0;
                        }
                        else {
                          if ((*_DAT_2f12a230 & 8) == 0) {
                            direct_messages_derror
                                      (iVar1,"InitLayerPalette: Could not set palette!\n");
                          }
                          fusion_ref_down(local_b0 + 0x20,0);
                        }
                      }
                      else if ((*_DAT_2f12a230 & 8) == 0) {
                        direct_messages_derror
                                  (iVar5,"InitLayerPalette: Could not create palette!\n");
                      }
                    }
                    iVar1 = iVar7 + iVar6 * 0x50;
                    if (*(int *)(iVar1 + 0xe8) == 0) {
                      iVar1 = *(int *)(iVar1 + 0x100);
                      dfb_layer_context_set_src_colorkey
                                (local_b8,*(undefined1 *)(iVar1 + 1),*(undefined1 *)(iVar1 + 2),
                                 *(undefined1 *)(iVar1 + 3),0);
                    }
                    else {
                      dfb_layer_context_set_src_colorkey
                                (local_b8,*(undefined1 *)(iVar1 + 0xe5),
                                 *(undefined1 *)(iVar1 + 0xe6),*(undefined1 *)(iVar1 + 0xe7),
                                 0xffffffff);
                    }
                    iVar1 = iVar7 + iVar6 * 0x50;
                    uVar4 = *(uint *)(iVar1 + 0xec);
                    if (uVar4 == 1) {
                      dfb_windowstack_set_background_color(local_40,iVar7 + iVar6 * 0x50 + 0xf0);
                      dfb_windowstack_set_background_color_index
                                (local_40,*(undefined4 *)(iVar1 + 0xf4));
                      uVar4 = *(uint *)(iVar1 + 0xec);
                    }
                    else if ((uVar4 != 0) && (uVar4 < 4)) {
                      iVar5 = (*(code *)param_1[0x12])
                                        (param_1,*(undefined4 *)(iVar1 + 0xf8),local_30);
                      if (iVar5 == 0) {
                        if (*(int *)(iVar1 + 0xec) == 2) {
                          local_90[2] = *(undefined4 *)(iVar1 + 0xc4);
                          local_90[0] = 6;
                          local_84 = *(undefined4 *)(iVar1 + 200);
                        }
                        else {
                          (*(code *)local_ac[4])(local_ac,local_90);
                        }
                        iVar7 = iVar7 + iVar6 * 0x50;
                        local_80 = *(undefined4 *)(iVar7 + 0xcc);
                        local_90[0] = local_90[0] | 9;
                        local_90[1] = 0x100000;
                        iVar1 = (*(code *)param_1[8])(param_1,local_90,&local_a8);
                        if (iVar1 == 0) {
                          iVar1 = (*(code *)local_ac[6])(local_ac,local_a8,0);
                          if (iVar1 == 0) {
                            (*(code *)local_ac[3])();
                            dfb_windowstack_set_background_image
                                      (local_40,*(undefined4 *)(*local_a8 + 0x68));
                            piVar3 = local_a8;
                          }
                          else {
                            DirectFBError("Failed loading background image",iVar1);
                            (*(code *)local_a8[3])();
                            piVar3 = local_ac;
                          }
                        }
                        else {
                          DirectFBError("Failed creating surface for background image",iVar1);
                          piVar3 = local_ac;
                        }
                        (*(code *)piVar3[3])();
                        uVar4 = *(uint *)(iVar7 + 0xec);
                      }
                      else {
                        if ((*_DAT_2f12a230 & 8) == 0) {
                          direct_messages_derror
                                    (iVar5,"Failed loading background image \'%s\'!\n",
                                     *(undefined4 *)(iVar1 + 0xf8));
                        }
                        uVar4 = *(uint *)(iVar1 + 0xec);
                      }
                    }
                    dfb_windowstack_set_background_mode(local_40,uVar4);
                    dfb_layer_set_level(local_44,0);
                    puVar9[0x14] = local_b8;
                    goto LAB_2de443ac;
                  }
                  if ((*_DAT_2f12a230 & 8) == 0) {
                    direct_messages_derror
                              (iVar1,
                               "InitLayers: Could not get surface of primary region of layer %d!\n",
                               iVar6);
                  }
                  fusion_ref_down(*(int *)((int)puVar8 + local_3c + iVar6 * 0x10 + 0x54) + 0x20,0);
                }
                else if ((*_DAT_2f12a230 & 8) == 0) {
                  direct_messages_derror
                            (iVar1,"InitLayers: Could not get primary region of layer %d!\n",iVar6);
                }
              }
              else {
                dfb_layer_set_level(local_44,0xffffffff);
                iVar1 = dfb_layer_context_set_configuration(local_b8,local_4c);
                if (iVar1 == 0) goto LAB_2de445bc;
                if ((*_DAT_2f12a230 & 8) == 0) {
                  direct_messages_derror
                            (iVar1,"InitLayers: Could not set configuration for layer %d!\n",iVar6);
                }
              }
              fusion_ref_down(local_b8 + 0x20,0);
            }
            else if ((*_DAT_2f12a230 & 8) == 0) {
              direct_messages_derror(iVar1,"InitLayers: Could not get context of layer %d!\n",iVar6)
              ;
            }
            iVar6 = 0;
            piVar3 = puVar8 + (local_48 + -1) * 5 + 0x14;
            do {
              iVar6 = iVar6 + 1;
              if (*piVar3 != 0) {
                if (piVar3[3] != 0) {
                  fusion_ref_down(piVar3[3] + 0x20,0);
                }
                fusion_ref_down(piVar3[2] + 0x20,0);
                fusion_ref_down(piVar3[1] + 0x20,0);
                fusion_ref_down(*piVar3 + 0x20,0);
                *piVar3 = 0;
              }
              piVar3 = piVar3 + -5;
            } while (iVar6 != local_48);
            dfb_boot_getTime("DF_BOOT_INITLAYERS",0x24,1,2);
            fusion_ref_down(puVar8[4] + 0x20,0);
            goto LAB_2de440b0;
          }
LAB_2de443ac:
          iVar6 = iVar6 + 1;
          puVar9[0x13] = local_44;
          puVar9 = puVar9 + 5;
        } while (iVar6 < local_48);
        iVar1 = 0;
        do {
          iVar1 = iVar1 + 1;
          if (local_50[0x14] != 0) {
            dfb_layer_activate_context(local_50[0x13],local_50[0x14]);
          }
          local_50 = local_50 + 5;
        } while (iVar1 < local_48);
      }
      dfb_boot_getTime("DF_BOOT_INITLAYERS",0x24,1,2);
      iVar6 = 0;
    }
  }
  return iVar6;
}

