
/* MSrv_System_Database::SetFastBootEnabled(unsigned char) */

void __thiscall MSrv_System_Database::SetFastBootEnabled(MSrv_System_Database *this,uchar param_1)

{
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "void MSrv_System_Database::SetFastBootEnabled(BOOL)",0x2a11);
                    /* try { // try from 2e5842e0 to 2e5842e7 has its CatchHandler @ 2e584314 */
  this[0x37de] = (MSrv_System_Database)param_1;
  SaveUserGeneralSettings(this);
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return;
}

