#include <iostream>
#include <thread>
#include "Loop.h"
int main()
{
    std::thread([]{std::cout << "Hello from thread!\n";}).join();
    std::cout << "Hello World!\n";
    return 0;
}
