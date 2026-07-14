#include "IDT.h"

#include <stddef.h>
#include <stdint.h>

#include "Dmesg.h"
#include "KSerde/KString.h"

extern "C" {
extern void isr_wrapper();
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

void init_idt() {
  dmesg("Initializing IDT ...\n");
  // Wipe the whole table
  KSerde::MemSet(s_idt_descriptors, 0, 256);

  setDescriptor(0x00, GateType::InterruptGate, reinterpret_cast<void*>(&isr_wrapper));

  IDTR idtr;
  idtr.base = reinterpret_cast<uint32_t>(&s_idt_descriptors);
  idtr.limit = static_cast<uint32_t>(sizeof(InterruptDescriptor) * 256 - 1);
  dmesg("setting IDTR ...\n");

  __asm__ volatile("lidt %0" : : "m"(idtr)); // load the new IDT
  dmesg("success??\n");

  int fail = 10 / 0;
}

} // namespace Kodols
