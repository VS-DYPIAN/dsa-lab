
/***************--SCOB54 VAIBHAV SAWANT ASSIGNMENT 4 CODE--**********************
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may 
require for finding any keyword. Use Binary Search Tree for implementation.
**********************************************************************************/

#include <iostream>
#include<string.h>
using namespace std;

struct node  // to defne struct with same name 
{

 char word[20];         
 char meaning[20];
 struct node  *left;
 struct node * right;
}*r;

class dict      // declaration of class dictionary 
{
public:        // function declaration 
 node *root;
 void create();                             // creation of node
 void disp(node *);                         // display data
 void insert(node * root,node *temp);       //insert the data
 int search(node *,char []);                // search the data
 int update(node *,char []);                // updating existing data
 void inorder_rec(node *rnode);             // to dispaly in increasing order
 void Descending_rec(node *rnode);           // to dispaly in decreasing order
 void inorder()
 {
  inorder_rec(root);
 }
 void Descending()
 {
 Descending_rec(root);
}
 node* del(node *,char []);                 // deletion of data
 node * min(node *);                        // to find minimum
};


void dict :: create()             // 1.Create function
{
 struct node *temp;
 int ch;

 do
 {
  temp = new node;        //new keyword is used for memory allocation
  cout<<"\nEnter Keyword:";
  cin>>temp->word;                // word as inpuy
  cout<<"\nEnter Meaning:";
  cin>>temp->meaning;            //meaning as input

  temp->left = NULL;            // isolated nodes
  temp->right = NULL;

  if(root == NULL)
  {
   root = temp;
  }
  else
  {
   insert(root, temp);
  }
  cout<<"\nDo u want to add more (y=>1/n=>0):";
  cin>>ch;
 }
 while(ch == 1);

}

void dict ::  insert(node * root,node *temp)     //2. insert function
{
 if(strcmp (temp->word, root->word) < 0 )      // strcmp is used to compare strings return 0 (equal),
                                               //returns value (V>0) (L>R) ;returns value (V<0) for l<R 
 {
  if(root->left == NULL)
   root->left = temp;
  else
   insert(root->left,temp);
 }
 else
 { if(root->right == NULL)
   root->right = temp;
  else
   insert(root->right,temp);
 }

}

void dict:: disp(node * root)       // 3.display function

{
 if( root != NULL)
 {
  disp(root->left);
  cout<<"\n Key Word :"<<root->word;
  cout<<"\t Meaning :"<<root->meaning;
  disp(root->right);
 }
}


int dict :: search(node * root,char word[20])     //4.search operation
{
 int c=0;      //initializing one count variable as c
 while(root != NULL)
 {
  c++;
  if(strcmp (word,root->word) == 0)  // matches with root value 
  {
   cout<<"\nNo of Comparisons:"<<c;
   return 1;
  }
  if(strcmp (word, root->word) < 0) // present in left subtree
   root = root->left;
  if(strcmp (word, root->word) > 0) // present in right subtree
   root = root->right;
 }

 return -1;
}
int dict :: update(node * root,char word[20])  // 5.updating value need to implement search Operation
{
 while(root != NULL)
 {
  if(strcmp (word,root->word) == 0)
  {
   cout<<"\nEnter New Meaning of Keyword : "<<root->word<< "=";
   cin>>root->meaning;
   return 1;
  }
  if(strcmp (word, root->word) < 0)
   root = root->left;
  if(strcmp (word, root->word) > 0)
   root = root->right;
 }
 return -1;
}
node* dict :: del(node * root,char word[20])   // 6.delete operation involves four cases
{
 node *temp;

 if(root == NULL)
 {
  cout<<"\nElement Not Found";
  return root;
 }

 if (strcmp(word,root->word) < 0)
 {
  root->left = del(root->left, word);
  return root;
 }
 if (strcmp(word,root->word) > 0)
 {
   root->right = del(root->right, word);
   return root;
 }

 if (root->right==NULL&&root->left==NULL) // and operator #case of leaf node 
 {
  temp = root;
  delete temp;
  return 0;
  }
  if(root->right==NULL)     // only left child present
  {
  temp = root;
  root = root->left;
  delete temp;
  return root;
  }
  else if(root->left==NULL)  // only left child present
  {
  temp = root;
  root = root->right;
  delete temp;
  return root;
  }
  temp = min(root->right);
  strcpy(root->word,temp->word);  //to copy one string to another
  root->right = del(root->right, temp->word);
  return root;

}

node * dict :: min(node *q)
{
 while(q->left != NULL)
 {
  q = q->left;
 }
 return q;
}



void dict :: inorder_rec(node *rnode)    // for ascending order
{
 if(rnode)
 {
  inorder_rec(rnode->left);
  cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
  inorder_rec(rnode->right);
 }
}
void dict :: Descending_rec(node *rnode)    // for ascending order
{
 if(rnode)
 {
  Descending_rec(rnode->right);
  cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
  Descending_rec(rnode->left);
 }
}


int main()
{
 int ch;
 dict d;
 d.root = NULL;


 do
 {
  cout<<" "<<endl;
  cout<<"*************************"<<endl;
  cout<<"Operations On Dictionary"<<endl;
  cout<<"*************************"<<endl;
  cout<<"1.Create"<<endl;
  cout<<"2.Display"<<endl;
  cout<<"3.Search"<<endl;
  cout<<"4.Update"<<endl;
  cout<<"5.Delete"<<endl;
  cout<<"6.Ascending order "<<endl;
  cout<<"7.Descending order "<<endl;
  cout<<"8.Exit"<<endl;
  cout<<"========================"<<endl;
  cout<<"Enter your choice:";
  cin>>ch;

  switch(ch)
  {
    case 1: d.create();
        break;
    
    case 2: if(d.root == NULL)
  {
    cout<<"\nNo any Keyword"<<endl;
  }
    else
  {
    cout<<"Stored data is : "<< endl;
    d.disp(d.root);
    
  }
    break;
    case 3: if(d.root == NULL)
 {
    cout<<"\nDictionary is Empty. First add keywords then try again ";
 }
    else
 {

    cout<<"\nEnter Keyword which you want to search:";
    char word[20];
    cin>>word;

    if( d.search(d.root,word) == 1)
    cout<<"\nKeyword Found";
    else
    cout<<"\nKeyword Not Found";
 }
    break;
    case 4:
    if(d.root == NULL)
  {
    cout<<"\nDictionary is Empty. First add keywords then try again ";
 }
    else
  {
    cout<<"\nEnter Keyword which meaning  want to update:";
    char word[20];
    cin>>word;
    if(d.update(d.root,word) == 1)
    cout<<"\nMeaning Updated";
    else
    cout<<"\nMeaning Not Found";
  }
    break;
    case 5:
    if(d.root == NULL)
  {
    cout<<"\nDictionary is Empty. First add keywords then try again ";
  }
    else
  {
    cout<<"\nEnter Keyword which u want to delete:";
    char word[20];
    cin>>word;
    if(d.root == NULL)
  {
    cout<<"\nNo any Keyword";
  }
    else
  {
    d.root = d.del(d.root,word);
  }
  break;
    case 6:
    if(d.root == NULL)
    {
     cout<<"\nDictionary is Empty. First add keywords then try again ";  
    }
    else
    {
     cout<<"\nAscending order is:\n"; 
     d.inorder();
     
    }
    break;
    case 7:
    if(d.root == NULL)
    {
     cout<<"\nDictionary is Empty. First add keywords then try again ";  
    }
    else
    {
     cout<<"\nDescending order is:\n"; 
     d.Descending();
     
    }
    break;
    case 8:
            exit(1);
    default:
            cout<<"Wrong choice"<<endl;
    
   }
  }
 } 
  while(1);
  return 0;
}
