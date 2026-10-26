
/* ArTvSettingsManager::CheckUSBUpdate() */

undefined4 ArTvSettingsManager::CheckUSBUpdate(void)

{
  bool bVar1;
  vector *pvVar2;
  int iVar3;
  size_t sVar4;
  FILE *__stream;
  int *piVar5;
  undefined3 extraout_var;
  __normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>> a_Stack_bc [4];
  __normal_iterator a_Stack_b8 [4];
  vector<DISK_INFO,std::allocator<DISK_INFO>> avStack_b4 [12];
  undefined4 uStack_a8;
  char acStack_a4 [132];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  MSrv_MountNotifier::GetInstance();
  pvVar2 = (vector *)MSrv_MountNotifier::GetMountedList();
  std::vector<DISK_INFO,std::allocator<DISK_INFO>>::vector(avStack_b4,pvVar2);
  __gnu_cxx::__normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>::
  __normal_iterator((__normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>
                     *)&uStack_a8);
  iVar3 = std::vector<DISK_INFO,std::allocator<DISK_INFO>>::size(avStack_b4);
  if (iVar3 == 0) {
                    /* try { // try from 005433b8 to 0054368b has its CatchHandler @ 005436a0 */
    puts("NO USB DEVICE CONNECTED.");
    uStack_1c = 0;
  }
  else {
    std::vector<DISK_INFO,std::allocator<DISK_INFO>>::begin();
    uStack_a8 = uStack_20;
    while( true ) {
      std::vector<DISK_INFO,std::allocator<DISK_INFO>>::end();
      bVar1 = __gnu_cxx::operator!=((__normal_iterator *)&uStack_a8,a_Stack_b8);
      if (CONCAT31(extraout_var,bVar1) == 0) break;
      iVar3 = __gnu_cxx::
              __normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>::
              operator->((__normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>
                          *)&uStack_a8);
      if (*(int *)(iVar3 + 0x58) != 6) {
        iVar3 = __gnu_cxx::
                __normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>::
                operator->((__normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>
                            *)&uStack_a8);
        strcpy(acStack_a4,(char *)(iVar3 + 0x48));
        sVar4 = strlen(acStack_a4);
        memcpy(acStack_a4 + sVar4,&UNK_00fe67bc,0x20);
        __stream = fopen(acStack_a4,"rb");
        if (__stream != (FILE *)0x0) {
          puts("TARGET IMAGE FOUND ON USB.");
          fclose(__stream);
          piVar5 = (int *)IEnvManager::Instance();
          if (piVar5 == (int *)0x0) {
            puts("CANNOT SAVE upgrade_mode ENV VAR.");
            uStack_1c = 2;
          }
          else {
            (**(code **)(*piVar5 + 0x1c))(piVar5,&UNK_00fe67fc,&UNK_00fe680c);
            (**(code **)(*piVar5 + 0x1c))(piVar5,&UNK_00fe6810,&UNK_00fe679c);
            (**(code **)(*piVar5 + 0x1c))(piVar5,&UNK_00fe6740,&UNK_00fe679c);
            (**(code **)(*piVar5 + 0xc))(piVar5);
            uStack_1c = 3;
          }
          goto LAB_005436e4;
        }
      }
      __gnu_cxx::__normal_iterator<DISK_INFO*,std::vector<DISK_INFO,std::allocator<DISK_INFO>>>::
      operator++(a_Stack_bc,(int)&uStack_a8);
    }
    puts("NO TARGET IMAGE FOUND ON USB DISKS.");
    uStack_1c = 1;
  }
LAB_005436e4:
  std::vector<DISK_INFO,std::allocator<DISK_INFO>>::~vector(avStack_b4);
  return uStack_1c;
}

