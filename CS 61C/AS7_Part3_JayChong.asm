; Description: Simple assembly program that sets text color, writes a character, and exits.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/28/2023
; Creation date: 11/25/2023

INCLUDE Irvine32.inc ; Include the Irvine32 library for input/output operations
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword ; declare the ExitProcess function prototype
SetColor proto, forecolor:dword, backcolor:dword ; and declare the SetColor function prototype
WriteChar proto, char:dword ; here we declare the WriteChar function prototype

WriteColorChar proc char:dword, forecolor:dword, backcolor:dword ; then define the WriteColorChar procedure with three parameters
  invoke SetColor, forecolor, backcolor ; and set the text color using the SetColor function
  mov eax, char ; and move the value of char into the eax register
  invoke WriteChar ; then invoke the WriteChar function to write the character
  ret ; then we can return from the WriteColorChar procedure
WriteColorChar endp

.data
  fc dword ? ; then declare a variable fc to store the foreground color
  bc dword ? ; and declare a variable bc to store the background color
  charToWrite dword 'A' ; and declare a variable charToWrite and initialize it with the character 'A'

.code
main proc
  mov fc, 2 ; after that we can set the foreground color (2 represents green)
  mov bc, 0 ; and set the background color (0 represents black)

  call Crlf ; when we move the cursor to the beginning of the next line
  invoke WriteColorChar, charToWrite, fc, bc ; we can invoke WriteColorChar to write the character 'A' in green on a black background

  invoke ExitProcess, 0 
main endp

end main 
