/*
November 11, 2019 11:10

Onkar Kulkarni

C++ code for the greedy algorithm I propose in Q2 A
Run code using following command:
g++ GreedyCoins_2A.cpp -o GreedyCoins_2A.exe
GreedyCoins_2A.exe

*/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std; 

int GreedyCoins_2A(int amount, int denominations[], int count[])
{

    // initially zero coins
    int coins = 0;

    int index = 0;

    cout << "\n\n----------------------------------- The Greedy Selection ---------------------------------------------------\n";
    while (amount > 0)
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
    cout << "\n\n########## GreedyCoins_2A 2A ##########" << '\n';
    
    int Amount;
    cout << "Enter the amoun in cents" << '\n';
    cin >> Amount;
    
    char names[4][20] = {"Quartrer", "Dime", "Nickel", "Penny"};
    
    // Note that denominations are sorted in reverse order.
    // Thus, denominations[0] will be largerst value and denominations[3] will be lowest
    int Denominations[4] = {25, 10, 5, 1};
    
    //initializing an array for count of each denomination as zero to begin with
    int Count[4] = {0, 0, 0, 0};

    // This will store the total amount of coins needed
    int Total_Coins;
    
    Total_Coins = GreedyCoins_2A(Amount, Denominations, Count);
    

    // Display the values on terminal
    cout << "\n\nThe amount\t'" << Amount <<"'\tCan be represented by min\t'"<< Total_Coins << "'\tnumber of coins" << '\n';
    cout << "The coin denominations are: " << '\n';
    for (int i = 0; i < 4; i++)
    {
        cout << '\t' << Count[i] << "\tCoins of\t" << names[i] << "(Coin of " << Denominations[i] << " Cents)" << '\n';
    }
}
