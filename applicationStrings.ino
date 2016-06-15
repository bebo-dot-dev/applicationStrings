#include <Arduino.h>
#include "applicationStrings.h"

void setup()
{
	Serial.begin(115200);
}


void loop()
{
	Serial.println(getAppStr(appStringType::uniqueStrEnumVal1));
	Serial.println(getAppStr(appStringType::uniqueStrEnumVal2));
	Serial.println(getAppStr(appStringType::uniqueStrEnumVal3));
	delay(1000);
}
