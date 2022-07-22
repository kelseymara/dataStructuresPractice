#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;

}
 
// put BST twice because return type node* is defined from BST class 

BST::node* BST::createLeaf(int k)
{
    node *n=new node;
    n->key=k;
    n->left=NULL;
    n->right=NULL;
    return n;
}

// all you want it to do is call addLeafPrivate function
// need this for when calling from main
// starts at root 
void BST::addLeaf(int k)
{
    addLeafPrivate(k,root);
}

void BST::addLeafPrivate(int k,node *ptr)
{
// if root is not pointing to anything (tree is empty)
    if(root==NULL)
    {
    // let root point to a newly created leaf
    root = createLeaf(k);
    }
    // if new key is less than current node key 
    else if(k < ptr->key)
    {
        // if the left pointer is pointing to something
        if(ptr->left !=NULL)
        {
            // traverse down left 
            // recursively call add leaf function
            addLeafPrivate(k,ptr->left);
        }
        else 
        // left pointer is NOT pointing to something
        {
            // add new node
            ptr -> left=createLeaf(k);
        }
    }

    else if(k > ptr->key)
    {
        // if the left pointer is pointing to something
        if(ptr->right !=NULL)
        {
            addLeafPrivate(k,ptr->right);
        }
        else 
        // right pointer is NOT pointing to something
        {
            // add new node
            ptr -> right=createLeaf(k);
        }
    }
    // new key is equal to current key
    else 
    {
        cout << "The key " << k << "has already been added to the tree" << endl;
    }
}

void BST::printInOrder()
{
// start traversal at the root
printInOrderPrivate(root);
}

void BST::printInOrderPrivate(node *ptr)
{
// if the tree is not empty
if(root!=NULL)
{
    // if left pointer is pointing to something
    if(ptr->left !=NULL)
    {
        // recursive call
        // Step One: go left 
        printInOrderPrivate(ptr->left);
    }
    // print contents of current node
    // Step Two: Process current node
    cout << ptr->key << " ";
    // Step Three: Go right if possible
    if(ptr->right !=NULL)
    {
        // recursively call 
        printInOrderPrivate(ptr->right);
    }
}
else
cout << "The tree is empty" << endl; 
}

BST::node* BST::returnNode(int k)
{
    // call return node private function
   return returnNodePrivate(k,root);
}
BST::node* BST::returnNodePrivate(int k,node *ptr)
{
    // check to see if pointer passed in is pointing to anything
    if(ptr !=NULL)
    {
        // see if current key is equal to key passed in 
        if(ptr->key == k)
        {
            // return pointer that is pointing to current node
            return ptr;
        }
        // not pointing to the right node
        else
        {
            // if key value passed in is less than key value you are looking at 
            if(k < ptr->key)
            {
                // use recursion to find it
                // Go left 
                return returnNodePrivate(k,ptr->left);
            }
            // greater than 
            else 
            {
                return returnNodePrivate(k,ptr->right);
            }
        }
    }
    else
    return NULL;
}
    

int BST::returnRootKey()
{
    if(root!=NULL)
    {
        return root->key;
    }
    else
    throw nullptr;
   // return NULL;
}

void BST::printChildren(int k)
{
    // create node pointer
    node *ptr=returnNode(k);
    if(ptr!=NULL)
    {
        cout << "Parent Node = " << ptr->key << endl;

        // conditional operator
        // if true, executes code 1
        // if false, executes code 2
        ptr->left==NULL?
        cout << "Left Child = NULL\n" : // code 1 , notice the : not ; 
        cout<< "Left Child = " << ptr->left->key << endl;  // code 2

         ptr->right==NULL?
        cout << "Right Child = NULL\n" : // code 1 , notice the : not ; 
        cout<< "Right Child = " << ptr->right->key << endl;  // code 2

    }
    else
    {
        cout << "Key " << k << " is not in the tree\n";
    }

}

int BST::findSmallestPrivate(node *ptr)
{
    if(root==NULL)
    {
        cout << "The tree is empty\n";
        throw nullptr;
    }
    else
    {
        // if left ptr is pointing to a node, recursively traverse down
        if(ptr->left!=NULL)
        {
        return findSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
    
}

int BST::findSmallest()
{
   return findSmallestPrivate(root);
}

void BST::removeNodePrivate(int k,node *parent)
{
    if(root!=NULL)
    {
        if(root->key==k)
        cout <<"Root found. Write a function to remove." << endl;
       // removeRootMatch(); // function not written yet
       else
       {
        // look at left child
        // if key want to remove has a value less than current nodes key
        if(k<parent->key && parent->left !=NULL)
        {
            // if parent's left child contains 
            // key value equal to key we're trying to delete
            parent->left->key==k?
            removeMatch(parent,parent->left,true):
            removeNodePrivate(k, parent->left);
        }
        else if (k>parent->key && parent->right !=NULL)
        {
            parent->right->key==k?
           removeMatch(parent,parent->right,false): // false bc right child 
            // recursively mode down right pointer
            removeNodePrivate(k, parent->right);
        }
        else 
        {
            cout << "The key " << k << " was not found in the tree\n";
        }
       }
    }

    else
    {
        cout << "The tree is empty\n";
    }
}

void BST::removeNode(int k)
{
    // start at the root 
    removeNodePrivate(k,root);
}

void BST::removeRootMatch()
{
    if(root!=NULL)
    {
        node *delPtr=root;
        int rootKey=root->key;
        int smallestInRightSubtree;

        //Case: 0 Children
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            delete delPtr;
        }
        // Case: 1 child 
        // left pointer NOT pointing to a node but the right pointer is
       // (root pointer attached to right pointer but not left)
        else if(root->left==NULL && root->right!=NULL)
        {
            root = root->right;
            delPtr->right=NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << " The new root contains key " << root->key << endl;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            root = root->left;
            delPtr->left=NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << " The new root contains key " << root->key << endl;
        }
        // Case: 2 Children
        else
        {
            smallestInRightSubtree= findSmallestPrivate(root->right);
            // deleting node that is smallest in root's right subtree then take the value in that node and overwrite root node with smallest value in root's right subtree
            removeNodePrivate(smallestInRightSubtree, root); 
            root->key=smallestInRightSubtree;
            cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty\n";
    }
}

void BST::removeMatch(node *parent, node *match, bool left)
{
    if(root !=NULL)
    {
        node *delPtr;
        int matchKey= match->key; 
        int smallestInRightSubtree; // in the case that node you want to delete has 2 children

        // Case: 0 Children 
        if(match->left == NULL && match->right==NULL)
        {
            delPtr=match;
            left == true?
            parent->left= NULL : 
            parent->right=NULL;
            delete delPtr;
             cout << "The node containing key " << matchKey << " was removed\n";
        }

        // Case: 1 Child
        // Have a right child but not left child
        else if(match->left==NULL && match->right!=NULL)
        {
            // are we dealing with the left child?
            left==true?
            parent->left=match->right :
            parent->right=match->right;
            match->right=NULL;
            delPtr=match;
            delete delPtr; // or you can just say delete match
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        // Have a left child but not right child
        else if(match->left!=NULL && match->right==NULL)
        {
            // are we dealing with the left child?
            left==true?
            parent->left=match->left :
            parent->right=match->left;
            match->left=NULL;
            delPtr=match;
            delete delPtr; // or you can just say delete match
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        // Case:  2 children 
        else 
        {
            smallestInRightSubtree=findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree,match);
            // overwrite matching key with key took from smallest node in right subtree
            match->key= smallestInRightSubtree;
        }
    }
    else
    cout << "Can not remove match. The tree is empty\n";
}