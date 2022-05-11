
/***************--SCOB54 VAIBHAV SAWANT ASSIGNMENT 4 CODE--**********************
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may d
require for finding any keyword. Use Binary Search Tree for implementation.
**********************************************************************************/

#include <iostream>
#include<string.h>
using namespace std;

struct node  // to defne struct with same name 
{

 char word[20];         
 char meaning[20];
 struct node  *l;
 struct node * r;
}*r;

class dict      
{
public: 
 dict()
 {
     r == NULL;
 }
 node *root;
 void create();
 void display(node*root);
 void insert(node * root,node *temp);       //insert the data
 int search(node *,char []); 
 int update(node * root,char word[20]);
 node* del(node * root,char word[20]);
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

  temp->l = NULL;            // isolated nodes
  temp->r = NULL;

  if(r== NULL)
  {
   r= temp;
  }
  else
  {
   insert(r, temp);
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
  if(root->l == NULL)
   root->l = temp;
  else
   insert(root->l,temp);
 }
 else
 { if(root->r == NULL)
   root->r = temp;
  else
   insert(root->r,temp);
 }

}


void dict:: display(node*root)
{
  if(root!= NULL)
  {
     display(root->l);
     cout<<" "<<root->word<<":"<<root->meaning<<endl;
     display(root->r);
  }
    
}

int dict :: search(node * root,char word[20])     //4.search operation
{
 int c=0;      //initializing one count variable as c
 while(r != NULL)
 {
  c++;
  if(strcmp (word,r->word) == 0)  // matches with root value 
  {
   
   cout<<"No of Comparisons:"<<c<<endl;
   return 1;
  }
  if(strcmp (word, r->word) < 0) // present in l subtree
   r = r->l;
  if(strcmp (word, r->word) > 0) // present in r subtree
   r = r->r;
 }

 return -1;
}


int dict :: update(node * root,char word[20])  // 5.updating value need to implement search Operation
{
 while(r != NULL)
 {
  if(strcmp (word,r->word) == 0)  // matches with root value 
  {
   
   cout<<"Enter new meaning of keyword :"<<r->word<<"=";
   cin>>r->meaning;
   return 1;
  }
  if(strcmp (word, r->word) < 0) // present in l subtree
   r = r->l;
  if(strcmp (word, r->word) > 0) // present in r subtree
   r = r->r;
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
  root->l = del(root->l, word);
  return root;
 }
 if (strcmp(word,root->word) > 0)
 {
   root->r = del(root->r, word);
   return root;
 }

 if (root->r==NULL&&root->l==NULL) // and operator #case of leaf node 
 {
  temp = root;
  delete temp;
  return 0;
  }
  if(root->r==NULL)     // only l child present
  {
  temp = root;
  root = root->l;
  delete temp;
  return root;
  }
  else if(root->l==NULL)  // only l child present
  {
  temp = root;
  root = root->r;
  delete temp;
  return root;
  }
  return 0;
}



int main()
{
    dict d;
    int c;
    char word[20];
    //d.root = NULL;
    
    
    while(1)
    {
        cout<<"*****Dictionary*****"<<endl;
        cout<<"1.Insert record"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Update"<<endl;
        cout<<"5.Delete"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>c;
        switch(c)
        {
            case 1:
             d.create();
             cout<<endl;
             break;
             
            case 2:
             cout<<"Stored data in ascending order :"<<endl;
             d.display(r);
             cout<<endl;
             break;
             
            case 3:
             cout<<"Enter the word to be searched :";
             
             cin>>word;
             if (d.search(r,word) ==1)
               cout<<"Keyword found"<<endl;
             else
               cout<<"keyword not found"<<endl;
             cout<<endl;
             break;
            
            case 4:
             cout<<"Enter Keyword which meaning  want to update :";
             //char word[20];
             cin>>word;
             if (d.update(r,word) ==1)
               cout<<"meaning updated"<<endl;
             else
               cout<<"keyword not found"<<endl;
             cout<<endl;
             break;
            
            case 5:
                cout<<"\nEnter Keyword which u want to delete:";
                char word[20];
                cin>>word;
                if(r == NULL)
                cout<<"\nNo any Keyword";
                else
                r = d.del(r,word);
                cout<<"keyword deleted"<<endl;
                break;
            case 6:
             exit(1);
             
            default:
             cout<<"Wrong choice"<<endl;
        }
    }
}
