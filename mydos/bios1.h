/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonmv.dev@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  gambs-theory <marrafonmv.dev@gmail.com>
 */

#ifndef BIOS1_H
#define BIOS1_H

void __attribute__((fastcall)) clear(void);
void __attribute__((fastcall)) kwrite(const char *);
void __attribute__((fastcall)) kwriteln(const char *);
/* void __attribute__((fastcall)) kread(char *); */
void __attribute__((fastcall)) fatal(const char *);
void __attribute__((fastcall)) load_kernel(void);
void __attribute__((fastcall)) set_cursor(char, char);

#endif
