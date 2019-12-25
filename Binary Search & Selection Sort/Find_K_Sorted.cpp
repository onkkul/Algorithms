
/*
October 12, 2019 13:27

Onkar Kulkarni

C++ code for Selection Sort
Sorting first k elements out of n inputs

Run code using following command:

g++ Find_K_Sorted.cpp -o Find_K_Sorted.exe
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
 

void Find_K_Sorted(int arr[], int length)
{
    while (true)
    {
        int k;
        cout << "\nEnter the value of K: " << "\t";
        cin >> k;
        
        //Perform only if valid input of "k" is received
        if (k > 0 && (k <= length))
        {
            //Call SelectionSort() for given input of k
            SelectionSort(arr, length, k);

            cout << "\nFirst "<< k <<" sorted values in the array are: ";
            for (int iter = 0; iter < k; iter++)
            {
                cout << arr[iter] << "\t";
            }
            break;
        }

        else
        {
            cout << "\nI will pretend I didn't see that.... Now enter valid K!" << '\n';
        }
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

    //call Find_K_Sorted() function to find first k smallest elements of array
    Find_K_Sorted(values, length);


}