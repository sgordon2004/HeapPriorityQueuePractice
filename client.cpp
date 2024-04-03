#include"pq.h"
#include<iostream>

int main()
{
    // instantiating heap class
    Heap myHeap;
    // creating coat object
    Coat myCoat;
    // will store user input
    std::string designer;
    // std::string strPrice; // stores price as string
    // double price = stod(strPrice); // stores price as double


    // ask the user for information until they tell you to stop
    std::string input; // string to store yes or no of user
    std::cout << "Would you like to enter coats? Enter 'y' or 'n'" << std::endl;
    std::cin >> input; // storing user response

    // if user says yes, begin collecting input
    if (input == "y")
    {
        // first entry
        std::cout << "Enter coat designer: "; // ask user for designer
        std::cin.ignore();
        getline(std::cin, myCoat.designer); // collect & assign designer input to coat object
        std::cout << "Enter price of coat: "; // ask user for price
        std::cin >> myCoat.price;
        //getline(std::cin, strPrice); // collect & store input
        // myCoat.designer = price; // assign price input to coat object
    }
    // if user says no, terminate program
    else
    {
        std::cout << "The priority queue is empty." << std::endl;
    }

    // will run until the user inputs no
    while (input == "y")
    {
        myHeap.insert(myCoat);
        std::cout << "Would you like to keep going? (y/n)" << std::endl;
        std::cin >> input;
        if (input == "n")
        {
            break;
        }
        std::cout << "Enter coat designer: "; // ask user for designer
        std::cin.ignore();
        getline(std::cin, myCoat.designer); // collect & assign designer input to coat object
        std::cout << "Enter price of coat: "; // ask user for price
        std::cin >> myCoat.price; // collect & store price input
        // myCoat.designer = price; // assign price input to coat object
    }

// print the three most expensive coats
std::cout  << std::endl; // print newline
std::cout << "1st most expensive coat: ";
std::cout << myHeap.peek(); // prints first most expensive coat
myHeap.remove(); // removes first expensive coat
std::cout  << std::endl; // print newline
std::cout << "2nd most expensive coat: ";
std::cout << myHeap.peek(); // prints second most expensive coat
myHeap.remove(); // removes second expensive coat
std::cout  << std::endl; // print newline
std::cout << "3rd most expensive coat: ";
std::cout << myHeap.peek(); // prints third most expensive coat

return 0;
}