/*
 * ApplicationStrings.h
 *
 *  Created on: 13 May 2016
 *      Author: joe
 */

#ifndef APPLICATIONSTRINGS_H_

#define APPLICATIONSTRINGS_H_

#include <Arduino.h>
#include <pgmspace.h>

/*
 * STRING_TABLE defines all strings and their associated enum value in the preprocessor generated
 * appStringType enum and appStrings[] array
 */
#define APP_STRING_TABLE \
	ENTRY(uniqueStrEnumVal1, "String1") \
	ENTRY(uniqueStrEnumVal2, "String2") \
	ENTRY(uniqueStrEnumVal3, "String3") \

//definition of the string enumeration - one unique enum value per string
enum appStringType {
#define ENTRY(enumVal, str) enumVal,
	APP_STRING_TABLE
#undef ENTRY
};

//forward declaration of the string array
#define ENTRY(enumVal, str) extern const char APP_STR_ ## enumVal[];
APP_STRING_TABLE
#undef ENTRY

//forward declaration of the string array
extern const char* const appStrings[];

//forward declaration of the string helper function
String getAppStr(appStringType strType);

#endif /* APPLICATIONSTRINGS_H_ */
