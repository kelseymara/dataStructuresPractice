// from https://www.youtube.com/watch?v=86g8jAQug04&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=33

  
 // keep the nodes in a queue (FIFO)

#include <iostream>
#include <queue>
using namespace std;
struct Node{
  char data;
  Node *left;
  Node *right;
  
};

// print data in level order
void LevelOrder(Node *root)
{
  if(root == NULL)
    return;
  queue<Node*> Q
  // store address of first node (root)
  Q.push(root);
  
  // whil ethere is at least one discovered node
  while(!Q.empty())
  {
    Node *current= Q.front(); // set current equal to node from the front 
    cout << current->data << " "; // print data of front node
    
    // if left child is not null, push its address into queue
    if(current->left!=NULL)
      Q.push(current->left);
    
    // if right child is not null, push its address into queue
    if(current->right!=NULL)
      Q.push(current->right);
    
    Q.pop(); // remove element at front
  }
  
  
}


          
  
  
