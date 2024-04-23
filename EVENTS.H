#ifndef EVENTS_H
#define EVENTS_H


#include "globals.h"
#include "model.h"
#include "random.h"
#include "effects.h"
#include "mouse.h"

void successful_pass(Context *context);
void penguin_collision(Context *context);
void post_collision(Context *context);
int closest_post(Context *context, int x);
void async_events(Context *context);
void sync_events_normal(Context *context);
void sync_events_hardmode(Context *context);

void mouse_collision_menu(Context *context);
void mouse_hovering_menu(Context *context);
void mouse_collision_final(Context *context);
void mouse_hovering_final(Context *context);
int mouse_collision_music();


#endif
