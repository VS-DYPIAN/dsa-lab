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
   void del(int);
   void casea(node *,node *);  //for case a:if l = r = null.
   void caseb(node *,node *);  //for case b:if l != null, r = null.or if l = null, r != null.
   void casec(node *,node *);  //for case c: if l != null, r != null
   void preorder(node *);
   void inorder(node *);
   void postorder(node *);
   void show(node *, int);
   void minimum(struct node* node);
   int  LongestPath(node *root);
   //node* Swapnodes(node *root);
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
void BST::insert(node *tree, node *newnode)  //To insert items in the tree
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
void BST::del(int i)               //To delete an item from tree
{
   node *par, *loc;
   if (r == NULL)
   {
      cout<<"Tree empty"<<endl;
      return;
   }
   find(i, &par, &loc);
   if (loc == NULL)
   {
      cout<<"Item not present in tree"<<endl;
      return;
   }
   if (loc->l == NULL && loc->r == NULL)
   {
      casea(par, loc);
      cout<<"item deleted"<<endl;
   }
   if (loc->l!= NULL && loc->r == NULL)
   {
      caseb(par, loc);
      cout<<"item deleted"<<endl;
   }
   if (loc->l== NULL && loc->r != NULL)
   {
      caseb(par, loc);
      cout<<"item deleted"<<endl;
   }
   if (loc->l != NULL && loc->r != NULL)
   {
      casec(par, loc);
      cout<<"item deleted"<<endl;
   }
   free(loc);
}
void BST::casea(node *par, node *loc )   // case a Called from del() if l = r = null.
{
   if (par == NULL)
{
   r= NULL;
}
else
{
   if (loc == par->l)
   par->l = NULL;
   else
   par->r = NULL;
   }
}
void BST::caseb(node *par, node *loc)  //case b Called from del() if l != null, r = null
{
   node *child;
   if (loc->l!= NULL)
      child = loc->l;
   else
      child = loc->r;
   if (par == NULL)
   {
      r = child;
   }
   else
   {
      if (loc == par->l)
         par->l = child;
      else
         par->r = child;
   }
}
void BST::casec(node *par, node *loc)  //case c Called from del() if l != null, r != null.
{
   node *ptr, *ptrsave, *suc, *parsuc;
   ptrsave = loc;
   ptr = loc->r;
   while (ptr->l!= NULL)
   {
      ptrsave = ptr;
      ptr = ptr->l;
   }
   suc = ptr;
   parsuc = ptrsave;
   if (suc->l == NULL && suc->r == NULL)
      casea(parsuc, suc);
   else
      caseb(parsuc, suc);
   if (par == NULL)
   {
      r = suc;
   }
   else
   {
      if (loc == par->l)
         par->l = suc;
      else
         par->r= suc;
   }
   suc->l = loc->l;
   suc->r= loc->r;
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
   int c, n,item ,Long;
   BST bst;
   node *t;
   while (1)
   {
      cout<<"******************"<<endl;
      cout<<"Operations on BST"<<endl;
      cout<<"******************"<<endl;
      cout<<"1.Insert Element "<<endl;
      cout<<"2.Delete Element "<<endl;
      cout<<"3.Search Element"<<endl;
      cout<<"4.Inorder Traversal"<<endl;
      cout<<"5.Preorder Traversal"<<endl;
      cout<<"6.Postorder Traversal"<<endl;
      cout<<"7.Display the tree"<<endl;
      cout<<"8.Minimum value in BST "<<endl;
      cout<<"9.Longest path"<<endl;
      cout<<"10.Swap"<<endl;
      cout<<"11.Quit"<<endl;
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
            if (r == NULL)
            {
               cout<<"Tree is empty, nothing to delete"<<endl;
               continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>n;
            bst.del(n);
            break;
         case 3:
            cout<<"Search:"<<endl;
            cin>>item;
            bst.search(r,item);
            break;
         case 4:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(r);
            cout<<endl;
            break;
         case 5:
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(r);
            cout<<endl;
            break;
         case 6:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(r);
            cout<<endl;
            break;
         case 7:
            cout<<"Display BST:"<<endl;
            bst.show(r,1);
            cout<<endl;
            break;
         case 8:
           // cout<<"Minimum value in BST is : "<<t->key<<endl;
            bst.minimum(r);
            cout<<endl;
            break;
         case 9:
            Long = bst.LongestPath(r);
            cout<<"Longest path in BST is :- "<<Long<<endl;
            cout<<endl;
            break;
         case 10:
            cout << "Befors swap order in BST is :-",bst.inorder(r),"\n";
            Swapnodes(r);
            cout<<"After swap order in Bst is :-",bst.inorder(r),"\n";
            Swapnodes(r);
			cout<<endl;
            break;
         case 11:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
