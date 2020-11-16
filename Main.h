#pragma once
#include "Reservation.h"
#include "User.h"
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class Main
{
private:
	static map<string, vector<bool>> timetable;

public:
	Main();
	void readMap();
	vector<string> split(const string& str, const string& delim);
};

