/*
**************--SCOB54 VAIBHAV SAWANT ASSIGNMENT 3 CODE--**********************
problem statement : beginning with an empty binary search tree, construct binary search 
tree by inserting the values in the order given. after constructing a binary tree - 
i. insert new node ii. find number of nodes in longest path iii. minimum data value found 
in the tree iv. change a tree so that the roles of the left and right pointers are swapped 
at every node v. search a value
*********************************************************************************
BINARY SEARCH TREE:- The right sub-tree of a node has a key greater than to its parent node's key.
The left sub-tree of a node has a key lesser than to its parent node's key.*
**********************************************************************************/
# include <iostream>         // provides basic input and output services for C++ programs
# include <cstdlib>          // declares a set of general-purpose functions
using namespace std;
struct node//node declaration
{
   int key;
   struct node *l;    //node declaration for left node   
   struct node *r;    //node declaration for right node
   
}*r;
class BST             //declaration of class as BST
{
   public://functions declaration
   void search(node *, int);
   void find(int, node **, node **);
   void insert(node *, node *);
    
   void preorder(node *);
   void inorder(node *);
   void postorder(node *);
   void show(node *, int);
   void minimum(struct node* node);
   BST()
   {
      r = NULL;
   }
};

void BST::find(int i, node **par, node **loc)//find the position of the item 
{
   node *ptr, *ptrsave;
   if (r == NULL)
   {
      *loc = NULL;     //*loc=location ptr
      *par = NULL;    //*par=parent node ptr; 
      return;
   }
   if (i == r->key)
   {
      *loc = r;
      *par = NULL;
      return;
   }
   if (i < r->key)
   ptr = r->l;      // present in left subtree
   else
   ptr = r->r;      // present in right subtree
   ptrsave = r;
   while (ptr != NULL)
   {
      if (i == ptr->key)
      {
         *loc = ptr;
         *par = ptrsave;
         return;
      }
      ptrsave = ptr;
      if (i < ptr->key)
      ptr = ptr->l;
      else
      ptr = ptr->r;
   }
   *loc = NULL;
   *par = ptrsave;
}

void BST::search(node *root, int data) //To search an item in BST.
{
   int depth = 0;
   
   while(root != NULL)
   {
      depth++;
      if(root->key == data)
      {
         cout<<"\nData found at depth: "<<depth<<endl;
         return;
      }
      else if(root->key > data)
      root = root->l;
      else
      root = root->r;
   }
   cout<<"\n Data not found"<<endl;
   return;
}
void BST::insert(node *root, node *newnode)  //To insert items in the tree
{
   if (r == NULL)
   {
      r = new node;
      r->key = newnode->key;
      r->l= NULL;
      r->r= NULL;
      cout<<"Root node is Added"<<endl;
      return;
   }
   if (root->key == newnode->key)
   {
      cout<<"Element already in the tree"<<endl;
      return;
   }
   if (root->key > newnode->key)
   {
      if (root->l != NULL)
      {
         insert(root->l, newnode);
      }
      else
      {
         root->l= newnode;
         (root->l)->l = NULL;
         (root->l)->r= NULL;
         cout<<"node Added To Left"<<endl;
         return;
      }
   }
   else
   {
      if (root->r != NULL)
      {
         insert(root->r, newnode);
      }
      else
      {
         root->r = newnode;
         (root->r)->l= NULL;
         (root->r)->r = NULL;
         cout<<"node Added To Right"<<endl;
         return;
      }
   }
}

void BST::minimum(struct node*node)   
{
struct node* current = node;
 
/* loop down to find the leftmost leaf */
while (current->l != NULL)
{
    current = current->l;
    cout<<"Minimum value in BST is : "<<current->key<<endl;
}
return ;
}

void BST::preorder(node *ptr)     //to traverse the node as preorder as: root ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ Left ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ right.
{
   if (r == NULL)
   {
      cout<<"Tree is empty"<<endl;
      return;
   }
   if (ptr != NULL)
   {
      cout<<ptr->key<<" ";
      preorder(ptr->l);
      preorder(ptr->r);
   }
}
void BST::inorder(node *ptr)   // to traverse the node as inorder as:left ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ root ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ right.
{
   if (r == NULL)
   {
      cout<<"Tree is empty"<<endl;
      return;
   }
   if (ptr != NULL)
   {
      inorder(ptr->l);
      cout<<ptr->key<<" ";
      inorder(ptr->r);
   }
}
void BST::postorder(node *ptr)   //to traverse the node as preorder as:left ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ right ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Å“ root
{
   if (r == NULL)
   {
      cout<<"Tree is empty"<<endl;
      return;
   }
   if (ptr != NULL)
   {
      postorder(ptr->l);
      postorder(ptr->r);
      cout<<ptr->key<<" ";
   }
}
void BST::show(node *ptr, int level)//print the tree
{
   int i;
   if (ptr != NULL)
   {
      show(ptr->r, level+1);
      cout<<endl;
      if (ptr == r)
         cout<<"Root->: ";
      else
      {
         for (i = 0;i < level;i++)
         cout<<" ";
      }
      cout<<ptr->key;
      show(ptr->l, level+1);
   }
}
int main()
{
   int c, n,item;
   BST bst;
   node *t;
   while (1)
   {
      cout<<"******************"<<endl;
      cout<<"Operations on BST"<<endl;
      cout<<"******************"<<endl;
      cout<<"1.Insert Element "<<endl;
      cout<<"2.Search Element"<<endl;
      cout<<"3.Inorder Traversal"<<endl;
      cout<<"4.Preorder Traversal"<<endl;
      cout<<"5.Postorder Traversal"<<endl;
      cout<<"6.Display the tree"<<endl;
      cout<<"7.Minimum value in BST "<<endl;
      cout<<"8.Quit"<<endl;
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c)
      {
         case 1:
            t = new node;
            cout<<"Enter the number to be inserted : ";
            cin>>t->key;
            bst.insert(r, t);
            break;
         
         case 2:
            cout<<"Search:"<<endl;
            cin>>item;
            bst.search(r,item);
            break;
         case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(r);
            cout<<endl;
            break;
         case 4:
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(r);
            cout<<endl;
            break;
         case 5:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(r);
            cout<<endl;
            break;
         case 6:
            cout<<"Display BST:"<<endl;
            bst.show(r,1);
            cout<<endl;
            break;
         case 7:
           // cout<<"Minimum value in BST is : "<<t->key<<endl;
            bst.minimum(r);
            cout<<endl;
            break;
         case 8:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
