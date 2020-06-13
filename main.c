#include <stdio.h>
#include <stdlib.h>
#include "fp.h"
#include <math.h>
#include <string.h>
#include <signal.h>
void signalhandler()
{
	printf("Exiting......\n");
	exit(0);
}
int main(int argc, char* argv[])
{
	char binarystring[100];
	char mode[100];
	float f;
	signal(SIGINT,signalhandler);
	printf("Welcome to IEEE 754 to Binary Converter // Use ctrl+c to exit // Created by - Autin Kurilla\n\n");
	while(1){
		printf("Enter 'fp' to convert a floating point number to binary or enter 'b' to convert a binary number to IEEE 754\n");
		scanf("%s",mode);
		if(strcmp(mode,"b") == 0) {
			printf("Enter a binary number in the form (+/-)xxxxxxxx.xxxxxxxxxxxxxxxxxxxxxxx or (sign)(exponent).(fraction) \n");
			scanf("%s",binarystring);
			f = makeFloat(binarystring);
			printf("%s in binary notatinon is - \n %f \n\n\n",binarystring,f);

		}
		else if(strcmp(mode,"fp") == 0){
			printf("Enter a float in the form (+/x)xx.xx or (sign)(float).(decimal) \n");
			scanf("%f",&f);
			printf("%f in binary notation is - \n",f);
			displayFloat(f);
			printf("\n\n\n");
		}
		else{
			printf("Invalid Mode entered \n");
		}
	}
}

