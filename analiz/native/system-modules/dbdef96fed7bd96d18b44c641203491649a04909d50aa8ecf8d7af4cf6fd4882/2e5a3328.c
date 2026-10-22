
/* MSrv_System_Database_DVB::RestoreDefaultCECSetting() */

void __thiscall MSrv_System_Database_DVB::RestoreDefaultCECSetting(MSrv_System_Database_DVB *this)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_m_stDefaultCEC_2e5d3bc8;
  uVar2 = *(undefined4 *)(PTR_m_stDefaultCEC_2e5d3bc8 + 4);
  *(undefined4 *)(this + 0x18144) = *(undefined4 *)PTR_m_stDefaultCEC_2e5d3bc8;
  *(undefined4 *)(this + 0x18148) = uVar2;
  *(undefined2 *)(this + 0x1814c) = *(undefined2 *)(puVar1 + 8);
  return;
}

