#include"Command.h"
#include"PassengerFlight.h"
#include "PassengerFlightRepository.h"
#include"Error.h"
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

Command::Command(int maxCapacity) : passenger_flight_Repository(maxCapacity), cargo_flight_Repository(maxCapacity)
{
}

Command::~Command()
{
}

void Command::AddPassengerFlight(PassengerFlight& flight)
{
	passenger_flight_Repository.Add(flight);
}

void Command::RemovePassengerFlight(int idx)
{
	passenger_flight_Repository.Remove(idx);
}

void Command::PrintPassengerFlights()
{
	passenger_flight_Repository.Print();
}

void Command::ShowTheLongestByDurationPassengerFlight()
{
	passenger_flight_Repository.ShowTheLongestByDurationFlight();
}

void Command::AddCargoFlight(CargoFlight& flight)
{
	cargo_flight_Repository.Add(flight);
}

void Command::RemoveCargoFlight(int idx)
{
	cargo_flight_Repository.Remove(idx);
}

void Command::PrintCargoFlights()
{
	cargo_flight_Repository.Print();
}

void Command::ShowTheLongestByDurationCargoFlight()
{
	cargo_flight_Repository.ShowTheLongestByDurationFlight();
}




