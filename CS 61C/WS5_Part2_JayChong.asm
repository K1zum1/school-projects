; Description: This program uses a loop and indirect addressing to copy a string and reverse the character order.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/23/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


.data
    source BYTE "This is the source string",0   ; source string
    target BYTE SIZEOF source DUP('#')          ; target string filled with '#' characters


.code
main proc
    mov esi, 0                   ; source pointer (start)
    mov edi, LENGTHOF source - 2 ; destination pointer (end)
    
    ; first we initialize loop counter with the size of the source string
    mov ecx, SIZEOF source

L1: 
    ; here we load a character from the source into AL register
    mov al, source[esi]

    ; then store the character from AL register into the target string
    mov target[edi], al

    ; after that increment source pointer and decrement destination pointer
    inc esi
    dec edi

    ; then decrement the loop counter
    loop L1

    ; load the address of the target string into EDX register
    mov edx, OFFSET target

    invoke ExitProcess, 0

main endp
end main
