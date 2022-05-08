//#include <bits/stdc++.h> or Assignment 11 OBST
/*Given sequence k = k1 <k2 < â€¦ < kn of n sorted keys, with a search probability pi for each key ki . 
Build the Binary search tree that has the least search cost given the access probability for each key.*/

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int sum(int frequency[], int i, int j)
{
    int sum = 0;
    for (int x = i; x <= j; x++)
        sum += frequency[x];
    return sum;
}

int optimalCost(int frequency[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return frequency[i];

    int frequencySum = sum(frequency, i, j);

    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int cost = optimalCost(frequency, i, r - 1) + optimalCost(frequency, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + frequencySum;
}

int optimalSearchTree(int keys[], int frequency[], int n)
{
    return optimalCost(frequency, 0, n - 1);
}

int main()
{
    int k,ch;
    do
    {
    cout<<"Optimal binary search tree"<<endl;
    cout<<"Enter the number of keys :";
    cin>>k;
    int keys[k];                    //= {10, 20, 30,40};
    int frequency[k] ;              //= {4, 2,6,3};
    cout<<"Enter the keys :";
    for (int i = 0; i < k; ++i) 
    {
    cin >> keys[i];
    }
    cout<<"Enter the frequency for each key :";
    for (int i = 0; i < k; ++i) 
    {
    cin >> frequency[i];
    }
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n);

    
    cout<<"\nDo u want to add more (y=>1/n=>0):";
    cin>>ch;
    
    }while(ch==1);
    return 0;
}

/*
OUTPUT

Cost of Optimal BST is 26
*/
