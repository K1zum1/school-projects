; Description: This program compares register values and sets the value of X based on the comparison results.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/31/2023
; Creation date: 10/25/2023

INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code                    
main proc               ; start of the main procedure

cmp ebx,ecx             ; compare values in ebx and ecx
	jna l2                ; if ebx <= ecx, jump to label l2
	cmp ebx,edx           ; compare values in ebx and edx
	jna l2                ; if ebx <= edx, jump to label l2
	jmp l3                ; jump to label l3 if neither of the above conditions met

	l2: cmp edx,eax       ; if we jumped to l2, compare edx and eax
	jna l5                ; if edx <= eax, jump to label l5
	l3: mov X,1           ; set X to 1 if we're in l3 or passed through the first conditions without jumping to l2
	jmp next2             ; jump to next2 label
	l5: mov X,2           ; if we jumped to l5, set X to 2
	next2:                

     invoke ExitProcess, 0 
main endp               
end main      