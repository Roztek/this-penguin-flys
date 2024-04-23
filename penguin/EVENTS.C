#include "events.h"

/*
	Note of Caution:
	  many values have been hard coded for optimization purposes.
	  comments above or below reflect meaning for the corresponding 
	  values.
*/

/*************************************************************
 * Function: successful_pass
 *  Purpose: update score when penguin successfully passes through posts
 *
 *  Details: this function checks if the post has passed the penguin and
 *           if the penguin is still alive, updating the score if so
 *
 *    IMPORTANT: the seemingly random - 1 lines up the penguins position
 *               with the post velocity (post velocity has uneven rate)
 *
 *        DEBUG: printf(" closest post index: %d\n", i);
 *
 *      input/output:
 *             context - pointer to the frame context structure
 ************************************************************/
void successful_pass(Context *context) {
	int i = closest_post(context, PENGUIN_X);

	int is_passing_post =	
		context->posts[i].x == 252;
     /* context->posts[i].x == PENGUIN_X + PENGUIN_WIDTH */
	int is_within_gap =
		(context->penguin.y + 6 >= context->posts[i].y_gap)
		&& (context->penguin.y <= context->posts[i].y_gap + 70);
        /* (context->penguin.y + PENGUIN_HEIGHT < context->posts[i].y_gap + GAP_HEIGHT) */
	if (context->penguin.life && is_passing_post) {
		if (is_within_gap) {
			update_score(&(context->score));
			play_chime();
		}
	}

	return;
}

/*************************************************************
 * Function: penguin_collision
 *  Purpose: check for collisions between the penguin and posts or ground
 *
 *  Details: this function checks if the penguin collided with any part of
 *           the post or the ground. If a collision occurs, the penguins life
 *           status is set to FALSE, indicating that the penguin is dead :'(
 *           note: + 6 on the y check enhances handling, compensating
 *                 for an animated hit-box (namely, the penguins wings)
 *
 *      input/output:
 *             context - pointer to the frame context structure
 ************************************************************/
void penguin_collision(Context *context) {
	int i = closest_post(context, PENGUIN_X);
					  
	int is_collision_x = 
		(156 <= context->posts[i].x)
     /* (PENGUIN_X <= context->posts[i].x + POST_WIDTH) */
	    && (252 >= context->posts[i].x);
	    /* (PENGUIN_X + PENGUIN_WIDTH >= context->posts[i].x) */
	int is_collision_upper_y =                        
		(context->penguin.y <= context->posts[i].y_gap + 118)
	 /* (context->penguin.y <= context->posts[i].y_gap + GAP_HEIGHT + POST_HEIGHT) */
		&& (context->penguin.y >= context->posts[i].y_gap + 70);
        /* (context->penguin.y + PENGUIN_HEIGHT >= context->posts[i].y_gap + GAP_HEIGHT) */
	int is_collision_lower_y =
		(context->penguin.y + 6 <= context->posts[i].y_gap)
		&& (context->penguin.y + 48 >= context->posts[i].y_gap);
		/* (context->penguin.y + PENGUIN_HEIGHT >= context->posts[i].y_gap - POST_HEIGHT) */
	if ((is_collision_x && (is_collision_upper_y || is_collision_lower_y))
		|| (context->penguin.y >= 308))
	{  /* (context->penguin.y >= PENGUIN_HEIGHT >= GROUND_HEIGHT) */
		context->penguin.life = FALSE;
		play_crash();
	}

	return;
}

/*************************************************************
 * Function: post_collision
 *  Purpose: check for collision between post and left edge of screen
 *
 *  Details: this function checks if a post has collided with the left edge of
 *           the screen by checking if it has finished drawing past its width,
 *           note: if so, resets x position, and gets new random y_gap value
 *
 *      input/output:
 *             context - pointer to the frame context structure
 ************************************************************/
void post_collision(Context *context) {
	int i = closest_post(context, -POST_WIDTH);
	int off_screen_left_threshold = -64;
								 /* -POST_WIDTH - POST_VELOCITY_X */
	if (context->posts[i].x <= off_screen_left_threshold) {
		context->posts[i].x = 640;
		context->posts[i].y_gap = random_num(POST_MIN_Y, POST_MAX_Y);
	}

	return;
}

/*************************************************************
 * Function: closest_post
 *  Purpose: find the closest post from a specified x coordinate
 *
 *  Details: this is a helper function to find the closest post in
 *           the current frame context from a given x pixel coordinate
 *           note: minimize checks to improve performance
 *                 total_checks = total_posts - 1
 *
 *      input/output:
 *             context - pointer to the frame context structure
 *
 *      input: x - x coordinate of the pixel
 *
 *     output: <int> - index of the closest post structure (0 to 2)
 ************************************************************/
int closest_post(Context *context, int x) {
    int closest_post = 0;
	int min_distance = abs(context->posts[0].x - x);
    int distance = abs(context->posts[1].x - x);;

    if (distance < min_distance) {
        min_distance = distance;
        closest_post = 1;
    }

    distance = abs(context->posts[2].x - x);
    if (distance < min_distance) {
        closest_post = 2;
    }

    return closest_post;
}

void async_events(Context *context) {
	penguin_flys(&(context->penguin));

	return;
}

void sync_events_normal(Context *context) {
	penguin_collision(context);
	post_collision(context);
	successful_pass(context);
	if (context->penguin.life == TRUE) {
		penguin_falls(&(context->penguin));
		update_post_x(&(context->posts[0]));
		update_post_x(&(context->posts[1]));
		update_post_x(&(context->posts[2]));
	}

	return;
}

void sync_events_hardmode(Context *context) {
	penguin_collision(context);
	post_collision(context);
	successful_pass(context);
	if (context->penguin.life == TRUE) {
		penguin_falls(&(context->penguin));
		update_post_x(&(context->posts[0]));
		update_post_y(&(context->posts[0]));
		update_post_x(&(context->posts[1]));
		update_post_y(&(context->posts[1]));
		update_post_x(&(context->posts[2]));
		update_post_y(&(context->posts[2]));
	}

	return;
}

void mouse_collision_menu(Context *context) {
	int normal_collision = ((mouse.x >= 220 && mouse.x <= 307) && (mouse.y >= 284 && mouse.y <= 312));
	int hardmode_collision = ((mouse.x >= 312 && mouse.x <= 399) && (mouse.y >= 284 && mouse.y <= 312));
	int exit_collision = ((mouse.x >= 472 && mouse.x <= 509) && (mouse.y >= 83 && mouse.y <= 123));
	int secret_collision = ((mouse.x >= 474 && mouse.x <= 505) && (mouse.y >= 240 && mouse.y <= 256));

	if (normal_collision) { context->buttons[NORMAL].toggled = TRUE; }
	if (hardmode_collision) { context->buttons[HARD].toggled = TRUE; }
	if (exit_collision) { context->quit = TRUE; }
	if (secret_collision) { context->user_input = TRY_TO_FIND_ME; }

	return;
}

void mouse_hovering_menu(Context *context) {
	int normal_collision = ((mouse.x >= 220 && mouse.x <= 307) && (mouse.y >= 284 && mouse.y <= 312));
	int hardmode_collision = ((mouse.x >= 312 && mouse.x <= 399) && (mouse.y >= 284 && mouse.y <= 312));
	int exit_collision = ((mouse.x >= 472 && mouse.x <= 509) && (mouse.y >= 83 && mouse.y <= 123));

	if (normal_collision) 
		context->buttons[NORMAL].hovering = TRUE; 
	else
		context->buttons[NORMAL].hovering = FALSE; 

	if (hardmode_collision) 
		context->buttons[HARD].hovering = TRUE; 
	else
		context->buttons[HARD].hovering = FALSE; 

	if (exit_collision) 
		context->buttons[EXIT].hovering = TRUE; 
	else
		context->buttons[EXIT].hovering = FALSE; 

	return;
}

void mouse_collision_final(Context *context) {
	int menu_collision = ((mouse.x >= 323 && mouse.x <= 387) && (mouse.y >= 220 && mouse.y <= 252));
	int restart_collision = ((mouse.x >= 253 && mouse.x <= 317) && (mouse.y >= 220 && mouse.y <= 252));

	if (menu_collision) { context->buttons[MENU].toggled = TRUE; }
	if (restart_collision) { context->buttons[RESTART].toggled = TRUE; }

	return;
}

void mouse_hovering_final(Context *context) {
	int menu_collision = ((mouse.x >= 323 && mouse.x <= 387) && (mouse.y >= 220 && mouse.y <= 252));
	int restart_collision = ((mouse.x >= 253 && mouse.x <= 317) && (mouse.y >= 220 && mouse.y <= 252));

	if (menu_collision) 
		context->buttons[MENU].hovering = TRUE; 
	else
		context->buttons[MENU].hovering = FALSE; 

	if (restart_collision) 
		context->buttons[RESTART].hovering = TRUE; 
	else
		context->buttons[RESTART].hovering = FALSE; 

	return;
}

int mouse_collision_music() {
	return (mouse.x >= 476 && mouse.x <= 505) && (mouse.y >= 141 && mouse.y <= 170);
}
