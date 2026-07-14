#pragma once

typedef signed int blkcnt_t; // Used for file block counts
typedef signed int blksize_t; // Used for block sizes
typedef signed int clock_t; // Used for system times in clock ticks or CLOCKS_PER_SEC (see <time.h>).
typedef signed int clockid_t; // Used for clock ID type in the clock and timer functions.
typedef signed int dev_t; // Used for device IDs.
typedef signed int fsblkcnt_t; // Used for file system block counts
typedef signed int fsfilcnt_t; // Used for file system file counts
typedef signed int gid_t; // Used for group IDs.
typedef signed int id_t; // Used as a general identifier; can be used to contain at least a pid_t, uid_t or a gid_t.
typedef signed int ino_t; // Used for file serial numbers.
typedef signed int key_t; // Used for interprocess communication.
typedef signed int mode_t; // Used for some file attributes.
typedef signed int nlink_t; // Used for link counts.
typedef signed int off_t; // Used for file sizes.
typedef signed int pid_t; // Used for process IDs and process group IDs.
typedef signed int pthread_attr_t; // Used to identify a thread attribute object.
typedef signed int pthread_cond_t; // Used for condition variables.
typedef signed int pthread_condattr_t; // Used to identify a condition attribute object.
typedef signed int pthread_key_t; // Used for thread-specific data keys.
typedef signed int pthread_mutex_t; // Used for mutexes.
typedef signed int pthread_mutexattr_t; // Used to identify a mutex attribute object.
typedef signed int pthread_once_t; // Used for dynamic package initialisation.
typedef signed int pthread_rwlock_t; // Used for read-write locks.
typedef signed int pthread_rwlockattr_t; // Used for read-write lock attributes.
typedef signed int pthread_t; // Used to identify a thread.
typedef __SIZE_TYPE__ size_t; // Used for sizes of objects.  (GCC-specific)
typedef signed int ssize_t; // Used for a count of bytes or an error indication.
typedef signed int suseconds_t; // Used for time in microseconds
typedef signed int time_t; // Used for time in seconds.
typedef signed int timer_t; // Used for timer ID returned by timer_create().
typedef signed int uid_t; // Used for user IDs.
typedef signed int useconds_t; // Used for time in microseconds.
