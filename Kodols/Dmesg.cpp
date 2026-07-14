#include "Dmesg.h"

#include "Devices/Serial.h"
#include "KSerde/KString.h"

using namespace KSerde;

namespace Kodols {

void dmesg(const char* message) {
  for (uint32_t i = 0; i < StrLen(message); i++) {
    write_serial(message[i]);
  }
}
} // namespace Kodols
