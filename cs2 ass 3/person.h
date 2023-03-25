#pragma once
#include <string>
using namespace std;

class person {
private:
	std::string Name;
	int ID;
	int Age;

public:
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

	person();
	person(string x, int y, int z);

	//setters getters
	void SetName(string x);
	void SetID(int x);
	void SetAge(int x);
	string GetName();
	int GetID();
	int GetAge();
	string GetName(int ID);

	virtual void Display() = 0;
};
