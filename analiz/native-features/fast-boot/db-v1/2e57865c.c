
/* MSrv_System_Database::GetFastBootEnabled() */

MSrv_System_Database __thiscall MSrv_System_Database::GetFastBootEnabled(MSrv_System_Database *this)

{
  MSrv_System_Database MVar1;
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "BOOL MSrv_System_Database::GetFastBootEnabled()",0x2a0c);
  MVar1 = this[0x37de];
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return MVar1;
}

