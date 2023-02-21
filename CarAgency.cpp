
#include <iostream>
#include <fstream>
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
    for (auto &car : cars)
    {
        if (car.getCount() > 0)
        {
            cout << car.getModel() << "\t" << car.getCount() << "\t" << car.getPrice() << endl;
        }
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
    if (car.getCount() > 0)
    {
        car.setCount(car.getCount() - 1);
        user.setWallet(user.getWallet() - car.getPrice());
        user.addPurchasedCars(car.getModel());
        std::cout << "Car purchased successfully\n";
    }

    // user.addOwnedCar(car);

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

void CarAgency::writeUsersToFile(std::string filename)
{

    for (auto user : users)
    {
        // std::cout<<user.getUsername()<<" "<<user.getWallet();
        user.writePurchasedCarsToFile(filename);
    }
}

void CarAgency::updatePurchasedCar(const std::string &filename, std::string carModel, const std::string &userName) {
    // Open the json file
    std::ifstream file(filename);
    Json::Value data;
    Json::Reader reader;

    // Parse the json data
    if (reader.parse(file, data)) {
        // Modify the json data
        for (auto &car : data["cars"]) {
            if (car["model"] == carModel) {
                car["count"] = car["count"].asInt()- 1;
                break;
            }
        }

        // for (auto &user : data["users"]) {
        //     if (user["username"] == userName) {
        //         user["purchasedCars"].append(carId);
        //         break;
        //     }
        // }
    }
    file.close();

    // Write the updated json data back to the file
    std::ofstream outputFile(filename);
    outputFile << data.toStyledString();
    outputFile.close();
}
