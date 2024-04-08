; Description:This program generates random grades (A, B, C, D, or F) and displays them.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/06/2023
; Creation date: 10/31/2023

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096

ExitProcess proto, dwExitCode: dword

.data
  ;define a variable to store the grade.
  grade BYTE ?

  ; define constants for grade letters.
  aGrade BYTE "A", 0
  bGrade BYTE "B", 0
  cGrade BYTE "C", 0
  dGrade BYTE "D", 0
  fGrade BYTE "F", 0

.code
main proc
  ; first we call the Randomize function to initialize the random number generator.
  call Randomize

  ; and initialize a loop counter (ecx) to 5.
  mov ecx, 5

  
  L1:
    ; first set eax to 51 and call RandomRange to get a random number between 50 and 100.
    mov eax, 51
    call RandomRange
    add eax, 50

    ; then call the GradeCalc function to determine the grade based on the random number.
    call GradeCalc

    ; and store the result (grade) in the grade variable.
    mov edx, 0
    mov grade, al

    ; then display the grade character.
    mov edx, OFFSET grade
    call WriteChar

    ; and move to the next line.
    call Crlf

    ; and decrement the loop counter (ecx) and loop if ecx is not zero.
    loop L1

  exit
main endp

GradeCalc proc
  ; check the value in eax to determine the grade.
  .IF eax >= 90
    mov al, aGrade
  .ELSEIF eax >= 80
    mov al, bGrade
  .ELSEIF eax >= 70
    mov al, cGrade
  .ELSEIF eax >= 60
    mov al, dGrade
  .ELSEIF eax >= 0
    mov al, fGrade
  .ENDIF

  ; then return with the appropriate grade character in al.
  ret
GradeCalc endp


invoke ExitProcess, 0
end main
