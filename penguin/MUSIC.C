#include "music.h"

#define TREBLE_LENGTH 231
#define BASS_LENGTH 430
/*
   Music Info:

    {Frequency, Duration, Volume}

    --- Rests ---
    {NULL, TIME_WHOLE, NULL},
    {NULL, TIME_HALF, NULL},
    {NULL, TIME_QUARTER, NULL},
    {NULL, TIME_EIGHTH, NULL},
    {NULL, TIME_SIXTEENTH, NULL},
    -------------

	 - 1 line of code equals 1 bar of music
	 - timing constants are arbitrary powers of two
*/
const Note treble_sheet_music[TREBLE_LENGTH] =
{
	/* --- Section: 0 --- */	/*	2 notes	*/
	{NULL, TIME_WHOLE, NULL}, {NULL, TIME_EIGHTH, NULL},		/*	except for this line - to stall startup	*/

	/* --- Section: 1 --- */	/*	26 notes	*/
	{NOTE_AS4, TIME_HALF, VOL_MID}, {NOTE_AS4, TIME_EIGHTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS4, TIME_EIGHTH, VOL_MID},
	{NOTE_GS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_GS4, TIME_HALF, VOL_MID}, {NOTE_GS4, TIME_QUARTER, VOL_MID}, {NOTE_GS4, TIME_EIGHTH, VOL_MID},
	{NOTE_AS4, TIME_EIGHTH, VOL_MID}, {NOTE_AS4, TIME_HALF, VOL_MID}, {NOTE_FS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},  {NOTE_FS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},  {NOTE_AS4, TIME_EIGHTH, VOL_MID},
	{NOTE_A4, TIME_SIXTEENTH, VOL_MID}, {NOTE_G4, TIME_SIXTEENTH, VOL_MID}, {NOTE_A4, TIME_HALF, VOL_MID}, {NOTE_A4, TIME_QUARTER, VOL_MID}, {NOTE_A4, TIME_EIGHTH, VOL_MID},

	/* --- Section: 2 --- */	/*	2 notes	*/
	{NULL, TIME_WHOLE, NULL},
	{NULL, TIME_WHOLE, NULL},

	/* --- Section: 3 --- */	/*	36 notes	*/
	{NOTE_AS4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_EIGHTH, NULL}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_QUARTER, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_D5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NOTE_C4, TIME_SIXTEENTH, VOL_MID}, {NOTE_D4, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_EIGHTH, NULL}, {NULL, TIME_QUARTER, NULL},
	{NOTE_AS4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_EIGHTH, NULL}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_QUARTER, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_D5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NOTE_C4, TIME_SIXTEENTH, VOL_MID}, {NOTE_D4, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NULL, TIME_EIGHTH, NULL}, {NULL, TIME_QUARTER, NULL},

	/* --- Section: 4 --- */	/*	 -- notes	*/
	{NOTE_AS4, TIME_QUARTER, VOL_MID}, {NOTE_F4, TIME_QUARTER, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_D5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NOTE_C4, TIME_SIXTEENTH, VOL_MID}, {NOTE_D4, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_GS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_AS5, TIME_HALF, VOL_MID}, {NOTE_AS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS5, TIME_SIXTEENTH, VOL_MID},  {NOTE_FS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_GS5, TIME_EIGHTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F5, TIME_HALF, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_F5, TIME_EIGHTH, VOL_MID},

	/* --- Section: 5 --- */	/*	35 notes	*/
	{NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_HALF, VOL_MID}, {NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_DS5, TIME_EIGHTH, VOL_MID},
	{NOTE_CS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F5, TIME_HALF, VOL_MID}, {NOTE_DS5, TIME_EIGHTH, VOL_MID}, {NOTE_CS5, TIME_EIGHTH, VOL_MID},
	{NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_D5, TIME_SIXTEENTH, VOL_MID}, {NOTE_E5, TIME_HALF, VOL_MID}, {NOTE_G5, TIME_QUARTER, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 6 --- */	/*	31 notes	*/
	{NOTE_AS4, TIME_QUARTER, VOL_MID}, {NOTE_F4, TIME_QUARTER, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_D5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS3, TIME_SIXTEENTH, VOL_MID}, {NOTE_C4, TIME_SIXTEENTH, VOL_MID}, {NOTE_D4, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_EIGHTH, VOL_MID}, {NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_GS5, TIME_SIXTEENTH, VOL_MID},
	{NOTE_AS5, TIME_HALF, VOL_MID}, {NOTE_AS5, TIME_QUARTER, VOL_MID}, {NOTE_CS6, TIME_EIGHTH, VOL_MID}, {NOTE_CS6, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_C6, TIME_EIGHTH, VOL_MID}, {NOTE_C6, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_A5, TIME_HALF, VOL_MID}, {NOTE_F5, TIME_QUARTER, VOL_MID},

	/* --- Section: 7 --- */	/*	15 notes	*/
	{NOTE_FS5, TIME_HALF, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_FS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS5, TIME_QUARTER, VOL_MID},
	{NOTE_A5, TIME_EIGHTH, VOL_MID}, {NOTE_A5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F5, TIME_QUARTER, VOL_MID}, {NOTE_F5, TIME_EIGHTH, VOL_MID}, {NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F5, TIME_QUARTER, VOL_MID},
	{NOTE_FS5, TIME_HALF, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_FS5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS5, TIME_QUARTER, VOL_MID},
	{NOTE_A5, TIME_EIGHTH, VOL_MID}, {NOTE_A5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F5, TIME_HALF, VOL_MID}, {NOTE_D5, TIME_QUARTER, VOL_MID},

	/* --- Section: 8 --- */	/*	33 notes	*/
	{NOTE_DS5, TIME_HALF, VOL_MID}, {NOTE_DS5, TIME_QUARTER, VOL_MID},  {NOTE_FS5, TIME_QUARTER, VOL_MID},
	{NOTE_F5, TIME_EIGHTH, VOL_MID}, {NULL, TIME_EIGHTH, NULL}, {NOTE_CS5, TIME_HALF, VOL_MID}, {NOTE_AS4, TIME_QUARTER, VOL_MID},
	{NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_C4, TIME_SIXTEENTH, VOL_MID}, {NOTE_C5, TIME_SIXTEENTH, VOL_MID}, {NOTE_CS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS4, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_EIGHTH, VOL_MID}, {NOTE_DS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_FS5, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_CS5, TIME_EIGHTH, VOL_MID},
	{NOTE_F5, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NOTE_F4, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F3, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}
};

const Note bass_sheet_music[BASS_LENGTH] =
{
	/* --- Section: 0 --- */	/*	2 notes	*/
	{NULL, TIME_WHOLE, NULL}, {NULL, TIME_EIGHTH, NULL},		/*	and this line - to stall startup	*/

	/* --- Section: 1 --- */	/*	12 notes	*/
	{NOTE_AS1, TIME_QUARTER, VOL_MID}, {NOTE_F2, TIME_QUARTER, VOL_MID}, {NOTE_AS2, TIME_HALF, VOL_MID},
	{NOTE_GS1, TIME_QUARTER, VOL_MID}, {NOTE_DS2, TIME_QUARTER, VOL_MID}, {NOTE_GS2, TIME_HALF, VOL_MID},
	{NOTE_FS1, TIME_QUARTER, VOL_MID}, {NOTE_CS2, TIME_QUARTER, VOL_MID}, {NOTE_FS2, TIME_HALF, VOL_MID},
	{NOTE_F1, TIME_QUARTER, VOL_MID}, {NOTE_C2, TIME_QUARTER, VOL_MID}, {NOTE_F2, TIME_HALF, VOL_MID},

	/* --- Section: 2 --- */	/*	32 notes	*/
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_G1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_G1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 3 --- */	/*	64 notes	*/
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 4 --- */	/*	64 notes	*/
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 5 --- */	/*	64 notes	*/
	{NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_B1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_C2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_D2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_D2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 6 --- */	/*	64 notes	*/
	{NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_AS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_GS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_FS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 7 --- */	/*	64 notes	*/
	{NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},

	/* --- Section: 8 --- */	/*	64 notes	*/
	{NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL},
	{NOTE_F2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_F2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_E2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_DS2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_D2, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}, {NOTE_CS1, TIME_SIXTEENTH, VOL_MID}, {NULL, TIME_SIXTEENTH, NULL}
};

static UWORD16 treble_index = 0;
static UWORD16 bass_index = 0;
static ULONG32 treble_elapsed = 0;
static ULONG32 bass_elapsed = 0;

UBYTE8 music_on = FALSE;

void toggle_music() {
	music_on ^= 1;
	
	if (music_on) {
		start_sound();
		start_music();
	}
	else {
		stop_sound();
	}

	return;
}

void start_music() {
	music_on = TRUE;
	
	treble_index = 2;
	bass_index = 2;
	treble_elapsed = 0;
	bass_elapsed = 0;

    set_tone(CHANNEL_A, treble_sheet_music[2].pitch);
    set_volume(CHANNEL_A, treble_sheet_music[2].velocity);

    set_tone(CHANNEL_B, bass_sheet_music[2].pitch);
    set_volume(CHANNEL_B, bass_sheet_music[2].velocity);

	return;
}

void update_music() {
	treble_elapsed++;
	bass_elapsed++;

	if (treble_elapsed >= treble_sheet_music[treble_index].duration) {
		treble_index++;
		treble_elapsed = 0;

		set_tone_isr(CHANNEL_A, treble_sheet_music[treble_index].pitch);
		set_volume_isr(CHANNEL_A, treble_sheet_music[treble_index].velocity);
	}

	if (bass_elapsed >= bass_sheet_music[bass_index].duration) {
		bass_index++;
		bass_elapsed = 0;

		set_tone_isr(CHANNEL_B, bass_sheet_music[bass_index].pitch);
		set_volume_isr(CHANNEL_B, bass_sheet_music[bass_index].velocity);
	}

	/*	synchronize music channels	*/
	if (treble_index == TREBLE_LENGTH) {
		set_volume_isr(CHANNEL_A, OFF);
		treble_index = 0;
		treble_elapsed = 0;

		set_volume_isr(CHANNEL_B, OFF);
		bass_index = 0;
		bass_elapsed = 0;
	}

	return;
}
