#pragma once
#include <iostream>
#include "mechanic.h"
using namespace std;



	mechanic:: mechanic() {
		counter = 0;
		appointments = NULL;
	}
	mechanic::mechanic(string x, int y, int z) : person(x, y, z) {
		counter = 0;
		appointments = NULL;
	}
	int mechanic::getCounter() {
		return counter;
	}
	void mechanic::setCounter(int x) {
		counter = x;
	}
	//checking availability 
	bool mechanic::isAvailable(Appointment appt) {
		for (int i = 0; i < counter; i++) {
			if (appt == appointments[i])
				return false;
		}
		return true;
	}
	//mechanic appointments
	void mechanic::Display() {
		cout << "Number of appointments: " << counter << endl;
		for (int i = 0; i < counter; i++) {
			cout << "Appointment " << counter << ": " << appointments[i].hours << " : " << appointments[i].mins << endl;
		}
	}
	//assuming that the user will only input from 1-24hrs and from 1-60mins
	bool mechanic::TakeAptmnt(Appointment aptmnt) {
		if (this->isAvailable(aptmnt)) {
			counter++;
			Appointment* newAppointments = new Appointment[counter];
			for (int i = 0; i < counter - 1; i++) {
				newAppointments[i] = appointments[i];
			}
			newAppointments[counter - 1] = aptmnt;
			delete[] appointments;
			appointments = newAppointments;
			cout << "apointment set with " << GetName() << " at " << aptmnt.hours << " : " << aptmnt.mins << endl;
			return true;
		}
		return false;
	}
	void mechanic:: operator=(mechanic c) {
		this->SetName(c.GetName());
		this->SetID(c.GetID());
		this->SetAge(c.GetAge());
		this->appointments = c.appointments;
		this->counter = c.counter;
	}

