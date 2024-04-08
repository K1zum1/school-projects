; Description: This program exchanges every pair of value in an array with an even number of elements
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/23/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
array dword 1,2,3,4,5,6,7,8   ; here I define an array of 4 DWORDs with initial values.

.code
main proc
 mov esi, OFFSET array      ; then I will nitialize the source index (esi) to point to the beginning of the array.
 mov ecx, LENGTHOF array - 1  ; and also nitialize the loop counter (ecx) to the length of the array minus 1.

L1:
  MOV eax,[esi]            ; then we can load the first DWORD at the current position into eax.
  XCHG eax,[esi+4]         ; and exchange the contents of eax with the next DWORD in the array.
  MOV [esi],eax            ; finally store the updated value back into the current position in the array.

  add esi, TYPE array      ; next move the source index (esi) to the next pair of DWORDs in the array.
  add esi, TYPE array

loop L1                    ; repeat the loop until ecx becomes zero.

invoke ExitProcess,0       
main endp
end main
