#include <iostream>
using namespace std;

void obst(void);
void print(int, int);

float p[20],q[20],wt[20][20],c[20][20];
int r[20][20],n;

void obst(void)
{
  int i,j,k,l,min;
  for(int i=0; i<n;i++)
  {
      r[i][i] = 0;
      wt[i][i] =q[i];
      c[i][i] = 0.0;
      
      r[i][i+1] = i+1;
      wt[i][i+1] = q[i]+q[i+1]+p[i+1];
      c[i][i+1] = q[i]+q[i+1]+p[i+1];
      
  }
  r[n][n] = 0;
  c[n][n] =0.0;
  wt[n][n]= q[n];
  
  for(i=2 ;i<=n ;i++)
  {
      for(j=0;j<=n-1 ;j++)
      {
         wt[j][j+i]=q[j+i]+p[j+i]+wt[j][j+i-1];
            c[j][j+i]=9999;
            for(l=j+1;l<=j+i;l++)
             {
                if(c[j][j+i]>(c[j][l-1]+c[l][j+i]))
                 {
                    c[j][j+i]=c[j][l-
                    1]+c[l][j+i];
                    r[j][j+i]=l;
                 }
             }
            c[j][j+i]+=wt[j][j+i];  
      }
      cout<<endl;
  }
    cout<<"Optimal BST is :: ";
    cout<<"w[0]["<<n<<"] :: "<<wt[0][n]<<endl;
    cout<<"c[0]["<<n<<"] :: "<<c[0][n]<<endl;;
    cout<<"r[0]["<<n<<"] :: "<<r[0][n]<<endl;;
}

void print(int l1, int r1)
{
    if(l1>=r1)
    return;
    if(r[l1][r[l1][r1]-1]!=0)
    cout<<" Left child of "<<r[l1][r1]<<" :: "<<r[l1][r[l1][r1]-1]<<endl;;
    if(r[r[l1][r1]][r1]!=0)
    cout<<" Right child of "<<r[l1][r1]<<" :: "<<r[r[l1][r1]][r1]<<endl;;
    print(l1,r[l1][r1]-1);
    print(r[l1][r1],r1);
    return;
}   


int main()
{
    cout<<"****Optimal binary search tree****"<<endl;
    cout<<endl;
    cout<<"Enter the number of keys : ";
    cin>>n;
    cout<<"Enter the probability for successful search : "<<endl;
    for(int i=1;i<=n; i++)
    {
        cout<<"p["<<i<<"]"<<" = ";
        cin>>p[i];
    }
    cout<<"Enter the probability for unsuccessful search : "<<endl;
    for(int i=0;i<=n; i++)
    {
        cout<<"q["<<i<<"]"<<" = ";
        cin>>q[i];
    }
    
    obst();
    print(0,n);
    cout<<endl;
}
