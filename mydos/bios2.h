/*
 *    SPDX-FileCopyrightText: 2024 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonmv.dev@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  gambs-theory <marrafonmv.dev@gmail.com>
 */

#ifndef BIOS2_H
#define BIOS2_H

int __attribute__((fastcall)) kread(char *);

void __attribute__((fastcall)) udelay(unsigned short);

void load_directory(void);

#endif /* BIOS2_H  */
