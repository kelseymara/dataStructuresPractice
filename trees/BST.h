class BST
{
// basic building block of BST
private: 

struct node
{
int key;
node *left;
node *right;
};

node *root; // root pointer to reference top of tree/root node
void addLeafPrivate(int k, node* ptr);

void printInOrderPrivate(node *ptr);

node* returnNodePrivate(int k,node *ptr);

int findSmallestPrivate(node *ptr);

void removeRootMatch();


void removeNodePrivate(int k,node *parent);

void removeMatch(node *parent, node *match, bool left);

public: 
BST(); 
node *createLeaf(int k); 

void addLeaf(int k); 

void printInOrder();

node* returnNode(int k);

int returnRootKey();
void printChildren(int k);

void removeNode(int k);

int findSmallest();
};