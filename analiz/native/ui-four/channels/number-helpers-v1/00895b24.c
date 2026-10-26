
/* ChannelControlFrame::ChangeChannel(unsigned short) */

void ChannelControlFrame::ChangeChannel(ushort param_1)

{
  ulong in_a1;
  
  ArChannelManager::SelectChannelByNumber(in_a1,'\x01');
  return;
}

