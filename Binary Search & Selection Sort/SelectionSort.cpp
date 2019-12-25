
/*
October 12, 2019 12:45

Onkar Kulkarni

C++ code for Selection Sort

Run code using following command:

g++ SelectionSort.cpp -o SelectionSort.exe

*/

#include <stdio.h>
#include <iostream>
using namespace std; 

  
void SelectionSort(int arr[], int n)  
{  
    int i, j, minimum;  
  
    // One by one reduce elements of unsorted subarray  
    for (i = 0; i < n; i++)  
    {  
        // init the minimum element in unsorted array  
        minimum = i;  
        for (j = i+1; j < n; j++)  
        {
            //Check if unsorted array has element less than initialized minimum
            if (arr[j] < arr[minimum])  
            {
                //If such element is found, make it the new minimum
                minimum = j;  
            }
        }
        // Swap the found minimum element with the previous min element  
        int tmp = arr[minimum];
        arr[minimum] = arr[i];
        arr[i] = tmp;
    }
} 
 

int main()
{
    int iter, length;
    cout << "Enter the number of elements you want to Sort: \n";
    cin >> length;
    int values[length];
    for (iter = 0; iter < length; iter++)
    {
        cout <<"Enter the " << iter+1 << "th element: \t";
        cin >> values[iter];    
    }

    cout << "\nInput Values in the array are: \t";
    for (iter = 0; iter < length; iter++)
    {
        cout << values[iter] << "\t";
    }

    SelectionSort(values, length);

    cout << "\nSorted Values in the array are: ";
    for (iter = 0; iter < length; iter++)
    {
        cout << values[iter] << "\t";
    }
}