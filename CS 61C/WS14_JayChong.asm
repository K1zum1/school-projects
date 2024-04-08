; Description: This program finds the largest number in an array
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 12/02/2023
; Creation date: 12/02/2023

INCLUDE irvine32.inc  
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
array1 sdword -15,-4,2,6,13  ; we can first define an array of integers
arraySize1 dword 5            ; and specify the size of the array
FindLargest proto array:ptr sdword, arraySize:dword  ; then declare the FindLargest function prototype

.code
main proc
 invoke FindLargest, addr array1, lengthof array1  ; then we call FindLargest function

  invoke ExitProcess,0
main endp


FindLargest proc array:ptr sdword, arraySize:dword
  mov esi,array         ; first we need to set esi to point to the beginning of the array
  mov ecx,arraySize     ; then set ecx to the size of the array
  mov eax,[esi]         ; after that we can initialize eax with the first element of the array
  dec ecx               ; and decrement the array size counter
  l1:
    add esi,4           ; move to the next element in the array (4 bytes per integer)
    mov ebx,[esi]       ; load the current element into ebx

    cmp ebx,eax         ; then compare the current element with the current maximum
    jle checkNum        ; and jump to checkNum if the current element is less than or equal to the maximum

    mov eax,ebx         ; after that we can update the maximum with the current element
    
    checkNum:
      loop l1           ; finally repeat the loop until all elements are processed
  ret
FindLargest endp

end main
