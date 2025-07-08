#    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
#    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonmv.dev@gmail.com>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  gambs-theory <marrafonmv.dev@gmail.com>

CC=gcc
MAKE=make

dos=$(shell basename $$(realpath .))

# Build the OS and an example user program.

# Link all objects needed by the OS.

$(dos).bin : bootloader.o bios1.o kernel.o kaux.o bios2.o logo.o syscall.o
	ld -melf_i386 -T lcrdos.ld --orphan-handling=discard $^ -o $@

# Create the disk image with 2880 blocks (1440 KB disk)
# (1) Create a disk with just zeros
# (2) Format the disk with the ty file system
# (3) Insert the boot loader and the kernel into the disk

# Some Constants
reserved_blocks = 30

# Preparing the file system formatter
tyfsedit: tyfsedit.c fsheader.h
	gcc tyfsedit.c -lm -o tyfsedit

# We need the formatter and the operating system
disk.img: tyfsedit format mydos.bin
	dd if=/dev/zero of=disk.img count=2880
	./format -r $(reserved_blocks) disk.img
	dd if=mydos.bin of=disk.img conv=notrunc obs=1 seek=16
	

	./put files/file1.txt disk.img
	./put files/file2.txt disk.img

# Here we are statically linking the user program 'prob.bin' into the kernel,
# so as to simulate the execution of a user program. If we were to actually load
# and execute an external program, we should remove 'prog.o' and 'liblcrdos.o'
# from the list of pre-requisites, and edit the linker script accordingly.
# Comment out the following line if this is the case.

$(dos).bin : prog.o liblcrdos.o

# Rules to build objects from either C or assembly code.

%.o : %.c
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c  $< -o $@

%.o : %.S
	as -32 $< -o $@

bootloader.o : bios1.h kernel.h
kernel.o : bios1.h bios2.h kernel.h kaux.h fsheader.h
kaux.o:    bios2.h kaux.h

$(dos).bin : .EXTRA_PREREQS = rt0.o lcrdos.ld

# Rules to build the user programs
# You would add new programs to this variable if bulding other user programs.
# The user library is automatically added by the linker script.

progs = prog.bin

$(progs)  : %.bin : %.o liblcrdos.a
	ld -melf_i386 -T prog.ld --orphan-handling=discard $< -o $@

$(progs:%.bin=%.o) : %.o : %.c lcrdos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

$(progs:%.bin=%.o) : lcrdos.h

$(progs:%.bin=%.o) : .EXTRA_PREREQS = prog.ld

# Recipes to build the user library.

liblcrdos.o: liblcrdos.c lcrdos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c  $< -o $@

liblcrdos.o : lcrdos.h

liblcrdos.a : liblcrdos.o
	ar rcs $@ $^

# Housekeeping.

.PHONY: clean

clean:
	rm -f *.bin *.o *~ *.s *.a *.img

include bintools.mk
