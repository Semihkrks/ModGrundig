
/* porting_InternalSubtitleRender::SetVideoSize(unsigned short, unsigned short) */

void porting_InternalSubtitleRender::SetVideoSize(ushort param_1,ushort param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_m_u16VideoHeight_2f18aefc;
  *(ushort *)PTR_m_u16VideoWidth_2f18b0b8 = param_1;
  *(ushort *)puVar1 = param_2;
  return;
}

