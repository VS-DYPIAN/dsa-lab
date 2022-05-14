#include <iostream>
#include <string.h>
using namespace std;

class Graph
{
    int n;
    string cities[20];
    int adj_mat[50][50];
    public:
     Graph()
     {
         
     }
     void create();
     void display();
};

void Graph:: create()
{
   cout<<"Enter number of cities :";
   cin>>n;
   for(int i=0;i<n; i++)
   {
       cout<<"Enter city # "<<i<<" Airport code :";
       cin>>cities[i];
   }
   for(int i=0;i<n; i++)
   {
       for(int j=i+1;j<n; j++)
       {
           cout<<"Enter distance between "<<cities[i]<<" and "<<cities[j]<< " : ";
           cin>>adj_mat[i][j];
           adj_mat[j][i] = adj_mat[i][j];
       }
   }
}

void Graph:: display()
{
  for(int i=0;i<n; i++)
  {
      cout<<"\t"<<cities[i]<<"\t";
  }
  for(int i=0;i<n; i++)
  {
      cout<<"\n"<<cities[i];
      for(int j=0;j<n; j++)
      {
          cout<<"\t"<<adj_mat[i][j]<<"\t";
      }
  }
}

int main()
{
    Graph g;
    int c;
    while(1)
    {
      cout<<"****************************"<<endl;
      cout<<"Operations on Graph"<<endl;
      cout<<"****************************"<<endl;
      cout<<"1.Create Graph using adjacency matrix"<<endl;
      cout<<"2.Display the Graph" <<endl;
      cout<<"3.Exit" <<endl;
      cout<<"Enter your choice :";
      cin>>c;
        switch(c)
        {
            case 1:
             g.create();
             cout<<endl;
             break;
             
            case 2:
             g.display();
             cout<<endl;
             break;
             
            case 3:
             exit(1);
             
            default :
             cout<<"Wrong choice"<<endl;
        }
    }
}
