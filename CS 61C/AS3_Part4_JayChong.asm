; Description: This program swaps the two 16-bit values stored in the variable 'three' by using registers ax and bx as temporary storage.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/26/2023


.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

; Data section
.data
  three word 12h, 34h ; define a variable 'three' with two 16-bit values: 12h and 34h

; Code section
.code
  mov ax, word ptr three    ; then load the first 16-bit value from 'three' into register ax
  mov bx, word ptr [three+2] ; and then load the second 16-bit value from 'three' into register bx
  mov three, bx             ; store the value from bx (second value) back into 'three'
  mov word ptr [three+2], ax ; store the value from ax (first value) back into 'three'

  ; at this point, the values in 'three' have been swapped
  invoke ExitProcess, 0
main end
end main
