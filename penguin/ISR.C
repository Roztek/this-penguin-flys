#include "isr.h"

static volatile UBYTE8 *ikbd_status           = 0xFFFFFC00;
static volatile UBYTE8 *ikbd_control          = 0xFFFFFC00;
static volatile UBYTE8 *ikbd_data             = 0xFFFFFC02;
static volatile UBYTE8 *interrupt_enable_b    = 0xFFFFFA09;
static volatile UBYTE8 *interrupt_inservice_b = 0xFFFFFA11;

static Vector vsync_orig_vector;
static Vector ikbd_orig_vector;

static eMouseState mouse_state = STATE_ZERO;

UBYTE8 frame_counter = 0;

/*************************************************************
 * Function: vsync_req
 *  Purpose: handles tasks to occur each vertical blank interrupt signal
 *
 * Details: this function increments the frame counter and conditionally 
 *          updates the music and mouse state based on the music_on and 
 *          mouse_on flags, respectively. It manages key repeat timing and 
 *          enqueues keyboard data when necessary. Finally, it sets a flag 
 *          to indicate a render request
 ************************************************************/
void vsync_req() {
	frame_counter++;
	
	if (music_on) 
		update_music();

	if (mouse_on)
		update_mouse(frame_counter);

	if (key_repeat) {
		key_timer--;
		if (key_timer == 0) {
			/* enqueue(previous scancode); */
			ikbd_buffer[tail++] = ikbd_buffer[tail - 1]; 
			key_timer = AFTER_REPEAT_DELAY;
		}
	}

	render_request = TRUE;

	return;
}

/*************************************************************
 * Function: ikbd_req
 *  Purpose: processes input from the keyboard each ikbd interrupt signal
 *
 * Details: this function reads the scancode from the ikbd data port and 
 *          processes it according to the current mouse state. It handles 
 *          button clicks, key presses and releases, and mouse movement by 
 *          updating the mouse state and enqueueing scancodes for further 
 *          processing. It also manages the key repeat feature and  
 *          acknowledges the interrupt
 ************************************************************/
void ikbd_req() {
	UBYTE8 scancode = *(ikbd_data);

	switch (mouse_state) {
		case STATE_ZERO:
			if (scancode >= DEFAULT_CLICK) {
				mouse.button = scancode;
				mouse_state = STATE_ONE;
			}
			else if ((scancode & BREAK ) == MAKE) {	
				/* enqueue(scancode); */
				ikbd_buffer[tail++] = scancode;			
				key_timer = INIT_REPEAT_DELAY;
				key_repeat = TRUE;
			}
			else if ((scancode & BREAK ) == BREAK) {
				key_timer = 0;
				key_repeat = FALSE;
			}
			break;

		case STATE_ONE:
			mouse.delta_x = scancode;
			mouse_state = STATE_TWO;
			break;

		case STATE_TWO:
			mouse.delta_y = scancode;
			mouse_state = STATE_ZERO;
			break;

		default: mouse_state = STATE_ZERO; break;
	}

	*interrupt_inservice_b &= 0xBF;

	return;
}

void load_vectors() {
	mask_interrupts();
	vsync_orig_vector = install_vector(VSYNC_VECTOR, vsync_isr);
	ikbd_orig_vector = install_vector(IKBD_VECTOR, ikbd_isr);
	unmask_interrupts();

	return;
}

void restore_vectors() {
	mask_interrupts();
	install_vector(VSYNC_VECTOR, vsync_orig_vector);
	install_vector(IKBD_VECTOR, ikbd_orig_vector);
	unmask_interrupts();

	return;
}

Vector install_vector(int num, Vector vector) {
	Vector orig;
	Vector *vector_ptr = (Vector *)((long)num << 2);

	enter_super();
	orig = *vector_ptr;
	*vector_ptr = vector;
	exit_super();

	return orig;
}

void mask_interrupts() {
    enter_super();
    *interrupt_enable_b &= 0xBF;
    exit_super();

	return;
}

void unmask_interrupts() {
    enter_super();
    *interrupt_enable_b |= 0x40;
    exit_super();

	return;
}
