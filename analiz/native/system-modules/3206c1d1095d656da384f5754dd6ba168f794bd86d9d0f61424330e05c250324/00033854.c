
undefined4 ne_ssl_context_set_verify(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    (*(code *)PTR_SSL_CTX_set_verify_00049818)(*param_1,3,0);
  }
  if (param_3 != 0) {
    uVar2 = *param_1;
    uVar1 = (*(code *)PTR_SSL_load_client_CA_file_0004963c)(param_3);
    (*(code *)PTR_SSL_CTX_set_client_CA_list_000498d4)(uVar2,uVar1);
  }
  if (param_4 != 0) {
    (*(code *)PTR_SSL_CTX_load_verify_locations_00049628)(*param_1,param_4,0);
  }
  return 0;
}

