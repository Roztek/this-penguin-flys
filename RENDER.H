#ifndef RENDER_H
#define RENDER_H


#include "raster.h"
#include "model.h"
#include "music.h"
#include "mouse.h"

extern UBYTE8 render_request;

void master_render(ULONG32 *base, int state, const Context *context, UBYTE8 frame_counter);

void render_init_state(ULONG32 *base, const Context *context);
void render_secret_state(ULONG32 *base);
void render_start_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter);
void render_idle_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter);
void render_round_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter);
void render_final_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter);

void render_penguin(ULONG32 *base, const Context *context, UBYTE8 frame_counter);
void render_dead_penguin(ULONG32 *base, const Context *context);
void render_post(ULONG32 *base, const Context *context, int index);
void render_score(ULONG32 *base, const Context *context);
void render_button(ULONG32 *base, const Context *context, int index, const ULONG32 *left_bitmap, const ULONG32 *right_bitmap);
void render_scoreboard(ULONG32 *base, const Context *context);
void render_ground(ULONG32 *base);
void render_grey(ULONG32 *base, const Context *context);
void render_secret(ULONG32 *base);
void render_splash(ULONG32 *base, const Context *context);

void render_mouse(ULONG32 *base, UBYTE8 frame_counter);


#endif
