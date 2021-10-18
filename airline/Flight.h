#ifndef FLIGHT_H
#define FLIGHT_H

#include<string>
#include "Date.h"
using namespace std;

class Flight
{
private:
	string from;
	string to;
	string planeId;
	int flightTime;
	Date* departureDate;

public:
	Flight(string from = "", string to = "", string planeId = "", int flightTime = 0, Date* departureDate = NULL);
	virtual string ToString();
	virtual string ToCsvString();
	virtual void InitFromCsvWithIndex(int csvPositionIndex, string value);
	Flight& InitFromCsvString(string csvString);
	int GetFlightTime();

	ostream& operator<<(ostream& out);
	bool operator>(Flight& flight);
	string operator+(string str);

	friend string operator+(string str, Flight& flight);
	friend ostream& operator<<(ostream& out, Flight& flight);
	friend istream& operator>>(istream& in, Flight& flight);
};
#endif // !PASSENGERFLIGHT_H