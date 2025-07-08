#ifndef TIMEC_H
#define TIMEC_H

int  __attribute__((fastcall, naked)) readtime (void);

// Receive a time in Binary Decimal Coded
void __attribute__((fastcall, naked)) settime  (unsigned short);

#endif /*TIMEC_H*/
