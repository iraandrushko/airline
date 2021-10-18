#include"Menu.h"
#include"PassengerFlight.h"
#include"Error.h"
#include"Date.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::ShowMenu()
{
	char userInput;

	do {
		showMainMenu();
		
		cin >> userInput;
		safeHandleUserInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void Menu::showMainMenu()
{
	cout << "Airline!!!\nPlease select an option:\n";
	cout << "1 - Add new passenger flight;\n";
	cout << "2 - Show all passenger flights;\n";
	cout << "3 - Remove passenger flight;\n";
	cout << "4 - Show the longest by duration passenger flight; \n";
	cout << "5 - Add new cargo flight;\n";
	cout << "6 - Show all cargo flights;\n";
	cout << "7 - Remove cargo flight;\n";
	cout << "8 - Show the longest by duration cargo flight; \n";
	cout << "0 - Exit.\n";
}

void Menu::addPassengerFlightAction()
{
	PassengerFlight flight;
	cin >> flight;

	command.AddPassengerFlight(flight);

	cout << "Passenger Flight Added!!!\n";
}

void Menu::addCargoFlightAction()
{
	CargoFlight flight;
	cin >> flight;

	command.AddCargoFlight(flight);

	cout << "Cargo Flight Added!!!\n";
}

void Menu::removePassangerFlightAction()
{
	int idx;
	cout << "Type flight id: ";
	cin >> idx;

	command.RemovePassengerFlight(idx);
	cout << "Passenger Flight Removed!!!\n";
}

void Menu::removeCargoFlightAction()
{
	int idx;
	cout << "Type flight id: ";
	cin >> idx;

	command.RemoveCargoFlight(idx);
	cout << " Cargo Flight Removed!!!\n";
}

void Menu::safeHandleUserInput(char userInput)
{
	try
	{
		switch (userInput)
		{
		case '1':
			addPassengerFlightAction();
			break;
		case '2':
			command.PrintPassengerFlights();
			cout << endl;
			break;
		case '3':
			removePassangerFlightAction();
			break;
		case '4':
			command.ShowTheLongestByDurationPassengerFlight();
			break;
		case '5':
			addCargoFlightAction();
			break;
		case '6':
			command.PrintCargoFlights();
			cout << endl;
			break;
		case '7':
			removeCargoFlightAction();
			break;
		case '8':
			command.ShowTheLongestByDurationCargoFlight();
			break;
		case '0':
			break;
		default:
			cout << "Wrong command selected\n";
			break;
		}
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occurs" << endl;
	}
}