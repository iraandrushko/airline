#ifndef CARGOFLIGHT_H
#define CARGOFLIGHT_H
#include<string>
#include "Date.h"
#include "Flight.h"
using namespace std;

class CargoFlight : public Flight
{
private:
	string cargoType;

public:
	CargoFlight(string cargoType = "", string from = "", string to = "", string planeId = "", int flightTime = 0, Date* departureDate = NULL);
	string ToString() override;
	string ToCsvString() override;
	void InitFromCsvWithIndex(int csvPositionIndex, string value) override;

	friend istream& operator>>(istream& in, CargoFlight& flight);
};


#endif // !CARGOFLIGHT_H