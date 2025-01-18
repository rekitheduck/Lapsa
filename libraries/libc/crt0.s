# MEOW

.intel_syntax prefix

.section .text

.global _start
_start:
    # Set up end of the stack frame linked list
    movd ebp, 0
    push ebp
    push ebp
    movd ebp, esp

    # We need those in a moment when we call main
    push esi
    push edi

    # Prepare signals, memory allocation, stdio and such.
    call initialize_standard_library

    # Run the global constructors.
    call _init

    # Restore argc and argv.
    popd rdi
    popd rsi

    # Run main
    call main

    # Terminate the process with the exit code.
    movd eax, edi
    call exit
.size _start, . - _start

.att_syntax prefix
