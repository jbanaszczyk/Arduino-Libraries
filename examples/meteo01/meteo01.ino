// Copy lines "#include..." and "using..." below into your sketch
// Copy file "tribool.h" from "src" directory into your project

#include <meteo.h>
using namespace jb::meteo;

// Connect Serial Monitor at speed 115200
void setup() {
	Serial.begin(115200);



}


void loop() {

	static float temperature = 0.f;
	static float humidity = 0.f;

	Serial.println("--------------------");

	Serial.print("Temperature ");
	Serial.print(temperature);
	Serial.println(" \u00B0C");

	Serial.print("Humidity:   ");
	Serial.print(humidity);
	Serial.println(" %");

	Serial.println();

	Serial.print("Heat index: ");
	Serial.print(heatIndexC(temperature,humidity));
	Serial.println(" \u00B0C");

	Serial.println();

	if ( temperature < 50.f)
	{
		temperature += 1.f;		
	} else if ( humidity < 100.f)
	{
		humidity += 1.f;
	}
	delay(1000);


}
