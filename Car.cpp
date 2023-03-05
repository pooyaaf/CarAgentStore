
#include "Car.hpp"

Car::Car(const std::string &model, int year, float price, int count, const std::vector<std::string> &ownedCars)
    : model(model), year(year), price(price), count(count), ownedCars(ownedCars) {}

std::string Car::getModel() const
{
  return model;
}

int Car::getYear() const
{
  return year;
}

float Car::getPrice() const
{
  return price;
}

int Car::getCount() const
{
  return count;
}

const std::vector<std::string> &Car::getOwnedCars() const
{
  return ownedCars;
}

void Car::setModel(const std::string &model)
{
  this->model = model;
}

void Car::setYear(int year)
{
  this->year = year;
}

void Car::setPrice(float price)
{
  this->price = price;
}

void Car::setCount(int count)
{
  this->count = count;
}
int Car::getNumAvailable()
{
  return count;
}