; Description: This program displays the string "Hello World" in a console window.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/28/2023
; Creation date: 11/25/2023


INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword


SetColor proc forecolor:dword, backcolor:dword
  
  mov eax, backcolor   ; first move the backcolor into eax
  shl eax, 4           ; then shift it left by 4 bits (multiply by 16)
  add eax, forecolor   ; then we can add the forecolor to the shifted backcolor
  call SetTextColor    ; and call the Irvine32 procedure to set the text color
  ret                  ; finally return from the procedure
SetColor endp


.code
main proc
  
  .data
    fc dword 83         ; this is the foreground color 
    bc dword 37         ; this is the background color 
    prompt byte "Hello World", 0ah ; random string to be printed


  .code
  ; then we can set the text color using the SetColor procedure
  invoke SetColor, fc, bc 

  ; then output a newline
  call Crlf

  
  mov edx, offset prompt ; then we load the address of the prompt string into edx
  call WriteString       ; and call the Irvine32 procedure to write the string to the console

  ; finally wait for a key press
  call WaitMsg

  
  invoke ExitProcess, 0
main endp

end main
