#include"pq.h"
#include<iostream>

int main()
{
    // instantiating heap class
    Heap myHeap;

    // ask the user for information until they tell you to stop
    std::string input; // string to store yes or no of user
    std::cout << "Would you like to enter coats? Enter 'y' or 'n'" << std::endl;
    std::cin >> input; // storing user response

    // if user says yes, begin collecting input
    if (input == "y")
    {
        // will run until the user inputs no
        while (input == "y")
        {
            for (int i = 0; i < 11; i++) // creates struct w/ unique names
            {
                std::string name = "myCoat" + std::to_string(i);
                Coat;
                // ask user for the coat designer
                std::cout << "Enter coat designer: ";
                name.designer;

            }

        }
        }
        // if user says no, terminate program
        else
        {
            std::cout << "The priority queue is empty." << std::endl;
        }
    return 0;
}