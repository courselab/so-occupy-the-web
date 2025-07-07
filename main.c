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
#include <timec.h>

#define 	RED	0x4
#define	      GREEN	0x2
#define	       BLUE	0x1

void print_rtc(void) {
  unsigned short bcd_rtc = readtime();
  unsigned char mask = 0b00001111;
  char time_buffer[6] = {'\0'}; // hh:mm
  unsigned char shift = 12;

  for (int i = 0; i < 5; i++ ) {
    if (i == 2) {
      time_buffer[i] = ':';
    } else {
      time_buffer[i] = ((bcd_rtc >> shift) & mask) + '0';
      shift -= 4;      
    }	    
  }
  printf (time_buffer);
}

int main(void)   
{
  /*
  set_video_mode();

  for (short i = 0; i <= 320; i++) {
    printp(i, 0,   RED);
    printp(i, 2, GREEN);
    printp(i, 4,  BLUE);
    
    printp(i,  6,   RED);
    printp(i,  8, GREEN);
    printp(i, 10,  BLUE);
  }
  */

  printf("System time clock: ");
  print_rtc();

  printf("\n\rBRASILIA time\n\r");
  settime(0b0001001000110100);
  print_rtc();
  
  return 0;  
}

