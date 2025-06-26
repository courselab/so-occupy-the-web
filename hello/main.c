/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 gambs-theory <marrafonvm.dev@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  gambs-theory <marrafonvm.dev@gmail.com>
 */

#include <stdio.h>

#define 	RED	0x4
#define	      GREEN	0x2
#define	       BLUE	0x1

int main(void)   
{
  set_video_mode();

  for (short i = 0; i <= 320; i++) {
    printp(i, 0,   RED);
    printp(i, 2, GREEN);
    printp(i, 4,  BLUE);
    
    printp(i,  6,   RED);
    printp(i,  8, GREEN);
    printp(i, 10,  BLUE);
  }
  
  return 0;  
}

