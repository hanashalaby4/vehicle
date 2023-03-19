
#ifndef _VEHICLE_
#define _VEHICLE_


#include <iostream>
using namespace std;


class FreightContainer
{
private: 
	int cargo_id;
	double weight;
public:
	FreightContainer(int id=0, int w=0)
	{
		cargo_id = id;
		weight = w;
	}
	void setId(int id)
	{
		cargo_id = id;
	}
	void setWeight(double w)
	{
		if (w == 0)
		{
			cout << "error, weight cannot be 0";
			exit(1);
		}
		weight = w;
	}
	int getId() const
	{
		return cargo_id;
	}
	double getWeight() const
	{
		return weight;
	}
	
	

};



class TransportVehicle
{
protected:
	int regisnum, age;
	double maxC;
	FreightContainer** container;
	int numContainer;
	string type;
public:

	TransportVehicle(int r, int a, double mC, int numC) :regisnum(r), age(a), maxC(mC), numContainer(numC)
	{
		type = "Vehicle";
		container = new FreightContainer * [numContainer];
		for (int i = 0; i < numContainer; i++)
		{
			container[i] = new FreightContainer;
		}
	}
	~TransportVehicle()
	{
		for (int i = 0; i < numContainer; i++)
		{
			delete container[i];
		}
		delete[]container;
	}

	int getID()
	{
		return regisnum;
	}
	
	virtual string getType()
	{
		return type;
	}
	virtual bool AddContainer() 
	{
		double W;
		int tempID;
		double new_max;
		
		for (int i = 0; i < numContainer; i++) 
		{
			do {
				cout << "Please enter the weight and ID of the container \n";
				cin >> W >> tempID;
				new_max = maxC - W;
				if (new_max<=0)
				{
					cout << "You have reached the maximum capacity available for " << getType() << " " << getID() << endl;
					return false;
				}
				else
				{

					(*(*(container + i))).setWeight(W);
					(*(*(container + i))).setId(tempID);
					cout << "A new container of weight " << (*(*(container + i))).getWeight()
						<< " and ID " << (*(*(container + i))).getId()
						<< " has been added to the " << getType() << " with registration ID: " << getID() << endl;

					cout << "The " << getType() << "'s current capacity is: " << new_max << endl;


				}
			} while (new_max > 0);
		}
		
	}
};



class Truck : public TransportVehicle
{
private:
	double kilos;
public:
	Truck(int r, int a, double mC, int numC, double k) :TransportVehicle(r, a, mC, numC)
	{
		type = "Truck";
		kilos = k;
		cout << "this truck has traveled " << kilos << " kilometers" << endl;
	}
	void setKilos(double k)
	{
		kilos = k;
	}
	double getKilos() const
	{
		return kilos;
	}
	string getType()
	{
		return type;
	}
	
};


class Plane : public TransportVehicle
{
private:
	double hours;
public:
	Plane(int r, int a, double mC,int numC, double h) :TransportVehicle(r, a, mC, numC)
	{
		hours = h;
		type = "Plane";
		cout << "this plane has flown for " << hours << " hours" << endl;
	}
	void setHours(int h)
	{
		hours = h;
	}
	double getHours() const
	{
		return hours;
	}
	string getType() const
	{
		return type;
	}
};
#endif _VEHICLE_