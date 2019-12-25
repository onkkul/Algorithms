/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
#include<typeinfo>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
    BST intBST;           // test the class constructor
 	// AVL AVL_BALANCE; 
    cout << "\nConstructing empty BST\n";

    int number;
    int choise = 0;

        // int arr[15] = {50, 25, 75, 12, 36, 62, 86, 6, 18, 30, 42, 56, 68, 80, 92};
 //    // int arr[9] = {41, 20, 65, 11, 29, 50, 26, 23, 55};
 //    int arr[6] = {10,20,30,40,50,25};
 //    for (int i = 0; i<6;i++)
 //    {

 //       	intBST.myRoot = intBST.insert(intBST.myRoot, arr[i]);
 //    }

 //    intBST.preOrder(intBST.myRoot);
 //    cout << '\n';
    
 //    for (int i = 0; i<6;i++)
 //    {
 //    	cout << "deletingg  " << arr[i]<< '\n';
	//     intBST.myRoot = intBST.nodeDelete(intBST.myRoot, arr[i]);
	//         intBST.preOrder(intBST.myRoot);
 //    cout << '\n';
	// }

 //    intBST.preOrder(intBST.myRoot);
 //    cout << '\n';

    // intBST.calculateImbalance(intBST.myRoot);
    // cout << '\n';

    while (choise < 7)
    {
    	cout << "### BST is Balanced using AVL after every Insertion/Deletion" << '\n';
        cout << "\n1. Inset elements" << '\n';
        cout << "2. Search elements" << '\n';
        cout << "3. Traverse Tree" << '\n';
        cout << "4. Count Nodes in the tree" << '\n';
        cout << "5. Delete Node" << '\n';
        cout << "6. Close Program" << '\n';
        cout << "\nPlease enter your choise:\t";
        cin >> choise;

        switch(choise)
        {
            case 1:
                for(;;)
                {
                    cout << "\nItem to insert (-999 to stop):\t";
                    cin >> number;

                    if (number == -999)
                    {
                        cout << "\n-------------------------------------------\n";
                        break;
                    }

                    intBST.myRoot = intBST.insert(intBST.myRoot, number);
                }
                break;

            case 2:
                cout << "\nSearching elements in the tree\n";
                cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
                
                for (;;)
                {
                    cout << "\nItem to find (-999 to stop):\t";
                    cin >> number;

                    if (number == -999)
                    {
                        cout << "\n-------------------------------------------\n";
                        break;
                    }

                    cout << (intBST.search(number) ? "Number Found" : "NUmber Not found") << endl;
                }

                break;

            case 3:
                cout << "\n----- PREORDER TRAVERSAL OF TREE -----\n";
                intBST.preOrder(intBST.myRoot);
                cout << "\n";

                cout << "\n----- INORDER TRAVERSAL OF TREE -----\n";
                
                intBST.inOrder(intBST.myRoot);
                cout << "\n";

                cout << "\n----- POSTORDER TRAVERSAL OF TREE -----\n";
                intBST.postOrder(intBST.myRoot);
                cout << "\n-------------------------------------------\n";

                break;

            case 4:
                int nodes;
                cout << "\n----- NODE COUNT OF TREE -----\n";
                nodes = intBST.nodeCount(intBST.myRoot);
                cout <<nodes;
                cout << "\n-------------------------------------------\n";
                break;

            case 5:
                
                if(intBST.empty())
                {
                    cout << "BST is Empty\n";
                    break;
                }
                
                cout << "Nodes in the tree are:" << '\n';
                intBST.inOrder(intBST.myRoot);
                
                while(!intBST.empty())
                {
                    cout << "\nEnter the node you want to Delete(-999 to stop):" << '\t';
                    cin >> number;
                    if(number == -999)
                    {
                        cout << "\n-------------------------------------------\n";
                        break;
                    }

                    intBST.myRoot = intBST.nodeDelete(intBST.myRoot, number);

                    cout << "Tree after Deletion is:" << '\n';
                    if(intBST.empty())
                    {
                        cout << "Empty" << '\n';
                        cout << "\n-------------------------------------------\n";
                        break;
                    }
                    else
                    {
                        intBST.inOrder(intBST.myRoot);
                        cout << '\n';
                    }
                }

                break;

            case 6:
                choise = 10;
                break;
        }
    }

 //    cout << "\nAVL" << '\n';
 //    intBST.preOrder(intBST.myRoot);

 //    intBST.myRoot->height = intBST.calculateImbalance(intBST.myRoot);

	// intBST.preOrder(intBST.myRoot);
	// cout << "\nunbalanced tree" << '\n';

 //    intBST.balance_tree(intBST.myRoot);

 //    cout << "Balanced tree" << '\n';
 //    intBST.preOrder(intBST.myRoot);
 //    cout << '\n';

    return 0;   

}