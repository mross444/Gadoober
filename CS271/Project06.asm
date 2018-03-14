TITLE Composite Numbers      (Project06.asm)

;  Author: Michael J Ross
;  Course /  Project ID : CS271 Project 6B               Date: 12/2/17
;  Description:  A program that creates combination problems and allows
;		user to guess the answer.  Problems follow the form of "r" items
;		out of a set of "n" possible choices.  Program picks n and r 
;		randomly in a bounded range.  Once user guesses at the answer,
;		program will display whether or not they were correct, and will
;		allow the user to go again if desired.

INCLUDE Irvine32.inc

;constants
R_LOWER_LIMIT = 1
N_LOWER_LIMIT = 3
N_UPPER_LIMIT = 12

.data
intro_1			BYTE	"Welcome to Combinations Calculator      Programmed by Michael J. Ross",0
ec_1			BYTE	"**EC: ",0

instr_1			BYTE	"I'll give you a combinations problem.  You enter your answer,",0
instr_2			BYTE	"and I'll let you know if you're right.",0

input_1			BYTE	"Problem:",0
input_2			BYTE	"Number of elements in the set: ",0
input_3			BYTE	"Number of elements to choose from the set: ",0
input_4			BYTE	"How many ways can you choose? ",0

error_1			BYTE	"Invalid response. ",0

result_1		BYTE	"There are ",0
result_2		BYTE	" combinations of ",0
result_3		BYTE	" items from a set of ",0
result_4		BYTE	".",0
result_5		BYTE	"You are correct!",0
result_6		BYTE	"You need more practice.",0
result_7		BYTE	"Another problem? (y/n): ",0

closing_1		BYTE	"OK ... goodbye.",0

myN 			DWORD	?
myR				DWORD	?
myAnswer		DWORD	?
myResult		DWORD	?
go_again		BYTE 	33 DUP(0)		;string response when user is asked whether or not to repeat

.code
main PROC

	pushad

	call 	Randomize				;set seed for rng

	call 	introduction

problem_loop:
	push 	OFFSET myR
	push 	OFFSET myN
	call 	showProblem

	push 	OFFSET myAnswer
	call 	getData

	push 	myR
	push 	myN
	push 	OFFSET myResult
	call 	combinations

	push 	OFFSET go_again
	push 	myR
	push 	myN
	push 	myAnswer
	push 	myResult
	call	showResults

	;check to go again
	cmp 	go_again, 1
	je 		problem_loop

	popad

	exit	; exit to operating system
main ENDP

;additional procedures

;macro for writing strings - referenced from module slides
mWriteStr MACRO buffer
	push edx
	mov  edx,OFFSET buffer
	call WriteString
	pop  edx
ENDM

;**************************************************
;                  introduction
;   display title, programmer name, and instructions
;
;   Registers modified: none
;**************************************************
introduction 	PROC

	mWriteStr 	intro_1
	call 		CrLf
	call 		CrLf
	mWriteStr 	instr_1
	call 		CrLf
	mWriteStr 	instr_2
	call 		CrLf
	call 		CrLf

	ret
introduction 	ENDP

;**************************************************
;                   showProblem
;   Calculates n and r using randomRange, then
; 	displays the problem to the user.
;	
;	Parameters: myN (reference), myR (reference)
;   Registers modified: none
;**************************************************
showProblem 	PROC

	;set up stack frame
	push 		ebp
	mov 		ebp, esp

	push 		eax
	push 		edi

	;display "Problem:"
	mWriteStr 	input_1
	call 		CrLf

	;calculate n first - use randomRange
	mov 		eax, N_UPPER_LIMIT
	sub 		eax, N_LOWER_LIMIT
	inc 		eax
	call 		RandomRange
	add 		eax, N_LOWER_LIMIT

	mov 		edi, [ebp+8]
	mov 		[edi], eax

	;display n
	mWriteStr	input_2	
	call 		WriteDec
	call 		CrLf

	;calculate r using randomRange
	sub 		eax, R_LOWER_LIMIT
	inc 		eax
	call 		RandomRange
	add 		eax, R_LOWER_LIMIT 		

	;store value in n address
	mov 		edi, [ebp+12]
	mov 		[edi], eax

	;display r
	mWriteStr	input_3	
	call 		WriteDec
	call 		CrLf

	;done
	pop 		edi
	pop 		eax
	pop 		ebp

	ret 		8
showProblem 	ENDP

;**************************************************
;                     getData
;   Gets the user's guess at the problem and stores
; 	the value in myAnswer
;	
;	Parameters: myAnswer (reference)
;   Registers modified: none
;**************************************************
getData 	PROC

	;set up stack frame
	push 	ebp
	mov 	ebp, esp

	push 	eax
	push 	edi

	mWriteStr 	input_4
	call 	ReadInt
	mov 	edi, [ebp + 8]
	mov 	[edi], eax

	;done
	pop 	edi
	pop 	eax
	pop 	ebp

	ret 	4
getData 	ENDP

;**************************************************
;                  combinations
;   Calculates the answer to the problem using the 
; 	equation n!/((r!)(n-r)!).  Calls the factorial
;	subroutine defined below.
;	
;	Parameters: myR (value), myN (value), myResult (reference)
;   Registers modified: none
;**************************************************
combinations 	PROC

 	;set up stack frame
 	push 		ebp
 	mov 		ebp, esp

 	pushad

 	;get n factorial
 	mov 		eax, [ebp + 12]
 	push 		eax
 	call 		factorial

 	;store in esi
 	mov 		esi, eax


 	;get r factorial
 	mov 		eax, [ebp + 16]
 	push 		eax
 	call 		factorial

 	;store in edi
 	mov 		edi, eax

 	;get (n - r) factorial
 	mov 		eax, [ebp + 12]
 	mov 		ebx, [ebp + 16]
 	sub 		eax, ebx
	push		eax
 	call 		factorial

 	;multiply by r factorial
 	mul 		edi

 	mov 		ebx, eax
 	mov 		eax, esi
 	mov 		edx, 0

 	div 		ebx

 	;store the result
 	mov 		edi, [ebp + 8]
 	mov 		[edi], eax

 	popad

 	pop 		ebp

	ret 		12
combinations 	ENDP

;**************************************************
;                  factorial
;   Calculates factorial of the provided value and 
; 	stores is in EAX. 
;	Reference: Irvine textbook
;	
;	Parameters: num (value)
;   Registers modified: eax, ebx
;**************************************************
factorial 	PROC

 	;set up stack frame
 	push 		ebp
 	mov 		ebp, esp

 	mov 		eax, [ebp + 8]

 	cmp 		eax, 0
 	jne			fact_recurse
 	mov 		eax, 1
 	jmp 		fact_end

fact_recurse:
	dec 		eax
	push 		eax
	call 		factorial

	mov 		ebx, [ebp + 8]
	mul 		ebx

fact_end:

 	;end
 	pop 		ebp	

	ret 		4
factorial 	ENDP

;**************************************************
;                   showResults
;	Shows summary of the problem and the result.
;	Displays a message indicating whether or not the
;	user guessed correctly.  Prompts the user if they
;	would like to go again, then stores the response
; 	in go_again.
;   
;	Parameters: myN, myR, myAnswer, myRequest (value),
;	go_again (reference)
;   Registers modified: none 
;**************************************************
showResults 	PROC

	push 		ebp
	mov 		ebp, esp

	pushad

	call 		CrLf
	mWriteStr 	result_1
	mov 		eax, [ebp + 8]
	call 		WriteDec
	mWriteStr	result_2
	mov 		eax, [ebp + 20]
	call 		WriteDec
	mWriteStr	result_3
	mov 		eax, [ebp + 16]
	call 		WriteDec
	mWriteStr 	result_4
	call 		CrLf

	mov 		eax, [ebp + 8]
	mov 		ebx, [ebp + 12]

	cmp 		eax, ebx
	je 			result_correct

	;incorrect
	mWriteStr	result_6
	jmp			result_end

result_correct:
	mWriteStr 	result_5

result_end:
	call 		CrLf
	call 		CrLf


go_again_start:
	;prompt to go again
	mWriteStr 	result_7
	mov 		edi, [ebp+24]
	mov 		edx, edi
	mov			ecx, 32
	call 		ReadString

	mov			esi, OFFSET go_again
	lodsb
	
	;'Y'
	cmp 		al, 89
	je 			go_again_yes

	;'y'
	cmp 		al, 121
	je 			go_again_yes

	;'N'
	cmp 		al, 78
	je 			go_again_no

	;'n'
	cmp 		al, 110
	je 			go_again_no

	;invalid response
	mWriteStr 	error_1
	call 		CrLf
	jmp 		go_again_start


;store the response in go_again
go_again_yes:
	mov 		edi, [ebp + 24]
	mov			ebx, 1
	mov 		[edi], ebx
	call 		CrLf
	jmp 		go_again_done

go_again_no:
	mov 		edi, [ebp + 24]
	mov			ebx, 0
	mov 		[edi], ebx
	call 		CrLf
	mWriteStr	closing_1
	call 		CrLf
	call 		CrLf

go_again_done:
	;end
	
	popad

	pop 		ebp

	ret 		20
showResults 	ENDP

END main