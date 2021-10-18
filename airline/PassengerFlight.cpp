#include "PassengerFlight.h"
#include"Error.h"
#include <string>
#include "Flight.h"
#include <iostream>
#include <sstream>
using namespace std;

PassengerFlight::PassengerFlight(int passengersCount, string from, string to, string planeId, int flightTime, Date* departureDate) 
	: Flight(from, to, planeId, flightTime, departureDate)
{
	this->passengersCount = passengersCount;
}

string PassengerFlight::ToString()
{
	return "Passenger " + Flight::ToString() + " with " + to_string(this->passengersCount) + " passengers";
}

string PassengerFlight::ToCsvString()
{
	return Flight::ToCsvString() + "," + to_string(this->passengersCount);
}

void PassengerFlight::InitFromCsvWithIndex(int csvPositionIndex, string value)
{
	if (csvPositionIndex == 9) {
		this->passengersCount = stoi(value);
	}
	
}

istream& operator>>(istream& in, PassengerFlight& flight) 
{
	in >> (Flight&)flight;

	int passengersCount;
	cout << "Passengers Count: ";
	in >> passengersCount;
	flight.passengersCount = passengersCount;
	return in;
}