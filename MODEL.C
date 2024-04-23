#include "model.h"

/*************************************************************
 * Function: init_context
 *  Purpose: initialize the context frame
 *
 *  Details: posts spawn on a virtual x-axis with hard coded initial
 *           x spawn values to improve performance. after initial
 *           spawn posts reset to x = 640 when reaching x = -64
 *
 *      IMPORTANT: posts spawning x position MUST ensure that as
 *                 velocity is applied, the posts changing x position
 *                 lines up exactly with PENGUIN_X; PENGUIN_X MUST
 *                 be a multiple of POST_VELOCITY_X to ensure this
 *
 *      input/output:
 *             context - pointer to the frame context structure
 ************************************************************/
void init_context(Context *context) {
    init_penguin(&(context->penguin));

    init_post(&(context->posts[0]), 644 + PENGUIN_X);
	init_post(&(context->posts[1]), 652 + PENGUIN_X + PENGUIN_X);
	init_post(&(context->posts[2]), 664 + PENGUIN_X + PENGUIN_X + PENGUIN_X);	
	
    init_score(&(context->score));
	
	init_button(&(context->buttons[0]), 249, 272);		/*	NORMAL	*/		
	init_button(&(context->buttons[1]), 289, 272);		/*	HARD	*/
	init_button(&(context->buttons[2]), 323, 220);		/*	MENU	*/
	init_button(&(context->buttons[3]), 253, 220);		/*	RESTART	*/

	return;
}

void init_penguin(Penguin *penguin) {
	penguin->y = PENGUIN_Y;
	penguin->velocity = FLIGHT_VELOCITY;
	penguin->life = TRUE;

	return;
}

void init_post(Post *post, int x) {
	int seed = random_num(0, 1);
	
	post->x = x;
	post->y_gap = random_num(POST_MIN_Y, POST_MAX_Y);
	
	if (seed)
		post->y_direction = 1;
	else
		post->y_direction = -1;

	return;
}

void init_score(Score *score) {
	score->y = 40;
	score->total = 0;

	return;
}

void init_button(Button *button, int x, int y) {
	button->x = x;
	button->y = y;
	button->hovering = FALSE;

	return;
}

/*************************************************************
 * Function: penguin_flys & penguin_falls
 *  Purpose: update the velocity or position of the penguin
 *
 *  Details: these functions adjust the penguins vertical movement.
 *           Pressing SPACE sets the penguins velocity to -9, moving
 *           it upward. Gravity incrementally increases velocity, capping
 *           it at +6 for downward motion.
 *           note: penguin only moves along the y-axis, with negative
 *                 negative for upward and positive for downward motion
 *
 *      input/output:
 *             penguin - pointer to the penguin structure
 ************************************************************/
void penguin_flys(Penguin *penguin) {
	if (penguin->y > -130) 						/* maximum virtual off screen height */
		penguin->velocity = FLIGHT_VELOCITY;
	
	if (penguin->y > -60) 
		play_flap();

	return;
}

void penguin_falls(Penguin *penguin) {
	penguin->y += penguin->velocity;

	if (penguin->velocity < TERMINAL_VELOCITY) 
		penguin->velocity += GRAVITY;

	return;
}

void update_post_x(Post *post) {
	post->x += POST_VELOCITY_X;

	return;
}

void update_post_y(Post *post) {
	post->y_gap += POST_VELOCITY_Y * post->y_direction;

	if (post->y_gap < POST_MIN_Y || post->y_gap > POST_MAX_Y )
		post->y_direction = -(post->y_direction); 

	return;
}

void update_score(Score *score) {
	score->total++;

	return;
}

void update_button(Button *button) {
	button->toggled = TRUE;

	return;
}
