/*
November 25, 2019 10:10

Onkar Kulkarni

C++ code for the findLCS

Run code using following command:
g++ findLCS.cpp -o findLCS.exe
*/

#include <cmath>
#include <iostream>
#include <stdio.h>
#include<string.h>


using namespace std; 

void ViewTable(char first_arr[], int first_length, char second_arr[], int second_length, int table[][10000])
{
    int i,j;

    cout << "\t ";
    for (j = 0; j < second_length; j++)
    {
        cout << second_arr[j] << "\t";
    }
    cout << "\n-------------------------------------------------------------------------\n";

    for (i = 0; i < first_length; i++)
    {
        cout << first_arr[i] << "\t|";
        for (j = 0; j < second_length; j++)
        {
            cout << table[i][j] << '\t';
        }
        cout << '\n';
    }

    cout << '\n';
}


int findLCS(char first_arr[], int first_length, char second_arr[], int second_length, int table[][10000])
{

    int i,j,temp = 0;
    int longestCS = 0;

    //Initialization of table
    for (i = 0; i < first_length; i++)
    {
        for (j = 0; j < second_length; j++)
        {
            

            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }

            else
            {
                table[i][j] = -1;
            }
        }
    }

    //display table after initialization
    cout << "##### The LCS table initialized #####" << '\n';
    ViewTable(first_arr, first_length, second_arr, second_length, table);

    for(int i = 1; i < first_length; i++)
    {
        for(int j = 1; j < second_length; j++)
        {
            //check if charecters match
            //include charecter only if it increases the current optimal result(i.e. it has not been used before)
            if(first_arr[i] == second_arr[j])
            {
                table[i][j] = max(table[i-1][j-1] + 1, table[i-1][j]);
            }
 
            //if it doesnt; you can not include the current charecter in this case
            else
            {
                table[i][j] = max(table[i-1][j], table[i][j-1]);

            }

            longestCS = table[i][j];
        }

        //display each step of the table as it is populated
        // ViewTable(first_arr, first_length, second_arr, second_length, table);
    }

    //display final table
    cout << "##### The LCS table populated #####" << '\n';
    ViewTable(first_arr, first_length, second_arr, second_length, table);

    return longestCS;
    
}


void findMembers(char first_arr[], int first_length, char second_arr[], int second_length, int table[][10000], char finalitems[])
{
    // as the result comes from table[i][j] = max(table[i-1][j-1] + 1, table[i-1][j]) or from the top max(table[i-1][j], table[i][j-1]) as in table.
    // If result comes after including the charecter, i.e, the first part, the item is included.
    int result = table[first_length-1][second_length-1];
    int j = second_length-1; 
    char ch = '-';
    for (int i = first_length-1; i > 0; i--)
    { 
        if (result > 0)
        {
            //This charecter is not included as result is same as the charecter before
            if (result == table[i-1][j])
            {
                //as this item is not included assigning default value to finalitems[i]
                finalitems[i] = ch;
                continue;  
            }  
                                    
            else
            { 
                //item is included. 
                finalitems[i] = first_arr[i];  
                // backtrack the j by reducing the size of the taken subsequence; also, reduce the final result
                result = result - 1; 
                j = j - 1;
            }
        }
    }
}


int main()
{

    string str1, str2, first_string, second_string;
    cout << "Enter first string" << '\n';
    cin >> str1;

    cout << "Enter second string" << '\n';
    cin >> str2;

    // str1 = "binghamton";
    // str2 = "bearcats";

    //adding constant at 0th location in the string
    first_string = "-" + str1;
    second_string = "+" + str2;

    //calculate the lengths of each string
    int first_length = first_string.length();
    int second_length = second_string.length();
    int temp_max = (first_length >= second_length)? first_length:second_length;

    char first_arr[first_length];
    char second_arr[second_length];
    char finalitems[temp_max];
    char ch= '-';       //default value for charecter array holding the final result

    int i, j;
    int LognestCS = 0;                  //length of longest common subsequence
    int Table[first_length][10000];     //dynamic table to hold LCS
    
    //copy the string components into an array
    //also, initialize the finalitems[] to default value
    for (i = 0; i <= first_length; i++)
    { 
        first_arr[i] = first_string[i]; 
        finalitems[i] = ch;
    } 

    for (j = 0; j <= second_length; j++)
    { 
        second_arr[j] = second_string[j];
        finalitems[j] = ch;
    } 


    LognestCS = findLCS(first_arr, first_length, second_arr, second_length, Table);


    findMembers(first_arr, first_length, second_arr, second_length, Table, finalitems);


    cout << "\n##### The Longest Common Subsequence #####" << '\n';
    cout << "\nFirst String : \t'" << str1 << "'\tSecond String :\t'" << str2 << "'\n";
    cout << "\nLength of LCS : \t" << LognestCS << '\n';
    cout << "\nThe LCS is :" << '\t';
    for (i = 0; i < temp_max; i++)
    {
        // finalitems[i];
        if(finalitems[i] != '-')
        {
            cout << finalitems[i] << '\t';
        }
    }

    cout <<"\n\n";

    return 0;
}