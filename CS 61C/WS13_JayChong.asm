; Description: This program takes in 3 integers and returns 1 if they are all different and 0 if they are not.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/28/2023
; Creation date: 11/25/2023

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
diffins proto firstin:dword, secondin:dword, thirdin:dword

.data
  in1  dword  4
  in2  dword  5
  in3  dword  52
  in4  dword  2
  in5  dword  11
  in6  dword  56
  in7  dword  73
  in8  dword  22
  in9  dword  13
  in10 dword 10
  in11 dword 11
  in12 dword 12
  in13 dword 16
  in14 dword 14
  in15 dword 15

.code
main proc
  invoke diffins, in1, in2, in3   ; invoke diffins to check if in1, in2, and in3 are different
  invoke diffins, in4, in5, in6   ; invoke diffins to check if in4, in5, and in6 are different
  invoke diffins, in7, in8, in9   ; invoke diffins to check if in7, in8, and in9 are different
  invoke diffins, in10, in11, in12 ; invoke diffins to check if in10, in11, and in12 are different
  invoke diffins, in13, in14, in15 ; invoke diffins to check if in13, in14, and in15 are different

  invoke ExitProcess, 0
main endp

diffins proc firstin:dword, secondin:dword, thirdin:dword ;
  push ebx                       ; save the value of the ebx register on the stack
  push edx                       ; and save the value of the edx register on the stack
  mov eax, firstin               ; then move the value of firstin into the eax register
  mov ebx, secondin              ; and move the value of secondin into the ebx register
  mov edx, thirdin               ; and move the value of thirdin into the edx register

  cmp eax, ebx
  je notdiff                      ; if in1 is equal to in2, jump to notdiff
  cmp ebx, edx
  je notdiff                      ; if in2 is equal to in3, jump to notdiff
  cmp eax, edx
  je notdiff                      ; if in1 is equal to in3, jump to notdiff
  mov eax, 1                       ; and if none of the above conditions are true, set eax to 1
  jmp ending                      ; then jump to ending

  notdiff:
    mov eax, 0                     ; if any of the above conditions are true, set eax to 0

  ending:
    pop edx
    pop ebx

  ret
diffins endp
end main
