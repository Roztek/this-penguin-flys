#ifndef PSG_H
#define PSG_H


#include "globals.h"

#define ON 1
#define OFF 0
#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2
#define ENVELOPE 0x10

/* ----- Reg Array ----- */
#define FREQ_A 0
#define FREQ_B 2
#define FREQ_C 4
#define NOISE_FREQ 6
#define MIXER 7
#define VOL_A 8
#define VOL_B 9
#define VOL_C 10
#define ENVELOPE_FINE 11
#define ENVELOPE_COARSE 12
#define ENVELOPE_SHAPE 13
#define PORT_A 14
#define PORT_B 15
/* --------------------- */
	
void write_psg(int reg, UBYTE8 val);
void write_psg_isr(int reg, UBYTE8 val);
UBYTE8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_tone_isr(int channel, int tuning);
void set_volume(int channel, int volume);
void set_volume_isr(int channel, int volume);
void set_noise(int tuning);
void set_envelope(int waveform, UBYTE8 shape);
void enable_channel(int channel, int tone_on, int noise_on);
void start_sound();
void stop_sound();


#endif
