.intel_syntax prefix

/* x86 crtn.s */
.section .init
    /* gcc will nicely put the contents of crtend.o's .init section here. */
    popd ebp
    ret

.section .fini
    /* gcc will nicely put the contents of crtend.o's .fini section here. */
    popd ebp
    ret

.att_syntax prefix
