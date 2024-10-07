#=================================================================
# Copyright 2024 Georgia Tech.  All rights reserved.
# The materials provided by the instructor in this course are for
# the use of the students currently enrolled in the course.
# Copyrighted course materials may not be further disseminated.
# This file must not be made publicly available anywhere.
# =================================================================

# HW2-2
# Student Name: Marcello Palucci
# Date:
#
#     I c o n   M a t c h
#
# This routine determines which of eight candidate icons matches a pattern icon.
#
#===========================================================================
# CHANGE LOG: brief description of changes made from P1-2-shell.asm
# to this version of code.
# Date  Modification
# 10/5	Initial code started 
# 10/6  Use only one register to compare to Pattern
#===========================================================================

.data
CandBase: 	.alloc 1152
PatternBase:	.alloc 144

.text
IconMatch:	addi	$1, $0, CandBase	# point to base of Candidates
	############################################################
	#      For debugging only: set $2 to -1 before swi 584 to  #
	#      allow previously generated puzzle to be loaded in   #
	       #addi    $2, $0, -1              
	############################################################

	        swi	584			# generate puzzle icons
	
	############################################################
	# The follow is an example of how to use the debugging     #
	# swi 585 to highlight certain cells.                      #
	# REMOVE THIS FROM YOUR CODE                               #
	#	addi    $2, $0, CandBase        # 0th icon, 0th cell
	#	swi     585
	#	addi    $2, $2, 20		# 0th icon, cell 5
	#	swi     585
	#	addi    $2, $0, PatternBase
	#	addi    $2, $2, 20		# pattern, cell 5
	#	swi     585
	# BESURE TO REMOVE ALL swi 585 DEBUGGING CODE before       #
	# submitting your code (otherwise it will count against    #
	# your static and dynamic instruction counts)              #
	############################################################
	
	addi	$8, $0, 0
	addi	$18, $0, 0					#base array
	addi 	$7, $0, 0					#px offset counter
	addi	$13, $0, 0					#jump to / to check other candidates
	addi	$21, $0, CandBase
#	addi	$24, $0, 0
	addi	$27, $0, 7

MLoop:	lw		$5, PatternBase($7)		#load PatternBase's offset
		addi 	$2, $7, PatternBase 	#set up patterBase debugger px locator
		swi		585						#call locator debugger

		addi	$24, $0, 0
		addi 	$7, $7, 4 				#increment px offset counter by 4 bytes / i++ jump (take next line too j Mloop)
		bne 	$5, $0, PtCmp			#if(patternBase[i] != 0) (ie if patternBase px is black then increment px offset)
		addi	$18, $18, 4
		j		MLoop

PtCmp:	lw		$20, CandBase($18)
		
		addi 	$8, $8, 0
		add 	$2, $18, $21 			#set up patterBase debugger px locator
		swi		585	
		addi	$18, $18, 576
		beq		$5, $20, CnCmp
		addi	$8, $8, 1
		
		addi	$13, $0, 4
		addi	$24, $24, 1
		j		PtCmp
CnCmp:	lw		$5, CandBase($18)
		slti	$25, $24, 7
		beq		$25 $0, End
#		lw		$5, CandBase($18)
		add 	$2, $18, $21 			#set up patterBase debugger px locator
		swi		585	
		
		addi	$24, $24, 1
		beq		$5, $20, SkipTo
		addi	$18, $18, 576

#		lw		$5, CandBase($18)
		


#		slti	$25, $24, 7
#		beq		$5, $20, SkipTo 
#		addi	$24, $24, 1
#		beq		$25 $0, End
		
#		addi	$18, $18, 576
		j		CnCmp

SkipTo:	beq		$27, $24, Reset
		addi	$18, $18, 576
		addi	$24, $24, 1
		 
		add 	$2, $18, $21 			#set up patterBase debugger px locator
		swi		585	
#		addi	$24, $24, 1
#		addi	$24, $24, 1
#		addi	$18, $18, 576 
		
#		addi	$24, $24, 1
#		addi	$18, $18, 576 
		j		SkipTo

Reset:	addi	$18, $18, -4028
		add 	$2, $18, $21 			#set up patterBase debugger px locator
		swi		585
		j		MLoop

End:    addi    $2, $8, 0               # REPLACE: guess the first icon
		swi	544			# submit answer and check
		jr	$31			# return to caller
