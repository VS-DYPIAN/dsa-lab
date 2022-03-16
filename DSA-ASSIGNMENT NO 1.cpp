/* ASSIGNMENT NO.: 1 ; Roll No.:-SCOB54

Title :A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method.  */

#include<iostream>
#include<string.h>
using namespace std;
// DECLARATION OF NODE
struct node
{
char label[20];                 // To store the name of chapter and section
int chcount;                     // To store the no of childs
node *child[50];             // Array of pointer to store addresses of node
}*root;
// DECLARATION OF CLASS
class BOOK
{
public:             // FUNCTION DECLARATION
void insert();            
void display();
BOOK()              // CONSTRUCTOR
{
root == NULL;
}
};
void BOOK::insert()
{
int secount;
root = new node();                                                // THE BOOK IS  CREATED
cout<<"Enter the name of book:"<<endl;
cin>>root->label;               // Arrow operator is used for accessing elements in the structure using pointer
cout<<"Enter the total number of chapters in book:"<<endl;
cin>>root->chcount;
for(int i=0;i<root->chcount;i++)
{
root->child[i] = new node();                               // CHAPTERS IS CREATED    
cout<<"Enter the name of chapters:"<<endl;
cin>>root->child[i]->label;
cout<<"Enter the number of sections:"<<endl;
cin>>root->child[i]->chcount;
for(int j=0;j<root->child[i]->chcount;j++)
{
root->child[i]->child[j] = new node();             // SECTIONS ARE CREATED
cout<<"Enter the name of section:"<<endl;
cin>>root->child[i]->child[j]->label;
cout<<"Enter the number of sub sections:"<<endl;
cin>>root->child[i]->child[j]->chcount;
for(int k=0; k<root->child[i]->child[j]->chcount; k++)
{
root->child[i]->child[j]->child[k] = new node();          // SUBSECTIONS ARE CREATED
cout<<"Enter the name of sub section:"<<endl;
cin>>root->child[i]->child[j]->child[k]->label;
}
}
}
}
void BOOK::display()
{
if(root != NULL)
{
cout<<"** Hierarchy of Book **"<<endl;
cout<<"Book Name is"<<root->label<<endl;
for(int i=0; i<root->chcount; i++)
{
cout<<"Chapter name is  "<<root->child[i]->label<<endl;
for(int j=0; j<root->child[i]->chcount; j++)
{
cout<<"Section name is "<<root->child[i]->child[j]->label<<endl;
for(int k=0; k<root->child[i]->child[j]->chcount; k++)
{
cout<<"Sub-section name is "<<root->child[i]->child[j]->child[k]->label<<endl;
}
}
}
}
}
int main()
{
BOOK g;
int ch;
do
{
cout<<"** MENU****"<<endl;
cout<<"1. Insert."<<endl;
cout<<"2. Display."<<endl;
cout<<"3. EXIT."<<endl;
cout<<"Enter the choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1: g.insert();
break;
case 2: g.display();
break;
case 3:
            exit(1);
}
}while(ch<4);
}
