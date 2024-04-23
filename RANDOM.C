#include "random.h"

/*************************************************************
 * Function: random_num
 *  Purpose: generate a random integer within a specified range
 *
 *  Details: values given for range are taken inclusively
 *
 *      input: lower - lower bounding integer in range
 *             upper - upper bounding integer in range
 *
 *     output: <int> - random integer within a range
 ************************************************************/
int random_num(int lower, int upper) {
	int num;
	
	num = (rand() % (upper - lower + 1)) + lower;

	return num;
}
