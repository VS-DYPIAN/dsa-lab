/*Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
using chaining with / without replacement. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, 
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)
chain is not working*/

#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct Dict
{
  public:
	char word[20];
	char meaning[20];
	int chain;

}; 	

class Hashfunction
{
	public:
		Dict ht[max];               //ht is array of type class dict
		char w[30],m[30];
		Hashfunction()	
		{
			for(int i=0;i<max;i++)
			{
				strcpy(ht[i].word,"-1");
				strcpy(ht[i].meaning,"-1");
				ht[max].chain= -1;
			}
		}
		
		int hash(char ckey[10])
		{
			int i,s=0,c=0,x=0;    // string to ascii conversion
			for(i=0;ckey[i]!='\0';i++)   // "/0" is used to check end of string
			{
				s=s+ckey[i];
			}
            x= s%max;
            c=x;
			return(c);
			while(1)
           {

                        if(strcmp(ht[x].word,"-1")==0)
                    {
                        strcpy(ht[x].word,w);
                        strcpy(ht[x].meaning,m);
                        if(c!=x)
                        {
                            ht[c].chain=x;
                        }
                        break;
                    }
                    else
                         x=(x+1)%10;

                        if(c==x)
                        {  cout<<"\n hash table is full";
                            break;
                        }
            }
			
		}
		
		void insert(Dict d);
		void display();
		int search(char cW[]);
		void delword(char cW[]);
		
};

void Hashfunction::insert(Dict d)
{
	int iIndex=10;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(d.word)+i*i)%max;
		//cout<<"\n\n Position :"<<" "<<i<<" " << "-1"<<" "<<iIndex<<endl;
		if(i>0)
		
		//cout<<"\n Collision is at "<<iIndex<<endl; 
		
		if(strcmp(ht[iIndex].word,"-1")==0)
		{
			ht[iIndex]=d;
			break;
		}
	}	
		
}

void Hashfunction::display()
{
	cout<<"index\t\tWord\t\tmeaning\t\tchain";
	for(int i=0;i<max;i++)
	{
		cout<<"\n"<<i<<"\t\t"<<ht[i].word<<"\t\t"<<ht[i].meaning<<"\t\t"<<ht[max].chain<<"\n";
	}

}

int Hashfunction::search(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].word,cW)==0)
		{
			cout<<"Word Found and Meaning is :"<<ht[iIndex].meaning<<endl;
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"Word Not Found"<<endl;
	return 0;
}

void Hashfunction::delword(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].word,cW)==0)
		{
			cout<<"\nWord Found and delword :"<<ht[iIndex].meaning<<endl;
			strcpy(ht[iIndex].word,"-1");
			strcpy(ht[iIndex].meaning,"-1");
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"Word Not Found"<<endl;
	
}
	
int main()
{
	char cW[10];
	int x,iFlag=0;
	Hashfunction h;
	Dict d;
	while(1)
	{
	      cout<<"**********"<<endl;
	      cout<<"Operations on dictionary using hashtable"<<endl;
	      cout<<"**********"<<endl;
	      cout<<"1.Insert "<<endl;
	      cout<<"2.Display Dictionary" <<endl;
	      cout<<"3.Search " <<endl;
	      cout<<"4.Delete" <<endl;
	      cout<<"5.Exit" <<endl;
	      cout<<"Enter your choice :-";
	      cin>>x;
                switch(x)
		{
			case 1:
				cout<<"Enter word:";
				cin>>d.word;
				cout<<"Enter Meaning:";
				cin>>d.meaning;
				h.insert(d);
				break;
			
			case 2:
				h.display();
				break;
				
			case 3:
				cout<<"\n Enter word to be searched:";
				cin>>cW;
				h.search(cW);
				break;
				
			case 4:
				cout<<"\n Enter the word to be deleted:";
				cin>>cW;
				h.delword(cW);
				break;
				
			case 5:
				exit(1);
			
			default:
                cout<<"Wrong choice"<<endl;
				
		}
	}			

}
