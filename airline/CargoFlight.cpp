#include "CargoFlight.h"
#include"Error.h"
#include <string>
#include "Flight.h"
#include <iostream>
#include <sstream>
using namespace std;

CargoFlight::CargoFlight(string cargoType, string from, string to, string planeId, int flightTime, Date* departureDate)
	: Flight(from, to, planeId, flightTime, departureDate)
{
	this->cargoType = cargoType;
}

string CargoFlight::ToString()
{
	return "Cargo " + Flight::ToString() + " carrying " + this->cargoType;
}

string CargoFlight::ToCsvString()
{
	return Flight::ToCsvString() + "," + this->cargoType;
}

void CargoFlight::InitFromCsvWithIndex(int csvPositionIndex, string value)
{
	if (csvPositionIndex == 9) {
		this->cargoType = value;
	}

}

istream& operator>>(istream& in, CargoFlight& flight)
{
	in >> (Flight&)flight;

	string cargoType;
	cout << "Cargo Type: ";
	in >> cargoType;
	flight.cargoType = cargoType;
	return in;
}