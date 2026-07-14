#include <stdint.h>

#include "Arch/i386/IO.h"
#include "Devices/Serial.h"
#include "Dmesg.h"

struct interrupt_frame_with_error_code {
  uint32_t error_code;
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
};

struct interrupt_frame {
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
};

extern "C" {

__attribute__((interrupt)) void divideByZeroHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x00: ruh roh, Divide by zer0!\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}
__attribute__((interrupt)) void debugHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x01: Debug!\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void NMIHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x02: NMI\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void breakpointHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x03: INT3 breakpoint\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void overflowHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x04: INTO overflow\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void boundRangeHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x05: BOUND range exceeded\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void invalidOpcodeHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x06 Invalid Opcode\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void noMathCoprocessorHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x07 Math Coprocessor not available\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void doubleFaultHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x08: Double Fault\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void coprocessorSegmentOverrunHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x09: Coprocessor Segment Overrun\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void invalidTSSHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x0A: Invalid TSS\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void segmentNotPresentHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x0B: Segment Not Present\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void stackSegmentFaultHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x0C: Stack-Segment fault\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void generalProtectionHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x0D: General Protection Fault\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void pageFaultHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x0E: Page Fault\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

// 0x0F Intel reserved.

__attribute__((interrupt)) void x87MathFaultHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x10: x87 math fault\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void alignmentCheckHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x11: Alignment check\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void machineCheckHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x12: Machine Check\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void SIMDFPHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x13: SIMD Floating Point exception\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void virtualizationHandler(interrupt_frame* frame) {
  Kodols::dmesg("0x14: Virtualzation Exception, EPT violation(s)\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

__attribute__((interrupt)) void controlProtectionHandler(interrupt_frame_with_error_code* frame) {
  Kodols::dmesg("0x15: Control Protection Exception\n\n");
  Kodols::outw(0x604, 0x2000);
  __asm__ volatile("cli; hlt");
}

// 0x16F Intel reserved.
// ...
// 0x1F Intel reserved
}
