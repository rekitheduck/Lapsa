#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int main(int, char**, char**);

void __libc_start(void* f, int, char*[]);

void __libc_start(void* cleanup, int argc, char* argv[]) {
  char** env;
  env = argv + argc + 1;

  exit(main(argc, argv, env));
}

#ifdef __cplusplus
}
#endif
