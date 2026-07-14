#pragma once

#include <stddef.h>
#include <stdint.h>

namespace KSerde {

void* MemSet(void* dest, uint8_t ch, size_t count);

uint32_t StrLen(const char* str);

} // namespace KSerde
