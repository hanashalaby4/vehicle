#include <iostream>
using namespace std;
#include "vehicle.h"

void setPlane(int& reg, int& age, double& maxCap, int &numOfC, double &hrs);
void setTruck(int& reg, int& age, double& maxCap, int& numOfC, double& KM);

int main()
{
	bool y;
	int registration, age, num;
	double maximumCapacity, kilometers, hours_flown;
	string vehicle;
	cout << "Please enter the type of vehicle for transportation \n"
		 << "The two choices are: Plane or Truck\n";

	cin >> vehicle;

	if (vehicle == "Plane" || vehicle=="plane")
	{
		setPlane(registration, age, maximumCapacity, num, hours_flown);

		Plane p1(registration, age, maximumCapacity, num, hours_flown);

		y=p1.AddContainer();
		cout << y;
	}

	if (vehicle == "Truck" || vehicle == "truck")
	{
		setTruck(registration, age, maximumCapacity, num, kilometers);

		Truck t1(registration, age, maximumCapacity, num, kilometers);
		 
		y=t1.AddContainer();
		cout << y;
	}
	
	

	return 0;
}
void setPlane(int& reg, int& age, double& maxCap, int& numOfC, double& hrs)
{
	cout << "\n Please enter the plane's registration number \n";
	cin >> reg;

	cout << " Please enter the plane's age \n";
	cin >> age;

	cout << " Please enter the plane's maximum capacity \n";
	cin >> maxCap;

	cout << " Please enter the number of containers \n";
	cin >> numOfC;

	cout << " Please enter the number of hours the plane has flown \n";
	cin >> hrs;

}
void setTruck(int& reg, int& age, double& maxCap, int& numOfC, double& KM)
{
	cout << "\n Please enter the truck's registration number \n";
	cin >> reg;

	cout << " Please enter the truck's age \n";
	cin >> age;

	cout << " Please enter the truck's maximum capacity \n";
	cin >> maxCap;

	cout << " Please enter the number of containers \n";
	cin >> numOfC;

	cout << " Please enter the number of kilometers the truck has traveled \n";
	cin >> KM;

}
