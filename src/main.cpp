#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "json/json.h"
#include "../include/CarAgency.hpp"
#include "../include/Car.hpp"
#include "../include/User.hpp"

using namespace std;

int main()
{

    CarAgency agency;
    string pathOfCarsJSON = "../car.json";
    agency.addCarsFromFile(pathOfCarsJSON);
    string pathOfUsersJSON = "../user.json";
    agency.addUsersFromFile(pathOfUsersJSON);

    int userChoice = 0;
    User *loggedInUser = nullptr;
    while (userChoice != 2)
    {
        cout << "Car Agency Program" << endl;
        cout << "1. Login" << endl;
        cout << "2. Quit" << endl;
        if (loggedInUser)
        {
            cout << "3. Purchase a Car" << endl;
            cout << "4. Show Wallet" << endl;
            cout << "5. Show Purchased Cars" << endl;
        }
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
        case 1:
        {
            string username, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            if (agency.checkUserExists(username))
            {
                User &user = agency.findUser(username);
                if (user.checkPassword(password))
                {
                    loggedInUser = &user;
                    cout << "Login successful" << endl;
                }
                else
                {
                    cout << "Incorrect password" << endl;
                }
            }
            else
            {
                cout << "User does not exist" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Exiting program" << endl;
            break;
        }
        case 3:
        {
            if (loggedInUser)
            {
                cout << "Available cars:" << endl;
                agency.showCars();
                cout << "Enter the model of the car you want to buy: ";
                string model;
                getline(cin, model);
                if (agency.checkCarExists(model))
                {
                    Car &car = agency.findCar(model);
                    if (loggedInUser->getWallet() >= car.getPrice())
                    {
                        if (agency.buyCar(*loggedInUser, model, pathOfUsersJSON, pathOfCarsJSON))
                        {
                            cout << "Car purchased successfully" << endl;
                        }
                        else
                        {
                            cout << "Error purchasing car" << endl;
                        }
                    }
                    else
                    {
                        cout << "You do not have enough money" << endl;
                    }
                }
                else
                {
                    cout << "Car does not exist" << endl;
                }
            }
            else
            {
                cout << "You must log in first" << endl;
            }
            break;
        }
        case 4:
        {
            cout << loggedInUser->getWallet() << endl;
            break;
        }
        case 5:
        {
            loggedInUser->showPurchasedCars();
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }

    return 0;
}
