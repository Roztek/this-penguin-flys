#ifndef MUSIC_H
#define MUSIC_H


#include "globals.h"
#include "psg.h"

/* ----- Volume  ----- */
#define VOL_MIN 3
#define VOL_LOW 6
#define VOL_MID 10          /*   originally 9 - increased volume for final compile   */
#define VOL_HIGH 12
#define VOL_MAX 15

/* ----- Timing  ----- */
#define TIME_WHOLE 128
#define TIME_HALF 64
#define TIME_QUARTER 32
#define TIME_EIGHTH 16
#define TIME_SIXTEENTH 8

/* ----- Octave  ----- */
#define OCTAVE_ONE 0
#define OCTAVE_TWO 1
#define OCTAVE_THREE 2
#define OCTAVE_FOUR 3
#define OCTAVE_FIVE 4
#define OCTAVE_SIX 5
#define OCTAVE_SEVEN 6
#define OCTAVE_EIGHT 7

/* ----- Pitch   ----- */
#define NOTE_C1 0xD5D
#define NOTE_CS1 0xC9C
#define NOTE_D1 0xBE7
#define NOTE_DS1 0xB3C
#define NOTE_E1 0xA9B
#define NOTE_F1 0xA02
#define NOTE_FS1 0x973
#define NOTE_G1 0x8EB
#define NOTE_GS1 0x86B
#define NOTE_A1 0x7F2
#define NOTE_AS1 0x780
#define NOTE_B1 0x714

#define NOTE_C2 (NOTE_C1 >> OCTAVE_TWO)
#define NOTE_CS2 (NOTE_CS1 >> OCTAVE_TWO)
#define NOTE_D2 (NOTE_D1 >> OCTAVE_TWO)
#define NOTE_DS2 (NOTE_DS1 >> OCTAVE_TWO)
#define NOTE_E2 (NOTE_E1 >> OCTAVE_TWO)
#define NOTE_F2 (NOTE_F1 >> OCTAVE_TWO)
#define NOTE_FS2 (NOTE_FS1 >> OCTAVE_TWO)
#define NOTE_G2 (NOTE_G1 >> OCTAVE_TWO)
#define NOTE_GS2 (NOTE_GS1 >> OCTAVE_TWO)
#define NOTE_A2 (NOTE_A1 >> OCTAVE_TWO)
#define NOTE_AS2 (NOTE_AS1 >> OCTAVE_TWO)
#define NOTE_B2 (NOTE_B1 >> OCTAVE_TWO)

#define NOTE_C3 (NOTE_C1 >> OCTAVE_THREE)
#define NOTE_CS3 (NOTE_CS1 >> OCTAVE_THREE)
#define NOTE_D3 (NOTE_D1 >> OCTAVE_THREE)
#define NOTE_DS3 (NOTE_DS1 >> OCTAVE_THREE)
#define NOTE_E3 (NOTE_E1 >> OCTAVE_THREE)
#define NOTE_F3 (NOTE_F1 >> OCTAVE_THREE)
#define NOTE_FS3 (NOTE_FS1 >> OCTAVE_THREE)
#define NOTE_G3 (NOTE_G1 >> OCTAVE_THREE)
#define NOTE_GS3 (NOTE_GS1 >> OCTAVE_THREE)
#define NOTE_A3 (NOTE_A1 >> OCTAVE_THREE)
#define NOTE_AS3 (NOTE_AS1 >> OCTAVE_THREE)
#define NOTE_B3 (NOTE_B1 >> OCTAVE_THREE)

#define NOTE_C4 (NOTE_C1 >> OCTAVE_FOUR)
#define NOTE_CS4 (NOTE_CS1 >> OCTAVE_FOUR)
#define NOTE_D4 (NOTE_D1 >> OCTAVE_FOUR)
#define NOTE_DS4 (NOTE_DS1 >> OCTAVE_FOUR)
#define NOTE_E4 (NOTE_E1 >> OCTAVE_FOUR)
#define NOTE_F4 (NOTE_F1 >> OCTAVE_FOUR)
#define NOTE_FS4 (NOTE_FS1 >> OCTAVE_FOUR)
#define NOTE_G4 (NOTE_G1 >> OCTAVE_FOUR)
#define NOTE_GS4 (NOTE_GS1 >> OCTAVE_FOUR)
#define NOTE_A4 (NOTE_A1 >> OCTAVE_FOUR)
#define NOTE_AS4 (NOTE_AS1 >> OCTAVE_FOUR)
#define NOTE_B4 (NOTE_B1 >> OCTAVE_FOUR)

#define NOTE_C5 (NOTE_C1 >> OCTAVE_FIVE)
#define NOTE_CS5 (NOTE_CS1 >> OCTAVE_FIVE)
#define NOTE_D5 (NOTE_D1 >> OCTAVE_FIVE)
#define NOTE_DS5 (NOTE_DS1 >> OCTAVE_FIVE)
#define NOTE_E5 (NOTE_E1 >> OCTAVE_FIVE)
#define NOTE_F5 (NOTE_F1 >> OCTAVE_FIVE)
#define NOTE_FS5 (NOTE_FS1 >> OCTAVE_FIVE)
#define NOTE_G5 (NOTE_G1 >> OCTAVE_FIVE)
#define NOTE_GS5 (NOTE_GS1 >> OCTAVE_FIVE)
#define NOTE_A5 (NOTE_A1 >> OCTAVE_FIVE)
#define NOTE_AS5 (NOTE_AS1 >> OCTAVE_FIVE)
#define NOTE_B5 (NOTE_B1 >> OCTAVE_FIVE)

#define NOTE_C6 (NOTE_C1 >> OCTAVE_SIX)
#define NOTE_CS6 (NOTE_CS1 >> OCTAVE_SIX)
#define NOTE_D6 (NOTE_D1 >> OCTAVE_SIX)
#define NOTE_DS6 (NOTE_DS1 >> OCTAVE_SIX)
#define NOTE_E6 (NOTE_E1 >> OCTAVE_SIX)
#define NOTE_F6 (NOTE_F1 >> OCTAVE_SIX)
#define NOTE_FS6 (NOTE_FS1 >> OCTAVE_SIX)
#define NOTE_G6 (NOTE_G1 >> OCTAVE_SIX)
#define NOTE_GS6 (NOTE_GS1 >> OCTAVE_SIX)
#define NOTE_A6 (NOTE_A1 >> OCTAVE_SIX)
#define NOTE_AS6 (NOTE_AS1 >> OCTAVE_SIX)
#define NOTE_B6 (NOTE_B1 >> OCTAVE_SIX)
/*
#define NOTE_C7 (NOTE_C1 >> OCTAVE_SEVEN)
#define NOTE_CS7 (NOTE_CS1 >> OCTAVE_SEVEN)
#define NOTE_D7 (NOTE_D1 >> OCTAVE_SEVEN)
#define NOTE_DS7 (NOTE_DS1 >> OCTAVE_SEVEN)
#define NOTE_E7 (NOTE_E1 >> OCTAVE_SEVEN)
#define NOTE_F7 (NOTE_F1 >> OCTAVE_SEVEN)
#define NOTE_FS7 (NOTE_FS1 >> OCTAVE_SEVEN)
#define NOTE_G7 (NOTE_G1 >> OCTAVE_SEVEN)
#define NOTE_GS7 (NOTE_GS1 >> OCTAVE_SEVEN)
#define NOTE_A7 (NOTE_A1 >> OCTAVE_SEVEN)
#define NOTE_AS7 (NOTE_AS1 >> OCTAVE_SEVEN)
#define NOTE_B7 (NOTE_B1 >> OCTAVE_SEVEN)

#define NOTE_C8 (NOTE_C1 >> OCTAVE_EIGHT)
#define NOTE_CS8 (NOTE_CS1 >> OCTAVE_EIGHT)
#define NOTE_D8 (NOTE_D1 >> OCTAVE_EIGHT)
#define NOTE_DS8 (NOTE_DS1 >> OCTAVE_EIGHT)
#define NOTE_E8 (NOTE_E1 >> OCTAVE_EIGHT)
#define NOTE_F8 (NOTE_F1 >> OCTAVE_EIGHT)
#define NOTE_FS8 (NOTE_FS1 >> OCTAVE_EIGHT)
#define NOTE_G8 (NOTE_G1 >> OCTAVE_EIGHT)
#define NOTE_GS8 (NOTE_GS1 >> OCTAVE_EIGHT)
#define NOTE_A8 (NOTE_A1 >> OCTAVE_EIGHT)
#define NOTE_AS8 (NOTE_AS1 >> OCTAVE_EIGHT)
#define NOTE_B8 (NOTE_B1 >> OCTAVE_EIGHT)
*/

/* -----  Note   ----- */
typedef struct {
    int pitch;
    int duration;
	int velocity;
} Note;

extern UBYTE8 music_on;

void toggle_music();
void start_music();
void update_music();


#endif
