#include <iostream>
#include <stdio.h>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
using namespace std;



template <class T>
class Queue {
private:
	int front;
	int rear;
	int counter;
	int maxSize;
	T* values;

public:
	Queue(int size) {
		values = new T[size];
		maxSize = size;
		front = 0;
		rear = -1;
		counter = 0;
	}
	T* GetValues() {
		return values;
	}
	bool IsEmpty() {
		return counter == 0;
	}
	bool IsFull() {
		return counter == maxSize;
	}
	bool Enqueue(T x) {
		if (IsFull()) {
			cout << "Error: the queue is full." << endl;
			return false;
		}
		else {
			// calculate the new rear position (circular)
			rear = (rear + 1) % maxSize;
			// insert new item		
			values[rear] = x;
			// update counter
			counter++;
			return true; 
		}
	}
	bool Dequeue(T& x) {
		if (IsEmpty()) {
			cout << "Error: the queue is empty." << endl;
			return false;
		}
		else {
			// retrieve the front item
			x = values[front];
			// move front 
			front = (front + 1) % maxSize;
			// update counter
			counter--;
			return true;
		}
	}
};
//sort by appoinment
void bubbleSort(customer cstmrs[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cstmrs[j] > cstmrs[j + 1]) {
				customer temp;
				temp = cstmrs[j + 1];
				cstmrs[j + 1] = cstmrs[j];
				cstmrs[j] = temp;
			}
		}
	}
}
bool takeappointment(Queue <mechanic> &a,int size, person:: Appointment appt,int &ID) {
	int count = size;
	while (size > 0) {
		mechanic x;
		a.Dequeue(x);
		if (x.TakeAptmnt(appt)) {
			a.Enqueue(x);
			ID = x.GetID();
			return true;
		}
		else {
			a.Enqueue(x);
			size--;
		}
	}
	return false;
}
string getName(Queue <mechanic> a, int size, int ID) {
	string Name="error";
	for (int i = 0; i < size; i++) {
		mechanic x;
		a.Dequeue(x);
		if (ID == x.GetID()) {
			Name = x.GetName();
		}
		a.Enqueue(x);
	}
	return Name;
}

int main() {
	const int size = 3; 
	const int size1 = 4;
	//mechanic* mechanics = new mechanic[size];
	//inputing mechanics
	mechanic mechncs[size];
	Queue <mechanic> mechnc(size);
	for (int i = 0; i < size;i++) {
		string x; int y, z;
		cout << "Mechanic Name: \n";
			cin >> x;
			cout << "ID: \n";
			cin >> y;
			cout << "Age: \n";
			cin>>z;
			mechncs[i].SetName(x);
			mechncs[i].SetID(y);
			mechncs[i].SetAge(z);
			mechnc.Enqueue(mechncs[i]);	
	}
	//inputing customers
	customer cstmrs[size1];
	for (int i = 0; i < size1; i++) {
		string x; int y, z;
		int ID=0;
		person::Appointment appt;
			cout << "custtomer Name: \n";
			cin >> x;
			cout << "ID: \n";
			cin >> y;
			cout << "Age: \n";
			cin >> z;
			cout << "hour: \n";
			cin >> appt.hours;
			cout << "mins: \n";
			cin >> appt.mins;
			if (!takeappointment(mechnc, size, appt, ID)) {
				cout << "appointment unavailavle, try again \n";
				cout << "hour: \n";
				cin >> appt.hours;
				cout << "mins: \n";
				cin >> appt.mins;
			}
			else
				cstmrs[i].SetMechanicID(ID);
		cstmrs[i].SetName(x);
		cstmrs[i].SetID(y);
		cstmrs[i].SetAge(z);
		cstmrs[i].Setaptmnt(appt);
	}
	
	Queue <customer> AppointOrder(size1);
	bubbleSort(cstmrs, size1);
	for (int i = 0; i < size1; i++) {
		AppointOrder.Enqueue(cstmrs[i]);
		cout << cstmrs[i].GetName() << " is assigned to " << getName(mechnc, size, cstmrs[i].GetMechanicID()) << " at " << cstmrs[i].gethours() << " : " << cstmrs[i].getmins() << endl;
	}

	return 0;
}