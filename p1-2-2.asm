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
# 09/12 Looping through pixels of an icon to find a nonblack one    (example)
# 09/13 Reduced avg # dynamic insts by precomputing ... before loop (example)
# 09/19 Fixed bug with loop bounds causing infinite loop.           (example)
# ...
# REPLACE the (example) lines with your own list of changes.
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
	
	
	# your code goes here
	addi	$10, $0, 0
	addi	$11, $0, 576
	addi	$12, $0, 1152
	addi	$13, $0, 1728
	addi	$14, $0, 2304
	addi	$15, $0, 2880
	addi	$16, $0, 3456
	addi	$17, $0, 4032
	addi	$18, $0, CandBase
	addi 	$7, $0, 0					#px offset counter

MLoop:	lw		$5, PatternBase($7)		#load PatternBase's offset
		addi 	$2, $7, PatternBase 	#set up patterBase debugger px locator
		swi		585						#call locator debugger
		bne 	$5, $0, Then			#if(patternBase[i] != 0) (ie if patternBase px is black then increment px offset)
		addi	$18, $18, 4
		addi 	$7, $7, 4 				#increment px offset counter by 4 bytes / i++ jump (take next line too j Mloop)
		j		MLoop

Then:	lw		$20, 0($18)
#		addi 	$2, $18, 0 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$21, 576($18)
#		addi 	$2, $18, 576 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$22, 1152($18)
#		addi 	$2, $18, 1152 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$23, 1728($18)
#		addi 	$2, $18, 1728 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$24, 2304($18)
#		addi 	$2, $18, 2304 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$25, 2880($18)
#		addi 	$2, $18, 2880 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$26, 3456($18)
#		addi 	$2, $18, 3456 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		lw		$27, 4032($18)
#		addi 	$2, $18, 4032 	#set up patterBase debugger px locator
#		swi		585						#call locator debugger
		addi	$18, $18, 4
		addi 	$7, $7, 4
		beq		$5, $20, cand0S
		beq		$5, $21, cand1S
		beq		$5, $22, cand2S
		beq		$5, $23, cand3S
		beq		$5, $24, cand4S
		beq		$5, $25, cand5S
		beq		$5, $26, cand6S
		beq		$5, $27, cand7S

cand0S:	beq		$20, $21, MLoop
		beq		$20, $22, MLoop
		beq		$20, $23, MLoop
		beq		$20, $24, MLoop
		beq		$20, $25, MLoop
		beq		$20, $26, MLoop
		beq		$20, $27, MLoop
		addi	$8, $0, 0
		j		End

#cand1S:	beq		$21, $20, MLoop
cand1S:		beq		$21, $22, MLoop
		beq		$21, $23, MLoop
		beq		$21, $24, MLoop
		beq		$21, $25, MLoop
		beq		$21, $26, MLoop
		beq		$21, $27, MLoop
		addi	$8, $0, 1
		j		End

#cand2S:	beq		$22, $20, MLoop
#		beq		$22, $21, MLoop
cand2S:		beq		$22, $23, MLoop
		beq		$22, $24, MLoop
		beq		$22, $25, MLoop
		beq		$22, $26, MLoop
		beq		$22, $27, MLoop
		addi	$8, $0, 2
		j		End

#cand3S:	beq		$23, $20, MLoop
#		beq		$23, $21, MLoop
#		beq		$23, $22, MLoop
cand3S:		beq		$23, $24, MLoop
		beq		$23, $25, MLoop
		beq		$23, $26, MLoop
		beq		$23, $27, MLoop
		addi	$8, $0, 3
		j		End

#cand4S:	beq		$24, $20, MLoop
#		beq		$24, $21, MLoop
#		beq		$24, $22, MLoop
#		beq		$24, $23, MLoop
cand4S:		beq		$24, $25, MLoop
		beq		$24, $26, MLoop
		beq		$24, $27, MLoop
		addi	$8, $0, 4
		j		End

#cand5S:	beq		$25, $20, MLoop
#		beq		$25, $21, MLoop
#		beq		$25, $22, MLoop
#		beq		$25, $23, MLoop
#		beq		$25, $24, MLoop
cand5S:		beq		$25, $26, MLoop
		beq		$25, $27, MLoop
		addi	$8, $0, 5
		j		End

#cand6S:	beq		$26, $20, MLoop
#		beq		$26, $21, MLoop	
#		beq		$26, $22, MLoop
#		beq		$26, $23, MLoop
#		beq		$26, $24, MLoop
#		beq		$26, $25, MLoop
cand6S:		beq		$26, $27, MLoop
		addi	$8, $0, 6
		j		End

#cand7S:	beq		$27, $20, MLoop
#		beq		$27, $21, MLoop
#		beq		$27, $22, MLoop
#		beq		$27, $23, MLoop
#		beq		$27, $24, MLoop
#		beq		$27, $25, MLoop
#		beq		$27, $26, MLoop
cand7S:		addi	$8, $0, 7
		j		End

End:    addi    $2, $8, 0               # REPLACE: guess the first icon
		swi	544			# submit answer and check
		jr	$31			# return to caller
