; Description: This program adds loops through an array and adds the difference between each element to a result variable. 
; Basically the Fibonacci sequence
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/8/2023
; Creation date: 10/4/2023


.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
array DWORD 0,2,5,9,10   
result DWORD 0            


.code
main proc
    mov ecx, LENGTHOF array  ; load the length of the array into the ECX register
    mov ESI, OFFSET array    ; and then load the address of the array into the ESI register

L1:
    MOV EAX,[ESI]           ; next load the value at the current position of the array into EAX
    MOV EBX,[ESI+4]         ; and load the value at the next position of the array into EBX
    SUB EBX,EAX             ; calculate the difference between the two values and store it in EBX
    ADD result,EBX          ; and add the difference to the "result" variable
    ADD ESI, TYPE array     ; move the pointer to the next DWORD in the array
Loop L1

    invoke ExitProcess,0

main endp
end main
