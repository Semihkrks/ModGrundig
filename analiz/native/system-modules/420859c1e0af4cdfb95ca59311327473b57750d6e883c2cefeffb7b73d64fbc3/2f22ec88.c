
/* MSrv_System_Database_DVB_Customer::Init() */

void __thiscall MSrv_System_Database_DVB_Customer::Init(MSrv_System_Database_DVB_Customer *this)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  undefined1 auStack_18 [8];
  
  (*(code *)PTR_puts_2f242158)(PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x6b0);
  piVar1 = (int *)(*(code *)PTR_GetInstance_2f242684)();
  piVar2 = (int *)(**(code **)(*piVar1 + 0x34))(piVar1);
  this[0x5c] = (MSrv_System_Database_DVB_Customer)0x0;
  iVar4 = 0;
  piVar1 = piVar2;
  do {
    if (*piVar1 != 0) {
      this[0x5c] = (MSrv_System_Database_DVB_Customer)((char)this[0x5c] + '\x01');
    }
    iVar4 = iVar4 + 0xc;
    piVar1 = (int *)((int)piVar2 + iVar4);
  } while (iVar4 != 0x1f8);
  (*(code *)PTR_memset_2f2420d4)(this + 0x5d,0xff,0x2a);
  iVar4 = (*(code *)PTR_operator_new___2f2424ac)((uint)(byte)this[0x5c] << 2,PTR_DAT_2f242748);
  *(int *)(this + 0x88) = iVar4;
  if (iVar4 == 0) {
    puVar5 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x240;
    puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 600;
    puVar7 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0xc20;
    uVar9 = 0xa9;
  }
  else {
    iVar4 = 0;
    iVar8 = 0;
    do {
      if (*piVar2 != 0) {
        iVar3 = *(int *)(this + 0x88);
        this[iVar4 + 0x5d] = SUB41(iVar8,0);
        *(int *)(iVar3 + iVar8 * 4) = iVar4;
        iVar8 = iVar8 + 1;
      }
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar4 != 0x2a);
    iVar4 = (*(code *)PTR_pthread_mutexattr_init_2f24227c)(auStack_18);
    puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54;
    if ((iVar4 != 0) && (iVar4 != 0x91)) {
      uVar9 = (*(code *)PTR_strerror_2f2421a0)();
      (*(code *)PTR_printf_2f2421b0)
                (PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x6d4,puVar6 + 600,0xba,
                 PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x6f0,uVar9);
    }
    iVar4 = (*(code *)PTR_pthread_mutexattr_settype_2f242738)(auStack_18,1);
    puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54;
    if ((iVar4 == 0) || (iVar4 == 0x91)) {
      iVar4 = (*(code *)PTR_pthread_mutex_init_2f242384)(this + 0x44,auStack_18);
      puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54;
    }
    else {
      uVar9 = (*(code *)PTR_strerror_2f2421a0)();
      (*(code *)PTR_printf_2f2421b0)
                (PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x6d4,puVar6 + 600,0xbb,
                 PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x710,uVar9);
      iVar4 = (*(code *)PTR_pthread_mutex_init_2f242384)(this + 0x44,auStack_18);
      puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54;
    }
    PTR_s_ess__d__________2f230528_0x48_2f241f54 = puVar6;
    if (iVar4 != 0) {
      pcVar10 = (code *)PTR_strerror_2f2421a0;
      if (iVar4 != 0x91) goto LAB_2f22ee60;
      goto LAB_2f22ee10;
    }
    iVar4 = (*(code *)PTR_operator_new___2f2424ac)((uint)(byte)this[0x5c] * 0x2a0,PTR_DAT_2f242748);
    *(int *)(this + 0x8c) = iVar4;
    if (iVar4 == 0) {
      puVar5 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x240;
      puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 600;
      puVar7 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0xc20;
      uVar9 = 0xc4;
    }
    else {
      iVar4 = (*(code *)PTR_operator_new___2f2424ac)((uint)(byte)this[0x5c] * 0x90,PTR_DAT_2f242748)
      ;
      *(int *)(this + 0x6390) = iVar4;
      if (iVar4 != 0) {
        (*(code *)PTR_CheckDatabaseEndAddress_2f242144)(this);
        (**(code **)(*(int *)this + 0x3a0))(this);
        (**(code **)(*(int *)this + 0x328))(this);
        (*(code *)PTR_ValidateUserSourceType_2f2424dc)(this);
        (*(code *)PTR_CheckFactoryMode_2f2425bc)(this);
        return;
      }
      puVar5 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x240;
      puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 600;
      puVar7 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0xc20;
      uVar9 = 199;
    }
  }
  do {
    (*(code *)PTR_printf_2f2421b0)(puVar5,puVar6,puVar7,uVar9);
    pcVar10 = (code *)PTR_abort_2f24206c;
    (*(code *)PTR_abort_2f24206c)();
LAB_2f22ee60:
    puVar6 = PTR_s_ess__d__________2f230528_0x48_2f241f54;
    uVar9 = (*pcVar10)();
    (*(code *)PTR_printf_2f2421b0)
              (PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x6d4,puVar6 + 600,0xbc,
               PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x74c,uVar9);
LAB_2f22ee10:
    (*(code *)PTR_printf_2f2421b0)
              (PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x770,puVar6 + 600,0xbf);
    puVar6 = puVar6 + 600;
    uVar9 = 0xc0;
    puVar5 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0x240;
    puVar7 = PTR_s_ess__d__________2f230528_0x48_2f241f54 + 0xc20;
  } while( true );
}

