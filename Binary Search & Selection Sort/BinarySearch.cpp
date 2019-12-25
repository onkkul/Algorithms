/*
October 14, 2019 11:53

Onkar Kulkarni

C++ code for Searching element such that A[i] = i

Run code using following command:
g++ BinarySearch.cpp -o BinarySearch.exe

*/


#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std; 


// This function displays the contents of array and their contents.
void Show(int length, int sorted[])
{
    int i;
    cout << "locations: \t";
    for (i = 1; i < length; i++)
    {
        cout << i << '\t';
    }
    cout << '\n';

    cout << "Values : \t";
    for (i = 1; i< length; i++)
    {
        cout << sorted[i] << '\t';
    }

    cout << '\n';

}


// This function takes input of contents in the array from the terminal
void GetInput(int length, int values[])
{

    int iter;

    //As array starts at '0'; enter a default non zero value staticly for location 0.
    //This way first user input will be stored at location 1
    values[0] = 10;

    for (iter = 1; iter < length; iter++)
    {
        cout <<"Enter the " << iter << "th element in array: \t";   //take inputs from user
        cin >> values[iter];    
    }
    
    cout << "\nInput Values in the array are: \n";  
    
    //Display the contents at those locations
    Show(length, values);

}


/*
Binary search function to find the location A[key] = key
int Search(Array_to_be_searched, size_of_array, element_to_be_searched, index_to_Store the location_of element)
*/
int Search(int sorted[], int size, int key, int found)
{

    int left = 1;
    int right = size-1;
    int middle = (left+right)/2;
    while (left <= right)
    {
       if(sorted[middle] < key || (middle < key))
       {
            //if value at sortedarray[middle_position] < key then the value A[key] lies to the right of the middle position.
            left = middle + 1;

       }

       else if(sorted[middle] == key && middle == key)
       {

            cout<<key<<" Found in the array at the location "<<middle <<"\n";
            found = found +1;
            break;
        } 
        
        else
        { 
            //if value at sortedarray[middle_position] > key then the value key = A[key] lies to the left of the middle position.
            right = middle - 1; 
        } 
        
        /*
        recursively search the left or right part for the value key = A[key] by splitting it in right & left part
        */
        middle = (left + right)/2;  
    }
    return found;
    
}


int main()
{
    int arraySize;
    cout << "\nEnter the size(length) of SORTED array" << '\n';
    cin >> arraySize;

    /*
    As array starts at 0, store a defalt non zero static value of 10 at A[0].
    by adding A[0] = 10, we make sure that A[0] != 0.
    Thus, first user input will be stored at location 1.
    This, in turn, will make sure that array starts at 1.(Vertually)
    To facilitate this, increase size by one so that we can accomodate the default value
    */
    arraySize = arraySize + 1;
    int location[arraySize];
    int sortedArray[arraySize];

    GetInput(arraySize, sortedArray);

    int key;
    int found = 0;
    
    cout << "\n\nFinding elements such that array[key] = key.......\n\n" << '\n';
    
    /*
    As we need to check for each element of array, simply run a for loop 
    acrros the array making one index of array key in each iteration.
    */
    for (key = 0; key <= arraySize; key ++)
    {
        found = Search(sortedArray, arraySize, key, found);
    }

    if (found == 0)
    {
        cout << "\n\n\n\n\nSorry mate, I didn't find a single such pair in array....!!" << '\n';
    }

}
