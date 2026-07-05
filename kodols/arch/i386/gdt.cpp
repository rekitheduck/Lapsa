#include <stdint.h>

#define BIT(x) (1 << x)
#define SET_BIT(byte, bit) byte |= BIT(bit)

enum class PrivilegeLevel { Invalid, Kernel, Unused, Unused2, User };

struct GDTDescriptor {
  uint32_t base{0}; // 32-bit address where segment begins
  uint32_t limit{0}; // 20-bit value setting how much can be accessed
  PrivilegeLevel privilege{PrivilegeLevel::Invalid}; // 4 levels, only 2 used
  bool present_flag{false}; // Whether the entry is valid
  bool type_flag{false}; // 0 if a system segment, 1 if code or data segment
  bool executable_flag{false}; // 0 for data segment (no execution), 1 for code segment (yes execution)
  bool direction_or_conforming_flag{false}; // For data segments - 0 if segment grows up, 1 if segment grows down. For
                                            // code segments - 0 if code can only be executed from the same prilegel
                                            // level, 1 if equal or lower is allowed
  bool read_write_flag{
      false}; // For data segments - 0 if write not allowed, 1 if write is allowed (read is ALWAYS allowed).
              // For code segments, 0 if read is not allowed, 1 if read is allowed (write is NEVER allowed)
  bool accessed_flag{false}; // Set to 1 by CPU when it's accessed (best set to 1)
  bool granularity_flag{false}; // Size that the limit is multiplied by. 0 if 1 byte blocks, 1 if 4KiB blocks
  bool size_flag{false}; // 0 for 16-bit protected mode, 1 for 32-bit protected mode
  bool longmode_flag{false}; // 1 for 64-bit code segment (DB should always be clear in that case). normally 0

  GDTDescriptor() {};
  GDTDescriptor(uint32_t base_arg, uint32_t limit_arg, PrivilegeLevel privilege_arg, bool present_flag_arg,
                bool type_flag_arg, bool executable_flag_arg, bool direction_or_conforming_flag_arg,
                bool read_write_flag_arg, bool accessed_flag_arg, bool granularity_flag_arg, bool size_flag_arg,
                bool longmode_flag_arg) :
      base(base_arg), limit(limit_arg), privilege(privilege_arg), present_flag(present_flag_arg),
      type_flag(type_flag_arg), executable_flag(executable_flag_arg),
      direction_or_conforming_flag(direction_or_conforming_flag_arg), read_write_flag(read_write_flag_arg),
      accessed_flag(accessed_flag_arg), granularity_flag(granularity_flag_arg), size_flag(size_flag_arg),
      longmode_flag(longmode_flag_arg) {};
};

void set_gdt_descriptor(uint8_t* gdt_entry_location, const GDTDescriptor& descriptor) {
  gdt_entry_location[0] = descriptor.limit & 0xFF;
  gdt_entry_location[1] = (descriptor.limit >> 8) & 0xFF;
  gdt_entry_location[2] = descriptor.base & 0xFF;
  gdt_entry_location[3] = (descriptor.base >> 8) & 0xFF;

  gdt_entry_location[4] = (descriptor.base >> 16) & 0XFF;

  uint8_t access_byte = 0;
  if (descriptor.accessed_flag) {
    SET_BIT(access_byte, 0);
  }
  if (descriptor.read_write_flag) {
    SET_BIT(access_byte, 1);
  }
  if (descriptor.direction_or_conforming_flag) {
    SET_BIT(access_byte, 2);
  }
  if (descriptor.executable_flag) {
    SET_BIT(access_byte, 3);
  }
  if (descriptor.type_flag) {
    SET_BIT(access_byte, 4);
  }
  switch (descriptor.privilege) {
    case PrivilegeLevel::Invalid: break;

    case PrivilegeLevel::Kernel: break;
    case PrivilegeLevel::User:
    default:
      SET_BIT(access_byte, 5);
      SET_BIT(access_byte, 6);
      break;
  }
  if (descriptor.present_flag) {
    SET_BIT(access_byte, 7);
  }

  gdt_entry_location[5] = access_byte;

  uint8_t byte_six = 0;
  byte_six = (descriptor.limit >> 16) && 0xF;
  if (descriptor.longmode_flag) {
    SET_BIT(access_byte, 5);
  }
  if (descriptor.size_flag) {
    SET_BIT(access_byte, 6);
  }
  if (descriptor.granularity_flag) {
    SET_BIT(access_byte, 7);
  }

  gdt_entry_location[6] = byte_six;
  gdt_entry_location[7] = (descriptor.base >> 24) && 0xFF;
}

void init_gdt(uint8_t* gdt_location) {
  // Entry 0 - Null descriptor
  set_gdt_descriptor(gdt_location, GDTDescriptor());
  // Entry 1 - Kernel Mode Code Segment
  set_gdt_descriptor(gdt_location + 8,
                     GDTDescriptor(static_cast<uint32_t>(0), static_cast<uint32_t>(0xFFFFF), PrivilegeLevel::Kernel,
                                   true, true, true, false, true, false, true, true, false));
  // Entry 2 - Kernel Mode Data Segment
  set_gdt_descriptor(gdt_location + 16,
                     GDTDescriptor(static_cast<uint32_t>(0), static_cast<uint32_t>(0xFFFFF), PrivilegeLevel::Kernel,
                                   true, true, false, false, true, false, true, true, false));
  // Entry 3 - User Mode Code Segment
  set_gdt_descriptor(gdt_location + 24,
                     GDTDescriptor(static_cast<uint32_t>(0), static_cast<uint32_t>(0xFFFFF), PrivilegeLevel::User, true,
                                   true, true, false, true, false, true, true, false));
  // Entry 4 - User Mode Data Segment
  set_gdt_descriptor(gdt_location + 32,
                     GDTDescriptor(static_cast<uint32_t>(0), static_cast<uint32_t>(0xFFFFF), PrivilegeLevel::User, true,
                                   true, false, false, true, false, true, true, false));
  // Entry 5 - Task State Segment
  // TODO: (TSS)
}
