#ifndef PASSENGERFLIGHT_H
#define PASSENGERFLIGHT_H

#include<string>
#include "Date.h"
#include "Flight.h"
using namespace std;

class PassengerFlight : public Flight
{
private:
	int passengersCount;

public:
	PassengerFlight(int passengersCount=0, string from="", string to="", string planeId="", int flightTime=0, Date* departureDate=NULL);
	string ToString() override;
	string ToCsvString() override;
	void InitFromCsvWithIndex(int csvPositionIndex, string value) override;

	friend istream& operator>>(istream& in, PassengerFlight& flight);
};

#endif // !PASSENGERFLIGHT_H