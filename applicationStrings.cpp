/*
 * applicationStrings.cpp
 *
 *  Created on: 14 May 2016
 *      Author: joe
 */

#include "applicationStrings.h"

#define ENTRY(enumVal, str) const char APP_STR_ ## enumVal[] PROGMEM = str;
APP_STRING_TABLE
#undef ENTRY

const char* const appStrings[] PROGMEM = {
#define ENTRY(enumVal, str) APP_STR_ ## enumVal,
		APP_STRING_TABLE
#undef ENTRY
};

//note this buffer needs to be large enough for the largest string defined in APP_STRING_TABLE
static char appStrBuffer[70];

String getAppStr(appStringType strType) {

	//note the use of pgm_read_dword here - this is a must on the esp8266 because addresses are 32bit
	strcpy_P(appStrBuffer, (char*)pgm_read_dword(&(appStrings[strType])));
	return String(appStrBuffer);
}


