/*
November 14, 2019 00:10

Onkar Kulkarni

C++ code for the greedy algorithm you propose in Q2 D

Run code using following command:
g++ GreedyCoins_2D.cpp -o GreedyCoins_2D.exe
GreedyCoins_2D.exe

*/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>



using namespace std; 

//funciton to sort user input denominations in descending order
void SelectionSort(int arr[], int length)  
{  
    int i, j, maximum;

    for (i = 0; i < length; i++)  
    {  
        // init the maximum element in unsorted array  
        maximum = i;  
        for (j = i+1; j < length; j++)  
        {
            //Check if unsorted array has element less than initialized maximum
            if (arr[j] > arr[maximum])  
            {
                //If such element is found, make it the new maximum
                maximum = j;  
            }
        }
        // Swap the found maximum element with the previous min element using a temporary variable.
        int tmp = arr[maximum];
        arr[maximum] = arr[i];
        arr[i] = tmp;
    }
}


// Main function
int GreedyCoins_2D(int amount, int denominations[], int count[])
{
    
    // initially zero coins
    int coins = 0;

    int index = 0;

    cout << "\n\n----------------------------------- The Greedy Selection ---------------------------------------------------\n";
    while (amount > 0 )
    {

        // check if amount is greater than or equal to the largerst denomination;
        // as the denominations are sorted, largerst denomination will be the first element of array
        if(amount >= denominations[index])
        {
            cout << "Current Amount:\t" << amount << "\tCurrent Denomination:\t" << denominations[index] << " cents\t" << "\tCoins so far:\t" << coins+1 <<'\n';
            
            // if it is, then substract the denominations from amount
            amount = amount - denominations[index];

            // increament the number of coins of that denomination by one
            count[index] = count[index] +1;

            // increament total number of coins by one
            coins++; 
        }

        // else, reduce the denomination to a lower value (subproblem) one as amount is greater than the current denomination
        else
        {
            index = index+ 1;
        }

    }

    cout << "--------------------------------------------------------------------------------------\n";
    cout << "--------------------------------------------------------------------------------------\n";

    return coins;
}


int main()
{
    cout << "########## GreedyCoins_2D 2D ##########" << '\n';
    
    int Amount;
    int number_of_denominations;
    int Total_Coins;

    cout << "Enter the amount in cents" << '\n';
    cin >> Amount;
    
    cout << "How many denominations?" << '\n';
    cin >> number_of_denominations;

    // Initialize array to store denominations
    int Denominations[number_of_denominations];

    //initializing an array for count of each denomination
    int Count[number_of_denominations];
    
    // Take inputs for denominations
    for (int i = 0; i < number_of_denominations; i++)
    {
        cout << "Enter " << i+1 << "th denomination"<< "\t";

        //initializing an array for count of each denomination as zero to begin with
        cin >> Denominations[i];
        Count[i] = 0;    
    }

    // Sort the user input in descending order
    SelectionSort(Denominations, number_of_denominations);

    // This will store the total amount of coins needed
    Total_Coins = GreedyCoins_2D(Amount, Denominations, Count);

    // Display the values on terminal
    cout << "\n\nThe amount\t'" << Amount <<"'\tCan be represented by min\t'"<< Total_Coins << "'\tnumber of coins" << '\n';
    cout << "The coin denominations are: " << '\n';
    for (int i = 0; i < number_of_denominations; i++)
    {
        cout << '\t' << Count[i] << "\tCoins of\t"  << Denominations[i] << '\n';
    }
}