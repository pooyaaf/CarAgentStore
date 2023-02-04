
#include <iostream>
#include <fstream> 
#include <vector>
#include "json/json.h"
#include "CarAgency.hpp"
#include "Car.hpp"
#include "User.hpp"

CarAgency::CarAgency(){}

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
    for (int i = 0; i < cars.size(); i++)
    {
        std::cout << i + 1 << ". " << cars[i].getModel() << " (" << cars[i].getCount() << " available)" << std::endl;
    }
}

User &CarAgency::findUser(const std::string &username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == username)
        {
            return users[i];
        }
    }
    std::cout << "User not found!" << std::endl;
    exit(1);
}

bool CarAgency::checkUserExists(const std::string &username) const
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == username)
        {
            return true;
        }
    }
    return false;
}

bool CarAgency::checkCarExists(const std::string &model) const
{
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].getModel() == model)
        {
            return true;
        }
    }
    return false;
}

Car &CarAgency::findCar(const std::string &model)
{
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i].getModel() == model)
        {
            return cars[i];
        }
    }
    std::cout << "Car not found!" << std::endl;
    exit(1);
}

bool CarAgency::buyCar(User &user, const std::string &model)
{
    Car &car = findCar(model);
    if (!checkCarExists(model))
    {
        std::cout << "Error: Car model not found\n";
        return false;
    }
    if (user.getWallet() < car.getPrice())
    {
        std::cout << "Error: Not enough balance\n";
        return false;
    }
    user.setWallet(user.getWallet() - car.getPrice());
    car.setCount(car.getCount() - 1);
    user.addOwnedCar(car);
    std::cout << "Car purchased successfully\n";
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
        addCar(Car(car["model"].asString(), car["year"].asInt(),
                   car["price"].asInt(), car["count"].asInt()));
    }
}

void CarAgency::addUsersFromFile(const std::string &fileName)
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
    for (const auto &user : root)
    {
        addUser(User(user["username"].asString(), user["password"].asString(), user["wallet"].asInt()));
    }
}
