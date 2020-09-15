#include<bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

void print(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}

vector<Node*> constructBst(int start, int end)
{
	vector<Node*> vec;
	
	if(start > end)
	{
		vec.push_back(NULL);
		return vec;
	}
	
	if(start == end)
	{
		Node* root = new Node;
		root->val = start;
		root->left = NULL;
		root->right = NULL;
		vec.push_back(root);
		return vec;
	}

	for(int i = start; i <= end; i++)
	{
		vector<Node*> left = constructBst(start, i - 1);
		vector<Node*> right = constructBst(i + 1, end);
		
		for(int j = 0; j < left.size(); j++)
		{
			for(int k = 0; k < right.size(); k++)
			{
				Node* root = new Node;
				root->val = i;
				root->left = left[j];
				root->right = right[k];
				vec.push_back(root);
			}
		}
	}
	
	return vec;
}

int main()
{
	int n;
	cin >> n;
	
	vector<Node*> v = constructBst(1, n);
	for(int i = 0; i < v.size(); i++)
	{
		print(v[i]);
		cout << endl;
	}
}
