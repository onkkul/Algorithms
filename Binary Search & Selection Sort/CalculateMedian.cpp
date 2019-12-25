
/*
October 1, 2019 14:37

Onkar Kulkarni

C++ code for Selection Sort
Finding Median of given input

Run code using following command:

g++ CalculateMedian.cpp -o CalculateMedian.exe
*/

#include <iostream>
using namespace std; 

  
void SelectionSort(int arr[], int length, int k)  
{  
    int i, j, minimum;
    // One by one search for first k smallest elements in the input 
    for (i = 0; i < k; i++)  
    {  
        // init the minimum element in unsorted array  
        minimum = i;  
        for (j = i+1; j < length; j++)  
        {
            //Check if unsorted array has element less than initialized minimum
            if (arr[j] < arr[minimum])  
            {
                //If such element is found, make it the new minimum
                minimum = j;  
            }
        }
        // Swap the found minimum element with the previous min element using a temporary variable.
        int tmp = arr[minimum];
        arr[minimum] = arr[i];
        arr[i] = tmp;
    }
} 


void CalculateMedian(int arr[], int length)
{
    
    //median is average of middle 2 elements if length is even
    //median is middle element if length is odd.
    //thus, we need only middle+1 elements in sorted oreder to calculate the median
    int middle = length/2;

    SelectionSort(arr, length, middle+1);

    //if length is even, take average of last two elements of array [a_0 to a_middle]
    if (length % 2 == 0)
    {
        cout <<'\n';
        double median = ((arr[middle-1] + arr[middle])/2.0);
        cout <<"\n\nMedian of the input is: \t"<< median << '\n';
    }

    // else just take the last element of array as median
    else
    {
        double median = arr[middle];
        cout <<"\n\nMedian of the input is: \t"<< median << '\n';
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

    CalculateMedian(values, length);

}