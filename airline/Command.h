#ifndef COMMAND_H
#define COMMAND_H
#include"PassengerFlight.h"
#include"CargoFlight.h"
#include"PassengerFlightRepository.h"
#include"CargoFlightRepository.h"


class Command 
{
	PassengerFlightRepository passenger_flight_Repository;
	CargoFlightRepository cargo_flight_Repository;

public:
	Command(int maxCapacity = 100);
	~Command();
	void AddPassengerFlight(PassengerFlight& car);
	void RemovePassengerFlight(int idx);
	void PrintPassengerFlights();
	void ShowTheLongestByDurationPassengerFlight();

	void AddCargoFlight(CargoFlight& flight);
	void RemoveCargoFlight(int idx);
	void PrintCargoFlights();
	void ShowTheLongestByDurationCargoFlight();
	
};

#endif // !COMMAND_H