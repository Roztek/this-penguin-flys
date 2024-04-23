#include "penguin.h"

UBYTE8 back_buffer[VIDEO_BUFFER_SIZE] = {0};

int main() {
	load_vectors();
	start_sound();
	this_penguin_flys();
	stop_sound();
	restore_vectors();

	return 0;
}

void this_penguin_flys() {
	UBYTE8 swapped = FALSE;

	ULONG32 *screen = get_video_base();	
	ULONG32 *back_screen;

	ULONG32 buffer_offset;
	ULONG32 t1 = 0, t2, t_delta;

	Context context;

	buffer_offset = 256 - ((ULONG32)(&back_buffer[0]) % 256);
	back_screen = (ULONG32 *)(&back_buffer[buffer_offset]);
	
	context.quit = FALSE;

	while(!context.quit) {
		t2 = frame_counter;
		t_delta = t2 - t1;
		t1 = t2;

		penguin_fsm(&context, t_delta, frame_counter);
		
		if(render_request) {
			if (!swapped) {
				master_render(screen, get_game_state(), &context, frame_counter);
				set_video_base(screen);
			}
			else {
				master_render(back_screen, get_game_state(), &context, frame_counter);
				set_video_base(back_screen);				
			}

			swapped ^= 1;
			render_request = FALSE;
		}

		if (frame_counter >= 24) { frame_counter = 0; }
	}

	clear_screen(screen);
	set_video_base(screen);	

	return;
}
