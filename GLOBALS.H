#ifndef GLOBALS_H
#define GLOBALS_H


/* ----- Library ----- */
#include <stdio.h>
#include <stdlib.h>

/* ----- General ----- */
#define NULL 0
#define TRUE 1
#define FALSE 0
#define DEFAULT -1              /* default input char */

#define START_SCANCODE 0x1C     /* makecode for [return] key */
#define QUIT_SCANCODE 0x01      /* makecode for [esc] key */
#define SPACE_SCANCODE 0x39     /* makecode for [ ]  key */
#define NORMAL_SCANCODE 0x31    /* makecode for [n] key */
#define HARD_SCANCODE 0x23      /* makecode for [h] key */
#define MENU_SCANCODE 0x32      /* makecode for [m] key */
#define RESTART_SCANCODE 0x13   /* makecode for [r] key */
#define MUSIC_SCANCODE 0x0E     /* makecode for [backspace] key */

/* ----- Raster  ----- */
#define SCREEN_WIDTH_BIT 640
#define SCREEN_HEIGHT_BIT 400
#define SCREEN_WIDTH_BYTE 80
#define SCREEN_HEIGHT_BYTE 50
#define SCREEN_WIDTH_WORD 40
#define SCREEN_HEIGHT_WORD 25
#define SCREEN_WIDTH_LONG 20

/* ----- Penguin ----- */
#define PENGUIN_X 220            /*	CAUTION: must alter EVENTS.C if changed */
#define PENGUIN_Y 172
#define PENGUIN_HEIGHT 32        /*	CAUTION: must alter EVENTS.C if changed */
#define PENGUIN_WIDTH 32         /*	CAUTION: must alter EVENTS.C if changed */
#define FLIGHT_VELOCITY -9
#define TERMINAL_VELOCITY 6
#define GRAVITY 1

/* -----  Post   ----- */
#define POST_MIN_Y 26
#define POST_MAX_Y 206
#define GAP_HEIGHT 102           /*	CAUTION: must alter EVENTS.C if changed */
#define POST_WIDTH 64            /*	CAUTION: must alter EVENTS.C if changed */
#define POST_HEIGHT 16           /*	CAUTION: must alter EVENTS.C if changed */
#define POST_VELOCITY_X -4
#define POST_VELOCITY_Y 1

/* -----  Other  ----- */
#define DIGIT_HEIGHT 32
#define DIGIT_WIDTH 16
#define BUTTON_HEIGHT 32
#define BUTTON_WIDTH 64
#define SCOREBOARD_HEIGHT 102
#define SCOREBOARD_WIDTH 64
#define GROUND_HEIGHT 340         /* CAUTION: must alter EVENTS.C if changed */
#define MOUSE_HEIGHT 32

/* -----  Types  ----- */
typedef unsigned char UBYTE8;
typedef unsigned int  UWORD16;
typedef unsigned long ULONG32;

/* ---  Assembly   --- */
void enter_super();
void exit_super();


#endif
