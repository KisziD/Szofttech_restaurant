#include "Controller.h"
#include "Reservation.h"
#include "User.h"

int main() {
	Controller con;
	con.newUser();
	con.listUsers();

	return 0;

}