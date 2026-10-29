
/* MSrv_System_Database::GetFactFastBoot() */

uint __thiscall MSrv_System_Database::GetFactFastBoot(MSrv_System_Database *this)

{
  uint uVar1;
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "BOOL MSrv_System_Database::GetFactFastBoot()",0x3bee);
  uVar1 = *(uint *)(this + 0x110d0);
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return (uVar1 & 0xffff) >> 0xf;
}

