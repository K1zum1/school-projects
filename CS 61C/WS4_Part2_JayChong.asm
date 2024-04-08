 ; Description: This simple code demonstrates the use of the data directive and the different data types.
 ; Author names: Jay Chong
 ; Author emails: jchong269@insite.4cd.edu
 ; Last modified date: 9/9/2023
 ; Creation date: 9/9/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

str1 TEXTEQU <"hamburger">

.data
;symbolic
	var1 BYTE str1

.code
main proc

	invoke ExitProcess,0
main endp
end main