#include "ScopePtr.h"

int main(int argc, char** argv) {
  struct Meow {
    int number_1{1};
    int number_6{6};
    char letter_h{'h'};
  };

  ScopePtr<Meow> meow = createScope<Meow>();

  if (meow.get() == nullptr) {
    return -1;
  }

  return 0;
}