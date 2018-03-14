TITLE Fibonacci Numbers     (Project02.asm)

;  Author: MRoss
;  Course /  Project ID : CS271 Project 2               Date: 10/15/17
;  Description: Greets the user, then displays Fibonacci numbers up to a user defined value less than 47

INCLUDE Irvine32.inc

;constants
UPPER_LIMIT = 47
NUMS_PER_LINE = 5

.data
intro_1			BYTE	"Fibonacci Numbers     by Michael J. Ross",0
ec_1			BYTE	"**EC: Display the numbers in aligned columns.",0
intro_2			BYTE	"What's your name? ",0
intro_3			BYTE	"Hello, ",0
instr_1			BYTE	"Enter the number of Fibonacci terms to be displayed.",0
instr_2			BYTE	"Give the number as an integer in the range [1 .. 46].",0
instr_3 		BYTE	"How many Fibonacci terms do you want? ",0
error_1			BYTE 	"Out of range. Enter a number in [1 .. 46].",0
spacer_1		BYTE	"              ",0
spacer_2		BYTE	"             ",0
spacer_3		BYTE	"            ",0
spacer_4		BYTE	"           ",0
spacer_5		BYTE	"          ",0
spacer_6		BYTE	"         ",0
spacer_7		BYTE	"        ",0
spacer_8		BYTE	"       ",0
spacer_9		BYTE	"      ",0
charCnt			BYTE	0
userName		BYTE	33 DUP(0)	;string to be entered by user
fibNums			DWORD 	?	;integer to be enetered by user
tmpInt			DWORD	?	;temp value for holding fib num
farewell_1		BYTE	"Results certified by Michael J. Ross.",0
repeat_1		BYTE	"Enter 1 if you would like to repeat this operation, otherwise enter 0: ",0
farewell_2		BYTE	"Goodbye, ",0
farewell_3		BYTE	".",0

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

;Prompt the user to enter the number of Fibonacci terms to be displayed. Advise the user to enter an integer in the range [1 .. 46].
userInstructions:
	mov		edx, OFFSET instr_1
	call 	WriteString
	call 	CrLf
	mov		edx, OFFSET instr_2
	call 	WriteString
	call 	CrLf
	call 	CrLf

;Get and validate the user input (n).
getUserData:
	mov		edx, OFFSET instr_3
	call 	WriteString
	call 	ReadInt
	call 	CrLf
	mov 	fibNums, eax

;Compare fibNums with UPPER_LIMIT, go back to userInstructions if invalid
	cmp 	eax, UPPER_LIMIT
	jge		invalidEntry
	cmp 	eax, 0
	jle 	invalidEntry
	jmp 	initFibs

;invalid entry
invalidEntry:
	mov 	edx, OFFSET error_1
	call 	WriteString
	call 	CrLf
	jmp 	getUserData

;Calculate and display all of the Fibonacci numbers up to and including the nth term. The results should be displayed 5 terms per line with at least 5 spaces between terms.
initFibs:
	mov 	ecx, fibNums
	mov 	eax, 1
	mov 	ebx, 1
	mov 	charCnt, 0

;Display first two numbers, checking if fibNums has been reached yet
	cmp 	ecx, 0
	jle		farewell
	call 	WriteDec
	inc 	charCnt
	dec 	ecx

	mov		edx, OFFSET spacer_1
	call 	WriteString

	cmp 	ecx, 0
	jle		farewell
	call 	WriteDec
	inc 	charCnt
	dec 	ecx
	call 	WriteString

;Go to end if there were only two digits
	cmp 	ecx, 0
	jle		farewell

displayFibs:
;swap eax, ebx
	mov		tmpInt, eax
	mov		eax, ebx
	mov		ebx, tmpInt 

;add the two
	add 	eax, ebx

;write eax
	call 	WriteDec
	inc 	charCnt

;spacing jump - jump to spacing spot based on how many
;digits the number is
	cmp 	charCnt, NUMS_PER_LINE
	jge 	spacing10

	cmp 	eax, 100000000
	jge		spacing9

	cmp 	eax, 10000000
	jge		spacing8

	cmp 	eax, 1000000
	jge		spacing7

	cmp 	eax, 100000
	jge		spacing6

	cmp 	eax, 10000
	jge		spacing5

	cmp 	eax, 1000
	jge		spacing4

	cmp 	eax, 100
	jge		spacing3

	cmp 	eax, 10
	jge		spacing2

	jmp		spacing1

endLoop1:
	loop 	displayFibs		
	jmp		farewell

;spacing block - determines how many spaces to use based
;on how many digits the number is
spacing1:
	mov 	edx, OFFSET spacer_1
	call 	WriteString
	jmp 	endLoop1

spacing2:
	mov 	edx, OFFSET spacer_2
	call 	WriteString
	jmp 	endLoop1

spacing3:
	mov 	edx, OFFSET spacer_3
	call 	WriteString
	jmp 	endLoop1

spacing4:
	mov 	edx, OFFSET spacer_4
	call 	WriteString
	jmp 	endLoop1

spacing5:
	mov 	edx, OFFSET spacer_5
	call 	WriteString
	jmp 	endLoop1

spacing6:
	mov 	edx, OFFSET spacer_6
	call 	WriteString
	jmp 	endLoop1

spacing7:
	mov 	edx, OFFSET spacer_7
	call 	WriteString
	jmp 	endLoop1

spacing8:
	mov 	edx, OFFSET spacer_8
	call 	WriteString
	jmp 	endLoop1

spacing9:
	mov 	edx, OFFSET spacer_9
	call 	WriteString
	jmp 	endLoop1

spacing10:
	call 	CrLf
	mov 	charCnt, 0
	jmp		endLoop1
;end spacing block

farewell:

;Display a parting message that includes the user’s name, and terminate the program.
	call 	CrLf
	call 	CrLf
	mov		edx, OFFSET farewell_1
	call 	WriteString
	call 	CrLf
	call 	CrLf

;ask the user if they would like to repeat
	mov		edx, OFFSET repeat_1
	call 	WriteString
	call 	ReadInt
	call 	CrLf

;jump back to userInstructions if repeat is chosen
	cmp 	eax, 1
	je 		userInstructions

;exit message
	mov 	edx, OFFSET farewell_2
	call 	WriteString
	mov		edx, OFFSET userName
	call 	WriteString
	mov 	edx, OFFSET farewell_3
	call 	WriteString
	call 	CrLf
	call 	CrLf

	exit	; exit to operating system
main ENDP

	;  (insert additional procedures here)

END main