#include<bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

Node* getNode(int v)
{
	Node* n = new Node();
	n->left = NULL;
	n->right = NULL;
	n->val = v;
	
	return n;
}

map<Node*, int> mp;

int find(Node* root)
{	
	if(root == NULL)
	{
		return 0;
	}
	
	if(mp.find(root) != mp.end())
	{
		return mp[root];
	}
	
	int left = find(root->left);
	int right = find(root->right);
	
	int excl = left + right;
	
	int incl = 1;
	if(root->left)
	{
		incl += find(root->left->left) + find(root->left->right);
	}
	if(root->right)
	{
		incl += find(root->right->left) + find(root->right->right);
	}
	
	mp[root] = max(incl, excl);
	
	return max(incl, excl);	
}

int main()
{
	Node* root = getNode(10);
	root->left = getNode(20);
	root->left->left = getNode(40);
	root->left->right = getNode(50);
	root->left->right->left = getNode(70);
	root->left->right->right = getNode(80);
	root->right = getNode(30);
	root->right->right = getNode(60);
	
	cout << find(root);
}
