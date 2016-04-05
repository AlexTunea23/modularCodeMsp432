
#include "driverlib.h"

/* Standard Includes */
#include <stdint.h>

#include <stdbool.h>

volatile uint8_t rx_buffer[1024];
uint16_t bufferIndex = 0;


int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

  CSKEY = 0x695A;                        // Unlock CS module for register access
  CSCTL0 = 0;                            // Reset tuning parameters
  CSCTL0 = DCORSEL_3;                   // Set DCO to 12MHz (nominal, center of 8-16MHz range)
                                         // Select ACLK = REFO, SMCLK = MCLK = DCO
  CSCTL1 = SELA_2 | SELS_3 | SELM_3;
  CSKEY = 0;                             // Lock CS module from unintended accesses

  // Configure UART pins
  P1SEL0 |= BIT2 | BIT3;

  __enable_interrupt();
  NVIC_ISER0 = 1 << ((INT_EUSCIA0 - 16) & 31); // Enable eUSCIA0 interrupt in NVIC module

  // Configure UART
  UCA0CTLW0 |= UCSWRST;
  UCA0CTLW0 |= UCSSEL__SMCLK;             // Put eUSCI in reset

  UCA0BR0 = 78;                           // 12000000/16/9600
  UCA0BR1 = 0x00;
  UCA0MCTLW = 0x1000 | UCOS16 | 0x0020;

  UCA0CTLW0 &= ~UCSWRST;                  
  UCA0IE |= UCRXIE;

  while(1)
 	   {
      testing();
 	   }
 	 }


void euscia0_isr(void)
{

	 if (UCA0IFG & UCRXIFG)
	    {
	        rx_buffer[bufferIndex] = UCA0RXBUF;
	        bufferIndex++;
	      testing();
	     }

}
