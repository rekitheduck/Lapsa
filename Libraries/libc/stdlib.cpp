#include "stdlib.h"

void abort(void) {}

void exit(int) {}

int atexit(void (*)(void)) {
  return 0;
}

int atoi(const char*) {
  return 0;
}

void free(void*) {}

char* getenv(const char*) {
  return "a";
}

void* malloc(size_t) {
  return nullptr;
}