/*
**************--SCOB54 VAIBHAV SAWANT ASSIGNMENT 3 CODE--**********************
problem statement : beginning with an empty binary search tree, construct binary search 
tree by inserting the values in the order given. after constructing a binary tree - 
i. insert new node ii. find number of nodes in longest path iii. minimum data value found 
in the tree iv. change a tree so that the roles of the left and right pointers are swapped 
at every node v. search a value
*/
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
   
   void insert(node *, node *);
   
   void preorder(node *);
   void inorder(node *);
   void postorder(node *);
   void display(node *, int);
   void minimum(struct node* node);
   int  LongestPath(node *root);
   node* Swapnodes(node *root);
   BST()
   {
      r = NULL;
   }
};


void BST::insert(node *tree, node *newnode)  //To insert items in the tree
{
   if (r == NULL)
   {
      r = new node;
      r->key = newnode->key;
      r->l= NULL;
      r->r= NULL;
      cout<<"Root node is Added"<<endl;    //this will execute only once 
      return;
   }
   if (tree->key == newnode->key)
   {
      cout<<"Element already in the tree"<<endl;
      return;
   }
   if (tree->key > newnode->key)
   {
      if (tree->l != NULL)
      {
         insert(tree->l, newnode);
      }
      else
      {
         tree->l= newnode;
         (tree->l)->l = NULL;
         (tree->l)->r= NULL;
         cout<<"node Added To Left"<<endl;
         return;
      }
   }
   else
   {
      if (tree->r != NULL)
      {
         insert(tree->r, newnode);
      }
      else
      {
         tree->r = newnode;
         (tree->r)->l= NULL;
         (tree->r)->r = NULL;
         cout<<"node Added To Right"<<endl;
         return;
      }
   }
}

void BST::display(node *ptr, int level)//print the tree
{
   int i;
   if (ptr != NULL)
   {
      display(ptr->r, level+1);
      cout<<endl;
      if (ptr == r)
         cout<<"Root->: ";
      else
      {
         for (i = 0;i < level;i++)
         cout<<" ";
      }
      cout<<ptr->key;
      display(ptr->l, level+1);
   }
}

int BST::LongestPath(node *root)
{
    if(root == NULL)
       return 0;
    int Lctr = LongestPath(root->l);
    int Rctr = LongestPath(root->r);
    if (Lctr>Rctr)
       return (Lctr +1);
    else return (Rctr +1);
    
}

void BST::search(node *root, int data) //To search an item in BST.
{
   int depth = 0;
   node *temp = new node;
   temp = root;
   while(temp != NULL)
   {
      depth++;
      if(temp->key == data)
      {
         cout<<"\nData found at depth: "<<depth<<endl;
         return;
      }
      else if(temp->key > data)
      temp = temp->l;
      else
      temp = temp->r;
   }
   cout<<"\n Data not found"<<endl;
   return;
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


void BST::preorder(node *ptr)     //to traverse the node as preorder as: root-l-f
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
void BST::inorder(node *ptr)   // to traverse the node as inorder as:l-root-r
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
void BST::postorder(node *ptr)   //to traverse the node as preorder as:l-r-root
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


node* Swapnodes(node *root)
{
    node* temp;
    if (root == NULL)
       return 0;
       
    temp = root->l;
        root->l = root->r;
        root->r = temp;

        Swapnodes(root->l);
        Swapnodes(root->r);
    return 0;
    
}

int main()
{
   int c, n,item ,Long;
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
      cout<<"8.Longest path"<<endl;
      cout<<"9.Swap"<<endl;
      cout<<"10.Quit"<<endl;
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
            bst.display(r,1);
            cout<<endl;
            break;
         
         case 7:
            bst.minimum(r);
            cout<<endl;
            break;
         
         case 8:
            Long = bst.LongestPath(r);
            cout<<"Longest path in BST is :- "<<Long<<endl;
            cout<<endl;
            break;
         
         case 9:
            cout << "Befors swap order in BST is :-",bst.inorder(r),"\n";
            Swapnodes(r);
            cout<<"After swap order in Bst is :-",bst.inorder(r),"\n";
            Swapnodes(r);
			cout<<endl;
            break;
         
         case 10:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
