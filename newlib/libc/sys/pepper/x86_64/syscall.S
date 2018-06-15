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

    test %rax, %rax
    jns 1f
    mov %fs:0, %rsi
    neg %eax
    mov %eax, __tls_errno@tpoff(%rsi)
    mov $-1, %eax

1:
    pop %rbp
    ret
