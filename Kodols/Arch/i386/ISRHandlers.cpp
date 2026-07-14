#include "Devices/Serial.h"
#include "Dmesg.h"

extern "C" {

__attribute__((noreturn)) void isr_handler() {
  Kodols::dmesg("ruh roh, Divide by zer0!\n\n");
  outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt"); // Completely hangs the computer
}
}
