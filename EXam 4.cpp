#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char word[20];
    char meaning[20];
    struct node* l;
    struct node* r;
}*r;

class Dict
{
  public :
   Dict()
   {
       r ==NULL;
   }
   node* root;
   void create();
   void insert(node* root,node* temp);
   void display(node* root);
   void search(node* root,char word[20]);
   void update(node* root,char word[20]);
   node* del(node* root,char word[20]);
};

void Dict:: create()
{
  struct node* temp;
  int ch;
  do
  {
     temp = new node;
     cout<<"Enter word : ";
     cin>>temp->word;
     cout<<"Enter meaning : ";
     cin>>temp->meaning;
     
     temp->l = NULL;
     temp->r = NULL;
     
     if(r == NULL)
     {
         r = temp;
     }
     else
     {
         insert(r,temp);
     }
     cout<<"Do you want to add more (1/0) : ";
     cin>>ch;
  }while(ch == 1);
}

void Dict:: insert(node* root,node* temp)
{
  if(strcmp(temp->word, root->word) < 0)
  {
      if(root->l == NULL)
      {
          root->l = temp;
      }
      else
      {
          insert(root->l,temp);
      }
  }
  else
  {
      if(root->r == NULL)
      {
          root->r = temp;
      }
      else
      {
          insert(root->r,temp);
      }  
  }
}

void Dict:: display(node* root)
{
  if(root == NULL)
  {
      return ;
  }
  else
  {
      display(root->l);
      cout<<"Word : "<<root->word<<" = "<<root->meaning<<endl;
      display(root->r);
  }
}

void Dict:: search(node* root,char word[20])
{
  int c =0;
  if(root !=NULL)
  {
    c++;
    if(strcmp(word,root->word) == 0)
    {
      cout<<"Word found"<<endl;
      cout<<"No. of comparison is : "<<c<<endl;
    }
    if(strcmp(word,root->word) < 0)
    {
        search(root->l,word);
    }
    if(strcmp(word,root->word) > 0)
    {
        search(root->r,word);
    }
  }
  else
  {
      cout<<"Tree is empty"<<endl;
  }
}

void Dict:: update(node* root,char word[20])
{
  if(root !=NULL)
  {
    if(strcmp(word,root->word) == 0)
    {
      cout<<"Enter a new meaning : ";
      cin>>root->meaning;
    }
    if(strcmp(word,root->word) < 0)
    {
        update(root->l,word);
    }
    if(strcmp(word,root->word) > 0)
    {
        update(root->r,word);
    }
  }
  else
  {
      cout<<"Tree is empty"<<endl;
  }
}

node* Dict:: del(node* root,char word[20])
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
    Dict d;
    int c;
    char w[20];
    while(1)
    {
        cout<<"*****Dictionary******"<<endl;
        cout<<"1. Insert record"<<endl;
        cout<<"2. Display "<<endl;
        cout<<"3. Search  "<<endl;
        cout<<"4. Update  "<<endl;
        cout<<"5. Delete  "<<endl;
        cout<<"6. Exit    "<<endl;
        cout<<"Enter your choice : ";
        cin>>c;
        switch(c)
        {
            case 1:
             d.create();
             cout<<endl;
             break;
             
            case 2:
             cout<<"Stored data in ascending order is : "<<endl;
             d.display(r);
             cout<<endl;
             break;
             
            case 3:
             cout<<"Enter a word to be searched : ";
             cin>>w;
             d.search(r,w);
             cout<<endl;
             break;
             
            case 4:
             cout<<"Enter a word to be updated : ";
             cin>>w;
             d.update(r,w);
             cout<<endl;
             break;
             
            case 5:
             cout<<"Enter a word to be deleted : ";
             cin>>w;
             d.del(r,w);
             cout<<endl;
             break;
             
            case 6:
             exit(1);
             
            default :
             cout<<" Wrong choice "<<endl;
        }
    }
}
