
.global write
.global exit
.global reader
.global strncmp

.text

write:
        mov $0x1, %rax
        syscall
        xor %rax, %rax
        ret

exit:
        mov $0x3c, %rax
        syscall

reader: 
        mov $0x0, %rax
        syscall
        ret

strncmp:
        push   %rax
        xor    %eax, %eax
        jz     no_decomp
        add    $0x4, %rsp
        no_decomp:
        pop    %rax
        xor    %r8d,%r8d
        l3:
        cmp    %r8,%rdx
        lea    (%rsi,%r8,1),%r9
        je     l1
        mov    (%rdi,%r8,1),%al
        test   %al,%al
        je     l2 
        mov    (%rsi,%r8,1),%cl
        movsbl %al,%r10d
        inc    %r8
        xor    $0xc,%ecx
        movsbl %cl,%ecx
        add    $0x6,%ecx
        cmp    %ecx,%r10d
        je     l3
        jmp    l2
        l1:   
        xor    %eax,%eax
        retq   
        l2:
        movzbl (%r9),%edx
        movzbl %al,%eax
        sub    %edx,%eax
        retq   
