#include "IDT.h"

#include <stddef.h>
#include <stdint.h>

#include "Dmesg.h"
#include "KSerde/KString.h"

extern "C" {
extern void divideByZeroHandler();
extern void debugHandler();
extern void NMIHandler();
extern void breakpointHandler();
extern void overflowHandler();
extern void boundRangeHandler();
extern void invalidOpcodeHandler();
extern void noMathCoprocessorHandler();
extern void doubleFaultHandler();
extern void coprocessorSegmentOverrunHandler();
extern void invalidTSSHandler();
extern void segmentNotPresentHandler();
extern void stackSegmentFaultHandler();
extern void generalProtectionHandler();
extern void pageFaultHandler();
extern void x87MathFaultHandler();
extern void alignmentCheckHandler();
extern void machineCheckHandler();
extern void SIMDFPHandler();
extern void virtualizationHandler();
extern void controlProtectionHandler();
}

namespace Kodols {

struct InterruptDescriptor {
  uint16_t offset_1; // offset bits 0..15
  uint16_t selector; // a code segment selector in GDT or LDT
  uint8_t zero; // unused, set to 0
  uint8_t type_attributes; // gate type, dpl, and p fields
  uint16_t offset_2; // offset bits 16..31
} __attribute__((packed));

struct IDTR {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

[[gnu::aligned(4096)]] static InterruptDescriptor s_idt_descriptors[256];

enum class GateType { InterruptGate, TrapGate, TaskGate };

void setDescriptor(size_t index, GateType type, void* isr_address) {
  InterruptDescriptor& d = s_idt_descriptors[index];
  d.offset_1 = static_cast<uint32_t>(reinterpret_cast<uint32_t>(isr_address) & 0xFFFF);
  d.selector = 0x08; // Kernel data selector
  d.offset_2 = static_cast<uint32_t>(reinterpret_cast<uint32_t>(isr_address) >> 16);
  switch (type) {
    case GateType::InterruptGate: d.type_attributes = 0x8E; break;
    case GateType::TrapGate: d.type_attributes = 0x8F; break;
    case GateType::TaskGate: d.type_attributes = 0x85; break;
    // TODO: usermode interrupts....
    default: break;
  }
}

void initIDT() {
  // Wipe the whole table
  KSerde::MemSet(s_idt_descriptors, 0, 256);

  setDescriptor(0x00, GateType::InterruptGate, reinterpret_cast<void*>(&divideByZeroHandler));
  setDescriptor(0x01, GateType::TrapGate, reinterpret_cast<void*>(&debugHandler));
  setDescriptor(0x02, GateType::InterruptGate, reinterpret_cast<void*>(&NMIHandler));
  setDescriptor(0x03, GateType::TrapGate, reinterpret_cast<void*>(&breakpointHandler));
  setDescriptor(0x04, GateType::TrapGate, reinterpret_cast<void*>(&overflowHandler));
  setDescriptor(0x05, GateType::InterruptGate, reinterpret_cast<void*>(&boundRangeHandler));
  setDescriptor(0x06, GateType::InterruptGate, reinterpret_cast<void*>(&invalidOpcodeHandler));
  setDescriptor(0x07, GateType::InterruptGate, reinterpret_cast<void*>(&noMathCoprocessorHandler));
  setDescriptor(0x08, GateType::InterruptGate, reinterpret_cast<void*>(&doubleFaultHandler));
  setDescriptor(0x09, GateType::InterruptGate, reinterpret_cast<void*>(&coprocessorSegmentOverrunHandler));
  setDescriptor(0x0A, GateType::InterruptGate, reinterpret_cast<void*>(&invalidTSSHandler));
  setDescriptor(0x0B, GateType::InterruptGate, reinterpret_cast<void*>(&segmentNotPresentHandler));
  setDescriptor(0x0C, GateType::InterruptGate, reinterpret_cast<void*>(&stackSegmentFaultHandler));
  setDescriptor(0x0D, GateType::InterruptGate, reinterpret_cast<void*>(&generalProtectionHandler));
  setDescriptor(0x0E, GateType::InterruptGate, reinterpret_cast<void*>(&pageFaultHandler));
  // 0x0F: Intel reserved
  setDescriptor(0x10, GateType::InterruptGate, reinterpret_cast<void*>(&x87MathFaultHandler));
  setDescriptor(0x11, GateType::InterruptGate, reinterpret_cast<void*>(&alignmentCheckHandler));
  setDescriptor(0x12, GateType::InterruptGate, reinterpret_cast<void*>(&machineCheckHandler));
  setDescriptor(0x12, GateType::InterruptGate, reinterpret_cast<void*>(&SIMDFPHandler));
  setDescriptor(0x12, GateType::InterruptGate, reinterpret_cast<void*>(&virtualizationHandler));
  setDescriptor(0x12, GateType::InterruptGate, reinterpret_cast<void*>(&controlProtectionHandler));
  // 0x16...0x1F: Intel reserved

  IDTR idtr;
  idtr.base = reinterpret_cast<uint32_t>(&s_idt_descriptors);
  idtr.limit = static_cast<uint32_t>(sizeof(InterruptDescriptor) * 256 - 1);

  __asm__ volatile("lidt %0" : : "m"(idtr)); // load the new IDT
}

} // namespace Kodols
