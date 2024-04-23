#include "raster.h"

/*************************************************************
 * Function: plot_bitmap_32
 *  Purpose: draws a 32x32 bitmap on the screen
 *
 *  Details: this function modifies the screen buffer pointed to by base
 *           to draw a 32x32 bitmap at the specified coordinates (x, y)
 *           note: utilizes bitwise shifts to avoid snapping to grid
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *
 *      input:  x/y - x and y coordinates of top left corner pixel
 *             bitmap - ULONG32 pointer to a 32x32 bitmap
 *             height - height of bitmap in bits
 ************************************************************/
 /*	CAUTION: no error checking - ! will plot off screen !	*/
void plot_bitmap_32_OR(ULONG32 *base, int x, int y,
					const ULONG32 *bitmap, unsigned int height)
{
	int i = 0;

	base += (x >> 5) + (y << 4) + (y << 2);

	while (i < height) {
		*base |= bitmap[i] >> (x & 31);
		*(base + 1) |= bitmap[i] << 32 - (x & 31);
		base += SCREEN_WIDTH_LONG;
		i++;
	}
	
	return;
}

 /*	CAUTION: no error checking - ! will plot off screen !	*/
void plot_bitmap_32_XOR(ULONG32 *base, int x, int y,
						const ULONG32 *bitmap, unsigned int height)
{
	int i = 0;
	base += (x >> 5) + (y << 4) + (y << 2);

	while (i < height) {
		*base ^= bitmap[i] >> (x & 31);
		*(base + 1) ^= bitmap[i] << 32 - (x & 31);
		base += SCREEN_WIDTH_LONG;
		i++;
	}

	return;
}

 /*	CAUTION: no error checking - ! will plot off screen !	*/
void plot_bitmap_32_AND(ULONG32 *base, int x, int y,
						const ULONG32 *bitmap, unsigned int height)
{
	int i = 0;
	base += (x >> 5) + (y << 4) + (y << 2);

	while (i < height) {
		*base &= bitmap[i] >> (x & 31);
		*(base + 1) &= bitmap[i] << 32 - (x & 31);
		base += SCREEN_WIDTH_LONG;
		i++;
	}

	return;
}

/*************************************************************
 * Function: plot_penguin
 *  Purpose: draws the penguin object to the screen
 *
 *  Details: this function modifies the screen buffer pointed to by base
 *           to draw posts at a semi-specified coordinate (240, y)
 *			 The function handles three cases:
 *              1. entire penguin is past top edge of the screen
 *			 	2. part of penguin is past top edge of the screen
 *              3. part or all of penguin is past ground height
 *              4. entire penguin is within top edge and ground height
 *           note: handles negative x coordinates
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *
 *      input: y - y coordinate of top left corner pixel
 *             velocity - velocity of the penguin
 ************************************************************/
void plot_penguin(ULONG32 *base, const ULONG32 *bitmap, int y) {
/* case 1: entirely past top edge of the screen */
	if (y < -PENGUIN_HEIGHT) { return; }
/* case 2: partly past top edge of the screen */
	if (y >= -PENGUIN_HEIGHT && y < 0) {
		plot_penguin_bitmap(base, PENGUIN_X, y, bitmap, PENGUIN_HEIGHT);
	}
/* case 3: past ground height */
	else if (y + PENGUIN_HEIGHT >= GROUND_HEIGHT) {
		plot_penguin_bitmap(base, PENGUIN_X, GROUND_HEIGHT - PENGUIN_HEIGHT,
					   bitmap, PENGUIN_HEIGHT);
	}
/* case 4: within top edge and ground height */
	else {
		plot_penguin_bitmap(base, PENGUIN_X, y, bitmap, PENGUIN_HEIGHT);
	}

	return;
}

void plot_penguin_bitmap(ULONG32 *base, int x, int y,
						    const ULONG32 *bitmap, unsigned int height)
{
	int i = 0;
    if (y < 0) {			/*	adjustments for negative y	*/
        bitmap += -y;
        height += y;
        y = 0;
    }
	base += (x >> 5) + (y << 4) + (y << 2);

	while (i < height) {
		*base |= bitmap[i] >> (x & 31);
		*(base + 1) |= bitmap[i] << 32 - (x & 31);
		base += SCREEN_WIDTH_LONG;
		i++;
	}
	
	return;
}

/*************************************************************
 * Function: plot_posts
 *  Purpose: draws a post object to the screen
 *
 *  Details: this function modifies the screen buffer pointed to by base
 *           to draw posts at a semi-specified coordinate (x, 0)
 *			 The function handles three cases:
 *              1. entire post is outside boundaries of the screen
 *			 	2. part of post extends past left edge of the screen
 *              3. part of post extends past right edge of the screen
 *              4. entire post is within boundaries of the screen
 *           note: handles negative x coordinates
 *
 *      input/output:
 *           base - ULONG32 pointer to the screen buffer
 *
 *      input:  x - x coordinate of starting location
 *            y_gap - x coordinate of the top of the safe zone between posts
 ************************************************************/
void plot_post(ULONG32 *base, int x, int y_gap) {
/* case 1: outside boundaries */
	if (x < -POST_WIDTH || x > 639) { return; }
/* case 2: partly past left edge of the screen */
	if (x <= -(POST_WIDTH / 2)) {
		/* top post	*/
		plot_post_bitmap(base, x + 32, y_gap - POST_HEIGHT, post_right_bitmap, 16);
		/* bottom post	*/
		plot_post_bitmap(base, x + 32, y_gap + GAP_HEIGHT, post_right_bitmap, 16);
	}
/* case 3: partly past right edge of the screen */
	else if (x + (POST_WIDTH / 2) > 639) {
		/* top post	*/
		plot_post_bitmap(base, x, y_gap - POST_HEIGHT, post_left_bitmap, 16);
		/* bottom post	*/
		plot_post_bitmap(base, x, y_gap + GAP_HEIGHT, post_left_bitmap, 16);
	}
/* case 4: within boundaries */
	else  {
		/* top post	*/
		plot_post_bitmap(base, x, y_gap - POST_HEIGHT, post_left_bitmap, 16);
		plot_post_bitmap(base, x + 32, y_gap - POST_HEIGHT, post_right_bitmap, 16);
		/* bottom post	*/
		plot_post_bitmap(base, x, y_gap + GAP_HEIGHT, post_left_bitmap, 16);
		plot_post_bitmap(base, x + 32, y_gap + GAP_HEIGHT, post_right_bitmap, 16);
	}

	return;
}

void plot_post_bitmap(ULONG32 *base, int x, int y,
						 const ULONG32 *bitmap, unsigned int height)
{
	int i = 0;
	base += (x >> 5) + (y << 4) + (y << 2);

	while (i < height) {
		if (x >= 0) {
			*base |= bitmap[i] >> (x & 31);
		}
		if (x < 608) {
			*(base + 1) |= bitmap[i] << 32 - (x & 31);
		}
		base += SCREEN_WIDTH_LONG;
		i++;
	}
	
	return;
}

/*************************************************************
 * Function: plot_score
 *  Purpose: draws the total score on the screen
 *
 *  Details: this function calculates each individual digit of the score
 *           and plots them at specific positions on the screen buffer.
 *           draws 1 to 3 digits depending on the magnitude of the score
 *           note: x position is centralized, y position can be adjusted
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *
 *      input:   y - y coordinate of the top of the score
 *            score - three digit value to be displayed as an
 *                    arabic numeral ranging from 0 to 9
 ************************************************************/
void plot_score(ULONG32 *base, int y, int total) {
	int hundreds, tens, ones;

	if (total <= 9) {
		plot_digit(base, 295, y, total);
	}
	else if (total <= 99) {
		tens = (total / 10) % 10;
		ones =  total % 10;
		plot_digit(base, 287, y, tens);
		plot_digit(base, 303, y, ones);
	}
	else {
		hundreds = total / 100;
		tens = (total / 10) % 10;
		ones =  total % 10;
		plot_digit(base, 279, y, hundreds);
		plot_digit(base, 295, y, tens);
		plot_digit(base, 311, y, ones);
	}

	return;
}

void plot_digit(ULONG32 *base, int x, int y, int digit) {
	if (digit == 0) {
		plot_bitmap_32_XOR(base, x, y, zero_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 1) {
		plot_bitmap_32_XOR(base, x, y, one_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 2) {
		plot_bitmap_32_XOR(base, x, y, two_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 3) {
		plot_bitmap_32_XOR(base, x, y, three_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 4) {
		plot_bitmap_32_XOR(base, x, y, four_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 5) {
		plot_bitmap_32_XOR(base, x, y, five_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 6) {
		plot_bitmap_32_XOR(base, x, y, six_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 7) {
		plot_bitmap_32_XOR(base, x, y, seven_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 8) {
		plot_bitmap_32_XOR(base, x, y, eight_bitmap, DIGIT_HEIGHT);
	}
	else if (digit == 9) {
		plot_bitmap_32_XOR(base, x, y, nine_bitmap, DIGIT_HEIGHT);
	}

	return;
}

void plot_scoreboard(ULONG32 *base) {
	int i = 0;
	int x = 288, y = 108;

	plot_bitmap_32_OR(base, x, y, scoreboard_left_bitmap1, 32);
	plot_bitmap_32_OR(base, x + 32, y, scoreboard_right_bitmap1, 32);

	plot_bitmap_32_OR(base, x, y + 32, scoreboard_left_bitmap2, 32);
	plot_bitmap_32_OR(base, x + 32, y + 32, scoreboard_right_bitmap2, 32);

	plot_bitmap_32_OR(base, x, y + 64, scoreboard_left_bitmap3, 32);
	plot_bitmap_32_OR(base, x + 32, y + 64, scoreboard_right_bitmap3, 32);

	return;
}

void unplot_scoreboard(ULONG32 *base) {
	int i = 0;
	int x = 288, y = 108;

	plot_bitmap_32_AND(base, x, y, zeros_32x32, 32);
	plot_bitmap_32_AND(base, x, y + 32, zeros_32x32, 32);
	plot_bitmap_32_AND(base, x, y + 64, zeros_32x32, 32);

	return;
}

void plot_button(ULONG32 *base, int x, int y,
				 const ULONG32 *left_bitmap, const ULONG32 *right_bitmap)
{
	plot_bitmap_32_OR(base, x, y, left_bitmap, BUTTON_HEIGHT);
	plot_bitmap_32_OR(base, x + 32, y, right_bitmap, BUTTON_HEIGHT);

	return;
}

void unplot_button(ULONG32 *base, int x, int y) {
	plot_bitmap_32_AND(base, x + 16, y, zeros_32x32, BUTTON_HEIGHT);

	return;
}

/*************************************************************
 * Function: plot_ground
 *  Purpose: draws a 640x60 bitmap of the ground on the screen
 *
 *  Details: this function modifies the screen buffer pointed to by
 *           base to draw a 640x60 bitmap at the coordinates (0, 340)
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 ************************************************************/
void plot_ground(ULONG32 *base) {
	int i = 0;
	base += 6800;

	while (i < 1200) {
		*base = ground_bitmap[i];
		base++;
		i++;
	}

	return;
}

/*************************************************************
 * Function: shift_ground
 *  Purpose: bit shift a specific section of ground bitmap
 *
 *  Details: this function modifies the ground bitmap to shift a
 *           specific section to create an efficient animation
 ************************************************************/
void shift_ground() {
	int i = 0, j;
	ULONG32* line;
	ULONG32 left_pixel;
	
	while (i < 8) { 
		line = &ground_bitmap[((i + 3) << 4) + ((i + 3) << 2)];
		left_pixel = (line[0] & 0x80000000) ? 1 : 0;
		
		j = 0;
		while (j < SCREEN_WIDTH_LONG - 1) {
			line[j] = (line[j] << 1) | (line[j + 1] >> 31);
			j++;
		}
		line[SCREEN_WIDTH_LONG - 1] 
			= (line[SCREEN_WIDTH_LONG - 1] << 1) | left_pixel;
			
		i++;
	}
	
	return;
}

/*************************************************************
 * Function: plot_splash
 *  Purpose: draws a 640x400 bitmap of splash art on the screen
 *
 *  Details: this function modifies the screen buffer pointed to by
 *           base to draw a 640x400 bitmap at the coordinates (0, 0)
 *
 *      input/output:
 *             base - ULONG32 pointer to the screen buffer
 *
 *      input: bitmap - ULONG32 pointer to the 640x400 bitmap
 ************************************************************/
void plot_splash(ULONG32 *base, const ULONG32 *bitmap) {
	int i = 0;

	while (i < 8000) {
		*base = bitmap[i];
		base++;
		i++;
	}

	return;
}

void plot_mouse(ULONG32 *base, int x, int y, const ULONG32 *bitmap) {
	plot_bitmap_32_XOR(base, x, y, bitmap, MOUSE_HEIGHT);

	return;
}
