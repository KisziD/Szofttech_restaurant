#include "User.h"

User::User(string n, string e, string p, string u, string pass, bool a) :
	name(n),
	email(e),
	phone(p),
	userName(u),
	password(pass),
	admin(a)
{
}

string User::getName()
{
	return name;
}

void User::setName(string n)
{
	name = n;
}

string User::getEmail()
{
	return email;
}

void User::setEmail(string e)
{
	email = e;
}

string User::getPhone()
{
	return phone;
}

void User::setPhone(string p)
{
	phone = p;
}

string User::getUName()
{
	return userName;
}

void User::setUName(string u)
{
	userName = u;
}

bool User::getAdmin()
{
	return admin;
}

void User::setAdmin(bool a)
{
	admin = a;
}
