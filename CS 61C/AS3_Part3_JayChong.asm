; Description: This program swaps the elements of the array by iterating through it with two pointers esi and edi
; from both ends and exchanging values.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/22/2023

.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

; Data section
.data
  array DWORD 1, 5, 6, 7, 0Ah, 1Bh, 1Eh, 22h, 2Ah, 32h  ; define an array of DWORD values

; Code section
.code
main proc
  mov esi, offset array  ; initialize esi with the address of the beginning of the array
  mov edi, offset array  ; initialize edi with the address of the beginning of the array
  mov ecx, lengthof array - 1  ; then set the loop counter to the length of the array minus one

  ; here we are looping to move edi to the end of the array
  l1:
    add edi, type array  ; first move edi to the next element in the array
    loop l1              ; then decrement ecx and continue looping until ecx becomes zero

  mov ecx, lengthof array  ; and reset the loop counter to the length of the array

  ; here we loop to swap elements from both ends of the array
  l2:
    mov eax, [esi]       ; load the value at esi (start of the array) into eax
    mov ebx, [edi]       ; and load the value at edi (end of the array) into ebx
    xchg eax, ebx        ; then swap the values in eax and ebx
    mov [esi], eax       ; store the swapped value back at esi
    mov [edi], ebx       ; store the swapped value back at edi

    add esi, type array  ; then move esi to the next element
    sub edi, type array  ; and move edi to the previous element
    dec ecx              ; finally decrement ecx (loop counter)

    loop l2              ; continue looping until ecx becomes zero

  invoke ExitProcess, 0  
main endp
end main
