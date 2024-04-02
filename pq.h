#include <string>

// coat struct with designer and price variables
struct Coat
{
    double price;
    std::string designer;
};

// Heap class
class Heap
{
    private: // only accessible within class
        Coat H[11]; // array represents the priority queue
        int size; // stores size of array
        int parent(int i); // returns index of parent node of given node
        int left(int i); // returns index of left child node of givcen node
        int right(int i); // returns index of right child node of given node
        void shiftUp(int i); // bubbles given node up to its proper place in array upon insertion
        void swap (Coat a, Coat b); // swaps places of a and b in array
        void heapify(Coat rooti); // bubbles given node down to its proper place in array upon deletion
        int findIndex(Coat x); // functino to find index of an element
    public: // accessible outside of class
        Heap(); // class constructor
        void insert(int p); // inserts into array
        double peek(); // returns most expensive coat in array
        double remove(); // removes most expensive coat from array
        void print_heap(); // prints out entire heap
};