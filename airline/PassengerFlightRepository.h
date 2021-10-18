#ifndef PASSENGERREPOSITORY_H
#define PASSENGERREPOSITORY_H

#include"Repository.h"
#include"PassengerFlight.h"
#include <string>
#include <sstream>
using namespace std;

class PassengerFlightRepository : public Repository<PassengerFlight>
{
protected:
	string GetFileName() { return "passenger_flights.txt"; }
	string GetTitle() { return "Passenger flights:"; }

	void LoadFlightsFromFile() override
	{
		string line;
		ifstream MyReadFile(this->GetFileName());

		while (getline(MyReadFile, line)) {

			PassengerFlight flight;
			flight.InitFromCsvString(line);

			Add(flight);
		}

		MyReadFile.close();
	}

public:
	PassengerFlightRepository(int max) : Repository(max) {
		this->LoadFlightsFromFile();
	}

	~PassengerFlightRepository()
	{
		WriteFlightsToFile();
	}
};
#endif // !PASSENGERREPOSITORY_H