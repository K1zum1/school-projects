; Description: This program demonstrates the use of the shift and rotate instructions
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 11/12/2023
; Creation date: 11/10/2023
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


.code

;part 1
  shl eax,4 ; multiples the value of eax by 16
;part 2
  shr ebx,2 ; divides the value of ebx by 4
;part 3
  ror dl,4 ; rotates the value of dl by 4 bits to the right

;part 4 - EBX would equal BFAFF69Fh
;part 5 - RBX would equal 0000000050509B64h

main proc			

	invoke ExitProcess,0
main endp
end main