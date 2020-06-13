#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fp.h"
#include <math.h>
/*Austin Kurilla
 * CS 252
 * Lab 8
 * Converting between floating point decimals and binary
 */

//Takes in a float value and prints the binary representation of the float to the console
void displayFloat(float f)
{
	int i;
	int * x;
	int z = 0;

	x = &f;
	for (i = sizeof(int) * 8 - 1; i >= 0; i--)
	{
		if(z == 1 || z == 9){
			printf(" ");
		}
		printf("%d", (*x) >> i & 1);
		z++;
	}
	printf("\n");

}
//Builds the float using bitwise operations
float makeFloatParts(int sign, int exp, char* man){
	floatU foo;
	unsigned int expU = exp + 127; 
	if(sign == -1)
	{
		foo.bits = 1;
	}
	else{
		foo.bits = 0;
	}

	foo.bits = (foo.bits << 8) | expU;
	int i;
	for(i = 0; i < 23; i++)
	{
	if(man[i] == '1')
	{
		foo.bits = (foo.bits << 1) | 1;
	}
	else
	{
	foo.bits = (foo.bits << 1) | 0;
	}
	}	
	return foo.theFloat;
}


//Takes in a binary string of characters and prints out the value represented as a float.
float makeFloat(char* f)
{
	char man[23];
	int sign = 1;
	int exp = 0;
	
	if(f == NULL)
	{
		fprintf(stderr,"Null string passed to makeFloat");
		return 0.0;
	}

	if(f[0] == '-'){
		sign = -1;
	}
	while(f[2 + exp] != '.')
	{
		exp++;
	}
	int i;
	int counter = 0;
	for(i = 2; i < strlen(f);i++)
	{
		if (i != (2 + exp))
		{
			man[counter] = f[i];
			counter++;
		}
	}
	float x = makeFloatParts(sign,exp,man);
	//printf("The float is %f\n",x);
	//printf("f is %s\n",f);
	//printf("The exp is : %d\n",exp);
	//printf("The man bits are %s\n",man);
	return x;
	
}

