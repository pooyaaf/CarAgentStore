
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "json/json.h"
// #include "CarAgency.hpp"
// #include "Car.hpp"
// #include "User.hpp"

using namespace std;

class Car
{
private:
    std::string model;
    int year;
    float price;
    int count;

public:
    Car(const std::string &model, int year, float price, int count)
        : model(model), year(year), price(price), count(count) {}

    std::string getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    float getPrice() const
    {
        return price;
    }

    int getCount() const
    {
        return count;
    }

    void setModel(const std::string &model)
    {
        this->model = model;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void setPrice(float price)
    {
        this->price = price;
    }

    void setCount(int count)
    {
        this->count = count;
    }
    int getNumAvailable()
    {
        return count;
    }
};

/*Car*/
class User
{
private:
    std::string username;
    std::string password;
    int wallet;
    std::vector<Car> ownedCars;

public:
    User(const std::string &username, const std::string &password, int wallet) : username(username), password(password), wallet(wallet) {}

    std::string getUsername() const
    {
        return username;
    }

    std::string getPassword() const
    {
        return password;
    }

    int getWallet() const
    {
        return wallet;
    }

    void setPassword(const std::string &password)
    {
        this->password = password;
    }

    void setWallet(int wallet)
    {
        this->wallet = wallet;
    }

    std::vector<Car> &getOwnedCars()
    {
        return ownedCars;
    }

    void addOwnedCar(Car &car)
    {
        ownedCars.push_back(car);
    }

    bool checkPassword(const std::string &password) const
    {
        return this->password == password;
    }
};

/*User*/

class CarAgency
{
private:
    std::vector<Car> cars;
    std::vector<User> users;

public:
    CarAgency() {}

    void addCar(const Car &car)
    {
        cars.push_back(car);
    }

    void addUser(const User &user)
    {
        users.push_back(user);
    }

    void showCars() const
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

    User &findUser(const std::string &username)
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

    bool checkUserExists(const std::string &username) const
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

    bool checkCarExists(const std::string &model) const
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

    Car &findCar(const std::string &model)
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

    bool buyCar(User &user, const std::string &model)
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

    void addCarsFromFile(const std::string &fileName)
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

    void addUsersFromFile(const std::string &fileName)
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
};

/*CarAgency*/
int main()
{
    CarAgency agency;
    agency.addCarsFromFile("./car.json");
    agency.addUsersFromFile("./user.json");

    int userChoice = 0;
    User *loggedInUser = nullptr;
    while (userChoice != 2)
    {
        cout << "Car Agency Program" << endl;
        cout << "1. Login" << endl;
        cout << "2. Quit" << endl;
        if (loggedInUser)
        {
            cout << "3. Purchase a Car" << endl;
        }
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
        case 1:
        {
            string username, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            if (agency.checkUserExists(username))
            {
                User &user = agency.findUser(username);
                if (user.checkPassword(password))
                {
                    loggedInUser = &user;
                    cout << "Login successful" << endl;
                }
                else
                {
                    cout << "Incorrect password" << endl;
                }
            }
            else
            {
                cout << "User does not exist" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Exiting program" << endl;
            break;
        }
        case 3:
        {
            if (loggedInUser)
            {
                cout << "Available cars:" << endl;
                agency.showCars();
                cout << "Enter the model of the car you want to buy: ";
                string model;
                getline(cin, model);
                if (agency.checkCarExists(model))
                {
                    Car &car = agency.findCar(model);
                    if (loggedInUser->getWallet() >= car.getPrice())
                    {
                        if (agency.buyCar(*loggedInUser, model))
                        {
                            cout << "Car purchased successfully" << endl;
                        }
                        else
                        {
                            cout << "Error purchasing car" << endl;
                        }
                    }
                    else
                    {
                        cout << "You do not have enough money" << endl;
                    }
                }
                else
                {
                    cout << "Car does not exist" << endl;
                }
            }
            else
            {
                cout << "You must log in first" << endl;
            }
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }

    return 0;
}
