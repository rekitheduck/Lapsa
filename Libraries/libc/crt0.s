.section .text

.global _start

_start:
    xorl %ebp, %ebp # Should get set to 0 here as per SysV ABI

    popl %esi # pop argc
    movl %esp, %ecx # store argv into ecx

    andl $0xfffffff0, %esp # align stack to 16-bytes bc of SSE
    pushl %eax

    # pushl %esp # prepare the stack # ???

    pushl %ecx # push argv
    pushl %esi # push argc
    pushl %edx # push function pointer for atexit

    # Move to doing everything in libc
    call __libc_start

    int3 # enter a debugger if we somehow end up back here

.size _start, . - _start
