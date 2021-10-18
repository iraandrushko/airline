#ifndef CARGOFLIGHTREPOSITORY_H
#define CARGOFLIGHTREPOSITORY_H

#include"Repository.h"
#include"CargoFlight.h"
#include<string>
using namespace std;

class CargoFlightRepository : public Repository<CargoFlight>
{
protected:
	string GetFileName() { return "cargo_flights.txt"; }
	string GetTitle() { return "Cargo flights:"; }

	void LoadFlightsFromFile() override
	{
		string line;
		ifstream MyReadFile(this->GetFileName());

		while (getline(MyReadFile, line)) {

			CargoFlight flight;
			flight.InitFromCsvString(line);

			Add(flight);
		}

		MyReadFile.close();
	}

public:
	CargoFlightRepository(int max) : Repository(max) {
		this->LoadFlightsFromFile();
	}

	~CargoFlightRepository()
	{
		WriteFlightsToFile();
	}
};
#endif // !CARGOFLIGHTREPOSITORY_H

