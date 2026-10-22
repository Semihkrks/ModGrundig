
/* MW_DTV_Scan_DVBT::StartStandbyScan() */

bool __thiscall MW_DTV_Scan_DVBT::StartStandbyScan(MW_DTV_Scan_DVBT *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined4 local_10;
  
  (*(code *)PTR_puts_2ee7608c)
            (PTR_s_v_DTV_Player_DVBT_DoNewFrontEnd_2ee60b70_0x10_2ee75d68 + 0x117c);
  if (this[0xc] == (MW_DTV_Scan_DVBT)0x0) {
    uVar2 = 0x27c;
    goto LAB_2ee5e464;
  }
  if (this[0x4e] != (MW_DTV_Scan_DVBT)0x0) {
    local_20 = PTR_vtable_2ee76464 + 8;
    local_18 = 1;
    local_1c = 10;
    local_14 = 0;
    local_10 = 0;
                    /* try { // try from 2ee5e424 to 2ee5e42b has its CatchHandler @ 2ee5e4a0 */
    iVar1 = (*(code *)PTR_Send_2ee76118)(*(undefined4 *)(this + 0x88),&local_20,0);
    return iVar1 == 0;
  }
  do {
    uVar2 = 0x27d;
LAB_2ee5e464:
    (*(code *)PTR_printf_2ee76104)
              (PTR_s_v_DTV_Player_DVBT_DoNewFrontEnd_2ee60b70_0x10_2ee75d68 + -0x560,
               PTR_s_v_DTV_Player_DVBT_DoNewFrontEnd_2ee60b70_0x10_2ee75d68 + 0x5a8,
               PTR_s_v_DTV_Player_DVBT_DoNewFrontEnd_2ee60b70_0x10_2ee75d68 + 0x1b34,uVar2);
    (*(code *)PTR_abort_2ee75f18)();
  } while( true );
}

