#pragma once
#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string flightNumber;
    string departurePoint;
    string destination;
    string airplaneModel;
    int totalSeats;
    int availableSeats;
    string* passengerList;



public:
    Airplane(string flightNum, string departure, string dest, string model, int seats)
        : flightNumber(flightNum), departurePoint(departure), destination(dest), airplaneModel(model), totalSeats(seats), availableSeats(seats) {
        passengerList = new string[totalSeats]; 
    }

    ~Airplane() {
        delete[] passengerList; 
    }




    void display() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure Point: " << departurePoint << endl;
        cout << "Destination: " << destination << endl;
        cout << "Airplane Model: " << airplaneModel << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Passenger List: ";
        for (int i = 0; i < totalSeats; ++i) {
            if (!passengerList[i].empty()) {
                cout << passengerList[i] << ", ";
            }
        }
        cout << endl;
    }



    string getFlightNumber() { return flightNumber; }
    string getDeparturePoint() { return departurePoint; }
    string getDestination() { return destination; }
    string getAirplaneModel() { return airplaneModel; }
    int getTotalSeats() { return totalSeats; }
    int getAvailableSeats() { return availableSeats; }


    void sellTicket(string passengerName) {
        if (availableSeats > 0) {
            for (int i = 0; i < totalSeats; ++i) {
                if (passengerList[i].empty()) {
                    passengerList[i] = passengerName;
                    availableSeats--;
                    cout << "Ticket sold to " << passengerName << endl;
                    return;
                }
            }
        }
        cout << "No available seats for this flight." << endl;
    }


    void returnTicket(string passengerName) {
        for (int i = 0; i < totalSeats; ++i) {
            if (passengerList[i] == passengerName) {
                passengerList[i].clear();
                availableSeats++;
                cout << "Ticket returned by " << passengerName << endl;
                return;
            }
        }
        cout << "Passenger " << passengerName << " not found in the passenger list." << endl;
    }
};
