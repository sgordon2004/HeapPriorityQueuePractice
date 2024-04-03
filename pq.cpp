#include"pq.h"
#include<iostream>
#include<algorithm>

// class constructor
Heap::Heap()
{
    // initialize size to -1
    // size represents the size of the array
    // size begins with the first element at size = 0
    size = -1;
}

// returns index parent of given value
int Heap::parent(int i)
{
    return (i - 1) / 2;
}

// returns index of left parent of given value
int Heap::left(int i)
{
    return (2 * i) + 1;
}

// returns index of right parent of given value
int Heap::right(int i)
{
    return (2 * i) + 2;
}

// swap spots of two given values
void Heap::swap(Coat a, Coat b)
{
    Coat temp = a; // temporary variable to store value
    a = b;
    b = temp;
}

// bubbles given item to correct spot in array
void Heap::shiftUp(int i)
{
    // while the given value is not the first in the array
        // (b/c if it is first it has been shifted all the way to the top already)
    // AND while the parent of the given value is less than the given value
        // (a max. heap must have the largest value at the top)
    while (i > 0 && H[parent(i)].price < H[i].price)
    {
        swap(H[i], H[parent(i)]); // parent and child switch places
        // the new parent is now what used to be the child
        i = parent(i); // ensures i remains on the same value given
    }
}

// accesses most expensive coat (aka topmost element in array)
double Heap::peek()
{
    return H[0].price; // first element in array
}

// removes topmost item from heap/array
double Heap::remove()
{
    // result is the removed item
    double result = H[0].price;
    //
    H[0].price = H[size].price; // moving the last element to the first spot in the PQ
    size--; // decrement size of array by 1
    heapify(H[0]);
    return result;
}

void Heap::insert(Coat c)
{
    size ++; // increment size of array
    H[size] = c; // inserting coat obbject into last place in array

    shiftUp(size); // bubble new element up to proper position
}

// function to find the index of rooti
int Heap::findIndex(Coat x)
    {
        int index = std::distance(H, std::find(H, H + size, x));
        return index;
    }

// bubbles given item down upon deletion
void Heap::heapify(Coat rooti)
{
    int rootiIndex = findIndex(rooti);
    
    if (rootiIndex * 2 + 2 <= size) // ensures we stay within array
    {
        int largest = rootiIndex;
        
        // compare the children to find the greater one

        if (H[left(rootiIndex)].price > H[largest].price) // if the given node's left child's key is greater than the given node's key
        {
            largest = left(findIndex(rooti)); // the left child is now the largest in the subtree
        }

        if (H[right(rootiIndex)].price > H[largest].price) // if the given node's right child's key is greater than the given node's key
        {
            largest = right(findIndex(rooti));
        }

        if (largest != rooti.price) // if the largest key is not the root
        {
            swap(rooti, H[largest]);
            heapify(H[largest]);
        }
    } else {return;}
   
}
