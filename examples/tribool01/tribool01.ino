// Copy lines "#include..." and "using..." below into your sketch
// Copy file "tribool.h" from "src" directory into your project

#include <tribool.h>
using namespace jb::logic;


tribool isWorking = unknown;

void setState()
{
	// Random number, sometimes 0
	// in most cases it sets isWorking as true, 
	// sometimes isWorking becomes false
	if (random(0, 10))
	{
		isWorking = true;
	}
	else
	{
		isWorking = false;
	}
}


// Connect Serial Monitor at speed 115200
void setup()
{
	Serial.begin(115200);
}

void loop()
{	
	if (isWorking)
	{
		Serial.println("My device is working");
	}
	else if (!isWorking)
	{
		Serial.println("My device failed");
	}
	else
	{
		Serial.println("My device was not initialized yet");
	}

	setState();

	delay(5000);
}

/****************
 * Example output,
 * the most important is the first line
 
 My device was not initialized yet
 My device is working
 My device is working
 My device is working
 My device is working
 My device failed
 My device is working

****************/
