#pragma once

#include <stddef.h>
#include <sys/types.h>

#define NULL 0

#define F_OK 0x0
#define R_OK 0x2
#define W_OK 0x4
#define X_OK 0x8

#define SEEK_CUR 1 // Set file offset to offset.
#define SEEK_END 2 // Set file offset to current plus offset.
#define SEEK_SET 3 // Set file offset to EOF plus offset.

#define F_LOCK 1 // Lock a section for exclusive use.
#define F_ULOCK 2 // Unlock locked sections.
#define F_TEST 3 // Test section for locks by other processes.
#define F_TLOCK 4 // Test and lock a section for exclusive use.

#define STDIN_FILENO 0 // File number of stdin. It is 0.
#define STDOUT_FILENO 1 // File number of stdout. It is 1.
#define STDERR_FILENO 2 // File number of stderr. It is 2.

// Duplicates from <sys/types.h>
typedef __SIZE_TYPE__ size_t; // Used for sizes of objects.  (GCC-specific)
typedef signed int ssize_t; // Used for a count of bytes or an error indication.
typedef signed int uid_t; // Used for user IDs.
typedef signed int gid_t; // Used for group IDs.
typedef signed int off_t; // Used for file sizes.
typedef signed int pid_t; // Used for process IDs and process group IDs.
typedef signed int useconds_t; // Used for time in microseconds.

// Duplicates from <inttypes.h>
typedef signed int intptr_t;

#ifdef __cplusplus
extern "C" {
#endif

int close(int);

// ssize_t write(int fd, const void *buf, size_t count);

int execv(const char*, char* const[]);
int execve(const char*, char* const[], char* const[]);
int execvp(const char*, char* const[]);
pid_t fork(void);

#ifdef __cplusplus
}
#endif
