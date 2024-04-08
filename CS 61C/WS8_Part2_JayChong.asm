; Description: This program writes a sequence of statements that display a subroutine’s return address
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/22/2023
; Creation date: 10/22/2023


INCLUDE Irvine32.inc
.686p
.model flat, stdcall
.stack 4096


ExitProcess PROTO, dwExitCode:DWORD


.data


.code
main PROC
    mov eax, [esp]    ; first we load the return address from the top of the stack into eax
    call WriteHex     ; then just call the WriteHex procedure to display the value in eax
main ENDP


END main
