#include "GDT.h"

#include <stdint.h>

struct GDTDescriptor {
  unsigned short limit_low;
  unsigned short base_low;
  uint8_t base_middle;
  uint8_t access_byte;
  uint8_t limit_and_flags;
  uint8_t base_high;
} __attribute__((packed));

[[gnu::aligned(4096)]] static GDTDescriptor gdt_descriptors[5]; // 5 for now

struct GDTR {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

void set_gdt_descriptor(uint32_t index, uint32_t base_address, uint32_t limit, uint8_t access_byte, uint8_t flags) {
  gdt_descriptors[index].base_low = base_address & 0xFFFF;
  gdt_descriptors[index].base_middle = (base_address >> 16) & 0xFF;
  gdt_descriptors[index].base_high = (base_address >> 24) & 0xFF;

  gdt_descriptors[index].limit_low = limit & 0xFFFF;
  gdt_descriptors[index].limit_and_flags = (limit >> 16) & 0xF;
  gdt_descriptors[index].limit_and_flags |= (flags << 4) & 0xF0;

  gdt_descriptors[index].access_byte = access_byte;
}

void init_gdt() {
  // Entry 0 - Null descriptor
  set_gdt_descriptor(0, 0, 0, 0, 0);
  // Entry 1 - Kernel Mode Code Segment
  set_gdt_descriptor(1, 0, static_cast<uint32_t>(0xFFFFF), 0x9A, 0x0C);
  // Entry 2 - Kernel Mode Data Segment
  set_gdt_descriptor(2, 0, static_cast<uint32_t>(0xFFFFF), 0x92, 0x0C);
  // Entry 3 - User Mode Code Segment
  set_gdt_descriptor(3, 0, static_cast<uint32_t>(0xFFFFF), 0xFA, 0x0C);
  // Entry 4 - User Mode Data Segment
  set_gdt_descriptor(4, 0, static_cast<uint32_t>(0xFFFFF), 0xF2, 0x0C);
  // Entry 5 - Task State Segment
  // TODO: (TSS)

  GDTR gdt_register;
  gdt_register.limit = static_cast<uint16_t>((sizeof(GDTDescriptor) * 5) - 1);
  gdt_register.base = reinterpret_cast<uint32_t>(&gdt_descriptors);
  asm volatile("lgdtl %0 \n\t"
               "movw $0x10, %%ax \n\t"
               "movw  %%ax, %%ds \n\t"
               "movw  %%ax, %%es \n\t"
               "movw  %%ax, %%fs \n\t"
               "movw  %%ax, %%gs \n\t"
               "movw  %%ax, %%ss \n\t"
               "ljmp $0x08,$meow\n\t"
               "meow:" ::"m"(gdt_register)
               : "eax");
}
