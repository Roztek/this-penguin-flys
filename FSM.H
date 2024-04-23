#ifndef FSM_H
#define FSM_H


#include "globals.h"
#include "model.h"
#include "events.h"
#include "music.h"
#include "keyboard.h"
#include "mouse.h"

#define MUSIC_DELAY 15
#define CONTEXT_DELAY 10
#define SECRET_DELAY 21

typedef enum {
	INIT_GAME_STATE,
	INIT_MENU_STATE,
	MENU_STATE,
	SECRET_STATE,
	IDLE_STATE,
	HALT_GROUND_STATE,
	NORMAL_STATE,
	HARDMODE_STATE,
	FINAL_STATE
} eGameState;

void penguin_fsm(Context *context, ULONG32 t_delta,  UBYTE8 frame_counter);
eGameState get_game_state();

void init_game_state(Context *context, ULONG32 t_delta);
void secret_state(ULONG32 t_delta);
void init_menu_state(Context *context, ULONG32 t_delta);
void menu_state(Context *context);
void idle_state(Context *context, UBYTE8 frame_counter);
void halt_ground_state(Context *context, ULONG32 t_delta);
void normal_state(Context *context, ULONG32 t_delta);
void hardmode_state(Context *context, ULONG32 t_delta);
void final_state(Context *context);


#endif
