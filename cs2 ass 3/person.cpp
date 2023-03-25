#pragma once
#include <iostream>
#include <stdio.h>
#include "person.h"
using namespace std;


	struct Appointment {
		int hours;
		int mins;

		bool operator<(Appointment aptmnt) {
			if (this->hours < aptmnt.hours) {
				return true;
			}
			else if (this->hours == aptmnt.hours) {
				if (this->mins < aptmnt.mins) {
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		bool operator>(Appointment aptmnt) {
			if (this->hours > aptmnt.hours) {
				return true;
			}
			else if (this->hours == aptmnt.hours) {
				if (this->mins > aptmnt.mins) {
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		bool operator==(Appointment aptmnt) {
			if ((this->hours == aptmnt.hours) && (this->mins == aptmnt.mins))
				return true;
			else
				return false;
		}
		void operator=(Appointment c) {
			mins = c.mins;
			hours = c.hours;
		}
	};

	person ::person() {
		Name = "";
		ID = -1;
		Age = -1;
	}
	person::person(string x, int y, int z) {
		Name = x;
		ID = y;
		Age = z;
	}
	//setters getters
	void person::SetName(string x) {
		Name = x;
	}
	void person::SetID(int x) {
		ID = x;
	}
	void person::SetAge(int x) {
		Age = x;
	}
	string person::GetName() {
		return Name;
	}
	int person::GetID() {
		return ID;
	}
	int person::GetAge() {
		return Age;
	}
	string person::GetName(int ID) {
		return Name;
	}


