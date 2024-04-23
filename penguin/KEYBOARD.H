#ifndef KEYBOARD_H
#define KEYBOARD_H


#include "globals.h"

#define MAKE 0x00
#define BREAK 0x80

#define IKBD_a 0x1E
#define IKBD_b 0x30
#define IKBD_c 0x2E
#define IKBD_d 0x20
#define IKBD_e 0x12
#define IKBD_f 0x21
#define IKBD_g 0x22
#define IKBD_h 0x23
#define IKBD_i 0x17
#define IKBD_j 0x24
#define IKBD_k 0x25
#define IKBD_l 0x26
#define IKBD_m 0x32
#define IKBD_n 0x31
#define IKBD_o 0x18
#define IKBD_p 0x19
#define IKBD_q 0x10
#define IKBD_r 0x13
#define IKBD_s 0x1F
#define IKBD_t 0x14
#define IKBD_u 0x16
#define IKBD_v 0x2F
#define IKBD_w 0x11
#define IKBD_x 0x2D
#define IKBD_y 0x15
#define IKBD_z 0x2C

#define IKBD_1 0x02
#define IKBD_2 0x03
#define IKBD_3 0x04
#define IKBD_4 0x05
#define IKBD_5 0x06
#define IKBD_6 0x07
#define IKBD_7 0x08
#define IKBD_8 0x09
#define IKBD_9 0x0A
#define IKBD_0 0x0B

#define IKBD_SPACE 0x39
#define IKBD_ESC 0x01
#define IKBD_BS 0x0E
#define IKBD_DELETE 0x53
#define IKBD_RETURN 0x1C
#define IKBD_TAB 0x0F

#define IKBD_UP 0x48
#define IKBD_DOWN 0x50
#define IKBD_LEFT 0x4B
#define IKBD_RIGHT 0x4D

#define IKBD_BUFFER_SIZE 256
#define INIT_REPEAT_DELAY 24
#define AFTER_REPEAT_DELAY 8

extern UBYTE8 ikbd_buffer[256];
extern UBYTE8 head;
extern UBYTE8 tail;

extern UBYTE8 key_repeat;
extern UBYTE8 key_timer;

UBYTE8 ikbd_available();
UBYTE8 read_ikbd_input();
UBYTE8 get_ikbd_input();

/* --- Circular Queue --- */
void enqueue(UBYTE8 scancode);
UBYTE8 dequeue();
UBYTE8 is_empty();
UBYTE8 is_full();
/* ---------------------- */


#endif
