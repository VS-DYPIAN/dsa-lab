/*Title :A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method.  */
#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char label[50];
    int chcount;
    node* child[50];
}*root;

class Book
{
  public:
    Book()
    {
        root ==NULL;
    }
    void create();
    void display();
};

void Book:: create()
{
  root = new node();
  cout<<"Enter the nameof the book :";
  cin>>root->label;
  cout<<"Enter the total number of chapters in book :";
  cin>>root->chcount;
  
  for(int i= 0 ;i<root->chcount ; i++)
  {
      root->child[i] = new node();
      cout<<"Enter the name of chapter :";
      cin>>root->child[i]->label;
      cout<<"Enter the number of sections ";
      cin>>root->child[i]->chcount;
      
      for(int j=0; j < root->child[i]->chcount; j++)
      {
          root->child[i]->child[j] = new node();
          cout<<"Enter the name section :";
          cin>>root->child[i]->child[j]->label;
          cout<<"Enter the number of sub-sections :";
          cin>>root->child[i]->child[j]->chcount;
          
          for(int k =0; k<root->child[i]->child[j]->chcount ;k++)
          {
              root->child[i]->child[j]->child[k] = new node();
              cout<<"Enter the name of subsection :";
              cin>>root->child[i]->child[j]->child[k]->label;
              cout<<endl;
          }
      }
  }
  cout<<"Details of book added successfully"<<endl;
  cout<<endl;
    
}

void Book:: display()
{
    if(root != NULL)
    {
        cout<<"** Hierarchy of Book **"<<endl;
        cout<<"Book Name is"<<root->label<<endl;
        for(int i=0; i<root->chcount; i++)
        {
            cout<<"Chapter name is : "<<root->child[i]->label<<endl;
            for(int j=0; j<root->child[i]->chcount; j++)
                {
                cout<<"Section name is :"<<root->child[i]->child[j]->label<<endl;
                    for(int k=0; k<root->child[i]->child[j]->chcount; k++)
                    {
                      cout<<"Sub-section name is :"<<root->child[i]->child[j]->child[k]->label<<endl;
                    }
            }
        }
    }
}

int main()
{
    Book b;
    int c;
    while(1)
    {
        cout<<"Book details"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>c;
        
        switch(c)
        {
            case 1:
              b.create();
              cout<<endl;
              break;
              
            case 2:
              b.display();
              cout<<endl;
              break;
              
            case 3:
               exit(1);
               
            default :
              cout<<"Wrong choice"<<endl;
        }
    }
}

