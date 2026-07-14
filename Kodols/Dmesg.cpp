#include "Dmesg.h"

#include "Devices/Serial.h"
#include "KSerde/KString.h"

using namespace KSerde;

namespace Kodols {

void dmesg(const char* message) {
  for (uint32_t i = 0; i < strLen(message); i++) {
    Kodols::Devices::Serial::writeByte(message[i]);
  }
}

} // namespace Kodols
