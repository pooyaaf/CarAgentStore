
// User.cpp 
#include "User.hpp" 
#include "Car.hpp"
#include <algorithm>

User::User(const std::string &username, const std::string &password, int wallet) : username(username), password(password), wallet(wallet) {} 
 
std::string User::getUsername() const { 
return username; 
} 
 
std::string User::getPassword() const { 
return password; 
} 
 
int User::getWallet() const { 
return wallet; 
}

void User::setPassword(const std::string &password) { 
this->password = password; 
} 
 
void User::setWallet(int wallet) { 
this->wallet = wallet; 
}

std::vector<Car>& User::getOwnedCars()
{
    return ownedCars;
}

void User::addOwnedCar(Car &car)
{
    ownedCars.push_back(car);
}

bool User::checkPassword(const std::string &password) const{
   return this->password == password;
}