; Description: This program adds the two previous elements of an array and stores the sum in the current element. 
; Basically the Fibonacci sequence
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/23/2023


.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

; Data section
.data
  count dword 5           ; number of Fibonacci numbers to generate
  array dword 7 DUP(1, 1, ?, ?, ?, ?, ?) ; array to store Fibonacci numbers

; Code section
.code
main proc
  mov ecx, count          ; first we load the loop counter with the value of 'count'
  mov esi, offset array   ; then load the address of 'array' into esi
  add esi, type array     ; move esi to point to the third element of 'array'
  add esi, type array     ; and move esi to point to the fifth element of 'array'

l1:
    mov eax, [esi-4]      ; load the value of the previous element (second-to-last) into eax
    mov ebx, [esi-8]      ; then load the value of the element before that (last) into ebx
    add eax, ebx          ; then we can add the two previous elements
    mov [esi], eax        ; and store the sum in the current element
    add esi, type array   ; move esi to point to the next element in 'array'
    loop l1               ; and repeat the loop until ecx becomes zero

  invoke ExitProcess, 0   
main endp
end main
