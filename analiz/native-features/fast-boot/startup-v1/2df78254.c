
/* ArSrvPowerManager::GetInstance() */

ArSrvPowerManager * ArSrvPowerManager::GetInstance(void)

{
  ArSrvPowerManager *this;
  
  if (m_pInstance == (ArSrvPowerManager *)0x0) {
    this = operator_new(0x10);
                    /* try { // try from 2df782b0 to 2df782b7 has its CatchHandler @ 2df782e8 */
    ArSrvPowerManager(this);
    m_pInstance = this;
    if (this == (ArSrvPowerManager *)0x0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("m_pInstance","./src/ArSrvPowerManager.cpp",0x2f,
                    "static ArSrvPowerManager* ArSrvPowerManager::GetInstance()");
    }
  }
  return m_pInstance;
}

