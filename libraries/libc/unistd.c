#include "unistd.h"

#include <asm/unistd.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    syscall(__NR_write);
}