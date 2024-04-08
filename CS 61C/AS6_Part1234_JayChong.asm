; Description: This program demonstrates the use of the shift, rotate, multiply, and divide instructions
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/12/2023
; Creation date: 11/10/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

; part 1
.data
  byteArray byte 81h,20h,33h
.code
  shr byteArray+2,1  ; first shift right the third byte in byteArray by 1 bit
  rcr byteArray+1,1  ; then rotate right through carry the second byte in byteArray by 1 bit
  rcr byteArray,  1  ; and rotate right through carry the first byte in byteArray by 1 bit

; part 2
.data
  wordArray word 810Dh,0C064h,93ABh
.code
  shl wordArray,  1  ; first shift left the first word in wordArray by 1 bit
  rcl wordArray+2,1  ; then rotate left through carry the second word in wordArray by 1 bit
  rcl wordArray+4,1  ; and rotate left through carry the third word in wordArray by 1 bit

; part 3
.data
  val1 dword ?
  val2 dword ?
  val3 dword ?
  val4 dword ?
.code
  mov eax,val2      ; load val2 into eax
  mov ebx,val3      ; and then load val3 into ebx
  mul ebx           ; then multiply eax by ebx, result in edx:eax
  mov ebx,val4      ; and load val4 into ebx
  sub ebx,3         ; then subtract 3 from ebx
  div ebx           ; and divide edx:eax by ebx, result in eax
  mov val1,eax      ; and store result in val1

; part 4
  mov eax,val2      ; load val2 into eax
  cdq               ; then sign extend eax into edx:eax for division
  mov ebx,val3      ; and load val3 into ebx
  idiv ebx          ; divide edx:eax by ebx, result in eax
  mov ebx,val1      ; then load val1 into ebx
  add ebx,val2      ; and add val2 to ebx
  imul ebx          ; then multiply eax by ebx, result in eax
  mov val1,eax      ; finally store result in val1

main proc
	invoke ExitProcess,0  

main endp
end main
