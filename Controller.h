#pragma once
#include "Reservation.h"
#include "User.h"
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Controller
{
private:
	map<string, string> timetable;
	vector<User> users;
	User* currentUser;

public:
	Controller();
	void readMap();
	vector<string> split(const string& str, const string& delim);
	void list();
	void newUser();
	void login();
	void listUsers();
	string encryptDecrypt(string toEncrypt);
};

