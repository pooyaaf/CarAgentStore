// Car.hpp
#ifndef CAR_HPP
#define CAR_HPP
#include <string>
#include <vector>

class Car
{
private:
  std::string model;
  int year;
  float price;
  int count;
  std::vector<std::string> ownedCars;

public:
  Car(const std::string &model, int year, float price, int count, const std::vector<std::string> &ownedCars = {});
  std::string getModel() const;
  int getYear() const;
  float getPrice() const;
  int getCount() const;
  void setModel(const std::string &model);
  void setYear(int year);
  void setPrice(float price);
  void setCount(int count);
  int getNumAvailable();
  const std::vector<std::string> &getOwnedCars() const;
};
#endif