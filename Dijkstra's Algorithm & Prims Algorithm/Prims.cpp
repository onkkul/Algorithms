/*December 05, 2019 10:10

Onkar Kulkarni

C++ code for Prims Algorithm

make okulkar4
*/

#include <iostream>
#include <limits.h> 
#include <stdio.h> 
#include<iomanip>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

# define black true
# define white false

// (Source Destination) Pair as edge
typedef pair<int, int> Edge; 


class Prims 
{ 
    int size; // No. of vertices 

    // as weighted graph, we need to store
    // source, destination and weight(edge)
    list< pair<int, int> > *adj;

    public: 
        Prims(int size); 

        void addEdge(int size); 

        void MST(); 
};

// Creating the adjecancy list
Prims::Prims(int size) 
{ 
    this->size = size; 
    adj = new list<Edge> [size]; 
} 


// Adding edges to the graph
void Prims::addEdge(int size) 
{ 
    int counter = 0;
    cout << "Nodes are named 0 through " << size-1 << "\nEnter -999 to breaK\n";
    int source, destination, weight;
    while(source != -999)
    {
        cout << "Add " << counter <<"th edge(source, destination, Edgeweight)" << '\n';
        cin >> source;
        if(source == -999)
        {
            break;
        }
        cin >> destination;
        cin >> weight;

        if((0 <= source && source < size) && (0 <= destination && destination < size))
        {
            adj[source].push_back(make_pair(destination, weight)); 
            adj[destination].push_back(make_pair(source, weight)); 
        }
        else
            cout << "Enter valid nodes" << '\n';
        counter++;
    }
} 

// Prints shortest paths from src to all other vertices 
void Prims::MST() 
{ 
    // starting from 0th node
    int src = 0;

    // Create a priority queue to store vertices in MST
    priority_queue< Edge, vector <Edge> , greater<Edge> > pq;

    // To store Prims MST array 
    vector<int> WeightedGraph(size, -1); 

    // Create a vector for keys and initialize all 
    // keys as infinite (INT_MAX) 
    vector<int> key(size, INT_MAX); 
    vector<bool> color(size, white); 

    // Insert source itself in priority queue and initialize 
    // its key as 0. 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 

    // Looping till priority queue empty
    while (!pq.empty()) 
    {
        // extract the node using the weights as key in queue
        int u = pq.top().second; 
        pq.pop(); 

        color[u] = black; // Include vertex in MST 

        // get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
 
            // for untraced node, add it to covered set
            if (color[v] == white && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                WeightedGraph[v] = u; 
            } 
        } 
    }

    // Print MST
    cout << "\nMST using Prims Algo..." << '\n';
    for (int i = 1; i < size; ++i)
    {
        printf("%d -> %d\n",WeightedGraph[i], i); 
        printf("  /   \n");
    }

    cout << "-------------------------------------------------------" << '\n';
} 
