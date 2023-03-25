#pragma once
#include "person.h"

class customer :public person {
private:
	int MechanicID;
	Appointment aptmnt;

public:
	customer();
	customer(std::string x, int y, int z);

	//setters and getters
	void SetMechanicID(int x);
	void Setaptmnt(Appointment x);
	int GetMechanicID();
	Appointment GetAppointment();
	void sethours(int x);
	void setmins(int x);
	int gethours();
	int getmins();
	//display everything about the customer
	void Display();

	//operators that take customers not appointments
	bool operator<(customer c);
	bool operator>(customer c);
	bool operator==(customer c);
	void operator=(customer c);
};

