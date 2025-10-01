#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random number between 0 and 2
    int sleepTime1 = std::rand() % 3; 
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime1));

    // Read number from file
    int a = 0;
    std::ifstream infile("./test.txt");
    if (infile.is_open()) {
        infile >> a;
        infile.close();
    } else {
        std::cerr << "Error: Could not open file test.txt for reading.\n";
        return 1;
    }

    // Sleep again
    int sleepTime2 = std::rand() % 3;
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime2));

    // Add 2 to the number
    a += 5 ;

    // Sleep once more
    int sleepTime3 = std::rand() % 3;
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime3));

    // Write updated number back to file
    std::ofstream outfile("./test.txt");
    if (outfile.is_open()) {
        outfile << a;
        outfile.close();
    } else {
        std::cerr << "Error: Could not open file test.txt for writing.\n";
        return 1;
    }

    std::cout << "P2 saying : Updated number saved: " << a << std::endl;

    return 0;
}
