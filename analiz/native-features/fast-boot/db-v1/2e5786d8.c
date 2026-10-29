
/* MSrv_System_Database::IsFastBootInUse() */

uint __thiscall MSrv_System_Database::IsFastBootInUse(MSrv_System_Database *this)

{
  uint uVar1;
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "BOOL MSrv_System_Database::IsFastBootInUse()",0x2a07);
  uVar1 = 0;
  if (this[0x37de] != (MSrv_System_Database)0x0) {
    uVar1 = (*(uint *)(this + 0x110d0) & 0xffff) >> 0xf;
  }
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return uVar1;
}

