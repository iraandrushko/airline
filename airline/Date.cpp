#include "Date.h"
#include"Error.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

Date::Date(int year, int month, int day, int hour, int minute)
{
	if (year < 1970 
		|| month < 1 || month > 12
		|| day < 1  || day > 31
		|| hour < 0 || hour > 23 
		|| minute < 0 || minute > 59)
		throw Error(ErrorCode::WrongDate);

	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}

string Date::ToDateString()
{
	return to_string(year) + "/" + 
		to_string(month) + "/" + 
		to_string(day) + " " + 
		to_string(hour) + ":" + 
		to_string(minute);
}

string Date::ToDateCsvString()
{
	return to_string(year) + "," +
		to_string(month) + "," +
		to_string(day) + "," +
		to_string(hour) + "," +
		to_string(minute);
}