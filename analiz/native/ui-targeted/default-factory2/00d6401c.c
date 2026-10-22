
IdleAppApp * FUN_00d6401c(void)

{
  IdleAppApp *this;
  
  this = operator_new(0x3c);
                    /* try { // try from 00d64068 to 00d6406f has its CatchHandler @ 00d64098 */
  IdleAppApp::IdleAppApp(this);
  return this;
}

