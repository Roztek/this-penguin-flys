#include "keyboard.h"

UBYTE8 ikbd_buffer[IKBD_BUFFER_SIZE] = {0};
UBYTE8 head = 0;
UBYTE8 tail = 0;

UBYTE8 key_repeat = FALSE;
UBYTE8 key_timer = INIT_REPEAT_DELAY;

UBYTE8 ikbd_available() {
	return head != tail;
}

UBYTE8 read_ikbd_input() {
	return dequeue();
}

UBYTE8 get_ikbd_input() {
	if (ikbd_available()) 
		return read_ikbd_input();

	return DEFAULT;
}

void enqueue(UBYTE8 scancode) {
	ikbd_buffer[tail++] = scancode;

	return;
}

UBYTE8 dequeue() {
	return ikbd_buffer[head++];
}

UBYTE8 is_empty() {
    return head == tail;
}

UBYTE8 is_full() {
    return ((tail + 1) % IKBD_BUFFER_SIZE) == head;
}
