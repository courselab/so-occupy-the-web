/*
 *    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonvm.dev@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  gambs-theory <marrafonvm.dev@gmail.com>
 */

#ifndef E8_H
#define E8_H

void __attribute__((fastcall, naked)) printf(const char *); 

// Degub function
int __attribute__((naked)) debug(const char, const char);

// Custom print pixel implementation
void __attribute__((fastcall, naked)) set_video_mode(void);

// x, y, and the color of the pixel
void __attribute__((fastcall, naked)) printp(short, short, short);

#endif	
