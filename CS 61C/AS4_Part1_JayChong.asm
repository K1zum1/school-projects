; Description: This program displays a string 4 times, each time in a different color.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/15/2023
; Creation date: 10/12/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc ; 

.data
str1 BYTE "hello this is an assignment",0 ; define a random null-terminated string.

.code
main proc
    mov eax, blue      ; we can assume 'blue' is a defined constant or variable.
    mov ecx, 4         ; then set up a loop counter (loop 4 times).
L1:
    call SetTextColor  ; call a function to set text color (assumed Irvine32 function).
    mov edx, OFFSET str1 ; and load the address of the 'str1' string into EDX.
    call WriteString  ; then call the function to display the string.
    call Crlf         ; and call a function to print a newline character.
    add eax, 3         ; finally add 3 to EAX (assuming it's used for some purpose).
    loop L1           ; and ecrement ECX and repeat the loop if not zero.

    invoke ExitProcess, 0 
main endp
end main
