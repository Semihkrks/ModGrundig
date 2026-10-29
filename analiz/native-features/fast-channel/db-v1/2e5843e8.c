
/* MSrv_System_Database::SetFastZapping(unsigned char) */

void __thiscall MSrv_System_Database::SetFastZapping(MSrv_System_Database *this,uchar param_1)

{
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "void MSrv_System_Database::SetFastZapping(BOOL)",0x29e2);
                    /* try { // try from 2e584440 to 2e584447 has its CatchHandler @ 2e584474 */
  this[0x37c8] = (MSrv_System_Database)param_1;
  SaveUserGeneralSettings(this);
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return;
}

