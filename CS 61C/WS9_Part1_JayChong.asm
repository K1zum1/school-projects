; Description: This assembly code initializes two 32-bit values, SetX and SetY. 
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/31/2023
; Creation date: 10/22/2023

.386                                
.model flat,stdcall                 
.stack 4096                         
ExitProcess proto,dwExitCode:dword  

.data                               
SetX dword 12345678h                ; declare SetX with hex value 12345678.
SetY dword 48742813h                ; and declare SetY with hex value 48742813.

.code                               
main proc                           

    mov eax,SetX                    ; first we load the value of SetX into eax register.
    mov edx,eax                     ; and copy the value from eax to edx.
    and edx,SetY                    ; then do bitwise AND operation between edx (which now holds SetX's value) and SetY.
    sub eax,edx                     ; and finally subtract the result of AND operation from the original SetX value. Store the result in eax.

    invoke ExitProcess,0            

main endp                           
end main                            