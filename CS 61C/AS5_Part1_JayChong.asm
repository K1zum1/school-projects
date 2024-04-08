; Description: This program initializes and potentially manipulates an array of 7 double words (dword) in memory.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 10/31/2023
; Creation date: 10/25/2023

INCLUDE Irvine32.inc   

.386                    
.model flat,stdcall     
.stack 4096             

ExitProcess proto,dwExitCode:dword   

N = 7                    ; define a random constant N with value 7

.data                    
array dword N dup(?)     ; first declare an array of N (7) uninitialized double words
j dword ?                ; then declare uninitialized variable j
k dword ?                ; and declare uninitialized variable k

.code                    
main proc               

	mov j,-5             
	mov k,5               
	mov esi,offset array  ; load the starting address of array into esi
	mov ecx,N             ; and load N (7) into ecx
	call fArray           ; then call the function fArray (which seems to be missing in the provided code)

	mov j,0               
	mov k,15              
	mov esi,offset array  ; load the starting address of array into esi
	mov ecx,N             ; and load N (7) into ecx
	call fArray           ; then call the function fArray (which seems to be missing in the provided code)

	call WaitMSG          ; and call the function WaitMSG (this function might be from the Irvine library to wait for a keypress, but not provided in the code)

	exit                  

    invoke ExitProcess, 0 
main endp               
end main                