#include "defines.h"

extern void start(void);

/*
 * Interrupt vector setting
 * By the definition of the linker script,
 * it is placed at the start address.
 *
 *
 * Set a pointer to start = start ().
 * Define the address at which the CPU starts execution first
 * when the microcomputer board is turned on (aka reset vector).
 *
 */
 
 void (*vectors[])(void) = {
     start, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  
 };
