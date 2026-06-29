#pragma once

// Duplicates from <sys/types.h>
typedef signed int blkcnt_t; // Used for file block counts
typedef signed int blksize_t; // Used for block sizes
typedef signed int dev_t; // Used for device IDs.
typedef signed int ino_t; // Used for file serial numbers.
typedef signed int mode_t; // Used for some file attributes.
typedef signed int nlink_t; // Used for link counts.
typedef signed int uid_t; // Used for user IDs.
typedef signed int gid_t; // Used for group IDs.
typedef signed int off_t; // Used for file sizes.
typedef signed int time_t; // Used for time in seconds.

#define S_IFMT 1 // type of file
#define S_IFBLK 2 // block special
#define S_IFCHR 4 // character specal
#define S_IFIFO 5 // FIFO special
#define S_IFREG 6 // regular
#define S_IFDIR 7 // directory
#define S_IFLNK 8 // symbolic link

#define S_IRUSR 0x2 // read permission, owner
#define S_IWUSR 0x4 // write permission, owner
#define S_IXUSR 0x8 // execute/search permission, owner
#define S_IRWXU (S_IRUSR | S_IWUSR | S_IXUSR) // read, write, execute/search by owner

#define S_IRGRP 0x20 // read permission, group
#define S_IWGRP 0x40 // write permission, group
#define S_IXGRP 0x80 // execute/search permission, group
#define S_IRWXG (S_IRGRP | S_IWGRP | S_IXGRP) // read, write, execute/search by group

#define S_IROTH 0x200 // read permission, others
#define S_IWOTH 0x400 // write permission, others
#define S_IXOTH 0x800 // execute/search permission, others
#define S_IRWXO (S_IROTH | S_IWOTH | IXO) // read, write, execute/search by others

#define S_ISUID 0x1000 // set-user-ID on execution
#define S_ISGID 0x2000 // set-group-ID on execution
#define S_ISVTX 0x4000 // on directories, restricted deletion flag

struct stat {
  dev_t st_dev; // ID of device containing file
  ino_t st_ino; // file serial number
  mode_t st_mode; // mode of file (see below)
  nlink_t st_nlink; // number of links to the file
  uid_t st_uid; // user ID of file
  gid_t st_gid; // group ID of file
  dev_t st_rdev; // device ID (if file is character or block special)
  off_t st_size; // file size in bytes (if file is a regular file)
  time_t st_atime; // time of last access
  time_t st_mtime; // time of last data modification
  time_t st_ctime; // time of last status change
  blksize_t st_blksize; // a filesystem-specific preferred I/O block size for this object.  In some filesystem types,
                        // this may vary from file to file
  blkcnt_t st_blocks; // number of blocks allocated for this object
};
