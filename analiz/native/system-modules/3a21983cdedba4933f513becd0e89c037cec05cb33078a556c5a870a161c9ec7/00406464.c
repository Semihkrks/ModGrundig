
void check_remote_input_interrupt_request(void)

{
  if (remote_desc != -1) {
    input_interrupt(0);
    return;
  }
  return;
}

