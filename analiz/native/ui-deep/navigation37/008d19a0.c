
/* CommonFrame::DropShadowOnFocus(void*, void*, void*) */

undefined4 CommonFrame::DropShadowOnFocus(void *param_1,void *param_2,void *param_3)

{
  AddHelpButtonForMenuItem(param_1);
  DropBubbleHelpOnFocus(param_1,(void *)0x0,(void *)0x0);
  return 1;
}

