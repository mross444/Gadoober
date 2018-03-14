TITLE Composite Numbers      (Project04.asm)

;  Author: Michael J Ross
;  Course /  Project ID : CS271 Project 4               Date: 11/3/17
;  Description: Gets a number from the user and displays that number
;		of composite numbers in ascending order

INCLUDE Irvine32.inc

;constants
UPPER_LIMIT = 400
NUMS_PER_LINE = 10

.data
intro_1			BYTE	"Composite Numbers      Programmed by Michael J. Ross",0
ec_1			BYTE	"**EC: ",0

instr_1			BYTE	"Enter the number of composite numbers you would like to see.",0
instr_2			BYTE	"I'll accept orders for up to ",0
instr_3 		BYTE	" composites.",0
instr_4			BYTE	"Enter the number of composites to display [1 .. ",0
instr_5			BYTE	"]: ",0

error_1			BYTE	"Out of range.  Try again.",0

spacer_1		BYTE	"     ",0

closing_1		BYTE 	"Results certified by Michael J. Ross.  Goodbye.",0

repeat_1		BYTE	"Enter 1 if you would like to repeat this operation, otherwise enter 0: ",0

userNum			DWORD	?			;user-defined number of composites to display
displayCnt		DWORD	0			;composites displayed so far
lineCnt			DWORD	0			;numbers displayed on current line so far
validFlg		DWORD	0			;0 if invaid number, 1 if valid
cmpstFlg		DWORD	0			;composite flag - 0 if not a composite, 1 if a composite
chkNum			DWORD	3			;number to check if composite. starts at 3 since 4 is first number
cntSave_1		DWORD	?			;used for storing count in display compositeloop

chkNumLimit_1	DWORD	?			;lower bound for isComposite chkNum
chkNumLimit_2	DWORD	?			;upper bound for isComposite chkNum
chkNum_2 		DWORD	?			;used for composite checking

debug_1			BYTE	"__DEBUGGING__",0
debug_2			BYTE	"__CHECK1__",0
debug_3			BYTE	"__CHECK2__",0
debug_4			BYTE	"__CHECK1__",0

.code
main PROC
	call 	introduction
	call 	getUserData
	call 	showComposites
	call 	farewell


	exit	; exit to operating system
main ENDP

;additional procedures

;**************************************************
;                  introduction
;   Displays intro message and instructions.
;
;   Registers modified: EAX, EDX
;**************************************************
introduction 	PROC
	mov		edx, OFFSET intro_1
	call 	WriteString
	call 	CrLf
	call 	CrLf
	mov 	edx, OFFSET instr_1
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET instr_2
	call 	WriteString
	mov 	eax, UPPER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET instr_3
	call 	WriteString
	call 	CrLf
	call	CrLf

	ret
introduction 	ENDP

;**************************************************
;                  getUserData
;   Gets the number from the user and checks for
;	validity.  Repeats if invliad number is enetered.
;
;   Registers modified: EAX, EBX, EDX
;	Variables modified: userNum, validFlg 
;**************************************************
getUserData		PROC

startGetData:
	;prompt
	mov		edx, OFFSET instr_4
	call 	WriteString
	mov 	eax, UPPER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET instr_5
	call 	WriteString

	;get input
	call 	ReadInt

	;store input
	mov 	userNum, eax

	;call validateUserData
	call 	validateUserData

	;check if validFlg was set to false, and return 
	;to start if so
	mov 	ebx, 0
	cmp 	validFlg, ebx
	jne 	continueToPrint

	;show message and return to start if invalid
	mov 	edx, OFFSET error_1
	call 	WriteString
	call 	CrLf
	jmp 	startGetData

continueToPrint:
	ret
getUserData 	ENDP


;**************************************************
;                validateUserData
;           -- getUserData subroutine --
;   Checks the upper and lower bounds of userNum 
;	for validity.
;
;	Registers modified: EBX
;	Variables modified: validFlg
;**************************************************
validateUserData 	PROC
	;check upper bound
	cmp 	userNum, UPPER_LIMIT
	jg		setFlagFalse

	;check lower bound
	mov 	ebx, 0
	cmp 	userNum, ebx
	jle 	setFlagFalse

	;set to true if passed
	mov 	validFlg, 1
	jmp 	endValidate

setFlagFalse:
	mov 	validFlg, 0

endValidate:

	ret
validateUserData 	ENDP


;**************************************************
;                showComposites
;   Loops through numbers, displaying numbers that 
;   are composites.  Completes once the user-defined
;	amount of composites have been displayed.

;   Registers modified: EAX, EBX, ECX, EDX
;	Variables modified: chkNum, chkNum_2, cmpstFlg, 
;      lineCnt, chkNumLimit_2
;**************************************************
showComposites 		PROC
	;set ecx counter with the userNum
	mov 	ecx, userNum

startCompositeLoop:
	
loopChk1:
	inc 	chkNum
	call 	isComposite

	cmp 	cmpstFlg, 0
	je 		loopChk1

	mov 	eax, chkNum
	call 	WriteDec
	mov 	edx, OFFSET spacer_1
	call 	WriteString

	inc 	lineCnt

	;determine if line break is needed
	cmp 	lineCnt, NUMS_PER_LINE
	je 		addLineBreak

	jmp 	endLoop1

addLineBreak:
	call 	CrLf
	mov 	lineCnt, 0

endLoop1:
	loop 	startCompositeLoop

	call 	CrLf
	call 	CrLf

	ret
showComposites 		ENDP

;**************************************************
;                 isComposite
;         --showComposites subroutine--
;   Checks whether the value in chkNum is a 
;	composite or not, updating the cmpstFlg based
;   on the result.
;
;   Registers modified: EAX, EBX, EDX
;   Variables modified: chkNum_2, chkNumLimit_2
;**************************************************
isComposite 		PROC
	
	;first, check if the number is even.  all even numbers
	;greater than 2 are composites
	mov 	eax, chkNum
	mov 	ebx, 2
	mov 	edx, 0
	div 	ebx
	cmp 	edx, 0
	je 		setCompositeFlgTrue

	;next, we check if the number is divisible by 3.
	mov 	eax, chkNum
	mov 	ebx, 3
	mov 	edx, 0
	div 	ebx
	cmp 	edx, 0
	je 		setCompositeFlgTrue

	;if still not composite, we need to check disibility 
	;by odd numbers between 5 and userNum/5

	mov 	chkNum_2, 5
	mov 	eax, chkNum
	mov		ebx, 5
	mov 	edx, 0
	div 	ebx
	mov 	chkNumLimit_2, eax

startChkLoop_1:
	;check if we are already at the limit
	mov 	ebx, chkNumLimit_2
	cmp 	chkNum_2, ebx
	jg 		endChkLoop_1

	mov 	eax, chkNum
	mov 	ebx, chkNum_2 
	mov 	edx, 0
	div 	ebx

	;check for divisibility
	mov 	ebx, 0
	mov 	eax, edx
	cmp 	eax, ebx
	je 		setCompositeFlgTrue

	;if not divisible, add 2, then check if upper limit
	;is reached
	mov 	ebx, 2
	add 	chkNum_2, ebx

	mov 	ebx, chkNumLimit_2
	cmp 	chkNum_2, ebx
	jge 	endChkLoop_1		
	jmp		startChkLoop_1

endChkLoop_1:

	;no matches found, so set flag to 0 (number is prime)
	mov		cmpstFlg, 0
	jmp 	endIsComposite

setCompositeFlgTrue:
	mov 	cmpstFlg, 1

endIsComposite:

	ret
isComposite 		ENDP

;**************************************************
;                  farewell
;          Displays ending message.
;
;          Registers modified: EDX
;**************************************************
farewell 	PROC
	mov		edx, OFFSET closing_1
	call 	WriteString
	call 	CrLf
	call 	CrLf

	ret
farewell 	ENDP


END main