#include "User.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <json/json.h>

User::User(const Json::Value &userData) {
    this->username = userData["username"].asString();
    this->password = userData["password"].asString();
    this->wallet = userData["wallet"].asInt();

    Json::Value carModels = userData["cars"];
    for (int i = 0; i < carModels.size(); ++i) {
        this->purchasedCars.push_back(carModels[i].asString());
    }
}

std::string User::getUsername() const {
    return this->username;
}

std::string User::getPassword() const {
    return this->password;
}

int User::getWallet() const {
    return this->wallet;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}

void User::setWallet(int wallet) {
    this->wallet = wallet;
}
std::vector<Car> &User::getOwnedCars() {
    return this->ownedCars;
}
const std::vector<Car>& User::getCars() const {
    return ownedCars;
}

void User::addOwnedCar(Car &car) {
    this->ownedCars.push_back(car);
}


void User::showOwnedCars() const {
    if (this->ownedCars.empty()) {
        std::cout << "You don't own any cars yet." << std::endl;
    } else {
        std::cout << "Your owned cars:" << std::endl;
        for (int i = 0; i < this->ownedCars.size(); ++i) {
            std::cout << "- " << this->ownedCars[i].getModel() << std::endl;
        }
    }
}

void User::addPurchasedCars(std::string model) {
    this->purchasedCars.push_back(model);
}

bool User::checkPassword(const std::string &password) const {
    return this->password == password;
}

void User::writePurchasedCarsToFile(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        Json::Value root;
        Json::Value carModels(Json::arrayValue);
        for (int i = 0; i < this->purchasedCars.size(); ++i) {
            carModels.append(this->purchasedCars[i]);
        }
        root["cars"] = carModels;
        file << root;
        file.close();
        std::cout << "Purchased cars saved to file." << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

void User::readPurchasedCarsFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        Json::Value root;
        file >> root;
        Json::Value carModels = root["cars"];
        for (int i = 0; i < carModels.size(); ++i) {
            this->purchasedCars.push_back(carModels[i].asString());
        }
        file.close();
        std::cout << "Purchased cars loaded from file." << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}
