#include<bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

Node* getNode(int val)
{
	Node* node = new Node();
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

int ans = INT_MAX;
map<Node*, int> mp;

int find(Node* node, Node* parent, int e, int total, int v)
{
	if(node == NULL)
	{
		return INT_MAX;
	}
	
	if(e >= total)
	{
		ans = min(ans, v);
		return ans;
	}
	
	if(mp.find(node) != mp.end())
	{
		return mp[node];
	}
	
	int a;
	
	if(parent != NULL)
	{
		a = 1;
		if(node->left && node->right)
		{
			a = 3;
		}
		else if(node->left || node->right)
		{
			a = 2;
		}
	}
	else
	{
		a = 0;
		if(node->left && node->right)
		{
			a = 2;
		}
		else if(node->left || node->right)
		{
			a = 1;
		}
	}
	
	int x = find(node->left, node, e + a, total, v + 1);
	int y = find(node->right, node, e + a, total, v + 1);
	
	int z = find(node->left, node, e, total, v);
	int w = find(node->right, node, e, total, v);
	
	x = min(x, y);
	x = min(x, z);
	
	mp[node] = min(x, w);
	return mp[node];
}

int main()
{
	Node* root = getNode(10);
	root->left = getNode(20);
	root->left->left = getNode(40);
	root->left->right = getNode(50);
//	root->left->right->left = getNode(70);
//	root->left->right->right = getNode(80);
	root->right = getNode(30);
//	root->right->right = getNode(60);
	
	Node* n = new Node();
	n = NULL;
	find(root, n, 0, 4, 0);
	if(ans == INT_MAX)
		ans = 1;
	cout << ans;
}
