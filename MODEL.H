#ifndef MODEL_H
#define MODEL_H


#include "globals.h"
#include "random.h"
#include "effects.h"

#define NORMAL 0
#define HARD 1
#define MENU 2
#define RESTART 3
#define EXIT 4

typedef struct {
	int y;
	int velocity;
	UBYTE8 life;			/*	1 (TRUE) = alive, 0 (FALSE) = dead	*/
} Penguin;

typedef struct {
	int x;
	int y_gap;				/*	y position of the safe zone, or gap	*/
	int y_direction;
} Post;

typedef struct {
	int y;
	int total;				/*	current total score of the round	*/
} Score;

typedef struct {
	int x;
	int y;
	UBYTE8 toggled;			/*	1 (TRUE) = on, 0 (FALSE) = off	*/
	UBYTE8 hovering;		/*	1 (TRUE) = , 0 (FALSE) = 	*/
} Button;

typedef struct {
	Penguin penguin;
	Post posts[3];
	Score score;
	Button buttons[5];		/*	0: NORMAL, 1: HARD, 2: MENU, 3: RESTART, 4: EXIT	*/
	char user_input;		/*	finite state machine input driver	*/
	UBYTE8 quit;			/*	1 (TRUE) = quit, 0 (FALSE) = continue	*/
} Context;

void init_context(Context *context);

void init_penguin(Penguin *penguin);
void init_post(Post *post, int x);
void init_score(Score *score);
void init_button(Button *button, int x, int y);

void penguin_flys(Penguin *penguin);
void penguin_falls(Penguin *penguin);
void update_post_x(Post *post);
void update_post_y(Post *post);
void update_score(Score *score);
void update_button(Button *button);


#endif
