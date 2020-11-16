#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include "Reservation.h"

using namespace std;
class User
{
private:

	string name, email, phone, username, password;
	bool admin;
	vector<Reservation> reservations;

public:

	User(string n, string e, string p, string u, string pass, bool a);
	User(vector<string> udata,bool a);
	string getName() const;
	void setName(string n);
	string getEmail() const;
	void setEmail(string e);
	string getPhone() const;
	void setPhone(string p);
	string getUname() const;
	void setUName(string u);
	string getPassword() const;
	void setPassword(string p);
	bool getAdmin() const;
	void setAdmin(bool a);
	void newReservation(vector<string> res);
};

