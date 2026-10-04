global nv_matrix_multiply

section .text
nv_matrix_multiply:
    mov r8, rdi
    mov r9, rsi
    mov r10, rdx

    xor rax, rax

.row_loop:
    cmp rax, 4
    jge .done

    mov r11, rax
    shl r11, 4
    add r11, r9

    movss xmm0, [r11]
    movss xmm1, [r11 + 4]
    movss xmm2, [r11 + 8]
    movss xmm3, [r11 + 12]

    xor rcx, rcx
.col_loop:
    cmp rcx, 4
    jge .next_row

    mov r12, rcx
    shl r12, 4
    add r12, r10

    movss xmm4, [r12]
    movss xmm5, [r12 + 4]
    movss xmm6, [r12 + 8]
    movss xmm7, [r12 + 12]

    movaps xmm8, xmm0
    mulss xmm8, xmm4
    movaps xmm9, xmm1
    mulss xmm9, xmm5
    addss xmm8, xmm9
    movaps xmm9, xmm2
    mulss xmm9, xmm6
    addss xmm8, xmm9
    movaps xmm9, xmm3
    mulss xmm9, xmm7
    addss xmm8, xmm9

    mov r13, rax
    shl r13, 4
    add r13, rcx
    shl r13, 2
    add r13, r8
    movss [r13], xmm8

    inc rcx
    jmp .col_loop

.next_row:
    inc rax
    jmp .row_loop

.done:
    ret