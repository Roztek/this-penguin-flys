#include "effects.h"

void play_flap() {
	set_tone(CHANNEL_C, 0xFF00);
	set_noise(0x0A);
	set_volume(CHANNEL_C, ENVELOPE);
	set_envelope(0x7F, 0x05);
	enable_channel(CHANNEL_C, OFF, ON);

	return;
}

void play_chime() {
	set_tone(CHANNEL_C, 0x7040);
	set_volume(CHANNEL_C, ENVELOPE);
	set_envelope(0xFF, 0xFF);
	enable_channel(CHANNEL_C, ON, OFF);

	return;
}

void play_crash() {	
	set_tone(CHANNEL_C, 0xFFFF);
	set_noise(0xFF);
	set_volume(CHANNEL_C, ENVELOPE);
	set_envelope(0xFF, 0xFF);
	enable_channel(CHANNEL_C, OFF, ON);

	return;
}
