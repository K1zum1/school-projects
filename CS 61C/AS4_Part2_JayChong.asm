; Description: This program clears the screen, prompts the user to enter two integers, adds them together, and displays the result.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/15/2023
; Creation date: 10/12/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
prompt1 BYTE "Enter an integer here: ",0
prompt2 BYTE "Enter another integer here: ",0
result BYTE "Sum: ",0
int1 dword ? ; define a random 32-bit integer variable 'int1'.

.code
main proc
    mov eax, 15          ; first we set EAX to 15.
    call SetTextColor    ; and set text color.
    call ClrScr          ; and clear the screen.

    mov dh, 12           ; then set the cursor position (row) to 12.
    mov dl, 40           ; and set the cursor position (column) to 40.
    call Gotoxy          ; finally move the cursor to the specified position.

    mov edx, OFFSET prompt1 ; then we can load the address of 'prompt1' into EDX.
    call WriteString     ; and display the prompt for user input.

    call ReadInt         ; read an integer from the user and store it in EAX.
    mov int1, eax        ; and store the user's input in the 'int1' variable.

    mov dh, 14           ; then set the cursor position (row) to 14.
    call Gotoxy          ; and move the cursor to the specified position.

    mov edx, OFFSET prompt2 ; load the address of 'prompt2' into EDX.
    call WriteString     ; then display the second prompt for user input.

    call ReadInt         ; read another integer from the user and add it to EAX.

    add eax, int1        ; and add the value in 'int1' to the user's input.

    mov dh, 15           ; then we can set the cursor position (row) to 15.
    call Gotoxy          ; and move the cursor to the specified position.

    mov edx, OFFSET result ; load the address of 'result' into EDX.
    call WriteString     ; and display the "Sum: " text.

    call WriteDec        ; and display the result of the addition.

    invoke ExitProcess, 0
main endp
end main
