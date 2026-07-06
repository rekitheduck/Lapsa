// Kodols entrypoint :3

#include "devices/serial.h"
#include <stdint.h>

extern "C" {

extern void init_gdt(uint8_t* gdt_location);

void main() {
  init_serial();
  write_serial('h');
  write_serial('e');
  write_serial('l');
  write_serial('l');
  write_serial('o');
  write_serial('r');
  write_serial('l');
  write_serial('d');
  // :3
}
}
