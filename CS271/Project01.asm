TITLE Elementary Arithmetic     (Project01.asm)

;  Author:	Michael Ross
;  Course /  Project ID : CS 271 Project 1            Date: 10/1/17
;  Description:  Performs elementary arithmetic on a user-defined integer
;    and displays the results.

INCLUDE Irvine32.inc

.data
intro_1			BYTE	"Elementary Arithmetic     by Michael J. Ross",0
intro_2			BYTE	"**EC1: Validates second number is less than the first.",0
intro_3			BYTE	"**EC2: Caclulates a rounded floating point quotient.",0
intro_4			BYTE	"**EC3: When completed, prompts user to run again.",0
instr_1			BYTE	"Enter 2 numbers, and I'll show you the sum, difference, product, quotient, and remainder.",0
numprompt_1		BYTE	"First number: ",0
numprompt_2		BYTE	"Second number: ",0
sumdisplay		BYTE	" + ",0
diffdisplay		BYTE	" - ",0
proddisplay		BYTE	" x ",0
quotdisplay		BYTE	" / ",0
equaldisplay	BYTE	" = ",0
remaindisplay	BYTE	" remainder ",0
num2message		BYTE	"The second number must be less than the first!",0
endmessage		BYTE	"Impressed?  Bye!",0
exitmessage		BYTE	"Would you like to repeat this operation?  Press 1 to continue: ",0
space_1			BYTE	"  (",0
space_2			BYTE	")",0
point_1			BYTE	".",0
usernum_1		DWORD	?			;first number to be entered by user
usernum_2		DWORD	?			;second number to be entered by user
result_sum		DWORD	?
result_diff		DWORD	?
result_prod		DWORD	?
result_quot		DWORD	?
result_rmdr		DWORD	?
tmpval			DWORD	?
exitflag		BYTE	0

.code
main PROC

;Display introduction
	mov 	edx, OFFSET intro_1
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET intro_2
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET intro_3
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET intro_4
	call 	WriteString
	call 	CrLf	
	call 	CrLf

startMath:

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

;Compare the two values			
	mov		eax, usernum_1				
	cmp 	eax, usernum_2
	jl		error1							;jump if second num is greater


;Calculate and display sum
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET sumdisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					
	add		eax, ebx						;calculate sum
	mov		result_sum, eax
	call	WriteDec
	call	CrLf
	

;Calculate and display difference
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET diffdisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					
	sub		eax, ebx						;calculate diff
	mov		result_diff, eax
	call	WriteDec
	call	CrLf

;Calculate and display product
	mov		eax, usernum_1					;first num
	call	WriteDec
	mov		edx, OFFSET proddisplay			;operator
	call	WriteString
	mov		eax, usernum_2					;second num
	call	WriteDec
	mov		edx, OFFSET equaldisplay		;equal
	call	WriteString

	mov		eax, usernum_1
	mov		ebx, usernum_2					
	mul		ebx								;calculate prod
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
	
	mov		edx, 0
	mov		eax, usernum_1
	mov		ebx, usernum_2					
	div		ebx								;calculate quot
	
	mov		result_quot, eax
	mov		result_rmdr, edx
	call	WriteDec										

	mov		edx, OFFSET remaindisplay		;remainder
	call	WriteString
	mov		eax, result_rmdr
	call    WriteDec

;Calculate floating point quotient
	mov		edx, OFFSET space_1
	call 	WriteString

	mov		eax, result_quot
	call 	WriteDec

;Calculate 10ths
	mov 	ebx, 10
	mov 	edx, OFFSET point_1
	call 	WriteString
	mov		eax, result_rmdr
	mov 	edx, 0
	mul 	ebx
	div		usernum_2
	call 	WriteDec

;Calculate 100ths 
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		usernum_2
	call 	WriteDec

;Calculate 1000ths 
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		usernum_2

;rounding
	mov		tmpval, eax
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		usernum_2
	mov		ebx, 5
	cmp 	eax, ebx
	jge		roundup
	jmp 	noroundup

roundup:
	mov 	tmpval, eax
	mov		ebx, 1
	add 	eax, ebx
	call 	WriteDec
	jmp 	endround

noroundup:
	mov 	tmpval, eax
	call 	WriteDec

endround:

;end parentheses
	mov		edx, OFFSET space_2
	call 	WriteString

	call	CrLf
	call	CrLf

;Jump past error block
	jmp 	exitPrompt

error1:											; second num was greater block
	mov 	edx, OFFSET num2message
	call	WriteString
	call	CrLf
	call	CrLf

exitPrompt:
;ask user to go again or exit
	mov		edx, OFFSET exitmessage
	call 	WriteString
	call 	readInt
	call 	CrLf
	cmp 	eax, 1
	jne 	theEnd							;go to the end if user did not enter 1
	jmp 	startMath						;otherwise, go back to startMath


theEnd:

;Display terminating message
	mov		edx, OFFSET endmessage
	call	WriteString
	call	CrLf
	call	CrLf

	exit	; exit to operating system
main ENDP

END main