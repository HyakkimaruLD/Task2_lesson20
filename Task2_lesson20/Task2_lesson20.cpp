

#include <iostream>
#include <string>
#include "Airplane.h"
using namespace std;

int main() {
    Airplane plane("ABC123", "New York", "Los Angeles", "Boeing 737", 150);
    cout << "==============================================" << endl;
    plane.display();


    cout << "-------------------------------------------"<< endl;

    plane.sellTicket("John Doe");
    plane.sellTicket("Jane Smith");

    plane.display();
    cout << "-------------------------------------------" << endl;
    plane.returnTicket("John Doe");


    plane.display();
    cout << "==============================================" << endl;
    return 0;
}