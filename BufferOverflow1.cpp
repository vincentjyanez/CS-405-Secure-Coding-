// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits> 

int main()
{
    std::cout << "Buffer Overflow" << std::endl;

    // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
    //  even though it is a constant and the compiler buffer overflow checks are on.
    //  You need to modify this method to prevent buffer overflow without changing the account_number
    //  variable, and its position in the declaration. It must always be directly before the variable used for input.
    //  You must notify the user if they entered too much data.

    // Prevent overflow by limiting input size to 19 characters (since char user_input[20] includes space for the null terminator)
    const std::string account_number = "CharlieBrown42";
    char user_input[20]; // Buffer of 20 characters

    
    // Debugging message to check if we reach here
    std::cout << "Prompting user for input..." << std::endl;

    std::cout << "Enter a value (max 19 characters): ";

    // Using std::cin.getline to get the input correctly
    std::cin.getline(user_input, 20); // Reads up to 19 characters

    // Debugging message to check if input was successfully read
    std::cout << "Input received!" << std::endl;


    // Check if input exceeded the buffer size
    if (std::cin.fail()) {
        std::cout << "Error: Input too long. Try again." << std::endl;
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore excess input
    }
    else {
        std::cout << "You entered: " << user_input << std::endl;
    }

    // To keep the window open
    std::cout << "Press Enter to exit...";
    std::cin.ignore();  // To discard any leftover input

    std::cin.get();  // Waits for the user to press Enter before closing.

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
