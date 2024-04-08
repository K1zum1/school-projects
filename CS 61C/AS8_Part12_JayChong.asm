; Description: This program determines the larger of these two input strings and writes it to the console window.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 12/5/2023
; Creation date: 12/4/2023

INCLUDE irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data
  str1 byte "ABCDE", 0     ; first given string
  str2 byte "ABCDD", 0     ; second given string

.code
main proc
  ; first we invoke the Str_compare function to compare str1 and str2
  invoke Str_compare, offset str1, offset str2
  ; then if result is greater, jump to str1bigger
  ja str1bigger
  ; otherwise if not, move the address of str2 to edx and jump to print
  mov edx, offset str2
  jmp print

str1bigger:
  ; then if str1 is bigger, move the address of str1 to edx
  mov edx, offset str1

print:
  ; and call WriteString to print the larger string
  call WriteString
  ; and call Crlf to print a newline

; Description: Str_trim procedure to remove all trailing "@" characters from a string.
.data
  prob7string byte "ABCD@@@@", 0

.code
  ; first we invoke Str_trim to remove trailing "@" characters from prob7string
  invoke Str_trim, offset prob7string, '@'
  ; then move the address of the modified prob7string to edx
  mov edx, offset prob7string
  ; and call WriteString to print the modified string
  call WriteString
  ; and call Crlf to print a newline

  invoke ExitProcess, 0
main endp
end main
