// Kodols entrypoint :3

#include <stdint.h>

#include "Devices/Serial.h"
#include "Dmesg.h"
#include "GDT.h"
#include "IDT.h"
#include "IO.h"

extern "C" {

void early_main() {
  Kodols::Devices::Serial::init();
  Kodols::dmesg("\n\n");
  Kodols::dmesg("hellorld\n");

  Kodols::initGDT();

  Kodols::initIDT();

  Kodols::dmesg("Welp, nothing else to do so let's go to sleep. goodnight :3\n");

  // assuming we're on QEMU, we can shutdown with
  Kodols::outw(0x604, 0x2000);
  // :3
}

void main() {
  Kodols::dmesg("back in main\n");
}
}
