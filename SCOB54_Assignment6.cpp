#include <iostream>
#include <string.h>

using namespace std;

class Graph
  {
   
      int n,u;
      string cities[20];
      int adj_mat[50][50] ;
       
     
       
      public:
      void CreateG();
      void Display();
      Graph()
      {
     
      }
   
  };
void Graph:: CreateG()
{
    cout << "Enter no. of cities: ";
    //int n,u;
    cin >> n;
    //string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;  
}
void Graph :: Display()
{
    
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
}
int main()

{
 Graph g;
 int x;
  while (1)
   {
      cout<<"****************************"<<endl;
      cout<<"Operations on Graph"<<endl;
      cout<<"****************************"<<endl;
      cout<<"1.Create Graph using adjacency matrix"<<endl;
      cout<<"2.Display the Graph" <<endl;
      cout<<"3.Exit" <<endl;
      cout<<"Enter your choice :-";
      cin>>x;
      switch(x)
      {
         case 1:
            g.CreateG();
           
            break;
         
         case 2:
            g.Display();
            break;
         
         case 3:
           
            exit(1);
           
         default:
            cout<<"Wrong choice"<<endl; 
      }
    }

}
