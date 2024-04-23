#include "psg.h"

static volatile UBYTE8 *PSG_reg_select = 0xFFFF8800;
static volatile UBYTE8 *PSG_reg_write  = 0xFFFF8802;

void write_psg(int reg, UBYTE8 val) {
	if (reg < 0 || reg > 15 || val < 0 || val > 255) { return; }

	enter_super();	
	*PSG_reg_select = reg;
	*PSG_reg_write = val;
	exit_super(); 	

	return;
}

void write_psg_isr(int reg, UBYTE8 val) {
	*PSG_reg_select = reg;
	*PSG_reg_write = val;

	return;
}

UBYTE8 read_psg(int reg) {
	UBYTE8 val;
	if (reg < 0 || reg > 15) { return 0; }

	enter_super();	
	*PSG_reg_select = reg;
	val = *PSG_reg_select;
	exit_super(); 	

	return val;
}

void set_tone(int channel, int tuning) {
	int fine = tuning & 0xFF;
	int coarse = (tuning >> 8) & 0x0F;
	
	if (channel != CHANNEL_A && channel != CHANNEL_B && channel != CHANNEL_C) {
		return;
	}

	if (channel == CHANNEL_A) {
		write_psg(FREQ_A, fine);
		write_psg(FREQ_A + 1, coarse);
	}
	else if (channel == CHANNEL_B) {
		write_psg(FREQ_B, fine);
		write_psg(FREQ_B + 1, coarse);
	}
	else {
		write_psg(FREQ_C, fine);
		write_psg(FREQ_C + 1, coarse);
	}

	return;
}

void set_tone_isr(int channel, int tuning) {
	int fine = tuning & 0xFF;
	int coarse = (tuning >> 8) & 0x0F;
	
	if (channel == CHANNEL_A) {
		write_psg_isr(FREQ_A, fine);
		write_psg_isr(FREQ_A + 1, coarse);
	}
	else {
		write_psg_isr(FREQ_B, fine);
		write_psg_isr(FREQ_B + 1, coarse);
	}

	return;
}

void set_volume(int channel, int volume) {
	if (channel != CHANNEL_A && channel != CHANNEL_B && channel != CHANNEL_C) {
		return;
	}

	if (channel == CHANNEL_A) {
		write_psg(VOL_A, volume);
	}
	else if (channel == CHANNEL_B) {
		write_psg(VOL_B, volume);
	}
	else {
		write_psg(VOL_C, volume);
	}

	return;
}

void set_volume_isr(int channel, int volume) {
	if (channel == CHANNEL_A) {
		write_psg_isr(VOL_A, volume);
	}
	else {
		write_psg_isr(VOL_B, volume);
	}
	
	return;
}

void set_noise(int tuning) {
	int noise = tuning & 0x1F;
	
	write_psg(NOISE_FREQ, noise);
	
	return;
}

void set_envelope(int waveform, UBYTE8 shape) {
	int fine = waveform & 0xFF;
	int coarse = (waveform >> 8) & 0xFF;
	UBYTE8 reshape = shape & 0xF;
	
	write_psg(ENVELOPE_FINE, fine);
	write_psg(ENVELOPE_COARSE, coarse);
	write_psg(ENVELOPE_SHAPE, reshape);
	
	return;
}

void enable_channel(int channel, int tone_on, int noise_on) {
	UBYTE8 mixer_val = read_psg(MIXER);	

    switch (channel) {
        case CHANNEL_A:
            mixer_val = (mixer_val & 0xF6) | (!tone_on << 0) | (!noise_on << 3);
            break;
        case CHANNEL_B:
            mixer_val = (mixer_val & 0xED) | (!tone_on << 1) | (!noise_on << 4);
            break;
        case CHANNEL_C:
            mixer_val = (mixer_val & 0xDB) | (!tone_on << 2) | (!noise_on << 5);
            break;
        default:
            return;
    }

    write_psg(MIXER, mixer_val);

	return;
}

void start_sound() {
    set_tone(CHANNEL_A, NULL);  
    set_volume(CHANNEL_A, OFF);				/*	starts with volumn at zero 	*/
    enable_channel(CHANNEL_A, ON, OFF); 
	
    set_tone(CHANNEL_B, NULL);  
    set_volume(CHANNEL_B, OFF); 
    enable_channel(CHANNEL_B, ON, OFF); 
	
    set_tone(CHANNEL_C, NULL);  
    set_volume(CHANNEL_C, OFF); 
	set_noise(NULL); 
    enable_channel(CHANNEL_C, ON, ON);

	return;
}

void stop_sound() {
	set_tone(CHANNEL_A, NULL);  
	set_volume(CHANNEL_A, OFF);
	enable_channel(CHANNEL_A, OFF, OFF); 
	
	set_tone(CHANNEL_B, NULL);  
	set_volume(CHANNEL_B, OFF);
	enable_channel(CHANNEL_B, OFF, OFF); 
	
	set_tone(CHANNEL_C, NULL);  
	set_volume(CHANNEL_C, OFF);
	enable_channel(CHANNEL_C, OFF, OFF); 

	return;
}
