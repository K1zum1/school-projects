; Description: To exchange the values in EAX and EBX and to make a subroutine return to an address 4 bytes higher in memory before the RET instruction
; Basically the Fibonacci sequence
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/15/2023
; Creation date: 10/12/2023

.386              
.model flat,stdcall 

.stack 4096       
ExitProcess proto,dwExitCode:dword 

; part 1
.data
	var1 dword 6   ; define a variable named var1 and initialize it with the value 6
	var2 dword 5   ; define a variable named var2 and initialize it with the value 5

.code
main proc          

mov eax,var1       ; move the value of var1 into the EAX register
mov ebx,var2       ; and move the value of var2 into the EBX register

	push eax        ; first push the value in EAX onto the stack
	push ebx        ; and push the value in EBX onto the stack
	pop eax         ; and pop the value from the stack into EAX, effectively swapping EAX and EBX
	pop ebx         ; finally pop the value from the stack into EBX, completing the swap

; part 2	
	pop ecx         ; then pop the value from the stack into ECX
	add ecx,3       ; and add 3 to the value in ECX
	push ecx        ; push the updated value of ECX back onto the stack

	invoke ExitProcess,0 

main endp          
end main           
