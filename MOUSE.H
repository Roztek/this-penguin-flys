#ifndef MOUSE_H
#define MOUSE_H


#include "globals.h"

#define DEFAULT_CLICK 0xF8
#define RIGHT_CLICK 0xF9
#define LEFT_CLICK 0xFA
#define BOTH_CLICK 0xFB
#define TRY_TO_FIND_ME 0x19

#define CLICK_DELAY 2

typedef enum {
	STATE_ZERO,
	STATE_ONE,
	STATE_TWO
} eMouseState;

typedef struct {            
    int button;         
    int x;
	int y;           
    int delta_x; 
	int delta_y; 
} MousePacket;

extern UBYTE8 mouse_on;
extern UBYTE8 mouse_click; 

extern MousePacket mouse;

void init_mouse(int x, int y);
void enable_mouse();
void disable_mouse();
void update_mouse(UBYTE8 frame_counter);


#endif
