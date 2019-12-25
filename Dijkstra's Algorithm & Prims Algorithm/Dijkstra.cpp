/*December 05, 2019 10:10

Onkar Kulkarni

C++ code for Dijkstra Algo

make okulkar4
*/


#include <limits.h> 
#include <stdio.h> 
#include <iostream>
#include<iomanip>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

// function to print the matrix
void showgraph(int size, int arr[][500])
{
    int i, j;
    cout << "The graph is: " << '\n';
    
    cout << "\t ";
    for (i = 0; i < size; i++)
    {
        cout << i << '\t';
    }
    cout <<"\n--------------------------" << '\n';
    for (i = 0; i < size; i++)
    {
        cout << i <<"\t|";
        for(j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout << '\n';
    }
}


// Function to get user input
void getInput(int size, int arr[][500])
{
    int i, j, count, temp;

    cout << "Enter 0 if path doesn't exist)" << '\n';
    count = 0;
   
    for (i = 0; i < size; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(i != j)
            {
            
                cout << "Cost between node: " << i << " and node:" << j << '\n';
                cin >> temp;
                arr[i][j] = temp;
                arr[j][i] = temp;
                count++;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }


    showgraph(size, arr);
}


// Function to print final solution
void printSolution(int size, int sequence[], int distance[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < size; i++) 
    {
        printf("%d \t\t %d \t\t \n", sequence[i], distance[i]);
    }
} 


// Function to display the table
void displayHead(int size, int selected[], int distance[], int from[], int current_index)
{
    int i;
    const string sep = " |" ;

    const int step_width = 4;
    const int name_width = 18;
    const int int_width = 15;

    const int total_width = (int_width+2)*(size) + step_width + name_width + sep.size() * (size+ 4) ;

    const string line = sep + string( total_width, '-' );

    const string plus = sep + string( total_width, '+' );

    cout << plus << '\n' << sep << setw(step_width) << "Step" << sep << setw(name_width) << "N'";
    for (i =0; i < size; i++)
    {
        cout  << sep << setw(int_width+2) << "Vert " << i;
    }
    cout << endl << sep << setw(step_width) << "" << sep << setw(name_width) << "";
    for (i =0; i < size; i++)
    {
        cout  << sep << setw(name_width) << "D(), P()";
    } 
    cout << endl << plus;
}


// Function to display intermediate selections in table
void displayTable(int size, int sequence[], int distance[], int from[], int current_index)
{
    int count,i;

    const string sep = " |" ;
    const int step_width = 4;
    const int name_width = 18;
    const int int_width = 15;
    const int total_width = (int_width+2)*(size) + step_width + name_width + sep.size() * (size+ 4) ;
    const string line = sep + string( total_width, '-' );
    const string plus = sep + string( total_width, '+' );


    cout << endl << sep << setw(step_width) << "" << sep << setw(name_width - 2*(current_index+1));
    for (count = 0; count <= current_index; count++)
    {
        cout << sequence[count] << " ,";
    }
    for (i = 0; i < size; i++)
    {
        cout  << sep << setw(int_width) << distance[i] << ", " << from[current_index+1];
    }
    cout << endl << line << '\n' ;
}


// Functin to find minimum distance from unexplored set
int minDistance(int size, int distance[], int selected[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < size; v++) 
    {
        // if it is not in selected and distance is minimum, select that value
        if (selected[v] == 0 && distance[v] <= min) 
        {
            min = distance[v], min_index = v; 
        }
    }

    return min_index; 
} 


void updateDistance(int size, int u, int graph[][500], int distance[], int selected[], int from[])
{
    for (int v = 0; v < size; v++) 
    {
        // if the value is not in selected and is not zero or maximum
        if (!selected[v] && graph[u][v] && distance[u] != INT_MAX)
        {   
            // check if this path leads to a reduced cost
            // if cost is reduced, update the cost or keep it as it is!
            if(distance[u] + graph[u][v] < distance[v]) 
            {
                distance[v] = distance[u] + graph[u][v];
                from[v] = u;
            }
        }
    } 
}


// Main function for dijkstra's algo
void dijkstra(int size, int graph[][500], int src) 
{ 
    int distance[size];     // contains the distance of each node
    int selected[size];     // to check if a node is in selected elements
    int sequence[size];     // the cost required to reach each node and how to reach it
    int from[size+1];       // from which node, this node can be reached
    int current_src;        // the node being explored


    // Initialize all values to defaults
    for (int i = 0; i < size; i++) 
    {
        distance[i] = INT_MAX;
        selected[i] = 0;
        from[i] = 0;
    }


    // for given input, make distance to reach that node as 0
    distance[src] = 0; 
    from[src] = -1;

    // print function to print required table
    displayHead(size, selected, distance, from, 0);
    
    // for node = 0 to n, find the next node with least cost
    for (int count = 0; count <= size - 1; count++)
    { 
        current_src = minDistance(size, distance, selected);
        selected[current_src] = 1;
        sequence[count] = current_src;
        src = current_src;

        if(count < size)
            updateDistance(size, current_src, graph, distance, selected, from);
        displayTable(size, sequence, distance, from, count);
    }

    printSolution(size, sequence, distance);

    cout << "--------------------------------------------------" << '\n';
} 
