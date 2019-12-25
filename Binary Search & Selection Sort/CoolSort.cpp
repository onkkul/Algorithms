
/*
October 13, 2019 14:20

Onkar Kulkarni

C++ code for CoolSort() Sort

Run code using following command:

g++ CoolSort.cpp -o CoolSort.exe
*/

#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std; 

//function to display the output
void Show(int length, int arr[])
{
    int i;
    // show locations of array
    for (i = 0; i < length; i++)
    {
        cout << i << '\t';
    }
    cout << '\n';

    //Show values present at the location
    for (i = 0; i< length; i++)
    {
        cout << arr[i] << '\t';
    }

    cout << '\n';

}


//Function to get input from user
void GetInput(int length, int values[])
{

    int iter;
    for (iter = 0; iter < length; iter++)
    {
        cout <<"Enter the " << iter+1 << "th element in array: \t";
        cin >> values[iter];    
    }
    
    cout << "\nInput Values in the array are: \t";
    
    //display the inputs
    Show(length, values);

}


void SelectionSort(int arr[], int subArry[], int subArrylen)  
{  
    

    //for each element in each gap set[0,5,10] use selection sort to sort elements WITHIN GAP.
    /*
    ARR[] = main array
    subArry[] = the gap set e.g. [0,5,10] etc
    subArrylen = length of gap
    */
    int sorted_element, Unsorted_element, minimum;  
    

    for (sorted_element = 0; sorted_element < subArrylen; sorted_element ++)  
    {  

        minimum = subArry[sorted_element];

        for (Unsorted_element = sorted_element + 1; Unsorted_element < subArrylen; Unsorted_element ++)  
        {
            if (arr[subArry[Unsorted_element]] < arr[minimum])  
            {
                minimum = subArry[Unsorted_element];  
            }
        }

        int newV = arr[minimum];
        arr[minimum] = arr[subArry[sorted_element]];
        arr[subArry[sorted_element]] = newV;
    
    }
} 


void MakePass(int gaps, int gap_values[], int length_to_sort, int values_to_sort[])
{
    /*
    Find all the possible gap sets for given input.
    gaps = numbr of gaps
    gap index = each gap e.g. Gaps = [5,3,1]
    length_to_sort = length of array to be sorted
    values_to_sort = actual array to be sorted

    */
    for (int gap_index = 0; gap_index < gaps; gap_index ++)
    {
        
        int mul_range = length_to_sort/gap_values[gap_index]+ 1;
        int subArry[mul_range] = {};

        for (int pass = 0; pass < gap_values[gap_index]; pass ++)
        {

            cout << "\nPass " << pass + 1 << " of gap " << gap_values[gap_index] << " in index:value format is:\n";
            int subArrylen = 0;
            
            for (int Quotient = 0; Quotient <= mul_range; Quotient++)
            {
                int k = gap_values[gap_index]*Quotient + pass;
                if (k < length_to_sort)
                {
                    subArry[Quotient] = k;
                    cout << k<<":"<< values_to_sort[k] << '\t';
                    subArrylen ++;
                    
                }
                
            }

            cout << "\nlength of pass: " << subArrylen << '\n'; 
            cout << '\n';

            //for each calculated gap set, send those elements for selection sort
            SelectionSort(values_to_sort, subArry, subArrylen);

            Show(length_to_sort, values_to_sort);
            
        }
    }
}


int main()
{

    // int gaps = 3;
    // int gap_values[gaps] = {5, 3, 1};

    // int length_to_sort = 12;
    // int values_to_sort[length_to_sort] = {62,83,18,53,7,17,95,86,47,90,25,28};

      
    int gaps;
    cout << "Enter the number of elements in the gap array: \n";
    cin >> gaps;
    int gap_values[gaps];
    GetInput(gaps, gap_values);

    int length_to_sort;
    cout << "Enter the number of elements you want to Sort: \n";
    cin >> length_to_sort;
    int values_to_sort[length_to_sort];   
    GetInput(length_to_sort, values_to_sort);

    Show(length_to_sort, values_to_sort);
    

    MakePass(gaps, gap_values, length_to_sort, values_to_sort);

}

