/*
November 13, 2019 17:10

Onkar Kulkarni

C++ code for the greedy algorithm you propose in Q2 B
Run code using following command:
g++ GreedyCoins_2B.cpp -o GreedyCoins_2B.exe
GreedyCoins_2B.exe

*/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>



using namespace std; 

int GreedyCoins_2B(int amount, int denominations[], int count[])
{

    // initially zero coins
    int coins = 0;

    int index = 0;

    cout << "\n\n----------------------------------- The Greedy Selection ---------------------------------------------------\n";
    while (amount > 0 )
    {
        
        // check if amount is greater than or equal to the largerst denomination
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

    cout << "---------------------------------------------------------------------------------\n";
    cout << "---------------------------------------------------------------------------------\n";

    return coins;
}


int main()
{
    cout << "\n\n########## GreedyCoins_2B 2B ##########" << '\n';
    
    int Amount;
    int base;
    int exponential;
    int Total_Coins;

    cout << "Enter the amount in cents" << '\n';
    cin >> Amount;

    cout << "Enter base 'C' of denominations" << '\n';
    cin >> base;
    
    cout << "Enter exponential k" << '\n';
    cin >> exponential;

    // Initialize array to store denominations
    int Denominations[exponential];

    //initializing an array for count of each denomination
    int Count[exponential];
    
    cout << exponential << "\tDenominations of\t" << base << ":\n";

    
    for (int i = 0; i <= exponential; i++)
    {
        // Calculate all the denominations such that c^0 ...... c^k
        Denominations[i] =  pow(base, exponential - i);

        //initializing an array for count of each denomination as zero to begin with
        cout << Denominations[i] << "\t" ;
        Count[i] = 0;    
    }

    // This will store the total amount of coins needed
    Total_Coins = GreedyCoins_2B(Amount, Denominations, Count);

    // Display the values on terminal
    cout << "\n\nThe amount\t'" << Amount <<"'\tCan be represented by min\t'"<< Total_Coins << "'\tnumber of coins" << '\n';
    cout << "The coin denominations are: " << '\n';
    for (int i = 0; i <= exponential; i++)
    {
        cout << '\t' << Count[i] << "\tCoins of\t"  << Denominations[i] << '\n';
    }
}