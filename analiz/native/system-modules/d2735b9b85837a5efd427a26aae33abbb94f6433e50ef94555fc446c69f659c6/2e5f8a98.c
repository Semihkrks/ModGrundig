
void MDrv_TSP_SecFlt_Update(undefined4 param_1,uint param_2)

{
  (*(code *)PTR_OSAL_TSP_EventSet_2e64ce98)
            (*(undefined4 *)(PTR_UtopiaResourceObtain_2e64c808 + (param_2 >> 5) * 4 + -0x3fdc),
             1 << (param_2 & 0x1f));
  return;
}

