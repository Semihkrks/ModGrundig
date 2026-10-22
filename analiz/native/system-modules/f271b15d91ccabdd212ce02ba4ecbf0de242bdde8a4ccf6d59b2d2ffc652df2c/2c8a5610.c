
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int iw_sockets_open(void)

{
  int iVar1;
  
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: int sock@[???] */
  iVar1 = (*(code *)PTR_socket_2c8b830c)(2,1,0);
  if (iVar1 < 0) {
    iVar1 = (*(code *)PTR_socket_2c8b830c)(4,1,0);
    if (iVar1 < 0) {
      iVar1 = (*(code *)PTR_socket_2c8b830c)(3,1,0);
      if ((iVar1 < 0) && (iVar1 = (*(code *)PTR_socket_2c8b830c)(5,1,0), iVar1 < 0)) {
        iVar1 = -1;
      }
    }
  }
  return iVar1;
}

