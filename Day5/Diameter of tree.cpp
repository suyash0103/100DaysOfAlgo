#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ans = 1;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

Node* getNode(int val)
{
	Node* root = new Node();
	root->val = val;
	root->left = NULL;
	root->right = NULL;
	return root;
}

int diameter(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int left = diameter(root->left);
	int right = diameter(root->right);
	
	ans = max(ans, left + right + 1);
	
	return max(left, right) + 1;
}

int main()
{
	Node* root = getNode(1);
	root->left = getNode(2);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->left->right->left = getNode(6);
	root->left->right->right = getNode(7);
	
	root->right = getNode(3);
	root->right->right = getNode(8);
	root->right->right->right = getNode(9);
	root->right->right->right->left = getNode(10);
	root->right->right->right->right = getNode(11);
	root->right->right->right->left->right = getNode(12);
	
	diameter(root);
	
	cout << "Diameter: " << ans;
}
