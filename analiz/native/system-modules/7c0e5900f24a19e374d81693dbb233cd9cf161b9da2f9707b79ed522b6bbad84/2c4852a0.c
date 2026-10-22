
int finitef(float __value)

{
  return (int)ABS(__value) + 0x80800000U >> 0x1f;
}

