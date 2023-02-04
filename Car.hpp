
#include <string> 
#include "User.hpp"

class Car { 
  private: 
    std::string model; 
    int year; 
    float price; 
    int count; 
 
  public: 
    Car(const std::string &model, int year, float price, int count); 
    std::string getModel() const; 
    int getYear() const; 
    float getPrice() const; 
    int getCount() const; 
    void setModel(const std::string &model); 
    void setYear(int year); 
    void setPrice(float price); 
    void setCount(int count); 
    int getNumAvailable();
};
