
/* MWidget::DrawBorders(_IDirectFBSurface*) */

void __thiscall MWidget::DrawBorders(MWidget *this,_IDirectFBSurface *param_1)

{
  int iVar1;
  MWidget MVar2;
  uint uVar3;
  
  if (this[0x160] != (MWidget)0x0) {
    iVar1 = QueryFlag(this,'\x04');
    if (iVar1 == 0) {
      uVar3 = *(uint *)(this + 0x16c);
      (**(code **)(param_1 + 0x54))
                (param_1,(uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff,uVar3 >> 0x18
                );
      MVar2 = this[0x160];
    }
    else {
      uVar3 = *(uint *)(this + 0x164);
      (**(code **)(param_1 + 0x54))
                (param_1,(uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff,uVar3 >> 0x18
                );
      MVar2 = this[0x160];
    }
    if (((byte)MVar2 & 4) != 0) {
      (**(code **)(param_1 + 0x94))(param_1,0,0,*(undefined4 *)(this + 0x24),this[0x161]);
      MVar2 = this[0x160];
    }
    if (((byte)MVar2 & 8) != 0) {
      (**(code **)(param_1 + 0x94))
                (param_1,0,*(int *)(this + 0x28) - (uint)(byte)this[0x161],
                 *(undefined4 *)(this + 0x24),(uint)(byte)this[0x161]);
      MVar2 = this[0x160];
    }
    if (((byte)MVar2 & 1) != 0) {
      (**(code **)(param_1 + 0x94))(param_1,0,0,this[0x161],*(undefined4 *)(this + 0x28));
      MVar2 = this[0x160];
    }
    if (((byte)MVar2 & 2) != 0) {
      (**(code **)(param_1 + 0x94))
                (param_1,*(int *)(this + 0x24) - (uint)(byte)this[0x161],0,(uint)(byte)this[0x161],
                 *(undefined4 *)(this + 0x28));
      return;
    }
  }
  return;
}

