
/* MSrv_System_Database::SetFactFastBoot(unsigned char) */

void __thiscall MSrv_System_Database::SetFactFastBoot(MSrv_System_Database *this,uchar param_1)

{
  mapi_scope_lock amStack_18 [8];
  
  mapi_scope_lock::mapi_scope_lock
            (amStack_18,(pthread_mutex_t *)(this + 0x44),
             "void MSrv_System_Database::SetFactFastBoot(BOOL)",0x3bf3);
                    /* try { // try from 2e57d11c to 2e57d123 has its CatchHandler @ 2e57d150 */
  *(uint *)(this + 0x110d0) = *(uint *)(this + 0x110d0) & 0xffff7fff | (param_1 & 1) << 0xf;
  SaveFactoryTvConfigurationSetting(this);
  mapi_scope_lock::~mapi_scope_lock(amStack_18);
  return;
}

