#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    std::istringstream iss(input);
    int number;
    if (iss >> number) {
        std::cout << "You entered the number: " << number << std::endl;
    } else {
        std::cerr << "Invalid input. Please enter a valid number." << std::endl;
    }

    return 0;
}
