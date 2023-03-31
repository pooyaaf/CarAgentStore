#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "json/json.h"
#include "CarAgency.hpp"
#include "Car.hpp"
#include "User.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

using namespace std;

int main()
{
    // Create a CarAgency instance
    CarAgency agency;
    string pathOfCarsJSON = "../car.json";
    agency.addCarsFromFile(pathOfCarsJSON);
    string pathOfUsersJSON = "../user.json";
    agency.addUsersFromFile(pathOfUsersJSON);

    // Create a socket
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    int userChoice = 0;
    User *loggedInUser = nullptr;

    while (userChoice != 2)
    {
        // Send the user menu to the client
        string menu = "";
        menu += "Car Agency Program\n";
        menu += "1. Login\n";
        menu += "2. Quit\n";
        if (loggedInUser)
        {
            menu += "3. Purchase a Car\n";
            menu += "4. Show Wallet\n";
            menu += "5. Show Purchased Cars\n";
        }
        send(new_socket, menu.c_str(), strlen(menu.c_str()), 0);

        // Receive the user's choice from the client
        char choice[1024] = {0};
        valread = read(new_socket, choice, 1024);
        userChoice = stoi(choice);

        switch (userChoice)
        {
        case 1:
        {
            // Receive the login credentials from the client
            char username[1024] = {0};
            char password[1024] = {0};
            send(new_socket, "Enter username: ", strlen("Enter username: "), 0);
            valread = read(new_socket, username, 1024);
            send(new_socket, "Enter password: ", strlen("Enter password: "), 0);
            valread = read(new_socket, password, 1024);

            if (agency.checkUserExists(username))
            {
                User &user = agency.findUser(username);
                if (user.checkPassword(password))
                {
                    loggedInUser = &user;
                    send(new_socket, "Login successful", strlen("Login successful"), 0);
                }
                else
                {
                    send(new_socket, "Incorrect password", strlen("Incorrect password"), 0);
                }
            }
            else
            {
                send(new_socket, "User does not exist", strlen("User does not exist"), 0);
            }
        }
        case 2:
        {
            send(new_socket, "Exiting program", strlen("Exiting program"), 0);
            break;
        }
        case 3:
        {
            if (loggedInUser)
            {

                send(new_socket, "Available cars:", strlen("Available cars:"), 0);
                std::string availableCars = agency.showCars();
                send(new_socket, availableCars.c_str(), availableCars.size(), 0);
                send(new_socket, "Enter the model of the car you want to buy: ", strlen("Enter the model of the car you want to buy: "), 0);
                // Receive the user's choice from the client for model
                char model[1024] = {0};
                valread = read(new_socket, model, 1024);
                if (agency.checkCarExists(model))
                {
                    Car &car = agency.findCar(model);
                    if (loggedInUser->getWallet() >= car.getPrice())
                    {
                        if (agency.buyCar(*loggedInUser, model, pathOfUsersJSON, pathOfCarsJSON))
                        {
                            send(new_socket, "Car purchased successfully", strlen("Car purchased successfully"), 0);
                        }
                        else
                        {
                            send(new_socket, "Error purchasing car", strlen("Error purchasing car"), 0);
                        }
                    }
                    else
                    {
                        send(new_socket, "You do not have enough money", strlen("You do not have enough money"), 0);
                    }
                }
                else
                {
                    send(new_socket, "Car does not exist", strlen("Car does not exist"), 0);
                }
            }
            else
            {
                send(new_socket, "You must log in first", strlen("You must log in first"), 0);
            }
            break;
        }
        case 4:
        {
            string walletMsg = "Your wallet balance is: " + std::to_string(loggedInUser->getWallet());
            send(new_socket, walletMsg.c_str(), walletMsg.length(), 0);
            break;
        }
        case 5:
        {
            std::string purchasedCarsStr = loggedInUser->showPurchasedCars();
            send(new_socket, purchasedCarsStr.c_str(), purchasedCarsStr.length(), 0);
            break;
        }
        }
    }
    return 0;
}