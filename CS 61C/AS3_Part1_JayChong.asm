; Description: This program demonstrates converting from big endian to little endian.
; Author names: Jay Chong
; Author emails: jchong269@insite.4cd.edu
; Last modified date: 9/27/2023
; Creation date: 9/21/2023


.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

; Data section
.data
  bigEndian BYTE 12h,34h,56h,78h   ; big-endian data
  littleEndian DWORD ?             ; placeholder for little-endian result

; Code section
.code
main proc
  mov ax, WORD PTR [bigEndian+2]  ; first we load the third byte (big-endian)
  mov cl, 16                      ; then shift 16 bits (2 bytes)
  shl eax, cl                     ; and shift the third byte to the most significant position
  mov ax, WORD PTR bigEndian      ; after that we load the first two bytes (big-endian)
  mov littleEndian, eax           ; and store the little-endian result in littleEndian variable
  mov ebx, 0                      ; finally set ebx to 0 (unused)

  invoke ExitProcess, 0          

main endp
end main
