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
#define MAXLINE 1500

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
    int sockfd;
    // buffer to send and receive messages with
    char buffer[MAXLINE];
    char msg[MAXLINE];
    const char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len;
    int n;

    len = sizeof(cliaddr); // len is value/result

    // lets keep track of the session time
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    // also keep track of the amount of data sent as well
    int bytesRead, bytesWritten = 0;

    // receive a message from the client (listen)
    cout << "Awaiting client response..." << endl;
    // recieve heloo msg from client
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                 MSG_WAITALL, (struct sockaddr *)&cliaddr,
                 &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);

    int userChoice = 0;
    int valread;
    User *loggedInUser = nullptr;
    memset(&msg, 0, sizeof(msg));
    while (userChoice != 2)
    {
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

        sendto(sockfd, menu.c_str(), strlen(menu.c_str()),
               MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
               len);
        cout << "menu sent." << endl;
        memset(&msg, 0, sizeof(msg)); // clear the buffer
        bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                              MSG_WAITALL, (struct sockaddr *)&cliaddr,
                              &len);
        buffer[n] = '\0';
        printf("Client : %s\n", msg);
        userChoice = stoi(msg);
        switch (userChoice)
        {

        case 1:
        {
            char username[MAXLINE] = {0};
            char password[MAXLINE] = {0};
            // recive username
            sendto(sockfd, "Enter username: ", strlen("Enter username: "),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                   len);
            memset(&msg, 0, sizeof(msg)); // clear the buffer
            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                  &len);
            strcpy(username, msg);
            memset(&msg, 0, sizeof(msg));
            // recive password
            sendto(sockfd, "Enter password: ", strlen("Enter password: "),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                   len);
            memset(&msg, 0, sizeof(msg)); // clear the buffer
            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                  &len);
            strcpy(password, msg);
            memset(&msg, 0, sizeof(msg));

            if (agency.checkUserExists(username))
            {
                User &user = agency.findUser(username);
                if (user.checkPassword(password))
                {
                    loggedInUser = &user;
                    cout << "User:" << username << " Logged in with password:" << password << "\n ";
                    // sendto(sockfd, "Login successful ", strlen("Login successful"), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
                    // memset(&msg, 0, sizeof(msg));
                    break;
                }
                else
                {
                    sendto(sockfd, "Incorrect password", strlen("Incorrect password"),
                           MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                           len);
                    memset(&msg, 0, sizeof(msg));
                    break;
                }
            }
            else
            {
                sendto(sockfd, "User does not exist", strlen("User does not exist"),
                       MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                       len);
                memset(&msg, 0, sizeof(msg));
                break;
            }
        }
        case 2:
        {
            sendto(sockfd, "Exiting program", strlen("Exiting program"),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                   len);
            memset(&msg, 0, sizeof(msg));
            // we need to close the socket descriptors after we're all done
            gettimeofday(&end1, NULL);
            close(sockfd);
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
                sendto(sockfd, "Available cars: (Enter to list view | cntrl + c to exit)", strlen("Available cars: (Enter to list view | cntrl + c to exit)"),
                       MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                       len);
                bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                      MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                      &len);
                memset(&msg, 0, sizeof(msg));
                std::string availableCars = agency.showCars();
                availableCars = availableCars + "\nEnter the model of the car you want to buy: ";
                sendto(sockfd, availableCars.c_str(), availableCars.size(),
                       MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                       len);

                char model[1024] = {0};
                bytesRead += recvfrom(sockfd, (char *)model, MAXLINE,
                                      MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                      &len);
                if (agency.checkCarExists(model))
                {
                    Car &car = agency.findCar(model);

                    if (loggedInUser->getWallet() >= car.getPrice())
                    {
                        if (agency.buyCar(*loggedInUser, model, pathOfUsersJSON, pathOfCarsJSON))
                        {

                            sendto(sockfd, "Car purchased successfully( Enter to back to menu | cntrl + c to exit)", strlen("Car purchased successfully( Enter to back to menu | cntrl + c to exit)"),
                                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                                   len);
                            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                                  &len);
                            memset(&msg, 0, sizeof(msg));
                        }
                        else
                        {

                            sendto(sockfd, "Error purchasing car( Enter to back to menu | cntrl + c to exit)", strlen("Error purchasing car( Enter to back to menu | cntrl + c to exit)"),
                                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                                   len);
                            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                                  &len);
                            memset(&msg, 0, sizeof(msg));
                        }
                    }
                    else
                    {
                        sendto(sockfd, "You do not have enough money( Enter to back to menu | cntrl + c to exit)", strlen("You do not have enough money( Enter to back to menu | cntrl + c to exit)"),
                               MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                               len);
                        bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                              MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                              &len);
                        memset(&msg, 0, sizeof(msg));
                    }
                }
                else
                {
                    sendto(sockfd, "Car does not exist( Enter to back to menu | cntrl + c to exit)", strlen("Car does not exist( Enter to back to menu | cntrl + c to exit)"),
                           MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                           len);
                    bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                          MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                          &len);
                    memset(&msg, 0, sizeof(msg));
                }
            }
            else
            {
                sendto(sockfd, "You must log in first( Enter to back to menu | cntrl + c to exit)", strlen("You must log in first( Enter to back to menu | cntrl + c to exit)"),
                       MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                       len);
                bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                      MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                      &len);
                memset(&msg, 0, sizeof(msg));
            }
            break;
        }
        case 4:
        {
            string walletMsg = "Your wallet balance is: " + std::to_string(loggedInUser->getWallet()) + "\n( Enter to back to menu | cntrl + c to exit)";
            sendto(sockfd, walletMsg.c_str(), walletMsg.length(),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                   len);
            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                  &len);
            memset(&msg, 0, sizeof(msg));
            break;
        }
        case 5:
        {
            std::string purchasedCarsStr = loggedInUser->showPurchasedCars() + "\n( Enter to back to menu | cntrl + c to exit)";
            sendto(sockfd, purchasedCarsStr.c_str(), purchasedCarsStr.length(),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
                   len);
            bytesRead += recvfrom(sockfd, (char *)msg, MAXLINE,
                                  MSG_WAITALL, (struct sockaddr *)&cliaddr,
                                  &len);
            memset(&msg, 0, sizeof(msg));
            break;
        }
        }
    }
    // n = recvfrom(sockfd, (char *)buffer, MAXLINE,
    //              MSG_WAITALL, (struct sockaddr *)&cliaddr,
    //              &len);
    // buffer[n] = '\0';
    // printf("Client : %s\n", buffer);
    // sendto(sockfd, (const char *)hello, strlen(hello),
    //        MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
    //        len);
    // std::cout << "Hello message sent." << std::endl;

    return 0;
}