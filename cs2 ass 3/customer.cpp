
#pragma once
#include <iostream>
#include "customer.h"
using namespace std;

customer::customer() {
		aptmnt.hours = 0;
		aptmnt.mins = 0;
		MechanicID = -1;
	}
customer::customer(string x, int y, int z) : person(x, y, z) {
		aptmnt.hours = 0;
		aptmnt.mins = 0;
		MechanicID = -1;
	}
	//setters and getters
	void  customer::SetMechanicID(int x) {
		MechanicID = x;
	}
	void  customer::Setaptmnt(Appointment x) {
		aptmnt = x;
	}
	int customer::GetMechanicID() {
		return MechanicID;
	}
	person::Appointment customer::GetAppointment() {
		return aptmnt;
	}
	void customer::sethours(int x) {
		aptmnt.hours = x;
	}
	void  customer::setmins(int x) {
		aptmnt.mins = x;
	}
	//int  customer ::gethours() {
	//	return aptmnt.hours;
	//}
	int  customer::gethours() {
		return GetAppointment().hours;
	}
	//int customer :: getmins() {
	//	return aptmnt.mins;
	//}
	int  customer::getmins() {
		return GetAppointment().mins;
	}
	//display everything about the customer
	void customer::Display() {
		cout << "mechanic ID: " << MechanicID << endl;
		cout << "Appointment: " << aptmnt.hours << " : " << aptmnt.mins << endl;
		cout << "Name: " << GetName() << endl;
		cout << "ID: " << GetID() << endl;
		cout << "Age: " << GetAge() << endl;
	}
	//operators that take customers not appointments
	bool  customer ::operator<(customer c) {
		if (this->aptmnt < c.aptmnt)
			return true;
		else
			return false;
	}
	bool customer :: operator>(customer c) {
		if (this->aptmnt > c.aptmnt)
			return true;
		else
			return false;
	}
	bool  customer ::operator==(customer c) {
		if (this->aptmnt == c.aptmnt)
			return true;
		else
			return false;
	}
	void  customer ::operator=(customer c) {
		this->SetName(c.GetName());
		this->SetID(c.GetID());
		this->SetAge(c.GetAge());
		aptmnt = c.aptmnt;
		MechanicID = c.MechanicID;
	}
