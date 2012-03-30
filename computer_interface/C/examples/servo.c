/*
	Created: December 2011
	by ihsan Kehribar <ihsan@kehribar.me>
*/

#include <stdio.h>
#include <stdlib.h>
#include "littleWire.h"
#include "littleWire_util.h"
#include "littleWire_servo.h"

#define DELAY 50	// Delay, in miliseconds

unsigned char currentLocation = 0;
unsigned char direction=1;	

int main(void)
{
	littleWire *myLittleWire = NULL;
	
	myLittleWire = littleWire_connect();

	if(myLittleWire == NULL){
		printf("Little Wire could not be found!\n");
		exit(EXIT_FAILURE);
	}

	//servo_init(myLittleWire);
	pinMode(myLittleWire,PIN3,OUTPUT);
	pinMode(myLittleWire,PIN4,OUTPUT);
	while(1)
	{
		digitalWrite(myLittleWire,PIN3,HIGH);
		digitalWrite(myLittleWire,PIN3,LOW);
		digitalWrite(myLittleWire,PIN4,HIGH);
		digitalWrite(myLittleWire,PIN4,LOW);
	}
	for(;;)
	{
		printf("Current locations: %d\n",currentLocation);

		// Set two servo channels to the same location
		servo_updateLocation(myLittleWire,currentLocation,currentLocation);
		
		if(direction)
			currentLocation++;
		else
			currentLocation--;

		if(currentLocation==255)
			direction=0;
		else if(currentLocation==0)
			direction=1;

		delay(DELAY);
	}
}
