
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

void CarAgency::loadCars(const std::string &filename)
{
  std::ifstream file(filename);
  Json::Value root;
  file >> root;

  for (const auto &carJson : root)
  {
    Car car(carJson);
    addCar(car);
  }
}   

void CarAgency::showCars() const
{
  for (const auto &car : cars)
  {
    std::cout << "Model: " << car.getModel()
              << ", Year: " << car.getYear()
              << ", Price: " << car.getPrice()
              << ", Count: " << car.getCount()
              << std::endl;
  }
}

User &CarAgency::findUser(const std::string &username)
{
  for (auto &user : users)
  {
    if (user.getUsername() == username)
    {
      return user;
    }
  }
  throw std::runtime_error("User not found");
}

bool CarAgency::checkUserExists(const std::string &username) const
{
  for (const auto &user : users)
  {
    if (user.getUsername() == username)
    {
      return true;
    }
  }
  return false;
}

bool CarAgency::checkCarExists(const std::string &model) const
{
  for (const auto &car : cars)
  {
    if (car.getModel() == model)
    {
      return true;
    }
  }
  return false;
}

Car &CarAgency::findCar(const std::string &model)
{
  for (auto &car : cars)
  {
    if (car.getModel() == model)
    {
      return car;
    }
  }
  throw std::runtime_error("Car not found");
}

bool CarAgency::buyCar(User &user, const std::string &model)
{
  Car &car = findCar(model);

  if (car.getCount() == 0)
  {
    std::cout << "Car not available" << std::endl;
    return false;
  }

  int carPrice = car.getPrice();
  int userWallet = user.getWallet();

  if (userWallet < carPrice)
  {
    std::cout << "Not enough money" << std::endl;
    return false;
  }

  user.setWallet(userWallet - carPrice);
  car.setCount(car.getCount() - 1);

  user.addPurchasedCars(car.getModel());
  user.addOwnedCar(car);

  std::cout << "Car purchased successfully" << std::endl;
  return true;
}

void CarAgency::addCarsFromFile(const std::string &fileName)
{
  std::ifstream file(fileName);
  Json::Value root;
  file >> root;

  for (const auto &key : root.getMemberNames())
  {
    Car car(root[key]);
    addCar(car);
  }
}

void CarAgency::addUsersFromFile(const std::string &fileName)
{
  std::ifstream file(fileName);
  Json::Value root;
  file >> root;

  for (const auto &key : root.getMemberNames())
  {
    User user(root[key]);
    addUser(user);
  }
}

void CarAgency::writeCarsToFile(std::string filename)
{
    Json::Value root;
    Json::Value carsJson;
    for (const Car& car : cars)
    {
        Json::Value carJson;
        carJson["model"] = car.getModel();
        carJson["year"] = car.getYear();
        carJson["price"] = car.getPrice();
        carJson["count"] = car.getCount();
        carsJson[car.getModel()] = carJson;
    }
    root["cars"] = carsJson;

    std::ofstream file(filename);
    file << root;
    file.close();
}

void CarAgency::writeUsersToFile(std::string filename)
{
    Json::Value root;
    Json::Value usersJson;
    for (const User& user : users)
    {
        Json::Value userJson;
        userJson["username"] = user.getUsername();
        userJson["password"] = user.getPassword();
        userJson["wallet"] = user.getWallet();

        std::vector<Car> ownedCars = user.getCars();
        Json::Value ownedCarsJson;
        for (const Car& car : ownedCars)
        {
            ownedCarsJson.append(car.getModel());
        }
        userJson["cars"] = ownedCarsJson;

        usersJson[user.getUsername()] = userJson;
    }
    root["users"] = usersJson;

    std::ofstream file(filename);
    file << root;
    file.close();
}
void CarAgency::updatePurchasedCar(const std::string &filename, std::string carModel, const std::string &userName)
{
    User& user = findUser(userName);
    Car& car = findCar(carModel);
    if (user.getWallet() >= car.getPrice() && car.getNumAvailable() > 0)
    {
        user.setWallet(user.getWallet() - car.getPrice());
        user.addPurchasedCars(carModel);
        car.setCount(car.getCount() - 1);
        car.setAvailability(car.getCount() > 0);

        writeCarsToFile(filename);
        user.writePurchasedCarsToFile(filename);
    }
}
