/*									************ Assignment No 10 ************
Problem statement :A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of 
any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for 
finding any keyword. Use Height balance tree and find the complexity for finding a keyword.

*/

#include <iostream>
using namespace std;

class Node
{
public:
	Node *Left, *Right;
	string key, val;
	int height;
};

class Avl
{
public:
	Node *create(Node *root, string key, string val)
	{
		root = new Node();
		root->key = key;
		root->val = val;
		root->Left = NULL;
		root->Right = NULL;
		root->height = 1;
		return root;
	}

	Node *insert(Node *root, string key, string val)
	{
		if (root == NULL)
			return create(root, key, val);

		else if (key < root->key)
		{
			root->Left = insert(root->Left, key, val);
		}

		else if (key > root->key)
		{
			root->Right = insert(root->Right, key, val);
		}

		return root;
	}

	int height(Node *temp)
	{
		int h = 0;
		if (temp != NULL)
		{
			int l_height = height(temp->Left);
			int r_height = height(temp->Right);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}

		return h;
	}

	int balFac(Node *temp)
	{
		int l_height = height(temp->Left);
		int r_height = height(temp->Right);
		int b_factor = l_height - r_height;

		return b_factor;
	}

	Node *rr(Node *root)
	{
		Node *temp;
		temp = root->Right;
		root->Right = temp->Left;
		temp->Left = root;

		return temp;
	}

	Node *ll(Node *root)
	{
		Node *temp;
		temp = root->Left;
		root->Left = temp->Right;
		temp->Right = root;

		return temp;
	}

	Node *lr(Node *root)
	{
		Node *temp;
		temp = root->Left;
		root->Left = rr(temp);

		return ll(root);
	}

	Node *rl(Node *root)
	{
		Node *temp;
		temp = root->Left;
		root->Right = ll(temp);

		return rr(root);
	}

	Node *balance(Node *root)
	{
		int bal_factor = balFac(root);
		if (bal_factor > 1)
		{
			if (balFac(root->Left) > 0)
				root = ll(root);
			else
				root = lr(root);
		}

		else if (bal_factor < -1)
		{
			if (balFac(root->Right) > 0)
				root = rl(root);
			else
				root = rr(root);
		}
		return root;
	}

	void inorder(Node *root)
	{
		if (root == NULL)
			return;
		inorder(root->Left);
		cout << root->key << "  " << root->val << endl;
		inorder(root->Right);
	}

	void modify(Node *root, string modKey)
	{
		string NewMeaning;
		if(root == NULL){
			cout<<"Enter a valid Word"<<endl;
			return;
		}

		if (modKey.compare(root->key) < 0)
			modify(root->Left, modKey);
		else if (modKey.compare(root->key) > 0)
			modify(root->Right, modKey);
		else if (modKey.compare(root->key) == 0)
		{
			cout << "\nWord Found!\nWord: " << root->key << "\t" << root->val;

			cout << "\nEnter new Meaning : ";
			cin >> NewMeaning;
			root->val = NewMeaning;
			cout << "\nDictionary Modified!";
		}
	}

	void delet(Node *root, string delKey)
	{
		Node *current = root;
		Node *temp;
		bool isleft = 0;
		int flag = 1;

		while (current != NULL  && current->key.compare(delKey) != 0)
		{
			if (current->key.compare(delKey) > 0)
			{
				temp = current;
				isleft = 1;
				current = current->Left;
			}

			else if (current->key.compare(delKey) < 0)
			{
				temp = current;
				isleft = 0;
				current = current->Right;
			}
			else{
				flag = 0;
				break;

			}
		}
		if(flag==0){
			cout << "\nWord. not found!";
			return;
		}
		if(current->key.compare(delKey) < 0){
			cout<<"-1"<<endl;
		}
		else if(current->key.compare(delKey) > 0){
			cout<<"+1"<<endl;
		}
		else{
			cout<<"compare value :- "<<current->key.compare(delKey)<<endl;
		}
		
		if (current->key.compare(delKey) == 0)
		{
			if (current->Left == NULL && current->Right == NULL)
			{
				if (isleft == 1)
				{
					temp->Left = NULL;
				}
				else
					temp->Right = NULL;
			}

			else
			{
				if (isleft == 1)
				{
					if (current->Left == NULL)
					{
						temp->Left = current->Right;
					}

					else if (current->Right == NULL)
					{
						temp->Left = current->Left;
					}

					else
					{
						string k = current->Left->key;
						string v = current->Left->val;
						temp->Left = current->Right;
						insert(root, k, v);
					}
				}
				else
				{
					if (current->Left == NULL)
					{
						temp->Right = current->Right;
					}

					else if (current->Right == NULL)
					{
						temp->Right = current->Left;
					}

					else
					{
						string k = current->Left->key;
						string v = current->Left->val;
						temp->Right = current->Right;
						insert(root, k, v);
					}
				}
			}

			cout << "\nDeleted!";
			return;
		}
		else
		{
			return;
		}
		
	}
};

int main()
{
	int choice, dchoice;
	string key, val, modKey, delKey;
	Node *root = new Node();
	Avl avlObj;

	do
	{
		cout << "\n1. Add word\n2. Delete word\n3. Update word\n4. Display\n5. Exit"<<endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		cout<<"Enter the number of words you want to enter :- ";
		int n;
		cin>>n;
		cout<<endl;
		while(n--){
			cout << "\nEnter the word and meaning :- ";
			cin >> key;
			cout<<endl;
			cout<<"Enter Meaning :- ";
			cin>> val;
			cout<<endl;
			root = avlObj.insert(root, key, val);
			cout<<endl;
		}
			break;

		case 2:
			cout << "\nEnter the word you want to delete :- ";
			cin >> delKey;
			cout<<endl;
			avlObj.delet(root, delKey);
			cout<<endl;
			break;

		case 3:
			cout << "\nEnter the word you want to modify :- ";
			cin >> modKey;
			cout<<endl;
			avlObj.modify(root, modKey);
			cout<<endl;
			break;

		case 4:
		
			avlObj.inorder(root);

			break;

		default:
			cout << "\nWrong option. Try again";
		}

	} while (choice != 5);

	return 0;
}
