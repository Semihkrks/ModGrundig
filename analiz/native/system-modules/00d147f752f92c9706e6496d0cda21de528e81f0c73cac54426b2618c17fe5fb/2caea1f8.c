
/* mapi_demux_filter_common::SetChangeSourceCB(EN_MAPI_DMX_FILTER_SOURCE (*)(void*), void*) */

void __thiscall
mapi_demux_filter_common::SetChangeSourceCB
          (mapi_demux_filter_common *this,_func_EN_MAPI_DMX_FILTER_SOURCE_void_ptr *param_1,
          void *param_2)

{
  *(void **)(this + 0xc) = param_2;
  *(_func_EN_MAPI_DMX_FILTER_SOURCE_void_ptr **)(this + 8) = param_1;
  return;
}

