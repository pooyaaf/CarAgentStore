// Car.hpp
#ifndef CAR_HPP
#define CAR_HPP
#include <string>
#include <json/json.h>
using namespace std;
class Car
{
private:
  std::string model;
  int year;
  float price;
  int count;
  bool available;

public:
  Car(const Json::Value &carJson);
  std::string getModel() const;
  int getYear() const;
  float getPrice() const;
  int getCount() const;
  void setModel(const std::string &model);
  void setYear(int year);
  void setPrice(float price);
  void setCount(int count);
  void setAvailability(bool available);
  int getNumAvailable();
};
#endif