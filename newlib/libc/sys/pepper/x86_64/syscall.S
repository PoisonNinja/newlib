.global syscall
syscall:
    mov %rdi, %rax
    mov %rsi, %rdi
    mov %rdx, %rsi
    mov %rcx, %rdx
    mov %r8, %r10
    mov %r9, %r8
    syscall

    cmpq $-4096, %rax
    ja 1f
    ret

1:
    neg %eax
    mov %fs:0, %rsi
    mov %eax, __tls_errno@tpoff(%rsi)
    movq $-1, %rax
    ret
