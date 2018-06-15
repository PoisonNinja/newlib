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
    pop %rbp
    ret
