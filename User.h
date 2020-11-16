#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include "Reservation.h"

using namespace std;
class User
{
private:

	string name, email, phone, userName, password;
	bool admin;
	vector<Reservation> reservations;

public:

	User(string n, string e, string p, string u, string pass, bool a);
	string getName();
	void setName(string n);
	string getEmail();
	void setEmail(string e);
	string getPhone();
	void setPhone(string p);
	string getUName();
	void setUName(string u);
	bool getAdmin();
	void setAdmin(bool a);
};

