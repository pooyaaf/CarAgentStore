#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    if (connect(sock, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        return 1;
    }

    char message[1024] = { 0 };
    std::string user_input;

    while (true) {
        std::cout << "Enter a message: ";
        std::getline(std::cin, user_input);

        if (user_input == "quit") {
            break;
        }

        send(sock, user_input.c_str(), user_input.size(), 0);

        int bytes_received = recv(sock, message, 1024, 0);
        if (bytes_received == -1) {
            std::cerr << "Error receiving response from server" << std::endl;
            break;
        } else if (bytes_received == 0) {
            std::cout << "Server disconnected" << std::endl;
            break;
        } else {
            std::cout << "Server response: " << message << std::endl;
        }
    }

    close(sock);
    return 0;
}
