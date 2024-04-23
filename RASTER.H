#ifndef RASTER_H
#define RASTER_H


#define VIDEO_BUFFER_SIZE 32256
#define HIGHBYTE_ADDRESS 0xFFFF8201
#define MIDBYTE_ADDRESS 0xFFFF8203

#include "globals.h"
#include "bitmap.h"

void plot_bitmap_32_OR(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height);
void plot_bitmap_32_XOR(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height);
void plot_bitmap_32_AND(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height);

void plot_penguin(ULONG32 *base, const ULONG32 *bitmap, int y);
void plot_penguin_bitmap(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height);
void plot_post(ULONG32 *base, int x, int gap);
void plot_post_bitmap(ULONG32 *base, int x, int y, const ULONG32 *bitmap, unsigned int height);
void plot_score(ULONG32 *base, int y, int total);
void plot_digit(ULONG32 *base, int x, int y, int digit);
void plot_scoreboard(ULONG32 *base);
void unplot_scoreboard(ULONG32 *base);
void plot_button(ULONG32 *base, int x, int y, const ULONG32 *left_bitmap, const ULONG32 *right_bitmap);
void unplot_button(ULONG32 *base, int x, int y);
void plot_ground(ULONG32 *base);
void shift_ground();
void plot_splash(ULONG32 *base, const ULONG32 *bitmap);
void plot_mouse(ULONG32 *base, int x, int y, const ULONG32 *bitmap);

/* ---  Assembly  --- */
void clear_screen(ULONG32 *base);
void clear_upper(ULONG32 *base);
ULONG32 *get_video_base();
void set_video_base(ULONG32 *base);
/* ------------------ */


#endif
