/*
November 10, 2019 10:10

Onkar Kulkarni

C++ code for the Knapsack

Run code using following command:
g++ Dynamic_Knapsack.cpp -o Dynamic_Knapsack.exe
tmp.exe
*/

#include <cmath>
#include <iostream>
#include <stdio.h>



using namespace std; 


// This function displays the items, weights and values.
void Show(int numberofitems, int weights[], int values[])
{
    int i;
    cout << "Item number: \t";
    for (i = 1; i < numberofitems; i++)
    {
        cout << i << '\t';
    }
    cout << '\n';

    cout << "Weights : \t";
    for (i = 1; i< numberofitems; i++)
    {
        cout << weights[i] << '\t';
    }
    cout << '\n';

    cout << "Values : \t";
    for (i = 1; i< numberofitems; i++)
    {
        cout << values[i] << '\t';
    }
    cout << '\n';

}


// This function takes input(Weight, Value) of items in separate array from the terminal
void GetInput(int numberofitems, int weights[], int values[])
{

    int iter;
    weights[0] = 0;
    values[0] = 0;
    cout << "######## Enter the values separated by SINGLE SPACE ########" << '\n';
    for (iter = 1; iter < numberofitems; iter++)
    {
        cout <<"Enter the weight and value of " << iter << "th item in list: \t";   //take inputs from user
        cin >> weights[iter];
        cin >> values[iter];

    }
    
    cout << "\nInput Values in the array are: \n";  
    
    //Display the contents at those locations
    Show(numberofitems, weights, values);

}


// To sort the input items in increasing order of weights.
void SelectionSort(int numberofitems, int weights[], int values[])  
{  
    int i, j, minimum;  
  
    // One by one reduce elements of unsorted subarray
    //Our array starts at 1.  
    for (i = 1; i < numberofitems; i++)  
    {  
        // init the minimum element in unsorted array  
        minimum = i;  
        for (j = i+1; j < numberofitems; j++)  
        {
            //Check if unsorted array has element less than initialized minimum
            if (weights[j] < weights[minimum])  
            {
                //If such element is found, make it the new minimum
                minimum = j;  
            }
        }
        // Swap the found minimum element with the previous min element  
        int weight_tmp = weights[minimum];
        int value_tmp = values[minimum];
        weights[minimum] = weights[i];
        values[minimum] = values[i];
        weights[i] = weight_tmp;
        values[i] = value_tmp;

    }
    cout << "\n\nSorted values are:" << '\n';
    Show(numberofitems, weights, values);
}


// To print the knapsack table on terminal
void PrintTable(int numberofitems, int weights[], int values[], int capacity, int table[][1000])
{
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << '\n';
    //print subroutine
    cout << "Capacity ------------->     \t| ";
    for (int i = 0; i <= capacity; i++)
    {
        cout << i << '\t';
    }
    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    for (int i = 1; i < numberofitems; i++)
    {
        cout << '\n';
        cout << "(index = "<< i << ", " << "V = "<< values[i] << ", " << "W= " << weights[i] << ")";
        cout << "\t| ";
        for(int j = 0; j <= capacity; j++)
        {
            cout << table[i][j] << '\t';
        }
    }
    cout <<"\n\n\n";
} 



// funtion for Initialization and filling of knapsack
void DynamicKnapsack(int numberofitems, int weights[], int values[], int capacity, int table[][1000])
{         
        
    //initialize table (initializing all empty places to -1)
    for (int i = 0; i < numberofitems; i++)
    {
        
        for(int j = 0; j <= capacity; j++)
        {
            if (j == 0 || i == 0)
            {
                table[i][j] = 0;    
            }

            else
            {
                table[i][j] = -1;
            }
        }
    }

    //Initializing empty locations of table to -1
    cout << "\n\n############### THE KNAPSACK TABLE - INITIALIZATION ###############" << '\n';
    PrintTable(numberofitems, weights, values, capacity, table);
     

    for(int ItemIndex = 1; ItemIndex < numberofitems; ItemIndex++)
    {
        for(int size = 1; size <= capacity; size++)
        {
            //include item only if it increases the current optimal result
            if(weights[ItemIndex] <= size)
            {
                table[ItemIndex][size] = max(table[ItemIndex-1][size-weights[ItemIndex]] + values[ItemIndex], table[ItemIndex-1][size]);
            }
 
            //if it doesnt; you can not include the current item in this case
            else
            {
                table[ItemIndex][size] = table[ItemIndex-1][size];
            }

            // cout << "Item:" << ItemIndex  << "\tV[item]:" << values[ItemIndex] << "\tW[item]:" << weights[ItemIndex] << "\tsize:" << size << "\tprevious max:" << table[ItemIndex-1][size] << "\tcurrent max:" << table[ItemIndex][size] << '\n';
        }

        // cout << "---------------------------------------------------------------------------------\n";
    }
    cout << "\n\n############### THE KNAPSACK TABLE - POPULATED ###############" << '\n';
    PrintTable(numberofitems, weights, values, capacity, table);
}



//funtion ro find out the items contributing to the final value of the knapsack
void FindItems(int numberofitems, int weights[], int values[], int capacity, int table[][1000], int finalitems[]) 
{ 

    // as the result comes from (table[ItemIndex-1][size-weights[ItemIndex-1]] + values[ItemIndex-1]) or from the top (table[ItemIndex-1][size]) as in Knapsack table.
    // If result comes after adding the value, i.e, the second part, the item is included.
    int result = table[numberofitems-1][capacity];
    int size = capacity; 

    cout << "The maximum value of knapsack (capacity = " << capacity <<") is:\t" << result << '\n'; 
     
    for (int ItemIndex = numberofitems-1; ItemIndex > 0; ItemIndex--)
    { 
        if (result > 0)
        {
            //This item is not included as result is same as the item before
            if (result == table[ItemIndex-1][size])
            {
                //as this item is not included assigning -1 to finalitems[ItemIndex]
                finalitems[ItemIndex] = -1;
                continue;  
            }  
                                    
            else
            { 
                //item is included. 
                finalitems[ItemIndex] = ItemIndex;  
                // backtrack the size by reducing the weight of the taken item; also, reduce the final result
                result = result - values[ItemIndex]; 
                size = size - weights[ItemIndex];
            }
        }
    }
}



int main()
{
    int NumberOfItems;
    cout << "\nEnter the total number of Items" << '\n';
    cin >> NumberOfItems;
    NumberOfItems = NumberOfItems +1;
    
    int Weights[NumberOfItems];
    int Values[NumberOfItems];

    GetInput(NumberOfItems, Weights, Values);

    cout << "\nSorting input in increasing order of weights" << '\n';
    SelectionSort(NumberOfItems, Weights, Values);

    int Capacity;
    cout << "Enter the capacity(weight) of 0/1 knapsack" << '\n';
    cin >> Capacity;
    int Table[NumberOfItems][1000];
    int FinalItems[NumberOfItems];


    // int NumberOfItems = 4;
    // NumberOfItems = NumberOfItems +1;
    // int Weights[NumberOfItems] = {0, 1, 3, 4, 5};
    // int Values[NumberOfItems] = {0, 1, 4, 5, 7};
    // int Capacity = 7;
    // int Table[NumberOfItems][1000];
    // int FinalItems[NumberOfItems];

    DynamicKnapsack(NumberOfItems, Weights, Values, Capacity, Table);
    FindItems(NumberOfItems, Weights, Values, Capacity, Table, FinalItems);
    
    cout << "The final items in the knapsack are:" << '\n';
    for (int i = 1; i < NumberOfItems; i++)
    {
        if (FinalItems[i] == i)
        {
            cout << "Item Index:\t" << FinalItems[i] << "\tWeight:\t"<< Weights[FinalItems[i]] << "\tValue:\t"<< Values[FinalItems[i]] << '\n';
        }
    }

}
