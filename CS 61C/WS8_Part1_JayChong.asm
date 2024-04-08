; Description: The program duplicates the last element of a five-value array to the position before it and then terminates.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/24/2023
; Creation date: 10/22/2023

.686p                              
.model flat,stdcall                
.stack 4096                        

ExitProcess PROTO, dwExitCode:DWORD   ; declare a prototype for the ExitProcess function, which takes a DWORD as an argument

.data                                
array dword 1, 2, 3, 4, 5             

.code                                
main PROC                            
    mov esi,lengthof array            ; first woad the length of 'array' into the ESI register
	dec esi                         ; and decrement ESI 
	mov edi,esi                      ; then copy the value of ESI into the EDI register
	dec edi                         ; decrement EDI 
	mov edx,array[esi*4]             ; then load the value of the last element in 'array' into the EDX register
	mov array[edi*4],edx             ;finally tore the value from the last element into the second to last element in 'array'
                                    

    invoke ExitProcess, 0            
main ENDP                           

END main                            
