
int finitel(double __value)

{
  return ((uint)((ulonglong)__value >> 0x20) & 0x7fffffff) + 0x80100000 >> 0x1f;
}

