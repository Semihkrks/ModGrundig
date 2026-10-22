
undefined4 FT_Render_Glyph(int param_1,undefined4 param_2)

{
  undefined4 local_10;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 4) == 0)) {
    local_10 = 6;
  }
  else {
    local_10 = (*(code *)PTR_FT_Render_Glyph_Internal_2e11846c)
                         (*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 4),param_1,
                          param_2);
  }
  return local_10;
}

