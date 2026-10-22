
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DirectFBCreate(undefined4 *param_1)

{
  int iVar1;
  int *__ptr;
  __pid_t _Var2;
  void *__ptr_00;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  pthread_t pStack_34;
  int local_30;
  int *local_2c [2];
  
  if (((*_DAT_2f12a230 & 0x20) == 0) && (cRam2df20c16 != '\0')) {
    direct_messages_once("DirectFBCreate","directfb.c",599,&UNK_2defbf6c,"DirectFBCreate start");
    cRam2df20c16 = '\0';
  }
  dfb_boot_getTime("DF_BOOT_DIRECTFBCREATE",3,0,0);
  local_38 = 0;
  pthread_mutex_lock((pthread_mutex_t *)lock_initialize_mutex);
  if (dfb_config == 0) {
    direct_log_printf(0,"(!) DirectFBCreate: DirectFBInit has to be called before DirectFBCreate!\n"
                     );
    *param_1 = 0;
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return 2;
  }
  if (param_1 == (undefined4 *)0x0) {
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return 9;
  }
  if (idirectfb_singleton != (int *)0x0) {
    (*(code *)idirectfb_singleton[2])();
    *param_1 = idirectfb_singleton;
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return 0;
  }
  dfb_boot_getTime("DF_BOOT_CONFIG_SET",4,0,1);
  if (((*(char *)(dfb_config + 0x7d4) == '\0') && (*(char *)(dfb_config + 0x8bf) == '\0')) &&
     (iVar4 = dfb_dodfbinfo_setdfbrccfg(), iVar4 == 0)) {
    puts(
        "Note:DFBCreate: DirectFBDoDFBInfo_SetDFBRcCfg fail! If you do not use SN, Please Ignore it "
        );
  }
  dfb_boot_getTime("DF_BOOT_CONFIG_SET",4,1,1);
  if (((*_DAT_2f12a230 & 0x20) == 0) && (cRam2df20c15 != '\0')) {
    direct_messages_once
              ("DirectFBCreate","directfb.c",0x297,&UNK_2defbf6c,
               "DirectFBDoDFBInfo_SetDFBRcCfg done");
    cRam2df20c15 = '\0';
  }
  dfb_boot_getTime("DF_BOOT_DIRECT_INIT",5,0,1);
  direct_initialize();
  dfb_boot_getTime("DF_BOOT_DIRECT_INIT",5,1,1);
  if (((*_DAT_2f12a230 & 0x20) == 0) && (cRam2df20c14 != '\0')) {
    direct_messages_once("DirectFBCreate","directfb.c",0x29f,&UNK_2defbf6c,"direct_initialize done")
    ;
    cRam2df20c14 = '\0';
  }
  if ((*_DAT_2f12a230 & 2) == 0) {
    dfb_check_gop_info();
  }
  if (((*_DAT_2f12a230 & 1) == 0) && (*(char *)(dfb_config + 0x1d) != '\0')) {
    direct_log_printf(0,
                      "\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~| DirectFB 1.4.2 |~~~~~~~~~~~~~~~~~~~~~~~~~~\n        (c) 2001-2009  The world wide DirectFB Open Source Community\n        (c) 2000-2004  Convergence (integrated media) GmbH\n      ----------------------------------------------------------------\n\n"
                     );
  }
  iVar4 = *(int *)(dfb_config + 0x80);
  if (iVar4 != 0) {
    uVar3 = *(undefined4 *)(dfb_config + 0x84);
    local_30 = 0;
    iVar1 = DirectGetInterface(&local_30,"IDirectFB","Requestor",0,0);
    if (((iVar1 == 0) && (iVar1 = (**(code **)(local_30 + 8))(local_2c), iVar1 == 0)) &&
       (iVar1 = (**(code **)(local_30 + 0x10))(local_2c[0],iVar4,uVar3), iVar1 == 0)) {
      idirectfb_singleton = local_2c[0];
      *param_1 = local_2c[0];
    }
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return iVar1;
  }
  dfb_boot_getTime("DF_BOOT_CORE_CREATE",6,0,1);
  iVar4 = dfb_core_create(&local_38);
  dfb_boot_getTime("DF_BOOT_CORE_CREATE",6,1,1);
  if (((*_DAT_2f12a230 & 0x20) == 0) && (cRam2df20c13 != '\0')) {
    direct_messages_once("DirectFBCreate","directfb.c",0x2be,&UNK_2defbf6c,"dfb_core_create done");
    cRam2df20c13 = '\0';
  }
  if (iVar4 != 0) {
    *param_1 = 0;
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return iVar4;
  }
  __ptr = calloc(1,0x98);
  if (__ptr == (int *)0x0) {
    iVar4 = 10;
    dfb_core_destroy(local_38,0);
LAB_2de42d48:
    *param_1 = 0;
    pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
    return iVar4;
  }
  __ptr[1] = 0xb15171d;
  dfb_boot_getTime("DF_BOOT_IDIRECTFB_CONSTRUCT",0x21,0,1);
  iVar4 = IDirectFB_Construct(__ptr,local_38);
  dfb_boot_getTime("DF_BOOT_IDIRECTFB_CONSTRUCT",0x21,1,1);
  if (((*_DAT_2f12a230 & 0x20) == 0) && (cRam2df20c12 != '\0')) {
    direct_messages_once
              ("DirectFBCreate","directfb.c",0x2d8,&UNK_2defbf6c,"IDirectFB_Construct done");
    cRam2df20c12 = '\0';
  }
  if (iVar4 != 0) {
    dfb_core_destroy(local_38,0);
    if ((void *)*__ptr != (void *)0x0) {
      free((void *)*__ptr);
      *__ptr = 0;
    }
    __ptr[1] = 0;
    free(__ptr);
    goto LAB_2de42d48;
  }
  iVar4 = dfb_core_is_master(local_38);
  if (iVar4 != 0) {
    if ((*(char *)(dfb_config + 0x7c5) == '\0') && (cRam2df23038 == '\0')) {
      iVar4 = pthread_create(&pStack_34,(pthread_attr_t *)0x0,(__start_routine *)&UNK_2de43078,
                             (void *)0x0);
      cRam2df23038 = '\x01';
      if ((iVar4 != 0) && (((*_DAT_2f12a230 & 0x20) == 0 && (cRam2df20c11 != '\0')))) {
        direct_messages_once
                  ("DirectFBCreate","directfb.c",0x2f3,"[DFB] Create DirectfbInitThread fail!\n");
        cRam2df20c11 = '\0';
      }
    }
    iVar4 = dfb_wm_post_init(local_38);
    if (iVar4 != 0) {
      if ((*_DAT_2f12a230 & 8) == 0) {
        direct_messages_derror(iVar4,"DirectFBCreate: Post initialization of WM failed!\n");
      }
      __ptr_00 = (void *)*__ptr;
      *param_1 = 0;
      if (__ptr_00 != (void *)0x0) {
        free(__ptr_00);
        *__ptr = 0;
      }
      __ptr[1] = 0;
      free(__ptr);
      goto LAB_2de42e8c;
    }
    dfb_core_activate(local_38);
  }
  idirectfb_singleton = __ptr;
  *param_1 = __ptr;
  dfb_boot_getTime("DF_BOOT_DIRECTFBCREATE",3,1,0);
  if (((*_DAT_2f12a230 & 0x20) == 0) && (_fdata != '\0')) {
    direct_messages_once("DirectFBCreate","directfb.c",0x30b,&UNK_2defbf6c,"DirectfbCreate done");
    _fdata = '\0';
  }
  dfb_boot_printTimeInfo();
  iVar4 = dfb_core_is_master(local_38);
  if ((((iVar4 != 0) && (*(char *)(dfb_config + 0x87f) != '\0')) &&
      (*(int *)(dfb_config + 0x894) != 0)) && (_Var2 = fork(), _Var2 == 0)) {
    printf("trigger %s\n",*(undefined4 *)(dfb_config + 0x894));
    iVar4 = execl(*(char **)(dfb_config + 0x894),(char *)0x0);
    if (iVar4 < 0) {
      puts(" ==> Error on execl !");
    }
  }
  iVar4 = 0;
  dfb_config_close_dump_settings_file();
LAB_2de42e8c:
  pthread_mutex_unlock((pthread_mutex_t *)lock_initialize_mutex);
  return iVar4;
}

