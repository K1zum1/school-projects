; Description: This program uses a loop to copy all elements from an unsigned word into an unsigned double word array
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/8/2023
; Creation date: 10/4/2023


.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
arrayW WORD 1234h, 5678h, 9ABCh, 0DEF0h
arrayD DWORD 0h                       

.code
main proc
    mov ecx, LENGTHOF arrayW   ; load the length of the arrayW into the ECX register
    mov esi, OFFSET arrayW    ; load the address of arrayW into the ESI register
    mov edi, OFFSET arrayD    ; load the address of arrayD into the EDI register

L1:
    mov eax, LENGTHOF arrayW   ; then we load the length of arrayW into EAX
    sub eax, ecx               ; and calculate the difference between the total length and the current position
    imul eax, TYPE arrayW      ; multiply the difference by the size of a WORD (2) to get the offset

    mov bx, [esi+eax]          ; load a WORD from arrayW at the calculated offset into BX
    movzx edx, bx              ; then zero-extend the WORD in BX to a DWORD in EDX
    imul eax, 2                ; multiply the offset by 2 to get the offset in arrayD (since DWORDs are twice the size of WORDs)
    mov [edi+eax], edx         ; and store the DWORD value from EDX into arrayD at the calculated offset

    LOOP L1                    ; continue looping while ECX is not zero

    invoke ExitProcess,0       
main endp
end main
