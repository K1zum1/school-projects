 ; Description: This simple code demonstrates the use of the data directive and the different data types.
 ; Author names: Jay Chong
 ; Author emails: jchong269@insite.4cd.edu
 ; Last modified date: 9/9/2023
 ; Creation date: 9/9/2023

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


.data
;data def
	valB BYTE 255
	valSB SBYTE -128
	valW WORD 65535
	valSW SWORD -32768
	valDW DWORD 4294967295
	valSD SDWORD -2147483648
	valFW FWORD 281474976710,655
	valQW QWORD 18446744073709551615
	valTB TBYTE 1000000000123456789Ah
	valR4 REAL4 -1.2
	valR8 REAL8 1.0E-260
	valR10 REAL10 1.0E+4000


.code
main proc

	invoke ExitProcess,0
main endp
end main