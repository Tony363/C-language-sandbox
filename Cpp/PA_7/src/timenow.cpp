#include <ctime>
#include <string>
#include <iostream>

int main() {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
    char buffer[80];
    strftime(buffer,80,"%D",now);
    std::cout << buffer << std::endl;
}