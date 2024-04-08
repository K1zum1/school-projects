; Description: This program checks the value of ecx against val1 and edx. 
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/31/2023
; Creation date: 10/22/2023

.386                                
.model flat,stdcall                 
.stack 4096                         
ExitProcess proto,dwExitCode:dword  

.data                               
val1 dword ?                        ; declare a 32-bit variable named val1 without initializing it.
X dword ?                           ; and declare a 32-bit variable named X without initializing it.

.code                               

cmp val1,ecx                        ; first we compare the value in val1 with ecx.
jna l1                              ; then jump to label l1 if val1 is below or equal to ecx.
cmp ecx,edx                         ; and compare the value in ecx with edx.
jna l1                              ; then jump to label l1 if ecx is below or equal to edx.
mov X,1                             ; if neither of the above conditions are met, set X to 1.
jmp next                            ; jump to the next label to continue the program.
l1: 
mov X,2                             ; and if any of the above conditions were met, set X to 2.
next:                               

invoke ExitProcess,0                

main endp                           
end main                            
