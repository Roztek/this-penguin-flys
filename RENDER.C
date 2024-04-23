#include "render.h"

UBYTE8 render_request = FALSE;

void master_render(ULONG32 *base, int state, const Context *context, UBYTE8 frame_counter) {
	switch (state) {
		case 0: 
        case 1: render_init_state(base, context); break;
        
		case 2: render_start_state(base, context, frame_counter); break;
		
		case 3: render_secret_state(base); break;
        
		case 4: render_idle_state(base, context, frame_counter); break;
        
		case 5: render_ground(base); break;
        
		case 6:
		case 7: render_round_state(base, context, frame_counter); break;
        
		case 8: render_final_state(base, context, frame_counter); break;
        
		default: break;
    }

	return;
}

/*************************************************************
 * Function: render_<XXXX>_state
 *  Purpose: renders current game state to the screen buffer
 *
 *  Details: these functions render the current game state
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *             context - pointer to the frame context structure
 *
 *      input: frame_counter - 3 tick frame counter
 ************************************************************/
void render_init_state(ULONG32 *base, const Context *context) {
	render_grey(base, context);

	return;
}

void render_secret_state(ULONG32 *base) {
	render_secret(base);

	return;
}

void render_start_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter) {
	render_splash(base, context);

	render_mouse(base, frame_counter);

	return;
}

void render_idle_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter) {
	clear_upper(base);	

	shift_ground();	

	render_penguin(base, context, frame_counter);
	render_score(base, context);
	render_ground(base);

	return;
}

void render_round_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter) {
	clear_upper(base);

	render_penguin(base, context, frame_counter);
	render_score(base, context);
	render_post(base, context, 0);
	render_post(base, context, 1);
	render_post(base, context, 2);
	
	return;
}

void render_final_state(ULONG32 *base, const Context *context, UBYTE8 frame_counter) {
	clear_upper(base);

	render_dead_penguin(base, context);
	render_post(base, context, 0);
	render_post(base, context, 1);
	render_post(base, context, 2);	
	render_scoreboard(base, context);

	if (!context->buttons[MENU].hovering) 
		render_button(base, context, MENU, menu_left_bitmap, menu_right_bitmap);
	else 
		render_button(base, context, MENU, menu_left_hovering_bitmap, menu_right_hovering_bitmap);
	if (!context->buttons[RESTART].hovering) 
		render_button(base, context, RESTART, restart_left_bitmap, restart_right_bitmap);
	else 
		render_button(base, context, RESTART, restart_left_hovering_bitmap, restart_right_hovering_bitmap);

	render_mouse(base, frame_counter);
	
	return;
}

/*************************************************************
 * Function: render_<XXXX>
 *  Purpose: renders a game object to the screen buffer
 *
 *  Details: these functions render various game objects to the
 *           screen such as the penguin, posts, score, or ground
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *             context - pointer to the frame context structure
 *
 *      input: frame_counter - 3 tick frame counter
 ************************************************************/
void render_penguin(ULONG32 *base, const Context *context, UBYTE8 frame_counter){
	if (frame_counter < 8) {
		plot_penguin(base, penguin_frame1, context->penguin.y);
	}
	else if (frame_counter < 16) {
		plot_penguin(base, penguin_frame2, context->penguin.y);
	}
	else {
		plot_penguin(base, penguin_frame3, context->penguin.y);
	}

	return;
}

void render_dead_penguin(ULONG32 *base, const Context *context) {
	plot_penguin(base, penguin_dead, context->penguin.y);

	return;
}

void render_post(ULONG32 *base, const Context *context, int index) {
	plot_post(base, context->posts[index].x, context->posts[index].y_gap);

	return;
}

void render_score(ULONG32 *base, const Context *context) {
	plot_score(base, context->score.y, context->score.total);

	return;
}

void render_button(ULONG32 *base, const Context *context, int index,
				   const ULONG32 *left_bitmap, const ULONG32 *right_bitmap) 
{
	unplot_button(base, context->buttons[index].x, context->buttons[index].y);	

	plot_button(base, context->buttons[index].x, context->buttons[index].y, left_bitmap, right_bitmap);

	return;
}

void render_scoreboard(ULONG32 *base, const Context *context) {
	unplot_scoreboard(base);	

	plot_scoreboard(base);
	plot_score(base, context->score.y, context->score.total);

	return;
}

void render_ground(ULONG32 *base) {
	plot_ground(base);

	return;
}

void render_grey(ULONG32 *base, const Context *context) {
	if (music_on)
		plot_splash(base, grey_bitmap1);
	else {
		if (context->buttons[EXIT].hovering)
			plot_splash(base, grey_power_bitmap2);
		else
			plot_splash(base, grey_bitmap2);
	}

	return;
}

void render_secret(ULONG32 *base) {
	if (music_on) 
		plot_splash(base, paul_bitmap1);
	else
		plot_splash(base, paul_bitmap2);

	return;
}

void render_splash(ULONG32 *base, const Context *context) {
	if (music_on) {
		if (context->buttons[NORMAL].hovering) {
			plot_splash(base, normal_bitmap1);
		}
		else if (context->buttons[HARD].hovering) {
			plot_splash(base, hard_bitmap1);
		} 
		else if (context->buttons[EXIT].hovering) {
			plot_splash(base, power_bitmap1);
		}
		else {
			plot_splash(base, splash_bitmap1);
		}
	}
	else {
		if (context->buttons[NORMAL].hovering) {
			plot_splash(base, normal_bitmap2);
		}
		else if (context->buttons[HARD].hovering) {
			plot_splash(base, hard_bitmap2);
		} 
		else if (context->buttons[EXIT].hovering) {
			plot_splash(base, power_bitmap2);
		}
		else {
			plot_splash(base, splash_bitmap2);
		}
	}

	return;
}

void render_mouse(ULONG32 *base, UBYTE8 frame_counter) {
	if (frame_counter < 12) { 
		plot_mouse(base, mouse.x, mouse.y, mouse_frame1);
	}
	else {
		plot_mouse(base, mouse.x, mouse.y, mouse_frame2);
	}

	return;
}
