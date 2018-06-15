.global syscall
syscall:
    push %rbp
    mov %rsp, %rbp

    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    mov %rcx, %rdx
    mov %r8, %r10
    mov %r9, %r8
    syscall

    test %rdx, %rdx
    jz 1f
    mov %fs:0, %rsi
    mov %rdx, __tls_errno@tpoff(%rsi)

1:
    pop %rbp
    ret
