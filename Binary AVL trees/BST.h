#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE


class BST
{
	public:

		/***** Function Members *****/
		BST();
		bool empty() const;
		bool search(const int & item) const; 
        

		// public:
		/***** Node class *****/
		class BinNode 
		{
			public:
			    int data;
			    int left_height;
			    int right_height;
			    int height;
			    int imbalance;
			    BinNode * left;
			    BinNode * right;

		    // BinNode constructors
		    // Default -- data part is default int value; both links are null.
		    BinNode(): left(0), right(0), imbalance(0)
		    {

		    }

		    // Explicit Value -- data part contains item; both links are null.
		    BinNode(int item): data(item), left(0), right(0), imbalance(0)
		    {

		    }
		};// end of class BinNode declaration


		/***** Data Members *****/
        BinNode * myRoot;
        BinNode * locptr = 0;
        BinNode * grandlocptr = 0;

		BST::BinNode* insert(BST::BinNode* name, const int & item);
		BST::BinNode* nodeDelete(BST::BinNode* name, const int & item);


        void preOrder(BST::BinNode* name);
        void inOrder(BST::BinNode* name);
        void postOrder(BST::BinNode* name);

        int nodeCount(BST::BinNode* name);
        int calculateImbalance(BST::BinNode* name);

    	BST::BinNode* rotateRight(BinNode* name);
      	BST::BinNode* rotateLeft(BinNode* name);

};
// end of class declaration

#endif

