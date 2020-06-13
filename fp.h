/* This file contains a bunch of declarations for statements.
 * The actual fumction definitions are in fp.c
 */

#ifndef FP_H__
#define FP_H__

typedef union floatU{
	unsigned int bits;
	float theFloat;
}floatU;

float makeFloatParts(int sign, int exp, char* man);

int binToDec(char c);
float makeFloat(char* f);
void displayFloat(float f);

#endif /* FP_H__ */
