/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify
the prominent land marks as nodes and perform DFS and BFS on that.*/

#include<iostream>
using namespace std;


class Graph
{
        public :
        	int mat[10][10];
        	string vertex[10];
        	int n,m,c;
        	int stack[10];
        	int E;
            Graph()
	        {
	        	for(int i=0;i<10;i++)
				{
					for(int j=0;j<10;j++)
					{
						mat[i][j]=0;
					}
	        		
				}
	        	
			} 
			void Create();
			void Display();
			void BFS();
			void DFS();
};       	
        	
        	
void Graph:: Create()
{
	cout<<"Enter no of land marks  in college :";
	cin>>n;
	
	
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the name of land marks "<<i+1<<" :";
		cin>>vertex[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
        {
		
            if(i==j)
            {
                    mat[i][j]=0;
            }
                        
            else if(mat[i][j]==0)
            {
                    cout<<"Is there edge between land mark "<<vertex[i]<<" and land mark "<<vertex[j]<<"(If yes type 1 else 0)"<<" : ";
                    cin>>mat[i][j];
                    mat[j][i]=mat[i][j];
					
                      
            }
                        
        }
    }
}
	
	

void Graph:: Display()
{
            cout<<"\n";
            for(int i=0;i<n;i++)
            {
                    cout<<"\t"<<vertex[i];
            }
            
            
            for(int i=0;i<n;i++)
            {
                    cout<<"\n"<<vertex[i];;
                    
                    
                    
                    for(int j=0;j<n;j++)
                    {
                            
                            cout<<"\t"<<mat[i][j];
                    }
                    
            }
}
    
void Graph:: DFS()
{
    	  
	    int vis[n];
	    int stack[2*n];
	    int top=0;
	    for(int i=0;i<n;i++)
		{
	        vis[i] = 0;
	    }
	
	    stack[top] = 0;
	    
	
	    while(top!=-1){
	        int node = stack[top];
	        top--;
	
	        if(vis[node]==0){
	            cout<<vertex[node]<<" ";
	            vis[node] = 1;
	            for(int i=0;i<n;i++){
	                if(mat[node][i]!=0){
	                    top++;
	                    stack[top] = i;
	                }
	            }
	        }
	
	    }
	    cout<<endl;
}

void Graph:: BFS()
{

    int vis[n];
    int queue[2*n];
    int front = 0,rear=0;
    for(int i=0;i<n;i++)
	{
        vis[i] = 0;
    }
    queue[rear] = 0;
    vis[0] = 1;
    rear++;

    while(front!=rear)
	{
        //  int size = rear+1;
        
        int node = queue[front];
        front++;
        cout<<vertex[node]<<" ";
        for(int i=0;i<n;i++){
            if(mat[node][i]==1 and vis[i] == 0)
			{
                queue[rear] = i;
                rear++;
                vis[i] = 1;
            }
        }
    }
    cout<<endl;
}                

int main()

{
 Graph g;
 int x;
  while (1)
   {
      cout<<"\n****************************"<<endl;
      cout<<"Operations on Graph"<<endl;
      cout<<"****************************"<<endl;
      cout<<"1.Create Graph using adjacency matrix"<<endl;
      cout<<"2.Display the Graph" <<endl;
      cout<<"3.DFS sequence of graph " <<endl;
      cout<<"4.BFS sequence of graph " <<endl;
      cout<<"5.Exit" <<endl;
      cout<<"Enter your choice :-";
      cin>>x;
      switch(x)
      {
         case 1:
            g.Create();
           
            break;
         
         case 2:
            g.Display();
            break;
         
         case 3:
           cout<<"DFS sequence of graph is :";
           g.DFS();
           break;
           
         case 4:
           cout<<"BFS sequence of graph is :";
           g.BFS();
           break;
           
         case 5:
           
            exit(1);
           
         default:
            cout<<"Wrong choice"<<endl; 
      }
    }

}
