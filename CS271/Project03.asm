TITLE Integer Accumulator     (Project03.asm)

;  Author: Michael J Ross
;  Course /  Project ID : CS271 Project 2               Date: 10/25/17
;  Description: Program that gets negative numbers from user as input
;		and displays the sum and average of those numbers

INCLUDE Irvine32.inc

;constants
LOWER_LIMIT = -100

.data
intro_1			BYTE	"Welcome to the Integer Accumulator by Michael J. Ross",0
ec_1			BYTE	"**EC: Numbers lines during output and displays floating point quotient.",0
intro_2			BYTE	"What is your name? ",0
intro_3			BYTE	"Hello, ",0

instr_1			BYTE	"Please enter numbers in [-100, -1].",0
instr_2			BYTE	"Enter a non-negative number when you are finshed to see results.",0
instr_3 		BYTE	"Enter number ",0

colon_1			BYTE	": ",0

closing_1		BYTE 	"You entered ",0
closing_2		BYTE 	" valid numbers.",0
closing_3		BYTE	"The sum of your valid numbers is ",0
closing_4		BYTE	"The rounded average is ",0
closing_5		BYTE	"Thank you for playing Integer Accumulator! It's been a pleasure to meet you, ",0
closing_6		BYTE	".",0
closing_7		BYTE	"The floating point quotient is ",0

point_1			BYTE	".",0

error_1			BYTE	"No negenetive numbers were entered.",0
error_2			BYTE	"Number entered is out of range and will not be counted.",0

repeat_1		BYTE	"Enter 1 if you would like to repeat this operation, otherwise enter 0: ",0

userName		BYTE	33 DUP(0)	;user's name
numCnt			DWORD	0			;number of negative numbers entered
numSum			DWORD	0			;sum of negative numbers entered
numAvg			DWORD	?			;used in rounding founction
tmpVal			DWORD	?			;used in rounding function

debug_1			BYTE	"__DEBUGGING__",0

.code
main PROC

introduction:

;Display the program title and programmer’s name. 
	mov		edx, OFFSET intro_1
	call 	WriteString
	call 	CrLf
	mov		edx, OFFSET ec_1
	call 	WriteString
	call 	CrLf
	call 	CrLf

;Then get the user’s name
	mov		edx, OFFSET intro_2
	call 	WriteString
	mov		edx, OFFSET userName
	mov 	ecx, 32
	call 	ReadString

;and greet the user.
	mov 	edx, OFFSET intro_3
	call 	WriteString
	mov 	edx, OFFSET userName
	call 	WriteString
	call 	CrLf
	call 	CrLf

;Prompt the user to enter the non-negative numbers.
userInstructions:
	mov		edx, OFFSET instr_1
	call 	WriteString
	call 	CrLf
	mov		edx, OFFSET instr_2
	call 	WriteString
	call 	CrLf

;before loop starts, initialize sum and cnt to 0
	mov 	numCnt, 0
	mov 	numSum, 0

getNumbersLoop:
;get number
	mov		edx, OFFSET instr_3
	call	WriteString
	mov 	eax, numCnt 	;display count+1
	add 	eax, 1
	call 	WriteDec
	mov 	edx, OFFSET colon_1
	call 	WriteString
	call	ReadInt

;check if number is negative
	cmp		eax, -1
	jle		negNumEntered
	jmp 	numResults

negNumEntered:
;check if number is out of range
	cmp		eax, LOWER_LIMIT
	jl 		outOfRange_1	

;increment numCount
	inc 	numCnt

;add number entered to sum
	add 	numSum, eax
	jmp 	loopBack_1

outOfRange_1:
;handle out of range value
	mov 	edx, OFFSET error_2
	call 	WriteString
	call 	CrLf

loopBack_1:

;go back to getNumbersLoop
	jmp 	getNumbersLoop


numResults:
	;first, check if count is zero.  jump to error message if so
	cmp		numCnt, 0
	je 		noNumsEntered

	;display count
	mov		edx, OFFSET closing_1
	call 	WriteString
	mov 	eax, numCnt
	call	WriteDec
	mov		edx, OFFSET closing_2
	call 	WriteString
	call	CrLf

	;display sum
	mov		edx, OFFSET closing_3
	call 	WriteString
	mov 	eax, numSum
	call	WriteInt
	call 	CrLf

	;peform integer division
	mov 	eax, numSum
	cdq
	mov 	ebx, numCnt
	idiv 	ebx

	;store result in numAvg
	mov 	numAvg, eax

	;-----begin rounding-----

	;take the remainder and move it to eax
	mov 	eax, edx

	;reverse the sign of the quotient
	mov 	ebx, -1
	imul 	ebx

	;multiply by 10
	mov 	ebx, 10
	mul 	ebx

	;divide by numCnt again
	mov 	edx, 0
	div 	numCnt 

	;if result is greater than 5 we round down
	cmp 	eax, 5
	jg 		roundDown 

	;if it is less than 5 we do not round down
	cmp 	eax, 5
	jl 		noRoundDown

	;if it equals 5, we round down if there is a remainder
	;othersie noRoundDown
	mov 	edx, eax
	cmp 	eax, 0
	jne 	roundDown

noRoundDown:
	mov 	eax, numAvg
	jmp 	endRound_1

roundDown:
	mov 	eax, numAvg
	dec 	eax

endRound_1:

	;-----end rounding-----

	;display result
	mov		edx, OFFSET closing_4
	call 	WriteString
	call	WriteInt
	call 	CrLf

	;==========begin floating point quotient==========

	;display message
	mov 	edx, OFFSET closing_7
	call	WriteString

	;start with the average taken before rounding
	mov 	eax, numAvg
	call 	WriteInt

	;display point
	mov 	edx, OFFSET point_1
	call 	WriteString

	;peform integer division again
	mov 	eax, numSum
	cdq
	mov 	ebx, numCnt
	idiv 	ebx

	;move the remainder into eax
	mov 	eax, edx

	;Calculate 10ths
	mov 	ebx, -1
	imul 	ebx			;reverse the sign
	mov 	ebx, 10
	mov 	edx, 0
	mul 	ebx
	div		numCnt
	call 	WriteDec

	;Calculate 100ths 
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		numCnt
	call 	WriteDec

	;Calculate 1000ths 
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		numCnt

	;rounding
	mov		tmpval, eax
	mov		eax, edx
	mul		ebx
	mov		edx, 0
	div		numCnt
	mov		ebx, 5
	cmp 	eax, ebx
	jge		roundUp
	jmp 	noRoundUp

roundUp:
	mov 	tmpval, eax
	mov		ebx, 1
	add 	eax, ebx
	call 	WriteDec
	jmp 	endRound_2

noRoundUp:
	mov 	tmpval, eax
	call 	WriteDec

endRound_2:
	call 	CrLf

	;===========end floating point quotient===========

	;go to farewell
	jmp 	farewell

noNumsEntered:
	mov 	edx, OFFSET error_1
	call 	WriteString
	call 	CrLf

farewell:
;ask the user if they would like to repeat
	mov		edx, OFFSET repeat_1
	call 	WriteString
	call 	ReadInt

;jump back to userInstructions if repeat is chosen
	cmp 	eax, 1
	je 		userInstructions

;Display a parting message that includes the user’s name, and terminate the program.
	mov		edx, OFFSET closing_5
	call 	WriteString
	mov		edx, OFFSET userName
	call 	WriteString
	mov 	edx, OFFSET closing_6
	call 	WriteString
	call 	CrLf
	call 	CrLf

	exit	; exit to operating system
main ENDP

	;  (insert additional procedures here)

END main