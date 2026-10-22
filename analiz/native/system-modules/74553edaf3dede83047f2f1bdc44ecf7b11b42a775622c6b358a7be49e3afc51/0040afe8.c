
void initialize(void)

{
  if (once == 0) {
    initialize_action();
    once = 1;
  }
  return;
}

