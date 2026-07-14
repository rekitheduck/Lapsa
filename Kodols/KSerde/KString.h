#pragma once

#include <stddef.h>
#include <stdint.h>

namespace KSerde {

void* memSet(void* dest, uint8_t ch, size_t count);

uint32_t strLen(const char* str);

} // namespace KSerde
