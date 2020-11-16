#pragma once
#include "Reservation.h"
#include "User.h"
#include <map>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class Controller
{
private:
	map<string, string> timetable;

public:
	Controller();
	void readMap();
	vector<string> split(const string& str, const string& delim);
};

