#    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonvm.dev@gmail.com>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  gambs-theory <marrafonvm.dev@gmail.com>

	/* Suppose we receive the argument in %cx. */

	.code16gcc	
	.global printf
	.global printp
	.global set_video_mode

	# Debugging Function
	.global debug
	.section .text
	
# Just print 2 ascii char using the stack
debug:
	push	%bp
	mov	%sp, %bp
	
	# Procedure
	mov	6(%bp), %bx
	mov     10(%bp), %cx

	# Print
	mov	$0x0e, %ah
	mov	%bl, %al

	int	$0x10
	mov	%cl, %al
	int	$0x10	

	# Exit 
	pop 	%bp
	xor	%ax, %ax
	ret
	
printf:	

	mov   	%cx, %bx
	
        mov   	$0x0e,%ah               
        mov   	$0x00, %si               
loop:                                 
        mov   	(%bx, %si), %al           
        cmp   	$0x0, %al               
        je    	end                    
        int   	$0x10                   
        add   	$0x01, %si               
        jmp   	loop                    
end:
        mov 	%si, %ax
        ret

# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
# |  https://en.wikipedia.org/wiki/BIOS_interrupt_call    |
# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

set_video_mode:
	mov 	$0x13, %al	# 13h Mode - 320x200 resolution 
	mov	$0x00, %ah	# Set video mode: See the link above
	int	$0x10
	ret
	
# Print Pixel
printp:
	push	%bp
	mov	%sp, %bp

	mov	6(%bp), %al	# Taking the third argument: Color

	mov	$0x0c, %ah	# Graphical Write mode
	mov 	$0x00, %bh	# Page number: 0
	int	$0x10	
	
	pop 	%bp

	ret
