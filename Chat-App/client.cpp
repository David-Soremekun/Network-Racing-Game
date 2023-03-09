#include "queue.h"
#include "receiver.h"
#include "util.h"
#include <SFML/Network.hpp>
#include <iostream>
#include <thread>

int clientMain()
{
    std::shared_ptr<sf::TcpSocket> socket = std::make_shared<sf::TcpSocket>();
    sf::Socket::Status status = socket->connect(sf::IpAddress::getLocalAddress(), PORT);
    if (status != sf::Socket::Done) {
        return 1;
    }
    sf::Packet packet;
    std::cout << "Connected\n";
    Queue<std::string> queue;
    // TODO launch a receiver thread to receive messages from the server.
    status=socket.receive(packet);
    if(status!=sf::Socket::Done)
    {
        std::cout<<"Issue Recieving Packet\n";
        return;
    }

    std::string s = "";
    while (1)
    {

        std::getline(std::cin, s);
        std::cout << "Sending: \"" << s << "\"" << std::endl;
        // TODO send messages to the server

        packet>>s;
        packet.clear();

        status=socket.send(packet);
        if(status!=sf::Socket::Done)
        {
            std::cout<<"Issue Sending PACKET\n";
            return;
        }

    }
    return 0;
}
