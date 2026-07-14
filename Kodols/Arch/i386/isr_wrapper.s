.align 4
.global isr_wrapper

isr_wrapper:
    pushal
    cld
    call isr_handler
    popal
    iret
