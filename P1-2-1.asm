#=================================================================
# Copyright 2024 Georgia Tech.  All rights reserved.
# The materials provided by the instructor in this course are for
# the use of the students currently enrolled in the course.
# Copyrighted course materials may not be further disseminated.
# This file must not be made publicly available anywhere.
# =================================================================

# HW2-2
# Student Name: Marcello Palucci
# Date: 10/5/2024
#
#     I c o n   M a t c h
#
# This routine determines which of eight candidate icons matches a pattern icon.
#
#===========================================================================
# CHANGE LOG: brief description of changes made from P1-2-shell.asm
# to this version of code.
# Date  Modification
# 10/5 initial coding

#===========================================================================

.data
CandBase: 		.alloc 1152
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
	#
	
	# your code goes here

		addi 	$7, $0, 0				#px offset counter
		#addi 	$8, $0, 0 				#boolean: px matches the Pattern
		#addi	$9, $0, 1				#boolean: px matches another Cand
		addi	$8, $0, 8

	########## loop to skip over black px in Pattern ###########
MLoop:	lw		$5, PatternBase($7)		#load PatternBase's offset
		addi 	$2, $7, PatternBase 	#set up patterBase debugger px locator
		swi		585						#call locator debugger
		bne 	$5, $0, Then			#if(patternBase[i] != 0) (ie if patternBase px is black then increment px offset)
		addi 	$7, $7, 4 				#increment px offset counter by 4 bytes / i++ jump (take next line too j Mloop)
		j		MLoop					

	########### here we will begin to compare pixels ###########
Then:	addi	$9, $7, CandBase		#reg 7 is j
		
outer:	lw		$10, CandBase($7)
		addi 	$2, $9, 0			 	#set up patterBase debugger px locator
		swi		585						#call locator debugger
		bne		$5, $10, incJ			

#chk0:	bne		$20,  

#chk1:

#chk2:

incJ:	addi	$9, $9, 576		#nned to remove
		addi	$7, $7, 576
		j		outer

Exit:	addi    $2, $0, 0               # REPLACE: guess the first icon
		swi	544			# submit answer and check
		jr	$31			# return to caller
