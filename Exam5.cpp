#include<iostream>
#include<string.h>
using namespace std;
class Telephone
{
	int key,address;
	int mobile[12];
	string name[10];
	public:
	Telephone()

	{
		for(int i=0;i<10;i++)
		{
			mobile[i]=(-1);
		}
	}
	void insert_linearprob();
	void insert_Quadraticprob();
	void display();
	int Search(long k);
};

void Telephone:: insert_linearprob()
{
		cout<<"Enter the mobile no : ";
		cin>>key;
		address=key%10;                  //hash function 
		if(mobile[address]==(-1))
		{
			mobile[address]=key;
			cout<<"Enter the name :";
			cin>>name[address];
		}
		else
		{
			int i=address+1;
			while(address!=i)
			{
				if(mobile[i]==(-1))
				{
					mobile[i]=key;
					cout<<"Enter the name :";
					cin>>name[i];
					break;
				}
				else
				{
					i=i%10+1;
				}
			}
		}
}

void Telephone:: insert_Quadraticprob()
{
	cout<<"Enter the mobile no : ";
	cin>>key;
	address=key%10;                  //hash function 
	if(mobile[address]==(-1))
	{
		mobile[address]=key;
		cout<<"Enter the name :";
		cin>>name[address];
	}
	else
	{
	   while(1)
	    {
		int k = 0;
		int V = (address + k*k)%10;
		
		
			if(mobile[V]==(-1))
			{
				mobile[V]=key;
				cout<<"Enter the name :";
				cin>>name[V];
				break;
			}
			else
			{
				k++;
			}
	   }
	}
}

void Telephone:: display()
{   
    
  cout<<"\nindex \t\t Mobile\t\t Name"<<endl;
    for(int i=0;i<10;i++)
    {
        if(mobile[i]!=(-1))
        {
        cout<<"index:"<<i<<"\t\t"<<mobile[i]<<"\t"<<name[i]<<endl;
        }
        else{
            cout<<"index:"<<i <<"\t"<<-1<<endl;
        }
    }
}

int Telephone:: Search(long k)
{
        int i;
        for(i=0;i<10;i++)
         {
             if(mobile[i]==k)
             {
              cout<<mobile[i]<<" is Found at "<<  i  <<" Location With Name "<<name[i]<<endl;
             return i;
             }
             
         }
        if(mobile[i]!=k)
             {
              cout<<"Record not found"<<endl;
             }
        if(i==10)
         {
         return -1;
         }
return 0;
}


int main(){
    int m=1;
    Telephone t;
    int x;
   
 while(1)   
  {
    cout << "******************************"<< endl;
    cout << "Opeartion on hashtable "<< endl;
    cout << "******************************"<< endl;
    cout << "1. Insert record using linear probing"     << endl;
    cout << "2. Insert record using quadratic  probing "<< endl;
    cout << "3.Display client's database "<< endl;
    cout << "4.Search record  "<< endl;
    cout << "5.Exit "<< endl;
    cout << "Enter your choice : ";
    cin>>x;
    
    
        switch(x)
        {
          long k;
	      case 1:
	        int n;
	        cout<<"How many record want to insert : ";
	        cin>>n;
	        for(int i=0;i<n;i++)
	        {
	        t.insert_linearprob();	
	        }
	    
	        break;
		       
	      case 2:
	        cout<<"How many record want to insert : ";
	        cin>>n;
	        for(int i=0;i<n;i++)
	        {
	        t.insert_Quadraticprob();
	        }
	        break;
	      
	      case 3:
	        t.display();
	        break;
	      
	      case 4:
	        cout<<"Search:";
            cin>>k;
	        t.Search(k);
	        break;
	      
	      case 5:
	        exit(1);
	      default:
	        cout<<"wrong choice"<<endl;
       }
    }    
   
}
