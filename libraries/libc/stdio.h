#pragma once

#include <stdarg.h>
#include <stddef.h>

typedef int FILE;
typedef int off_t;

FILE *stderr;
FILE *stdin;
FILE *stdout;

#ifdef __cplusplus
extern "C"
{
#endif

    int printf(const char *format);
    int fclose(FILE *);
    int fflush(FILE *);
    FILE *fopen(const char *, const char *);
    int fprintf(FILE *, const char *, ...);
    size_t fread(void *, size_t, size_t, FILE *);
    int fseek(FILE *, long, int);
    long ftell(FILE *);
    size_t fwrite(const void *, size_t, size_t, FILE *);
    void setbuf(FILE *, char *);
    int vfprintf(FILE *, const char *, va_list);

#ifdef __cplusplus
}
#endif
