extern Init_EFI

BITS 64
DEFAULT REL

section .text
global efi_main

efi_main:
    ; Microsoft x64 ABI:
    ; RCX = ImageHandle
    ; RDX = EFI_SYSTEM_TABLE*

    push rbp
    mov rbp, rsp
    sub rsp, 32

    mov r8, rdx
    mov r9, rcx

    mov rcx, [r8 + 0x60]
    mov rdx, message
    mov rax, [rcx + 0x18]
    call rax

    mov rcx, r8
    mov rdx, r9
    call Init_EFI

.hang:
    hlt
    jmp .hang

section .data
message:
    dw 'F','S','L','_','E','F','I','_','V','1','.','0',13,10,0
