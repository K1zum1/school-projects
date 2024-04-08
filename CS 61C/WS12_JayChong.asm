; Description: This program counts the number of 1's in a 32-bit binary number
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/20/2023
; Creation date: 11/18/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code
main proc
  ; first we initialize the 32-bit binary number in ebx
  mov ebx,00110101b
  ; then call the CountBits function to count the number of set bits 
  call CountBits
  ; and set eax to 0 (not necessary for this specific code)
  mov eax,0
main endp


CountBits proc
  ; we need to preserve ebx and ecx registers
  push ebx
  push ecx
  ; and then initialize the loop counter ecx to 32 (number of bits in a DWORD)
  mov ecx,32
  ; and initialize eax to 0 (to store the count of set bits)
  mov eax,0

  
  l1: shr ebx,1      ; then we can shift the bits to the right (carry flag contains the value of the last bit)
    jnc l2          ; and jump to l2 if the carry flag is not set (last bit was 0)
    inc eax         ; increment the count if the last bit was 1
  l2: loop l1        ; and continue the loop until ecx becomes zero

  ; then we can restore preserved registers
  pop ecx
  pop ebx

  ; and finally return from the procedure
  ret
CountBits endp


invoke ExitProcess,0
end main
