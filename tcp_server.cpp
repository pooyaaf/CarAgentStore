#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
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

int main(int argc, char *argv[])
{
    // Create a CarAgency instance
    CarAgency agency;
    string pathOfCarsJSON = "../car.json";
    agency.addCarsFromFile(pathOfCarsJSON);
    string pathOfUsersJSON = "../user.json";
    agency.addUsersFromFile(pathOfUsersJSON);
    // for the server, we only need to specify a port number
    if (argc != 2)
    {
        cerr << "Usage: port" << endl;
        exit(0);
    }
    // grab the port number
    int port = atoi(argv[1]);
    // buffer to send and receive messages with
    char msg[1500];

    // setup a socket and connection tools
    sockaddr_in servAddr;
    bzero((char *)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);

    // open stream oriented socket with internet address
    // also keep track of the socket descriptor
    int serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSd < 0)
    {
        cerr << "Error establishing the server socket" << endl;
        exit(0);
    }
    // bind the socket to its local address
    int bindStatus = bind(serverSd, (struct sockaddr *)&servAddr,
                          sizeof(servAddr));
    if (bindStatus < 0)
    {
        cerr << "Error binding socket to local address" << endl;
        exit(0);
    }
    cout << "Waiting for a client to connect..." << endl;
    // listen for up to 5 requests at a time
    listen(serverSd, 5);
    // receive a request from client using accept
    // we need a new address to connect with the client
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
    // accept, create a new socket descriptor to
    // handle the new connection with client
    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if (newSd < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }
    cout << "Connected with client!" << endl;
    // lets keep track of the session time
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    // also keep track of the amount of data sent as well
    int bytesRead, bytesWritten = 0;

    // receive a message from the client (listen)
    cout << "Awaiting client response..." << endl;

    int userChoice = 0;
    int valread;
    User *loggedInUser = nullptr;
    memset(&msg, 0, sizeof(msg));
    while (userChoice != 2)
    {
        memset(&msg, 0, sizeof(msg)); // clear the buffer
        bytesRead += recv(newSd, (char *)&msg, sizeof(msg), 0);
        cout << "Client: " << msg << endl;
        userChoice = stoi(msg);
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
        send(newSd, menu.c_str(), strlen(menu.c_str()), 0);
        switch (userChoice)
        {

        case 1:
        {
            // Receive the login credentials from the client
            char username[1024] = {0};
            char password[1024] = {0};
            send(newSd, "Enter username: ", strlen("Enter username: "), 0);
            valread = read(newSd, username, 1024);
            send(newSd, "Enter password: ", strlen("Enter password: "), 0);
            valread = read(newSd, password, 1024);
            if (agency.checkUserExists(username))
            {
                User &user = agency.findUser(username);
                if (user.checkPassword(password))
                {
                    loggedInUser = &user;
                    cout << "User:" << username << " Logged in with password:\n"
                         << password;
                    send(newSd, "Login successful\n", strlen("Login successful\n"), 0);
                    memset(&msg, 0, sizeof(msg));
                    break;
                }
                else
                {
                    send(newSd, "Incorrect password\n", strlen("Incorrect password\n"), 0);
                    memset(&msg, 0, sizeof(msg));
                    break;
                }
            }
            else
            {
                send(newSd, "User does not exist\n", strlen("User does not exist\n"), 0);
                memset(&msg, 0, sizeof(msg));
                break;
            }
        }
        case 2:
        {
            send(newSd, "Exiting program\n", strlen("Exiting program\n"), 0);
            memset(&msg, 0, sizeof(msg));
            // we need to close the socket descriptors after we're all done
            gettimeofday(&end1, NULL);
            close(newSd);
            close(serverSd);
            cout << "********Session********" << endl;
            cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
            cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
                 << " secs" << endl;
            cout << "Connection closed..." << endl;
            break;
        }
        case 3:
        {
            if (loggedInUser)
            {

                send(newSd, "Available cars: (Enter to list view | cntrl + c to exit)", strlen("Available cars: (Enter to list view | cntrl + c to exit)"), 0);
                std::string availableCars = agency.showCars();
                send(newSd, availableCars.c_str(), availableCars.size(), 0);
                send(newSd, "Enter the model of the car you want to buy: ", strlen("Enter the model of the car you want to buy: "), 0);
                // Receive the user's choice from the client for model
                char model[1024] = {0};
                // memset(&msg, 0, sizeof(msg));
                // bytesRead += recv(newSd, (char *)&model, sizeof(model), 0);
                valread = read(newSd, model, 1024);
                cout << model;
                // cout<<"Selected car model :"<<model;
                if (agency.checkCarExists(model))
                {
                    Car &car = agency.findCar(model);
                    if (loggedInUser->getWallet() >= car.getPrice())
                    {
                        if (agency.buyCar(*loggedInUser, model, pathOfUsersJSON, pathOfCarsJSON))
                        {
                            send(newSd, "Car purchased successfully", strlen("Car purchased successfully"), 0);
                        }
                        else
                        {
                            send(newSd, "Error purchasing car", strlen("Error purchasing car"), 0);
                        }
                    }
                    else
                    {
                        send(newSd, "You do not have enough money", strlen("You do not have enough money"), 0);
                    }
                }
                else
                {
                    send(newSd, "Car does not exist", strlen("Car does not exist"), 0);
                }
            }
            else
            {
                send(newSd, "You must log in first", strlen("You must log in first"), 0);
            }
            break;
        }

        case 4:
        {
            string walletMsg = "Your wallet balance is: " + std::to_string(loggedInUser->getWallet());
            send(newSd, walletMsg.c_str(), walletMsg.length(), 0);
            break;
        }
        case 5:
        {
            std::string purchasedCarsStr = loggedInUser->showPurchasedCars();
            send(newSd, purchasedCarsStr.c_str(), purchasedCarsStr.length(), 0);
            break;
        }
        }
    }

    return 0;
}