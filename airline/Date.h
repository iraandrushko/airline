#ifndef DATE_H
#define DATE_H

#include<string>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

public:
	Date(int year=2021, int month=1, int day=1, int hour=0, int minute=0);
	string ToDateString();
	string ToDateCsvString();
};

#endif // !DATE_H