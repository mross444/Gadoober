TITLE Composite Numbers      (Project04.asm)

;  Author: Michael J Ross
;  Course /  Project ID : CS271 Project 5               Date: 11/19/17
;  Description: Creates an array of random numbers, then sorts the 
; 	 array and calculates the median.

INCLUDE Irvine32.inc

;constants
NUM_LOWER_LIMIT = 100
NUM_UPPER_LIMIT = 999
CNT_LOWER_LIMIT = 10
CNT_UPPER_LIMIT = 200

.data
intro_1			BYTE	"Sorting Random Numbers      Programmed by Michael J. Ross",0
ec_1			BYTE	"**EC: ",0

instr_1			BYTE	"This program generates random numbers in the range [",0
instr_2			BYTE	" .. ",0
instr_3 		BYTE	"],",0
instr_4			BYTE	"displays the original list, sorts the list, and calculates the",0
instr_5			BYTE	"median value.  Finally, it displays the list sorted in descending order.",0

getdata_1		BYTE	"How many numbers should be generated? [",0
getdata_2		BYTE	"]: ",0

error_1			BYTE	"Invalid input",0

spacer_1		BYTE	"     ",0

title_1			BYTE	"The unsorted random numbers:",0
title_2			BYTE	"The sorted list:",0

result_1		BYTE	"The unsorted random numbers:",0
result_2		BYTE	"The median is ",0
result_3		BYTE	".",0
result_4		BYTE	"The sorted list:",0

repeat_1		BYTE	"Enter 1 if you would like to repeat this operation, otherwise enter 0: ",0

debug_1			BYTE	"__DEBUGGING__",0
debug_2			BYTE	"__CHECK1__",0
debug_3			BYTE	"__CHECK2__",0
debug_4			BYTE	"__CHECK1__",0

myRequest		DWORD	?
myArray			DWORD	CNT_UPPER_LIMIT DUP(?)

.code
main PROC
	call 	Randomize				;set seed for rng

	call 	introduction			

	push	OFFSET myRequest

	call 	getData

	push 	OFFSET myArray
	push 	myRequest
	call 	fillArray

	;display unsorted random numbers
	push 	OFFSET myArray
	push 	myRequest
	push 	OFFSET title_1
	call 	displayList

	;sort the array 
	push 	OFFSET myArray
	push 	myRequest
	call 	sortList

	;display median
	push 	OFFSET myArray
	push 	myRequest
	call 	displayMedian

	;display sorted array
	push 	OFFSET myArray
	push 	myRequest
	push 	OFFSET title_2
	call 	displayList



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
	mov 	edx, OFFSET instr_1
	call 	WriteString
	mov 	eax, NUM_LOWER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET instr_2
	call 	WriteString
	mov 	eax, NUM_UPPER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET instr_3
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET instr_4
	call 	WriteString
	call 	CrLf
	mov 	edx, OFFSET instr_5
	call 	WriteString
	call 	CrLf
	call 	CrLf

	ret
introduction 	ENDP

;**************************************************
;                   getData
;   Get a user request in the range [min = 
;	CNT_LOWER_LIMIT .. max = CNT_UPPER_LIMIT]. 
;	Validates the request, looping until valid 
; 	input is provided
;	
;	Parameters: myRequest (reference)
;   Registers modified: eax, edx
;**************************************************
getData 	PROC

	;set up stack frame
	push 	ebp
	mov 	ebp, esp

collect_data:
	mov		edx, OFFSET getdata_1
	call 	WriteString
	mov 	eax, CNT_LOWER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET instr_2
	call 	WriteString
	mov 	eax, CNT_UPPER_LIMIT
	call 	WriteDec
	mov 	edx, OFFSET getdata_2
	call 	WriteString
	
	;get the input
	call 	ReadInt

	;validate 

	;check lower bound
	cmp 	eax, CNT_LOWER_LIMIT
	jl 		invalid_entry

	;check upper bound
	cmp 	eax, CNT_UPPER_LIMIT
	jg 		invalid_entry

	jmp 	end_getData

invalid_entry:
	mov		edx, OFFSET error_1
	call 	WriteString
	call 	CrLf
	jmp		collect_data


end_getData:
	
	mov 	ebx, [ebp+8]
	mov 	[ebx], eax

	call 	CrLf

	pop 	ebp

	ret 	4

getData 	ENDP

;**************************************************
;                   fillArray
;   Generate request random integers in the range 
;	[lo = NUM_LOWER_LIMIT .. hi = NUM_UPPER_LIMIT], 
;	storing them in consecutive elements of an array.
;	
;	Parameters: request (value), array (reference)
;   Registers modified: eax, ecx, edi
;**************************************************
fillArray 	PROC
	push	ebp
	mov 	ebp, esp
	mov 	ecx,[ebp+8]		;set loop counter
	mov 	edi,[ebp+12]	;set address of array in edi

loopAgain:
	;get random number in range
	mov 	eax, NUM_UPPER_LIMIT
	sub 	eax, NUM_LOWER_LIMIT
	inc 	eax
	call 	RandomRange
	add 	eax, NUM_LOWER_LIMIT
	
	;store in array position
	mov 	[edi], eax

	;increment array position
	add 	edi, 4
	
	loop 	loopAgain

	pop		ebp

	ret 	8

fillArray 	ENDP

;**************************************************
;                   sortList
;   Sort the list in descending order.  Implemented
; 	using selection sort
;	
;	Parameters: array(reference), request (value)
;   Registers modified: eax, ebx, ecx, edx, esi, edi
;**************************************************
sortList 	PROC

	push	ebp
	mov 	ebp, esp
	;esi -- i
	;ebx -- j
	;edx -- k
	mov 	edi,[ebp+12]

	mov 	edx, 0
	mov 	ecx, [ebp+8]
	dec 	ecx
	;for(k=0; k<request-1; k++) {

	sortLoop1:

		;i = k;
		mov 	esi, edx

		push 	ecx
		mov 	ebx, edx
		inc 	ebx
		mov 	ecx, [ebp+8]
		sub 	ecx, ebx
		;for(j=k+1; j<request; j++) {

		sortLoop2:

			push 	edx
			;if(array[j] > array[i]){

				mov 	eax, ebx
				add 	eax, eax
				add 	eax, eax

				mov 	edx, esi
				add 	edx, edx
				add 	edx, edx

				mov 	eax,[edi+eax]
				mov 	edx,[edi+edx]

				cmp 	eax, edx

				jle 	chkFalse

				;i=j
				mov 	esi, ebx
			;}

			chkFalse:
			pop 	edx

			inc 	ebx
			loop 	sortLoop2
		;}

		pop 	ecx

		;exchange(array[k],array[i])

		push 	ebx

		;calculate offsets (multiplied by 4)
		mov 	eax, edx
		add 	eax, eax
		add 	eax, eax

		mov 	ebx, esi
		add 	ebx, ebx
		add 	ebx, ebx

		add 	ebx, edi
		add 	eax, edi

		push 	ebx
		push 	eax
		call 	exchangeElements

		pop 	ebx

		inc 	edx
		loop 	sortLoop1
	;}

	pop		ebp

	ret 	8

sortList 	ENDP

;**************************************************
;                exchangeElements
;   for most sorting algorithms
;	
;	Parameters: array[i] (reference), array[j] 
;	(reference), where i and j are the indexes of
;	elements to be exchanged
;   Registers modified: eax, ebx
;**************************************************
exchangeElements 	PROC

	push 	ebp
	mov 	ebp, esp

	push	ecx
	push	edx

	mov 	eax, [ebp+8]
	mov 	ebx, [ebp+12]

	mov 	ecx, [eax]
	mov 	edx, [ebx]

	mov		[ebx], ecx
	mov		[eax], edx

	pop		edx
	pop		ecx

	pop 	ebp

	ret 	8

exchangeElements 	ENDP

;**************************************************
;                  displayMedian
;   Calculate and display the median value, rounded 
;	to the nearest integer. 
;	
;	Parameters: array (reference), request (value)
;   Registers modified: eax, ebc, ecx, edx, edu
;**************************************************
displayMedian 	PROC
	
	push 	ebp
	mov 	ebp, esp

	mov 	edx, OFFSET result_2
	call 	WriteString

	mov 	ebx, [ebp+8] 	;total count of numbers
	mov 	edi, [ebp+12]	;start of array
	mov 	ecx, 2

	;divide count by 2
	mov 	eax, ebx
	mov 	edx, 0
	div 	ecx

	cmp 	edx, 0
	je 		evenNumber

	mov 	ecx, 4
	mul 	ecx

	add 	eax, edi
	mov 	ebx, eax
	mov 	eax, [eax]




	jmp 	endMedian

evenNumber:
	mov 	ecx, 4
	mul 	ecx

	add 	eax, edi
	mov 	ebx, eax
	mov 	eax, [eax]

	sub 	ebx, 4
	mov 	ebx, [ebx]

	add 	eax, ebx
	mov 	edx, 0
	mov 	ecx, 2
	div 	ecx
	

endMedian:

	call 	WriteDec

	mov 	al, '.'
	call 	WriteChar

	call 	CrLf
	call 	CrLf

	pop 	ebp

	ret 	8

displayMedian 	ENDP

;**************************************************
;                   displayList
;   Displays the list, 10 numbers per line 
;	
;	Parameters: array (reference), request (value), 
;	title (reference)
;   Registers modified: eax, ebx, ecx, edx, esi, edi
;**************************************************
displayList 	PROC
	push	ebp
	mov 	ebp, esp
	mov 	edx, [ebp+8]
	call 	WriteString
	call 	CrLf

	;start displaying the list
	mov 	ebx, 0			;ebx will hold nums per line
	mov 	ecx, [ebp+12] 	;ecx is the total nums
	mov 	esi, [ebp+16]	;esi hold address of array
	mov		edi, 0			;edi is current item being displayed

displayLoop:

	mov		eax, [esi+edi]
	call 	WriteDec

	cmp 	ebx, 9
	je 		lineBreak

normalSpace:
	mov 	al, 32
	call 	WriteChar
	call 	WriteChar
	call 	WriteChar

	inc 	ebx
	jmp 	endSpace

lineBreak:
	call 	CrLf
	mov 	ebx, 0

endSpace:
	add 	edi, 4
	loop 	displayLoop

	call 	CrLf
	call 	CrLf

	pop 	ebp

	ret 	12

displayList 	ENDP

END main