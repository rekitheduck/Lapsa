#include "KString.h"

namespace KSerde {

void* memSet(void* dest, uint8_t ch, size_t count) {
  for (size_t i = 0; i < count; i++) {
    static_cast<uint8_t*>(dest)[i] = ch;
  }

  return dest;
}

uint32_t strLen(const char* str) {
  uint32_t pos = 0;
  while (str[pos] != '\0') {
    pos++;
  }
  return pos;
}

} // namespace KSerde
