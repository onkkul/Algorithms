/*December 05, 2019 10:10

Onkar Kulkarni

driver code for Dijkstra & Prims Algorithm

make okulkar4
*/

#include <limits.h> 
#include <stdio.h> 
#include <iostream>
#include<iomanip>
#include<typeinfo>

#include "Dijkstra.cpp"
#include "Prims.cpp"


int main() 
{
	int size, choice = 0;
	cout << "Enter the number of nodes : " << '\t';
	cin >> size;

	while (choice <= 3)
	{
		cout << "\n\n1. Dijkstra's algorithm" << '\n';
		cout << "2. Prims algorithm" << '\n';
		cout << "3. Exit" << '\n';
		cout << "Enter your choice(1/2): " << '\n';
		cin >> choice;

		int source;
		int graph[size][500];
	    Prims p(size);

		switch(choice)
		{	
		    case 1:
			    getInput(size, graph);
			    cout << "Enter the source" << '\n';
			    cin >> source;
			    dijkstra(size, graph, source);
			    break;

			case 2: 
			    p.addEdge(size); 
			    p.MST();
			    break;

			case 3:
				choice = 6;
				break;
				return 1;
		}
	}
    return 0; 
} 