/* dmatrix.h - Handles Data Matrix ECC 200 */

/*
    libzint - the open source barcode library
    Copyright (C) 2009 Robin Stuart <robin@zint.org.uk>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright 
       notice, this list of conditions and the following disclaimer.  
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.  
    3. Neither the name of the project nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission. 

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
    SUCH DAMAGE.
*/

/*
    Containes Extended Rectangular Data Matrix (DMRE)
    See http://www.eurodatacouncil.org for information
    Contact: harald.oehlmann@eurodatacouncil.org
 */

#include "common.h"

#ifndef __IEC16022ECC200_H
#define __IEC16022ECC200_H
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern int data_matrix_200(struct zint_symbol *symbol, unsigned char source[], int length);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#define MAXBARCODE 3116

#define DM_ASCII	1
#define DM_C40		2
#define DM_TEXT		3
#define DM_X12		4
#define DM_EDIFACT	5
#define DM_BASE256	6

static const int c40_shift[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	
static const int c40_value[] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
	3,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,4,5,6,7,8,9,10,11,12,13,
	15,16,17,18,19,20,21,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
	22,23,24,25,26,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	
static const int text_shift[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	2, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3 };

static const int text_value[] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
	3,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,4,5,6,7,8,9,10,11,12,13,
	15,16,17,18,19,20,21,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,
	22,23,24,25,26,0,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,27,28,29,30,31 };

// Activate DMRE Extensions
//#define DMRE
#ifdef DMRE
// With Rectangular extensions

// Position in option array [symbol option value - 1]
// The position in the option array is by increasing total data codewords with square first
	
static const int intsymbol[] = {
	0,	/*  1: 10x10 ,  3*/	1,	/*  2: 12x12 ,  5*/	3,	/*  3: 14x14 ,  8*/	5,	/*  4: 16x16 , 12*/
	7,	/*  5: 18x18 , 18*/	9,	/*  6: 20x20 , 22*/	12, /*  7: 22x22 , 30*/	14, /*  8: 24x24 , 36*/
    16, /*  9: 26x26 , 44*/	21,	/* 10: 32x32 , 62*/	25, /* 11: 36x36 , 86*/	28, /* 12: 40x40 ,114*/
    30,	/* 13: 44x44 ,144*/	31,	/* 14: 48x48 ,174*/	32,	/* 15: 52x52 ,204*/	33,	/* 16: 64x64 ,280*/
    34,	/* 17: 72x72 ,368*/	35,	/* 18: 80x80 ,456*/	36,	/* 19: 88x88 ,576*/	37,	/* 20: 96x96 ,696*/
    38,	/* 21:104x104,816*/	39,	/* 22:120x120,1050*/40,	/* 23:132x132,1304*/41,	/* 24:144x144,1558*/
    2,	/* 25:  8x18 ,  5*/	4,	/* 26:  8x32 , 10*/	6,	/* 27: 12x26 , 16*/	10,	/* 28: 12x36 , 22*/
    13,	/* 29: 16x36 , 32*/	17,	/* 30: 16x48 , 49*/	8,	/* 31:  8x48 , 18*/	11, /* 32:  8x64 , 24*/
    15,	/* 33: 12x64 , 43*/	22,	/* 34: 16x64 , 62*/	18,	/* 35: 24x32 , 49*/ 20,	/* 36: 24x36 , 55*/
	24,	/* 37: 24x48 , 80*/	27,	/* 38: 24x64 ,108*/	19, /* 39: 26x32 , 52*/ 23,	/* 40: 26x40 , 70*/
	26,	/* 41: 26x48 , 90*/	29, /* 42: 26x64 ,118*/
    0 };

// Number of DM Sizes
#define DMSIZESCOUNT 42
// Number of 144x144 for special interlace
#define INTSYMBOL144 41

// Horizontal matrix size

static const int matrixH[] = {
/*0*/	10,	/* 10x10 ,3 */	12,	/* 12x12 ,5 */	8,	/*  8x18 ,5 */	14, /* 14x14 , 8 */
/*4*/	8,	/*  8x32 ,10 */	16,	/* 16x16 ,12 */	12,	/* 12x26 ,16 */	18, /* 18x18 ,18 */
/*8*/   8,	/*  8x48 ,18 */	20,	/* 20x20 ,22 */	12, /* 12x36 ,22 */	8,	/*  8x64 ,24 */
/*12*/	22,	/* 22x22 ,30 */	16,	/* 16x36 ,32 */	24, /* 24x24 ,36 */	12,	/* 12x64 ,43 */
/*16*/	26, /* 26x26 ,44 */	16, /* 16x48 ,49 */	24,	/* 24x32 ,49 */	26,	/* 26x32 ,52 */
/*20*/	24,	/* 24x36 ,55 */	32, /* 32x32 ,62 */	16, /* 16x64 ,62 */	26,	/* 26x40 ,70 */
/*24*/	24,	/* 24x48 ,80 */	36, /* 36x36 ,86 */	26,	/* 26x48 ,90 */	24,	/* 24x64 ,108*/
/*28*/	40,	/* 40x40 ,114*/	26,	/* 26x64 ,118*/	44,	/* 44x44 ,144*/	48,	/* 48x48,174 */
/*32*/	52, /* 52x52,204 */	64, /* 64x64,280 */	72,	/* 72x72,368 */	80, /* 80x80,456 */
/*36*/	88, /* 88x88,576 */	96, /* 96x96,696 */	104,/*104x104,816*/	120,/*120x120,1050*/
/*40*/	132,/*132x132,1304*/144/*144x144,1558*/
		};

// Vertical matrix sizes

static const int matrixW[] = {
/*0*/	10, /* 10x10 */	12, /* 12x12 */	18, /*  8x18 */	14,	/* 14x14 */
/*4*/	32, /*  8x32 */	16, /* 16x16 */	26, /* 12x26 */	18, /* 18x18 */
/*8*/   48, /*  8x48 */	20, /* 20x20 */	36, /* 12x36 */	64, /*  8x64 */
/*12*/	22, /* 22x22 */	36, /* 16x36 */	24, /* 24x24 */	64,	/* 12x64 */
/*16*/	26, /* 26x26 */	48,	/* 16x48 */	32,	/* 24x32 */	32,	/* 26x32 */
/*20*/	36,	/* 24x36 */	32, /* 32x32 */	64,	/* 16x64 */	40,	/* 26x40 */
/*24*/	48,	/* 24x48 */	36,	/* 36x36 */	48,	/* 26x48 */	64,	/* 24x64 */
/*28*/	40,	/* 40x40 */	64,	/* 26x64 */	44,	/* 44x44 */	48, /* 48x48 */
/*32*/	52, /* 52x52 */	64, /* 64x64 */	72,	/* 72x72 */	80, /* 80x80 */
/*36*/	88, /* 88x88 */	96, /* 96x96 */	104,/*104x104*/	120,/*120x120*/
/*40*/ 132,/*132x132*/ 144 /*144x144*/
		};

// Horizontal submodule size (including subfinder)

static const int matrixFH[] = {
/*0*/	10,	/* 10x10 */	12, /* 12x12 */	8,	/*  8x18 */	14,	/* 14x14 */
/*4*/	8,	/*  8x32 */	16,	/* 16x16 */	12,	/* 12x26 */	18, /* 18x18 */
/*8*/   8,	/*  8x48 */	20, /* 20x20 */	12, /* 12x36 */	8,	/*  8x64 */
/*12*/	22,	/* 22x22 */	16,	/* 16x36 */	24,	/* 24x24 */	12,	/* 12x64 */
/*16*/	26,	/* 26x26 */	16,	/* 16x48 */	24,	/* 24x32 */	26,	/* 26x32 */
/*20*/	24,	/* 24x36 */	16,	/* 32x32 */	16,	/* 16x64 */	26,	/* 26x40 */
/*24*/	24,	/* 24x48 */	18,	/* 36x36 */	26,	/* 26x48 */	24,	/* 24x64 */
/*28*/	20,	/* 40x40 */	26,	/* 26x64 */	22,	/* 44x44 */	24,	/* 48x48 */
/*32*/	26,	/* 52x52 */	16,	/* 64x64 */	18,	/* 72x72 */	20,	/* 80x80 */
/*36*/	22,	/* 88x88 */	24,	/* 96x96 */	26,	/*104x104*/	20,	/*120x120*/
/*40*/	22,	/*132x132*/	24	/*144x144*/
		};

// Vertical submodule size (including subfinder)

static const int matrixFW[] = {
/*0*/	10,	/* 10x10 */	12,	/* 12x12 */	18,	/*  8x18 */	14,	/* 14x14 */
/*4*/	16,	/*  8x32 */	16,	/* 16x16 */	26,	/* 12x26 */	18, /* 18x18 */
/*8*/   24,	/*  8x48 */	20,	/* 20x20 */	18,	/* 12x36 */	16,	/*  8x64 */
/*12*/	22,	/* 22x22 */	18,	/* 16x36 */	24,	/* 24x24 */	16,	/* 12x64 */
/*16*/	26,	/* 26x26 */	24,	/* 16x48 */	16,	/* 24x32 */	16,	/* 26x32 */
/*20*/	18,	/* 24x36 */	16,	/* 32x32 */	16,	/* 16x64 */	20,	/* 26x40 */
/*24*/	24,	/* 24x48 */	18,	/* 36x36 */	24,	/* 26x48 */	16,	/* 24x64 */
/*28*/	20,	/* 40x40 */	16,	/* 26x64 */	22,	/* 44x44 */	24,	/* 48x48 */
/*32*/	26,	/* 52x52 */	16,	/* 64x64 */	18,	/* 72x72 */	20,	/* 80x80 */
/*36*/	22,	/* 88x88 */	24,	/* 96x96 */	26,	/*104x104*/	20,	/*120x120*/
/*40*/	22,	/*132x132*/	24	/*144x144*/
		};

// Total Data Codewords

static const int matrixbytes[] = {
/*0*/	3,		/* 10x10 */	5,		/* 12x12 */	5,		/* 8x18 */	8,		/* 14x14 */
/*4*/	10,		/* 8x32 */	12,		/* 16x16 */	16,		/* 12x26 */	18,		/* 18x18 */
/*8*/   18,		/* 8x48 */	22,		/* 20x20 */	22,		/* 12x36 */	24,		/* 8x64 */
/*12*/	30,		/* 22x22 */	32,		/* 16x36 */	36,		/* 24x24 */	43,		/* 12x64 */
/*16*/	44,		/* 26x26 */	49,		/* 16x48 */	49,		/* 24x32 */	52,		/* 26x32 */
/*20*/	55,		/* 24x36 */	62,		/* 32x32 */	62,		/* 16x64 */	70,		/* 26x40 */
/*24*/	80,		/* 24x48 */	86,		/* 36x36 */	90,		/* 26x48 */	108,	/* 24x64 */
/*28*/	114,	/* 40x40 */	118,	/* 26x64 */	144,	/* 44x44 */	174,	/* 48x48 */
/*32*/	204,	/* 52x52 */	280,	/* 64x64 */	368,	/* 72x72 */	456,	/* 80x80 */
/*36*/	576,	/* 88x88 */	696,	/* 96x96 */	816,	/*104x104*/	1050,	/*120x120*/
/*40*/	1304,	/*132x132*/	1558	/*144x144*/
		};

// Data Codewords per RS-Block

static const int matrixdatablock[] = {
/*0*/	3,	/* 10x10 */	5,	/* 12x12 */	5,	/* 8x18 */	8,	/* 14x14 */
/*4*/	10,	/* 8x32 */	12,	/* 16x16 */	16,	/* 12x26 */	18, /* 18x18 */
/*8*/   18, /* 8x48 */	22,	/* 20x20 */	22,	/* 12x36 */	24,	/* 8x64 */
/*12*/	30,	/* 22x22 */	32,	/* 16x36 */	36,	/* 24x24 */	43,	/* 12x64 */
/*16*/	44,	/* 26x26 */	49,	/* 16x48 */	49,	/* 24x32 */	52,	/* 26x32 */
/*20*/	55,	/* 24x36 */	62,	/* 32x32 */	62,	/* 16x64 */	70,	/* 26x40 */
/*24*/	80,	/* 24x48 */	86,	/* 36x36 */	90,	/* 26x48 */	108,/* 24x64 */
/*28*/	114,/* 40x40 */	118,/* 26x64 */	144,/* 44x44 */	174,/* 48x48 */
/*32*/	102,/* 52x52 */	140,/* 64x64 */	92,	/* 72x72 */	114,/* 80x80 */
/*36*/	144,/* 88x88 */	174,/* 96x96 */	136,/*104x104*/	175,/*120x120*/
/*40*/	163,/*132x132*/	156	/*144x144*/
		};

// ECC Codewords per RS-Block

static const int matrixrsblock[] = {
/*0*/	5,	/* 10x10 */	7,	/* 12x12 */	7,	/*  8x18 */	10,	/* 14x14 */
/*4*/	11,	/*  8x32 */	12,	/* 16x16 */ 14,	/* 12x26 */ 14,	/* 18x18 */
/*8*/	15, /*  8x48 */	18,	/* 20x20 */	18,	/* 12x36 */ 18,	/*  8x64 */
/*12*/	20,	/* 22x22 */ 24,	/* 16x36 */	24,	/* 24x24 */	27,	/* 12x64 */
/*16*/	28,	/* 26x26 */ 28,	/* 16x48 */	28,	/* 24x32 */	32,	/* 26x32 */
/*20*/	33,	/* 24x36 */	36,	/* 32x32 */	36,	/* 16x64 */	38,	/* 26x40 */
/*24*/	41,	/* 24x48 */	42,	/* 36x36 */	42,	/* 26x48 */	46,	/* 24x64 */
/*28*/	48,	/* 40x40 */	50,	/* 26x64 */	56,	/* 44x44 */	68, /* 48x48 */
/*32*/	42,	/* 52x52 */ 56,	/* 64x64 */ 36,	/* 72x72 */	48, /* 80x80 */
/*36*/	56,	/* 88x88 */ 68,	/* 96x96 */ 56,	/*104x104*/	68,	/*120x120*/
/*40*/	62,	/*132x132*/	62	/*144x144*/
		};

#else
// No Rectangular extensions

static const int intsymbol[] = {
	0,1,3,5,7,8,10,12,13,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,2,4,6,9,11,14 };

// Number of DM Sizes
#define DMSIZESCOUNT 30
// Number of 144x144 for special interlace
#define INTSYMBOL144 29

static const int matrixH[] = {
	10, 12, 8, 14, 8, 16, 12, 18, 20, 12, 22, 16, 24, 26, 16, 32, 36, 40, 44, 48,
	52, 64, 72, 80, 88, 96, 104, 120, 132, 144 };

static const int matrixW[] = {
	10, 12, 18, 14, 32, 16, 26, 18, 20, 36, 22, 36, 24, 26, 48, 32, 36, 40, 44,
	48, 52, 64, 72, 80, 88, 96, 104, 120, 132, 144 };

static const int matrixFH[] = {
	10, 12, 8, 14, 8, 16, 12, 18, 20, 12, 22, 16, 24, 26, 16, 16, 18, 20, 22, 24,
	26, 16, 18, 20, 22, 24, 26, 20, 22, 24 };

static const int matrixFW[] = {
	10, 12, 18, 14, 16, 16, 26, 18, 20, 18, 22, 18, 24, 26, 24, 16, 18, 20, 22,
	24, 26, 16, 18, 20, 22, 24, 26, 20, 22, 24 };

static const int matrixbytes[] = {
	3, 5, 5, 8, 10, 12, 16, 18, 22, 22, 30, 32, 36, 44, 49, 62, 86, 114, 144,
	174, 204, 280, 368, 456, 576, 696, 816, 1050, 1304, 1558 };

static const int matrixdatablock[] = {
	3, 5, 5, 8, 10, 12, 16, 18, 22, 22, 30, 32, 36, 44, 49, 62, 86, 114, 144,
	174, 102, 140, 92, 114, 144, 174, 136, 175, 163, 156 };
	
static const int matrixrsblock[] = {
	5, 7, 7, 10, 11, 12, 14, 14, 18, 18, 20, 24, 24, 28, 28, 36, 42, 48, 56, 68,
	42, 56, 36, 48, 56, 68, 56, 68, 62, 62 };

#endif

#endif				/* __IEC16022ECC200_H */
