
// User.cpp
#include "User.hpp"
#include "Car.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "json/json.h"

using namespace std;

User::User(const std::string &username, const std::string &password, int wallet) : username(username), password(password), wallet(wallet) {}

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}

int User::getWallet() const
{
    return wallet;
}

void User::setPassword(const std::string &password)
{
    this->password = password;
}

void User::setWallet(int wallet)
{
    this->wallet = wallet;
}

std::vector<Car> &User::getOwnedCars()
{
    return ownedCars;
}

void User::addOwnedCar(Car &car)
{
    ownedCars.push_back(car);
}
void User::showOwnedCars() const{
    std::cout << "Owned cars for " << this->username<<":\n";
    for(const auto &carModel : purchasedCars){
        std::cout<<"- "<< carModel<<"\n";
    }
    std::cout<<"\n";

}

void User::addPurchasedCars(std::string model)
{
    purchasedCars.push_back(model);
}

bool User::checkPassword(const std::string &password) const
{
    return this->password == password;
}
void User::writePurchasedCarsToFile(std::string filename)
{
    Json::Value userData;
    userData["username"] = username;
    userData["password"] = password;
    userData["wallet"] = wallet;
    Json::Value purchasedCarModels(Json::arrayValue);
    for (auto car : purchasedCars)
    {
        purchasedCarModels.append(car);
    }
    userData["purchasedCars"] = purchasedCarModels;
    //
    std::ofstream file(filename, std::ios::app);
    file << userData;
    file.close();
}
void User::readPurchasedCarsFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        Json::Value data;
        file >> data;

        for (auto &userData : data["users"])
        {
            if (userData["username"] == this->username)
            {
                for (auto &carModel : userData["purchasedCars"])
                {
                    this->purchasedCars.push_back(carModel.asString());
                }
                break;
            }
        }
    }
}