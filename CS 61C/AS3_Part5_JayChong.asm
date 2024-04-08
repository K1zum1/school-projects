; Description: This program uses the XCHG instruction three times to reorder the values from A, B, C, D to B, C, D, A.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/27/2023

.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

; Data section
.data
  array1 byte 10h, 20h, 30h, 40h ; define an array 'array1' with four byte values

  array2 word 2 dup(0)           ; define another array 'array2' with two word values (initialized to 0)

; Code section
.code
main proc
  mov ax, word ptr array1    ; first we can load the first 16-bit value from 'array1' into register ax (A)
  mov bx, word ptr [array1+2] ; then load the second 16-bit value from 'array1' into register bx (B)

  xchg al, ah                ; swap the low and high bytes of ax (A and B are now B and A)
  xchg ah, bl                ; swap the high byte of ax with the low byte of bx (B and A are now B and C)
  xchg bl, bh                ; swap the low byte of bx with the high byte of bx (B and C are now C and B)

  mov array2, ax             ; and store the value of ax (C) into the first word of 'array2'
  mov array2+2, bx           ; then sttore the value of bx (B) into the second word of 'array2'

  mov eax, dword ptr array2  ; load the 32-bit value from 'array2' into eax (D)

  invoke ExitProcess, 0  
main endp
end main
