/*****************************************************************************/
/*                                                                           */
/*				   stdlib.h				     */
/*                                                                           */
/*			       General utilities			     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2002 Ullrich von Bassewitz                                       */
/*               Wacholderweg 14                                             */
/*               D-70597 Stuttgart                                           */
/* EMail:        uz@musoftware.de                                            */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/



#ifndef _STDLIB_H
#define _STDLIB_H



#include <stddef.h>



/* Standard exit codes */
#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

/* Return type of the div function */
typedef struct {
    int rem;
    int quot;
} div_t;

/* Memory management */
void* __fastcall__ malloc (size_t size);
void* __fastcall__ calloc (size_t count, size_t size);
void* __fastcall__ realloc (void* block, size_t size);
void __fastcall__ free (void* block);

/* Non standard memory management functions */

void __fastcall__ _heapadd (void* mem, size_t size);
/* Add a block to the heap */

size_t __fastcall__ _heapmemavail (void);
/* Return the total free heap space */

size_t __fastcall__ _heapmaxavail (void);
/* Return the size of the largest free block on the heap */

/* Random numbers */
#define	RAND_MAX   	0x7FFF
int rand (void);
void __fastcall__ srand (unsigned seed);
void _randomize (void);         /* Non-standard */

/* Other standard stuff */
void abort (void);
int __fastcall__ abs (int val);
long __fastcall__ labs (long val);
int __fastcall__ atoi (const char* s);
long __fastcall__ atol (const char* s);
int __fastcall__ atexit (void (*exitfunc) (void));
void* bsearch (const void* key, const void* base, size_t n,
	       size_t size, int (*cmp) (const void*, const void*));
div_t __fastcall__ div (int numer, int denom);
void __fastcall__ exit (int ret);
char* __fastcall__ getenv (const char* name);
void qsort (void* base, size_t count, size_t size,
	    int (*compare) (const void*, const void*));
int system (const char* s);

/* Non-ANSI functions */
void __fastcall__ _swap (void* p, void* q, size_t size);
#ifndef __STRICT_ANSI__
char* __fastcall__ itoa (int val, char* buf, int radix);
char* __fastcall__ utoa (unsigned val, char* buf, int radix);
char* __fastcall__ ltoa (long val, char* buf, int radix);
char* __fastcall__ ultoa (unsigned long val, char* buf, int radix);
#endif



/* End of stdlib.h */
#endif



