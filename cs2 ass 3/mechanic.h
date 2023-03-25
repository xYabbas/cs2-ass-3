#pragma once
#include "person.h"
using namespace std;

class mechanic : public person {
private:
    int counter;
    Appointment* appointments;

public:
    mechanic();
    mechanic(string x, int y, int z);
    int getCounter();
    void setCounter(int x);
    bool isAvailable(Appointment appt);
    void Display();
    bool TakeAptmnt(Appointment aptmnt);
    void operator=(mechanic c);
};
