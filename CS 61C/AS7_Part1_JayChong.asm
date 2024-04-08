; Description: This program demonstrates how to take three integer parameters and returns their sum in the EAX register.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/28/2023
; Creation date: 11/25/2023


INCLUDE Irvine32.inc


.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword


AddThree proc
  ; first we load the first parameter into eax
  mov eax, [esp + 4] 

  ; and then add the second parameter to eax
  add eax, [esp + 8] 

  ; then add the third parameter to eax
  add eax, [esp + 12]

  ; finally return with the result in eax
  ret
AddThree endp


main proc
  ; and initialize three numbers (1, 2, 3)
  mov eax, 1
  mov ebx, 2
  mov ecx, 3

  ; next we can call the AddThree procedure with parameters 1, 2, and 3
  call AddThree 

  invoke ExitProcess, 0
main endp


end main
