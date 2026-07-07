// Kodols entrypoint :3

#include <stdint.h>

#include "devices/serial.h"
#include "gdt.h"

extern "C" {

void update_gdt();

void early_main() {
  init_serial();
  dmesg("\n\n");
  dmesg("hellorld\n");

  init_gdt();
  dmesg("gdt initialized!\n");

  // assuming we're on QEMU, we can shutdown with
  outw(0x604, 0x2000);
  // :3
}

void main() {
  dmesg("back in main\n");
}
}
