
// User.hpp
#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Car.hpp"

class User
{
private:
    std::string username;
    std::string password;
    int wallet;
    std::vector<Car> ownedCars;
    std::vector<std::string> purchasedCars;

public:
    User(const std::string &username, const std::string &password, int wallet);
    std::string getUsername() const;
    std::string getPassword() const;
    int getWallet() const;
    void setPassword(const std::string &password);
    void setWallet(int wallet);
    std::vector<Car> &getOwnedCars();
    void addOwnedCar(Car &car);
    void showOwnedCars() const;
    void addPurchasedCars(std::string model);
    bool checkPassword(const std::string &password) const;
    void writePurchasedCarsToFile(std::string filename);
    void readPurchasedCarsFromFile(const std::string &filename);
};

#endif

