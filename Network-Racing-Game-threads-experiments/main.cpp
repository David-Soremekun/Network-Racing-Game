#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

void Client()
{
    sf::TcpSocket socket;
    int unsigned short PortNum=4300;
    sf::IpAddress address("152.105.67.130");
    sf::Socket::Status status;
    status = socket.connect(address,PortNum);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem connecting\n";
        return;
    }
    sf::Packet packet;
    packet<<"SIUUUUUUUUUUU";
    status=socket.send(packet);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem sending\n";
        return;
    }



}

void Server()
{

    sf::TcpListener listener;
    sf::Socket::Status status;
    status= listener.listen(4300);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem listening\n";
        return;
    }

    sf::TcpSocket socket;
    status=listener.accept(socket);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem accepting\n";
        return;
    }

    sf::Packet packet;
    status=socket.receive(packet);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem receiving\n";
        return;
    }

    std::string message("Muchas gracias afición esto es para vosotros");
    std::cout<<message;
    packet>>message;
    packet.clear();

    status=socket.send(packet);
    if(status != sf::Socket::Done){
        std::cout<<"ERROR- Problem receiving\n";
        return;
    }



}

int main()
{
    std::thread ServerThread(Server);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::thread ClientThread(Client);


//    std::vector<std::thread> threadVec;
//    threadVec.push_back(ServerThread);
//    threadVec.push_back(ClientThread);
//
//    for(int i=0; i<threadVec.size(); i++){
//        threadVec.at(i).join();
//    }

    ServerThread.join();
    ClientThread.join();

    return 0;

}
