TITLE Elementary Arithmetic     (Project01.asm)

;  Author:	Michael Ross
;  Course /  Project ID : CS 271 Project 1            Date: 10/1/17
;  Description:  Performs elementary arithmetic on a user-defined integer
;    and displays the results.

INCLUDE Irvine32.inc

;  note - no constant definitions for this program

.data
intro_1			BYTE	"Elementary Arithmetic     by Michael J. Ross",0
instr_1			BYTE	"Enter 2 numbers, and I'll show you the sum, difference, product, quotient, and remainder.",0
numprompt_1		BYTE	"First number: ",0
numprompt_2		BYTE	"Second number: ",0
sumdisplay		BYTE	" + ",0
diffdisplay		BYTE	" - ",0
proddisplay		BYTE	" x ",0
quotdisplay		BYTE	" / ",0
equaldisplay	BYTE	" = ",0
remaindisplay	BYTE	" remainder ",0
endmessage		BYTE	"Impressed?  Bye!",0
usernum_1		DWORD	?			;first number to be entered by user
usernum_2		DWORD	?			;second number to be entered by user
result_sum		DWORD	?
result_diff		DWORD	?
result_prod		DWORD	?
result_quot		DWORD	?
result_rmdr		DWORD	?


.code
main PROC

;Display introduction
	mov 	edx, OFFSET intro_1
	call 	WriteString
	call 	CrLf
	call 	CrLf

;Display instructions
	mov 	edx, OFFSET instr_1
	call 	WriteString
	call 	CrLf
	call 	CrLf

;Get two numbers from user
	mov 	edx, OFFSET numprompt_1
	call 	WriteString
	call 	ReadInt
	mov		usernum_1, eax
	mov 	edx, OFFSET numprompt_2
	call 	WriteString
	call 	ReadInt
	mov		usernum_2, eax	
	call 	CrLf

;Calculate sum
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET sumdisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					;calculate sum
	add		eax, ebx
	mov		ebx, result_sum
	mov		result_sum, eax
	call	WriteDec

	call	CrLf
	

;Calculate difference
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET diffdisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					;calculate diff
	sub		eax, ebx
	mov		ebx, result_diff
	mov		result_diff, eax
	call	WriteDec
										

	call	CrLf

;Calculate product
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET proddisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					;calculate prod
	mul		ebx
	mov		ebx, result_prod
	mov		result_prod, eax
	call	WriteDec

	call	CrLf

;Calculate quotient and remainder
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET quotdisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString
	
	mov		eax, usernum_1
	mov		ebx, usernum_2					;calculate quot
	div		ebx
	
	mov		result_quot, ebx
	mov		result_rmdr, edx
	mov		eax, result_quot
	call	WriteDec										

	mov		edx, OFFSET remaindisplay		;remainder
	call	WriteString
	mov		eax, result_rmdr
	call    WriteDec
	call	CrLf
	call	CrLf

;Display terminating message
	mov		edx, OFFSET endmessage
	call	WriteString
	call	CrLf
	call	CrLf

	exit	; exit to operating system
main ENDP

	;  (insert additional procedures here)

END main