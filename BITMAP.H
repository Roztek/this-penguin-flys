#ifndef BITMAP_H
#define BITMAP_H


#include "globals.h"

/* ----- Mouse  ----- */
extern const ULONG32 mouse_frame1[MOUSE_HEIGHT];
extern const ULONG32 mouse_frame2[MOUSE_HEIGHT];

/* ----- Penguin ----- */
extern const ULONG32 penguin_frame1[PENGUIN_HEIGHT];
extern const ULONG32 penguin_frame2[PENGUIN_HEIGHT];
extern const ULONG32 penguin_frame3[PENGUIN_HEIGHT];
extern const ULONG32 penguin_dead[PENGUIN_HEIGHT];

/* -----  Post   ----- */
extern const ULONG32 post_left_bitmap[POST_HEIGHT];		/*	x2 16x32 chunks	*/
extern const ULONG32 post_right_bitmap[POST_HEIGHT];	/*	total: 64x16	*/

/* ----- Numbers ----- */
extern const ULONG32 zero_bitmap[DIGIT_HEIGHT];
extern const ULONG32 one_bitmap[DIGIT_HEIGHT];
extern const ULONG32 two_bitmap[DIGIT_HEIGHT];
extern const ULONG32 three_bitmap[DIGIT_HEIGHT];
extern const ULONG32 four_bitmap[DIGIT_HEIGHT];
extern const ULONG32 five_bitmap[DIGIT_HEIGHT];
extern const ULONG32 six_bitmap[DIGIT_HEIGHT];
extern const ULONG32 seven_bitmap[DIGIT_HEIGHT];
extern const ULONG32 eight_bitmap[DIGIT_HEIGHT];
extern const ULONG32 nine_bitmap[DIGIT_HEIGHT];

/* ----- Buttons ----- */
extern const ULONG32 menu_left_bitmap[BUTTON_HEIGHT];	/*	x2 32x32 chunks	*/
extern const ULONG32 menu_right_bitmap[BUTTON_HEIGHT];	/*	total: 64x32	*/
extern const ULONG32 menu_left_hovering_bitmap[BUTTON_HEIGHT];
extern const ULONG32 menu_right_hovering_bitmap[BUTTON_HEIGHT];
extern const ULONG32 restart_left_bitmap[BUTTON_HEIGHT];
extern const ULONG32 restart_right_bitmap[BUTTON_HEIGHT];
extern const ULONG32 restart_left_hovering_bitmap[BUTTON_HEIGHT];
extern const ULONG32 restart_right_hovering_bitmap[BUTTON_HEIGHT];

/* -----  Score  ----- */
extern const ULONG32 scoreboard_left_bitmap1[32];		/*	x6 32x32 chunks	*/
extern const ULONG32 scoreboard_left_bitmap2[32];		/*	total: 64x96	*/
extern const ULONG32 scoreboard_left_bitmap3[32];
extern const ULONG32 scoreboard_right_bitmap1[32];
extern const ULONG32 scoreboard_right_bitmap2[32];
extern const ULONG32 scoreboard_right_bitmap3[32];

/* ----- Splash  ----- */
extern const ULONG32 splash_bitmap1[8000];               /* bitmap2 = volumn knob on    */
extern const ULONG32 splash_bitmap2[8000];               /* bitmap2 = volumn knob off   */
extern const ULONG32 grey_bitmap1[8000];
extern const ULONG32 grey_bitmap2[8000];
extern const ULONG32 grey_power_bitmap2[8000];
extern const ULONG32 paul_bitmap1[8000];
extern const ULONG32 paul_bitmap2[8000];
extern const ULONG32 normal_bitmap1[8000];
extern const ULONG32 normal_bitmap2[8000];
extern const ULONG32 hard_bitmap1[8000];
extern const ULONG32 hard_bitmap2[8000];
extern const ULONG32 power_bitmap1[8000];
extern const ULONG32 power_bitmap2[8000];

/* -----  Other  ----- */
extern const ULONG32 zeros_32x32[32];
extern const ULONG32 ground_bitmap[1200];


#endif
