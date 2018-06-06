#include <tribool.h>

using tribool = jb::logic::tribool;
using jb::logic::unknown;

// such a declaration is required by Arduino preprocessor
jb::logic::tribool getTribool(int index);

tribool getTribool(int index)
{
	if (index == 0)
	{
		return tribool(false);
	}
	else if (index == 1)
	{
		return tribool(true);
	}
	else
	{
		return tribool(unknown);
	}
}

void setup()
{
	Serial.begin(115200);

	Serial.println(" A B   A&&B   A||B   A==B");

	for (auto index1 = 0; index1 < 3; ++index1)
	{
		for (auto index2 = 0; index2 < 3; ++index2)
		{
			auto A = getTribool(index1);
			auto B = getTribool(index2);

			Serial.print(" ");
			Serial.print(char(A));
			Serial.print(" ");
			Serial.print(char(B));
			Serial.print("   ");
			Serial.print(char(A && B));
			Serial.print("      ");
			Serial.print(char(A || B));
			Serial.print("      ");
			Serial.print(char(A == B));
			Serial.println();
		}
	}
}

void loop()
{
}

/****************
* Sketch output,

 A B   A&&B   A||B   A==B
 0 0   0      0      1
 0 1   0      1      0
 0 ?   0      ?      ?
 1 0   0      1      0
 1 1   1      1      1
 1 ?   ?      1      ?
 ? 0   0      ?      ?
 ? 1   ?      1      ?
 ? ?   ?      ?      ?

****************/
