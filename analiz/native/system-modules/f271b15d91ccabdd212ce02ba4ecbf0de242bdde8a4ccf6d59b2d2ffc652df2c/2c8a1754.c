
void iw_init_event_stream(stream_descr *stream,char *data,int len)

{
  stream->end = data + len;
  stream->value = (char *)0x0;
  stream->current = data;
  return;
}

