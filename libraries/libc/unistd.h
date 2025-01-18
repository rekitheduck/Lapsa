#pragma once

#include <stddef.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int close(int);

    // ssize_t write(int fd, const void *buf, size_t count);

    int execv(const char *, char *const[]);
    int execve(const char *, char *const[], char *const[]);
    int execvp(const char *, char *const[]);
    pid_t fork(void);

#ifdef __cplusplus
}
#endif