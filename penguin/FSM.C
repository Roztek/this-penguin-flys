#include "fsm.h"

static eGameState game_state = INIT_GAME_STATE;

/*************************************************************
 * Function: penguin_fsm
 *  Purpose: implement game loop with a finite state machine
 *
 *  Details: this finite state machine is driven by the game loop, or clock,
 *           being called 70 times per second. it executes the games update
 *           logic depending on which state it is in, then checks if it should
 *           change states, returning its next state regardless of transition.
 *           input in tracked in the context structure as <char user_input>,
 *           where the FMS looks to decide some of its actions.
 *        note: see Figure 6 in Game Specifications Document on page 11.
 *
 *      IMPORTANT: user_input is carefully reset to a default value to
 *                 ensure intended functionality with each execution
 ************************************************************/
void penguin_fsm(Context *context, ULONG32 t_delta,  UBYTE8 frame_counter) {
	context->user_input = get_ikbd_input();

	if (context->user_input == QUIT_SCANCODE) {
		context->quit = TRUE;
	}
	else {
		switch (game_state) {
			case INIT_GAME_STATE: init_game_state(context, t_delta); break;
			
			case INIT_MENU_STATE: init_menu_state(context, t_delta); break;

			case MENU_STATE: menu_state(context); break;

			case SECRET_STATE: secret_state(t_delta); break;

			case IDLE_STATE: idle_state(context, frame_counter); break;

			case HALT_GROUND_STATE: halt_ground_state(context, t_delta); break;

			case NORMAL_STATE: normal_state(context, t_delta); break;

			case HARDMODE_STATE: hardmode_state(context, t_delta); break;

			case FINAL_STATE: final_state(context); break;

			default: game_state = INIT_MENU_STATE; break;
		}
	}

	context->user_input = DEFAULT;			/*	! reset user input !	*/

	return;
}

eGameState get_game_state() {
	return game_state;
}

/*************************************************************
 * Function: init_game_state
 *  Purpose: initializes the game state and context at the start
 *
 *  Details: sets up the initial state of buttons in the game  
 *           context, initializes the mouse position, and handles  
 *           the transition to the menu state after a certain    
 *           delay, starting the music and enabling mouse control
 ************************************************************/
void init_game_state(Context *context, ULONG32 t_delta) {
	static ULONG32 timer = MUSIC_DELAY;

	init_context(context);

	context->buttons[NORMAL].toggled = FALSE;
	context->buttons[HARD].toggled = FALSE;
	context->buttons[MENU].toggled = FALSE;
	context->buttons[RESTART].toggled = FALSE;

	context->buttons[EXIT].hovering = TRUE;

	init_mouse(307, 212);

	if (t_delta > 0) 
		timer--; 
	if (timer == 0) {
		game_state = MENU_STATE;
		start_music();
		enable_mouse();
		context->buttons[EXIT].hovering = FALSE;
	}

	return;
}

/*************************************************************
 * Functions: secret_state
 *   Purpose: ... details omitted ...
 *
 *   Details: ... details omitted ...
 ************************************************************/
void secret_state(ULONG32 t_delta) {
	static ULONG32 timer = SECRET_DELAY;

	if (t_delta > 0) 
		timer--; 
	if (timer == 0) {
		game_state = MENU_STATE;
		enable_mouse();
		timer = SECRET_DELAY;
	}

	return;
}

/*************************************************************
 * Function: init_context_state
 *  Purpose: initializes the game state and context for menu state
 *
 *  Details: sets up the initial state of buttons in the game  
 *           context, initializes the mouse position, and handles  
 *           the transition to the menu state after a certain delay           
 ************************************************************/
void init_menu_state(Context *context, ULONG32 t_delta) {
	static ULONG32 timer = CONTEXT_DELAY;
	
	init_context(context);

	context->buttons[NORMAL].toggled = FALSE;
	context->buttons[HARD].toggled = FALSE;
	context->buttons[MENU].toggled = FALSE;
	context->buttons[RESTART].toggled = FALSE;

	init_mouse(307, 212);

	if (t_delta > 0) 
		timer--; 
	if (timer == 0) {
		game_state = MENU_STATE;
		enable_mouse();
		timer = CONTEXT_DELAY;
	}

	return;
}

/*************************************************************
 * Function: menu_state
 *  Purpose: handles main menu interactions and state transitions
 *
 *  Details: this function checks for mouse interactions and keyboard 
 *           inputs to manage menu options like starting the game, 
 *           toggling music, switching game difficulty, and exiting. 
 *           It then updates the game state and context based on
 *           these user actions
 ************************************************************/
void menu_state(Context *context) {
	mouse_hovering_menu(context);

	if (mouse_click) {
		mouse_collision_menu(context);
	
		if (mouse_collision_music()) 
			toggle_music();

		mouse_click = FALSE;
	}

	if (context->user_input == MUSIC_SCANCODE) 
		toggle_music();

	if (context->user_input == NORMAL_SCANCODE
		|| context->user_input == HARD_SCANCODE
		|| context->buttons[NORMAL].toggled == TRUE
		|| context->buttons[HARD].toggled == TRUE)
	{
		game_state = IDLE_STATE;
		disable_mouse();

		if (context->user_input == NORMAL_SCANCODE) {
			context->buttons[NORMAL].toggled = TRUE;
		}
		if (context->user_input == HARD_SCANCODE) {
			context->buttons[HARD].toggled = TRUE;
		}
	}

	if (context->user_input == TRY_TO_FIND_ME) {
		game_state = SECRET_STATE;
		disable_mouse();
	}

	return;
}

/*************************************************************
 * Function: idle_state
 *  Purpose: handle idle state game logic
 *
 *  Details: checks penguins life status and resets context if dead. 
 *           Animates penguin's y position based on frame_counter and
 *           changes game state if SPACE is pressed. Does NOT reset 
 *           button states to preserve HALT_GROUND_STATE requirements
 ************************************************************/
void idle_state(Context *context, UBYTE8 frame_counter) {
	if (context->penguin.life != TRUE) {
		init_context(context);
		context->buttons[RESTART].toggled = FALSE;
	}

	if (frame_counter < 8) {
		context->penguin.y = 172;
	}
	else if (frame_counter < 16) {
		context->penguin.y = 175;
	}
	else {
		context->penguin.y = 169;
	}

	if (context->user_input == SPACE_SCANCODE) {
		game_state = HALT_GROUND_STATE;
	}

	return;
}

/*************************************************************
 * Function: halt_ground_state
 *  Purpose: to halt the ground bitmap from animating
 *
 *  Details: halts the ground by holding the state for 2 frames to 
 *           ensure ground bitmap is rendered to both buffers.  
 *           Transitions to NORMAL_STATE or HARDMODE_STATE based 
 *           on button toggle states
 ************************************************************/
void halt_ground_state(Context *context, ULONG32 t_delta) {
	static ULONG32 timer = 2;	

	if (t_delta > 0) 
		timer--; 
	if (timer == 0) {
		if (context->buttons[NORMAL].toggled == TRUE) {
			game_state = NORMAL_STATE;
		}
		if (context->buttons[HARD].toggled == TRUE) {
			game_state = HARDMODE_STATE;
		}		
		timer = 2;
	}

	return;
}

/*************************************************************
 * Functions: normal_state & hardmode_state
 *   Purpose: handles game logic for normal and hardmode states
 *
 *   Details: in both states, SPACE triggers asynchronous events; 
 *            t_delta (or the clock) triggers synchronous events. 
 *            On penguin death, transitions to FINAL_STATE, updates
 *            score, and initializes the mouse. The difference between 
 *            these states is the difficulty level of events processed
 *            in sync_events_normal and sync_events_hardmode functions
 ************************************************************/
void normal_state(Context *context, ULONG32 t_delta) {
	if (context->user_input == SPACE_SCANCODE) 
		async_events(context);

	if (t_delta > 0) 
		sync_events_normal(context);

	if (context->penguin.life == FALSE) {
        game_state = FINAL_STATE;
		context->score.y = 140;
		init_mouse(320, 280);
		enable_mouse();
    }

	return;
}

void hardmode_state(Context *context, ULONG32 t_delta) {
	if (context->user_input == SPACE_SCANCODE) 
		async_events(context);

	if (t_delta > 0) 
		sync_events_hardmode(context);

	if (context->penguin.life == FALSE) {
        game_state = FINAL_STATE;
		context->score.y = 140;
		init_mouse(320, 280);
		enable_mouse();
    }

	return;
}

/*************************************************************
 * Function: final_state
 *  Purpose: handles final menu interactions and state transitions
 *
 *  Details: this function checks for mouse interactions and keyboard 
 *           inputs to manage final options like restarting the game, 
 *           and returning to the main menu. It then updates the game 
 *           state and context based on these user actions
 ************************************************************/
void final_state(Context *context) {
	mouse_hovering_final(context);

	if (mouse_click) {
		mouse_collision_final(context);
		mouse_click = FALSE;
	}

	if (context->user_input == MENU_SCANCODE
		|| context->buttons[MENU].toggled == TRUE)
	{
		game_state = INIT_MENU_STATE;
		disable_mouse();
    }

	if (context->user_input == SPACE_SCANCODE
	    || context->user_input == RESTART_SCANCODE
		|| context->buttons[RESTART].toggled == TRUE)
	{
        game_state = IDLE_STATE;
		disable_mouse();
    }

	return;
}
