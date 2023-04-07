
// CarAgency.hpp
#ifndef CarAgency_HPP
#define CarAgency_HPP

#include <iostream> 
#include <vector> 
#include <fstream> 
#include <json/json.h> 
// #include "Car.hpp" 
#include "User.hpp" 
#include "Car.hpp"

class CarAgency { 
  private: 
    std::vector<Car> cars; 
    std::vector<User> users; 
 
  public: 
    CarAgency(); 
    void addCar(const Car &car); 
    void addUser(const User &user); 
    std::string showCars() const;
    User& findUser(const std::string &username); 
    bool checkUserExists(const std::string &username) const; 
    bool checkCarExists(const std::string &model) const; 
    Car& findCar(const std::string &model); 
    bool buyCar(User &user, const std::string &model,const std::string &filename1,const std::string &filename2);    void addCarsFromFile(const std::string &fileName); 
    void addUsersFromFile(const std::string &fileName); 
    void writeUsersToFile(std::string filename);
    double getUserWallet(const std::string& filename, const std::string& userName);
    void updatePurchasedCar(const std::string &filename, std::string carModel, const std::string &userName) ;
};
#endif