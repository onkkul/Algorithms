#include <iostream>
#include<typeinfo>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST(): myRoot(0)
{
}


bool BST::empty() const
{ 
    return myRoot == 0; 
}


bool BST::search(const int & item) const
{
    BinNode * locptr = myRoot;
    bool found = false;
    int temp = 0;
    while (!found && locptr != 0)
    {
        if (item < locptr->data) 
        {      // descend left
            temp = locptr->data;
            locptr = locptr->left;
        }
    
        else if (locptr->data < item)  // descend right
        {
            temp = locptr->data;
            locptr = locptr->right;
        }
    
        else                           // item found
        {
            cout << item << (locptr == myRoot? "\tis root of tree.\t":"\tis child of\t") << temp << '\n';
            found = true;
        }
    }
    return found;
}


BST::BinNode* BST::insert(BST::BinNode* name, const int & item)
{
    BinNode * locptr = name;   // search pointer

    if (BST::empty())
    {
        cout << "inserted at root" << '\n';
        locptr = new BinNode(item);
        myRoot = locptr;
        return myRoot;
    }

    else
    {
        if (locptr == 0)
        {
            locptr = new BinNode(item);
        }

        if(item < locptr->data)
        {
            locptr->left = BST::insert(locptr->left, item);
        }

        else if(item > locptr->data)
        {
            locptr->right = BST::insert(locptr->right, item);
        }

        else
        {   
            return locptr;
        }

        myRoot->imbalance = BST::calculateImbalance(myRoot);

        int imbalance = locptr->left_height - locptr->right_height;

        if(imbalance > 1 && item < locptr->left->data)
        {
            return BST::rotateRight(locptr);
        }
      
        // Right Right Case  
        if (imbalance < -1 && item > locptr->right->data)  
            return rotateLeft(locptr);  
      
        // Left Right Case  
        if (imbalance > 1 && item > locptr->left->data)  
        {  
            locptr->left = rotateLeft(locptr->left);  
            return rotateRight(locptr);  
        }  
      
        // Right Left Case  
        if (imbalance < -1 && item < locptr->right->data)  
        {  
            locptr->right = rotateRight(locptr->right);  
            return rotateLeft(locptr);  
        }  
    }
    
    // return node
    return locptr;  
}


void BST::preOrder(BST::BinNode* name)
{
    BinNode * locptr = name;

    // first print the current node
    cout << locptr->data << '\t';

    // explore the left subtree
    if (locptr->left != 0)
    {
        BST::preOrder(locptr->left);
    }    

    // explore the right subtree
    if(locptr->right != 0)
    {        
        BST::preOrder(locptr->right);
    }

    // if no subtree found, return to parent level
    else
    {
        return;
    }
}


void BST::inOrder(BST::BinNode* name)
{
    BinNode * locptr = name;

    // first explore the left subtree
    if (locptr->left != 0)
    {
        BST::inOrder(locptr->left);
    }

    //print the node of subtree
    cout << locptr->data << '\t';

    // explore the right subtree
    if(locptr->right != 0)
    {        
        BST::inOrder(locptr->right);
    }

    // if there is no more left or right subtree present
    // return to the higher level
    else
    {
        return;
    }
}


void BST::postOrder(BST::BinNode* name)
{
    BinNode * locptr = name;    // search pointer, initially at the root of tree

    // recursively call postOrder() on the left subtree
    if (locptr->left != 0)
    {
        BST::postOrder(locptr->left); 
    }

    // recursively call postOrder() on the right subtree
    if(locptr->right != 0)
    {        
        BST::postOrder(locptr->right);
    }

    // print parent at last
    cout << locptr->data << '\t';

}


int BST::nodeCount(BST::BinNode* name)
{
    BinNode * locptr = name;
    BinNode * parent = 0;
    int nodes_number = 0;
    bool Empty_Root;

    BST::empty() ?  Empty_Root = true: Empty_Root = false;

    // count only if tree is not empty
    if (Empty_Root == false)
    {
        nodes_number = 1;

        // recursively explore the left subtree to count nodes
        if (locptr->left != 0)
        {
            nodes_number = nodes_number + BST::nodeCount(locptr->left); 
            
        }

        // recursively explore the right subtree to count node
        if(locptr->right != 0)
        {        
            nodes_number = nodes_number + BST::nodeCount(locptr->right);
        }

    }

    // if tree is empty, return default value of zero
    else
    {
        cout << "Tree Empty" << '\n';
    }

    return nodes_number;
 
}


BST::BinNode* BST::nodeDelete(BST::BinNode* name, const int & item)
{
    BinNode * locptr = name;   // search pointer
    BinNode * temp;

    if(BST::empty())
    {
        return 0;
    }

    if (locptr == 0)
    {
        locptr = 0;
        return 0;
    }  

    if(item < locptr->data)
    {
        // cout << "Going left of " << locptr->data << '\n';
        locptr->left = BST::nodeDelete(locptr->left, item);
    }
    
    
    else if(item > locptr->data)
    {
        // cout << "Going right of " << locptr->data << '\n';
        locptr->right = BST::nodeDelete(locptr->right, item);
    }

    else
    {   
        // node with only one child or no child  
        if((locptr->left == 0) || (locptr->right == 0))  
        {  
            
            BinNode * temp = (locptr->left)? locptr->left : locptr->right;  


            // No child case  
            if (temp == 0)  
            {

                // temp = locptr;  
                locptr = 0;
                return 0;
            }  

            else // One child case  
            *locptr = *temp; // Copy the contents of the child 
            free(temp);   
        }  
        else
        {  
            BinNode * temp = locptr->right;
            
            while (temp->left !=0)
            {               
                temp = temp->left;
            }

            // we found the inorder successor
            // now copy the data from that node
            int temp_data = temp->data;
            locptr->data = temp_data;
            //now delete the inorder succesor
            if(BST::nodeCount(myRoot) > 3)
            {
                BST::nodeDelete(locptr->right, temp->data);
            }

            else
            {
                if (locptr->data != 0)
                {
                    locptr->data = locptr->right->data;
                    locptr->right = 0;
                }                
            }            
        }
    }  

    // If the tree had only one node 
    // then return  
    if (locptr == 0)  
    {
        locptr = 0;
        return 0;      
    }

    myRoot->imbalance = BST::calculateImbalance(myRoot);

    int left_height =0, right_height = 0;
    int left_left_height = 0, left_right_height = 0;
    int right_left_height = 0, right_right_height = 0;
    
    if (locptr->left != 0)
    {
        left_height= locptr->left_height;
            
        if (locptr->left->left != 0)
            left_left_height = locptr->left->left_height;
        
        if(locptr->left->right != 0)
            left_right_height = locptr->left->right_height;
    }

    if (locptr->right != 0)
    {
        right_height = locptr->right_height;
        
        if(locptr->right->left != 0)
            right_left_height = locptr->right->left_height;

        if(locptr->right->right != 0)
            right_right_height = locptr->right->right_height;
    }

    int imbalance = left_height - right_height;
    int leftChild_imbalance =  left_left_height - left_right_height;
    int rightChild_imbalance =  right_left_height - right_right_height;
    
    
    //left left case
    if(imbalance > 1 && leftChild_imbalance >= 0)
    {
        return BST::rotateRight(locptr);
    }
  
    // left - right case 
    if(imbalance > 1 && leftChild_imbalance < 0)
    {
        locptr->left = rotateLeft(locptr->left);
        return rotateRight(locptr);  
    }
  
    // Right Right Case  
    if (imbalance < -1 && rightChild_imbalance <= 0)  
    {  
        return rotateLeft(locptr);  
    }  
  
    // Right Left Case  
    if (imbalance < -1 && rightChild_imbalance > 0)  
    {            
        locptr->right = rotateRight(locptr->right);  
        return rotateLeft(locptr);  
    }  

    // return the pointer
    return locptr;
}


//calculates imbalances; return heights
int BST::calculateImbalance(BST::BinNode* name)
{
    BinNode * locptr = name;

    int left_height = 0;
    int right_height = 0;
    int difference;
    bool Empty_Root;

    BST::empty() ?  Empty_Root = true: Empty_Root = false;

    // count only if tree is not empty
    if (Empty_Root == false)
    {
        // recursively explore the left subtree to count height
        if (locptr->left != 0)
        {
            left_height = 1 + BST::calculateImbalance(locptr->left); 
            
        }

        // recursively explore the right subtree to count height
        if(locptr->right != 0)
        {        
            right_height = 1 + BST::calculateImbalance(locptr->right);
        }

        locptr->height = max(left_height, right_height);
        locptr->left_height = left_height;
        locptr->right_height = right_height;
        
        return max(left_height, right_height);        
    }

    // if tree is empty, return default value of zero
    else
    {
        cout << "Tree Empty" << '\n';
        return 0;
    }

    return max(left_height, right_height);
}


BST::BinNode* BST::rotateRight(BST::BinNode* parent)
{
    cout << "Rotating " << parent ->data <<"right" << '\n';
    BinNode * leftChild = parent->left;
    BinNode * temp = leftChild->right;
    
    leftChild->right = parent;
    parent->left = temp;

    BST::calculateImbalance(parent);
    BST::calculateImbalance(leftChild);

    return leftChild;
}


BST::BinNode* BST::rotateLeft(BST::BinNode* parent)
{
    cout << "Rotating " << parent ->data <<"left" << '\n';
    BinNode * rightChild = parent->right;
    BinNode * temp = rightChild->left;
    rightChild->left = parent;
    parent->right = temp;

    BST::calculateImbalance(parent);
    BST::calculateImbalance(rightChild);

    return rightChild;
}

