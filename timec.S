# Reference: https://stanislavs.org/helppc/int_1a.html
 /* Suppose we receive the argument in %cx. */

        .code16gcc
        .global readtime, settime 
        .section .text

# Set time on real time clock
settime:
	# Parameters via fastcall - %cx and %dx, therefore, %cx is already "signed"
	mov	$0x03, %ah
	int	$0x1a

# Read time on real time clock 
readtime:
	mov	$0x02, %ah
	int	$0x1a

	mov	%cx, %ax
	ret
