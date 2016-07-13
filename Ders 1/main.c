

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01 | 0x80;                     // Set P1.0 to output direction

  for (;;)
  {
    volatile unsigned int i;

    P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR

    P1OUT ^= 0x80;                          // Toggle P1.7 using exclusive-OR

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}