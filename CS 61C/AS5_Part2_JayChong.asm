; Description: This program compares values (ebx, ecx, and val1) and sets the value of X based on the comparison results.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/31/2023
; Creation date: 10/25/2023

INCLUDE Irvine32.inc    

.386                    
.model flat,stdcall     
.stack 4096             
ExitProcess proto,dwExitCode:dword   

.data                    
val1 dword ?            ; first declare uninitialized variable val1
X dword ?               ; then declare uninitialized variable X

.code                    
main proc               

	cmp ebx,ecx          ; first compare the values in ebx and ecx
	ja l1                ; if ebx > ecx, jump to label l1
	cmp ebx,val1         ; then compare the values in ebx and val1
	ja l1                ; if ebx > val1, jump to label l1
	mov X,2              ; if none of the above conditions met, set X to 2
	jmp next             ; and jump to the next label after l1
	l1: mov X,1          ; if any of the above conditions met, set X to 1
	next:                
     invoke ExitProcess, 0 
main endp               
