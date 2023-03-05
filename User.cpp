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

void User::setOwnedCars(const std::vector<Car>& cars) {
    ownedCars = cars;
}

const std::vector<Car>& User::getOwnedCars() const {
    return ownedCars;
}

void User::addOwnedCar(Car &car)
{
    ownedCars.push_back(car);
}

void User::showPurchasedCars() const
{
    std::cout << "Purchased cars for " << this->username << ":\n";
    for (const auto &carModel : purchasedCars)
    {
        std::cout << "- " << carModel << "\n";
    }
    std::cout << "\n";
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
    Json::Value fileData;
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        inputFile >> fileData;
    }

    Json::Value userData;
    userData["username"] = username;
    userData["password"] = password;
    userData["wallet"] = wallet;
    Json::Value purchasedCarModels(Json::arrayValue);
    for (auto car : purchasedCars)
    {
        purchasedCarModels.append(car);
    }
    userData["cars"] = purchasedCarModels;

    fileData[username] = userData;

    std::ofstream outputFile(filename);
    outputFile << fileData;
    outputFile.close();
}

void User::readPurchasedCarsFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        Json::Value fileData;
        file >> fileData;

        Json::Value userData = fileData[username];
        password = userData["password"].asString();
        wallet = userData["wallet"].asInt();

        Json::Value purchasedCarModels = userData["cars"];
        for (auto &carModel : purchasedCarModels)
        {
            purchasedCars.push_back(carModel.asString());
        }
    }
}
