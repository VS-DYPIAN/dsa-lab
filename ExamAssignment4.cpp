#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char word[50];
    char meaning[50];
    struct node* l ;
    struct node* r;
}*r;

class Dict
{
  public:
    Dict()
    {
        r == NULL;
    }
    void create();
    void insert(node*root,node*temp);
    void display(node*root);
};

void Dict:: create()
{
   struct node* temp;
   int ch;
   do
   {
       temp = new node;
       cout<<"Enter a word :";
       cin>>temp->word;
       cout<<"Enter meaning :";
       cin>>temp->meaning;
       temp->l =NULL;
       temp->r =NULL;
       if(r==NULL)
       {
           r = temp;
       }
       else
       {
           insert(r,temp);
       }
       cout<<"Do yo want to add more(y=1;n=0)? :";
       cin>>ch;
   }
   while(ch==1);
}

void Dict:: insert(node*root,node*temp)
{
  if(strcmp(temp->word,root->word )< 0)
  {
      if(root->l== NULL)
      {
          root->l =temp;
      }
      else
      {
          insert(root->l,temp);
      }
  }
  else
  {
     if(root->r== NULL)
      {
          root->r =temp;
      }
      else
      {
          insert(root->r,temp);
      } 
  }
    
}

void Dict:: display(node*root)
{
  if(root!= NULL)
  {
      display(root->l);
      cout<<"\n Key word :"<<root->word;
      cout<<"\t Key meaning :"<<root->meaning;
      display(root->r);
  }
    
}

int main()
{
    Dict d;
    int c;
    
    while(1)
    {
        cout<<"*****Dictionary*****"<<endl;
        cout<<"1.Insert record"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>c;
        switch(c)
        {
            case 1:
             d.create();
             cout<<endl;
             break;
             
            case 2:
             cout<<"Stored data is :"<<endl;
             d.display(r);
             cout<<endl;
             break;
             
            case 3:
             exit(1);
             
            default:
             cout<<"Wrong choice"<<endl;
        }
    }
}
