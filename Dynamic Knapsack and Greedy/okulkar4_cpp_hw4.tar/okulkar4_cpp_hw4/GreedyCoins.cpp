#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std; 


int GreedyCoins(int amount, int denominations[], int count[])
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
