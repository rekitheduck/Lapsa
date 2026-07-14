// Kodols entrypoint :3

#include <stdint.h>

#include "Devices/Serial.h"
#include "Dmesg.h"
#include "GDT.h"
#include "IDT.h"

extern "C" {

void update_gdt();

void early_main() {
  init_serial();
  Kodols::dmesg("\n\n");
  Kodols::dmesg("hellorld\n");

  Kodols::initGDT();

  Kodols::initIDT();

  Kodols::dmesg("Welp, nothing else to do so let's go to sleep. goodnight :3\n");

  // assuming we're on QEMU, we can shutdown with
  outw(0x604, 0x2000);
  // :3
}

void main() {
  Kodols::dmesg("back in main\n");
}
}
