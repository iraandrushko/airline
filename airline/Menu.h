#ifndef MENU_H
#define MENU_H

#include"Command.h"

class Menu
{
public:
	void ShowMenu();
private:
	Command command;
	void showMainMenu();
	void addPassengerFlightAction();
	void removePassangerFlightAction();
	
	void addCargoFlightAction();
	void removeCargoFlightAction();
	
	void safeHandleUserInput(char userInput);
};

#endif // !MENU_H