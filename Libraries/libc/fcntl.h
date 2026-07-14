#pragma once

#include <sys/stat.h>
#include <unistd.h>

// Duplicates from <sys/types.h>
typedef signed int off_t; // Used for file sizes.
typedef signed int pid_t; // Used for process IDs and process group IDs.

#define F_DUPFD 1 // Duplicate file descriptor.
#define F_GETFD 2 // Get file descriptor flags.
#define F_SETFD 3 // Set file descriptor flags.
#define F_GETFL 4 // Get file status flags and file access modes.
#define F_SETFL 5 // Set file status flags.
#define F_GETLK 6 // Get record locking information.
#define F_SETLK 7 // Set record locking information.
#define F_SETLKW 8 // Set record locking information; wait if blocked.

#define FD_CLOEXEC 9 // Close the file descriptor upon execution of an exec family function.

#define F_RDLCK 10 // Shared or read lock.
#define F_UNLCK 11 // Unlock.
#define F_WRLCK 12 // Exclusive or write lock.

#define O_CREAT 0x1 // Create file if it does not exist.
#define O_EXCL 0x2 // Exclusive use flag.
#define O_NOCTTY 0x4 // Do not assign controlling terminal.
#define O_TRUNC 0x8 // Truncate flag.

#define O_APPEND 0x10 // Set append mode.
#define O_DSYNC 0x20 // Write according to synchronised I/O data integrity completion.
#define O_NONBLOCK 0x40 // Non-blocking mode.
#define O_RSYNC 0x80 // Synchronised read I/O operations.
#define O_SYNC 0x100 // Write according to synchronised I/O file integrity completion.

#define O_ACCMODE 0x200 // Mask for file access modes.

#define O_RDONLY 0x400 // Open for reading only.
#define O_RDWR 0x800 // Open for reading and writing.
#define O_WRONLY 0x1000 // Open for writing only.

struct flock {
  short l_type; // Type of lock; F_RDLCK, F_WRLCK, F_UNLCK.
  short l_whence; // Flag for starting offset.
  off_t l_start; // Relative offset in bytes.
  off_t l_len; // Size; if 0 then until EOF.
  pid_t l_pid; // Process ID of the process holding the lock; returned with F_GETLK.
};
