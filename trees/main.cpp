#include <iostream>
#include <cstdlib>
#include "BST.cpp"
//#include "BST.h"
using namespace std;

int main()
{
 
    // numbers from in markdown file picture
    int treeKeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

    // create BST object
    BST myTree;
  
    cout << "Printing the tree in order\nBefore adding Numbers\n";

    myTree.printInOrder();
    for(int i=0;i<16;i++)
    {
      // adding all of the numbers
      myTree.addLeaf(treeKeys[i]);
    }
    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree.printInOrder();

    // prints root children
    // myTree.printChildren(myTree.returnRootKey());

    // prints all the children
    for(int i=0;i<16;i++)
    {
      // adding all of the numbers
      myTree.printChildren(treeKeys[i]);
      cout << endl;
    }

    cout << "The smallest value in the tree is " << myTree.findSmallest() << endl;
    
    return 0;
}