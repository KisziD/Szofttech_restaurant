#include "User.h"

User::User(string n, string e, string p, string u, string pass, bool a) :
	name(n),
	email(e),
	phone(p),
	username(u),
	password(pass),
	admin(a)
{
}

User::User(vector<string> udata, bool a):
	name(udata[0]),
	email(udata[1]),
	phone(udata[2]),
	username(udata[3]),
	password(udata[4]),
	admin(a)
{
}

string User::getName() const
{
	return name;
}

void User::setName(string n)
{
	name = n;
}

string User::getEmail() const
{
	return email;
}

void User::setEmail(string e)
{
	email = e;
}

string User::getPhone() const
{
	return phone;
}

void User::setPhone(string p)
{
	phone = p;
}

string User::getUname() const
{
	return username;
}

void User::setUName(string u)
{
	username = u;
}

string User::getPassword() const
{
	return password;
}

void User::setPassword(string p)
{
	password = p;
}

bool User::getAdmin() const
{
	return admin;
}

void User::setAdmin(bool a)
{
	admin = a;
}

void User::newReservation(vector<string> res)
{
}
