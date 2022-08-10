#pragma once
#include "Klient.h"

class menu
{
protected:
	vector<string> points;
public:
	int meny();
	void stmenu();
	void adminmenu();
	void Klientmenu();
	void trainermenu();
	void redmenu();

};