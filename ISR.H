#ifndef ISR_H
#define ISR_H


#include "globals.h"
#include "render.h"
#include "music.h"
#include "keyboard.h"
#include "mouse.h"

#define VSYNC_VECTOR 28
#define IKBD_VECTOR 70

typedef void (*Vector)();

extern UBYTE8 frame_counter;

void vsync_req();
void ikbd_req();

void load_vectors();
void restore_vectors();
Vector install_vector(int num, Vector vector);
void mask_interrupts();
void unmask_interrupts();

/* ---  Assembly  --- */
void vsync_isr();
void ikbd_isr();
/* ------------------ */


#endif
