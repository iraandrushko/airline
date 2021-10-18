#include "Flight.h"
#include"Error.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Flight::Flight(string from, string to, string planeId, int flightTime, Date* departureDate)
{
	this->from = from;
	this->to = to;
	this->planeId = planeId;
	this->flightTime = flightTime;
	this->departureDate = departureDate;
}

int Flight::GetFlightTime()
{
	return flightTime;
}

string Flight::ToString()
{
	return "Flight '" + planeId + "' from '" + from + "' to '" + to + "' at " + (*departureDate).ToDateString();
}

string Flight::ToCsvString()
{
	return planeId + "," + from + "," + to + "," + to_string(flightTime) + "," + departureDate->ToDateCsvString();
}

Flight& Flight::InitFromCsvString(string csvString) 
{
	stringstream ss(csvString);
	string str;
	int index = -1;

	string planeId, from, to;
	int flightTime, year, month, day, hour, minute, passengersCount;

	while (getline(ss, str, ',')) {
		switch (++index)
		{
		case 0:
			planeId = str;
			break;
		case 1:
			from = str;
			break;
		case 2:
			to = str;
			break;
		case 3:
			flightTime = stoi(str);
			break;
		case 4:
			year = stoi(str);
			break;
		case 5:
			month = stoi(str);
			break;
		case 6:
			day = stoi(str);
			break;
		case 7:
			hour = stoi(str);
			break;
		case 8:
			minute = stoi(str);
			break;
		default:
			this->InitFromCsvWithIndex(index, str);
			break;
		}
	}

	Date* departureDate = new Date(year, month, day, hour, minute);
	this->from = from;
	this->to = to;
	this->planeId = planeId;
	this->flightTime = flightTime;
	this->departureDate = departureDate;
	
	return *this;
}

void Flight::InitFromCsvWithIndex(int csvPositionIndex, string value) {}

string Flight::operator+(string str)
{
	return this->ToString() + str;
}

string operator+(string str, Flight& flight)
{
	return str + flight.ToString();
}

ostream& Flight::operator<<(ostream& out)
{

	return out << this->ToString();
}

ostream& operator<<(ostream& out, Flight& flight)
{
	return flight << out;
}

istream& operator>>(istream& in, Flight& flight)
{
	string from, to, planeId;
	int flightTime, year, month, day, hour, minute;

	cout << "Airplane Id: ";
	in >> planeId;
	flight.planeId = planeId;

	cout << "Departure city: ";
	in >> from;
	flight.from = from;

	cout << "Destination city: ";
	in >> to;
	flight.to = to;

	cout << "Flight duration: ";
	in >> flightTime;
	flight.flightTime = flightTime;

	cout << "Departure year: ";
	in >> year;

	cout << "Departure month: ";
	in >> month;

	cout << "Departure day: ";
	in >> day;

	cout << "Departure hour: ";
	in >> hour;

	cout << "Departure minute: ";
	in >> minute;

	Date* departureDate = new Date(year, month, day, hour, minute);
	flight.departureDate = departureDate;

	return in;
}

bool Flight::operator>(Flight& flight)
{
	return this->flightTime > flight.flightTime;
}

