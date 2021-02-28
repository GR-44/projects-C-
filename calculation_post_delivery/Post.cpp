// calculation cost of post package delivery from three companies: "Package", "TwoDayPackage" and "OvernightPackage"

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main()
{
    Package p("Bob", "Doe", "1st Drivelane 24", "NY", "NY", "125467", "602300", 1.25, 22.35);
    cout << "First name: " << p.getFirstName() << endl;
    cout << "Last name: " << p.getLastName() << endl;
    cout << "Address: " << p.getAddress() << endl;
    cout << "City: " << p.getCity() << endl;
    cout << "State: " << p.getState() << endl;
    cout << "ZIP sender: " << p.getZipSender() << endl;
    cout << "ZIP reciever: " << p.getZipReciever() << endl;
    cout << "Price for kilogram: $" << p.getPrice() << endl;
    cout << "Package weight: " << p.getWeight() << " kg" << endl;
    cout << "Cost: $" << p.calculateCost() << endl;

    cout << endl;

    TwoDayPackage p2("Bob", "Doe", "1st Drivelane 24", "NY", "NY", "125467", "602300", 1.25, 22.35, 10.0);
    cout << "First name: " << p2.getFirstName() << endl;
    cout << "Last name: " << p2.getLastName() << endl;
    cout << "Address: " << p2.getAddress() << endl;
    cout << "City: " << p2.getCity() << endl;
    cout << "State: " << p2.getState() << endl;
    cout << "ZIP sender: " << p2.getZipSender() << endl;
    cout << "ZIP reciever: " << p2.getZipReciever() << endl;
    cout << "Price for kilogram: $" << p2.getPrice() << endl;
    cout << "Package weight : " << p2.getWeight() << " kg" << endl;
    cout << "Markup value: $" << p2.getMarkup() << endl;
    cout << "Cost: $" << p2.calculateCost() << endl;

    cout << endl;

    OvernightPackage p3("Bob", "Doe", "1st Drivelane 24", "NY", "NY", "125467", "602300", 1.25, 22.35, 10.0);
    cout << "First name: " << p3.getFirstName() << endl;
    cout << "Last name: " << p3.getLastName() << endl;
    cout << "Address: " << p3.getAddress() << endl;
    cout << "City: " << p3.getCity() << endl;
    cout << "State: " << p3.getState() << endl;
    cout << "ZIP sender: " << p3.getZipSender() << endl;
    cout << "ZIP reciever: " << p3.getZipReciever() << endl;
    cout << "Price for kilogram: $" << p3.getPrice() << endl;
    cout << "Package weight : " << p3.getWeight() << " kg" << endl;
    cout << "Markup value: $" << p3.getMarkup() << endl;
    cout << "Cost: $" << p3.calculateCost() << endl;

    cout << endl;


    return 0;
}

