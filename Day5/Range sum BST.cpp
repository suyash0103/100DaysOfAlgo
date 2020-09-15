#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ans = 0;

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

void sum(Node* root, int l, int r)
{
	if(root == NULL)
		return;
	
	if(root->val >= l && root->val <= r)
	{
		ans += root->val;
	}
	
	sum(root->left, l, r);
	sum(root->right, l, r);
}

int main()
{
	int l, r;
	cin >> l >> r;
	
	Node* root = getNode(10);
	root->left = getNode(5);
	root->left->left = getNode(3);
	root->left->right = getNode(7);
	
	root->right = getNode(15);
	root->right->right = getNode(18);

	sum(root, l, r);
	
	cout << "Range sum: " << ans;
}
