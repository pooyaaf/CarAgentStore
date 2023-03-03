
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "json/json.h"
#include "CarAgency.hpp"
#include "Car.hpp"
#include "User.hpp"

using namespace std;

CarAgency::CarAgency() {}

void CarAgency::addCar(const Car &car)
{
    cars.push_back(car);
}

void CarAgency::addUser(const User &user)
{
    users.push_back(user);
}

void CarAgency::showCars() const
{
    std::cout << "Available cars: " << std::endl;
    for (const auto &car : cars)
    {
        if (car.getCount() > 0)
        {
            std::cout << car.getModel() << "\t" << car.getCount() << "\t" << car.getPrice() << std::endl;
        }
    }
}

User& CarAgency::findUser(const std::string &username)
{
    auto user = std::find_if(users.begin(), users.end(),
        [&username](const User& user) { return user.getUsername() == username; });
    if (user == users.end())
    {
        throw std::runtime_error("Error: User not found");
    }
    return *user;
}

bool CarAgency::checkUserExists(const std::string &username) const
{
    auto user = std::find_if(users.begin(), users.end(),
        [&username](const User& user) { return user.getUsername() == username; });
    return user != users.end();
}

bool CarAgency::checkCarExists(const std::string &model) const
{
    auto car = std::find_if(cars.begin(), cars.end(),
        [&model](const Car& car) { return car.getModel() == model; });
    return car != cars.end();
}

Car& CarAgency::findCar(const std::string &model)
{
    auto car = std::find_if(cars.begin(), cars.end(),
        [&model](const Car& car) { return car.getModel() == model; });
    if (car == cars.end())
    {
        throw std::runtime_error("Error: Car not found");
    }
    return *car;
}

bool CarAgency::buyCar(User &user, const std::string &model)
{
    if (!checkCarExists(model))
    {
        return false;
    }
    Car &car = findCar(model);
    if (car.getCount() <= 0 || user.getWallet() < car.getPrice())
    {
        return false;
    }
    user.setWallet(user.getWallet() - car.getPrice());
    car.setCount(car.getCount() - 1);
    user.addOwnedCar(car);
    user.addPurchasedCars(car.getModel());
    return true;
}

void CarAgency::addCarsFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file\n";
        return;
    }
    Json::Value root;
    Json::Reader reader;

    if (!reader.parse(file, root))
    {
        std::cout << "Error: Unable to parse JSON\n";
        return;
    }
    for (const auto &car : root)
    {
        Car newCar(car["model"].asString(),car["year"].asInt(), car["price"].asFloat(), car["count"].asInt());
        addCar(newCar);
    }
}

void CarAgency::addUsersFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file\n";
        return;
    }

    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(file, root)) {
        std::cout << "Error: Unable to parse JSON\n";
        return;
    }

    for (const auto &user : root) {
        addUser(User(user["username"].asString(), user["password"].asString(), user["wallet"].asInt()));
    }
}

void CarAgency::writeUsersToFile(std::string filename) {
    Json::Value data(Json::objectValue);
    for (const auto &user : users) {
        Json::Value userData;
        userData["username"] = user.getUsername();
        userData["password"] = user.getPassword();
        userData["wallet"] = user.getWallet();

        Json::Value ownedCarModels(Json::arrayValue);
        for (auto car : user.getOwnedCars()) {
            ownedCarModels.append(car.getModel());
        }
        userData["cars"] = ownedCarModels;

        data[user.getUsername()] = userData;
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    } else {
        std::cout << "Error: Unable to open file\n";
    }
}

void CarAgency::updatePurchasedCar(const std::string &filename, std::string carModel, const std::string &userName) {
    Json::Value data;
    std::ifstream file(filename);

    if (file.is_open()) {
        file >> data;
        file.close();
    } else {
        std::cout << "Error: Unable to open file\n";
        return;
    }

    Json::Value userData = data[userName];
    if (userData.isNull()) {
        std::cout << "Error: User not found\n";
        return;
    }

    userData["cars"].append(carModel);
    data[userName] = userData;

    std::ofstream outfile(filename);
    outfile << data;
    outfile.close();
}
