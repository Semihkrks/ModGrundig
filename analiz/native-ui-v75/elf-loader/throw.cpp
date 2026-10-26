extern "C" __attribute__((noinline)) void thrower() { throw 75; }
extern "C" int probe_main() { try { ((void(*)())0x01160100)(); } catch(int x) {return x;} return 99; }
