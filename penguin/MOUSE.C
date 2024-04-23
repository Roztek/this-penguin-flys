#include "mouse.h"

UBYTE8 mouse_on = FALSE;
UBYTE8 mouse_click = FALSE;

MousePacket mouse;

void init_mouse(int x, int y) {	
	mouse.button = DEFAULT_CLICK;
	
	mouse.x = x;
	mouse.y = y;
	mouse.delta_x = 0;
	mouse.delta_y = 0;

	return;
}

void enable_mouse() {
	mouse_on = TRUE;

	return;
}

void disable_mouse() {
	mouse_on = FALSE;

	return;
}

void update_mouse(UBYTE8 frame_counter) {
	static ULONG32 timer = CLICK_DELAY;

	if (frame_counter < 2) { 
		if (timer != 0)
			timer--; 
	}

	if ((mouse.button == LEFT_CLICK || mouse.button == RIGHT_CLICK)
		&& (timer == 0)) 
	{
		mouse_click = TRUE;	
		timer = CLICK_DELAY;
	}

	mouse.x += (int)((char)mouse.delta_x);
	mouse.y += (int)((char)mouse.delta_y);
	
	if (mouse.x < 0) { mouse.x = 0; }
	if (mouse.x > 607) { mouse.x = 607; }
	if (mouse.y < 0) { mouse.y = 0; }
	if (mouse.y > 308) { mouse.y = 308; }

	mouse.delta_x = 0;
	mouse.delta_y = 0;

	return;
}
