#include<bits/stdc++.h>

using namespace std;

struct Node 
{
	Node* left;
	Node* right;
	int val;
	int col;
};

Node* getNode(int val, int col)
{
	Node* node = new Node();
	node->val = val;
	node->col = col;
	
	return node;
}

int ans = INT_MAX;

pair<int, int> dfs(Node* root)
{
	if(root == NULL)
	{
		return {0, 0};
	}
	
	pair<int, int> pl = dfs(root->left);
	pair<int, int> pr = dfs(root->right);
	
	int total1 = pl.first + pr.first;
	int total0 = pl.second + pr.second;
	
	cout << root->val << " " << total1 << " " << total0 << endl;
	
	if(root->left || root->right)
	{
		ans = min(ans, abs(total1 - total0));
		cout << root->val << " " << ans << endl;
	}
	
	if(root->col == 1)
	{
		return {total1 + 1, total0};
	}
	else
	{
		return {total1, total0 + 1};
	}
}

int main()
{
	Node* root = getNode(1, 1);
	root->left = getNode(2, 1);
	root->right = getNode(3, -1);
	root->left->left = getNode(4, -1);
	root->right->left = getNode(5, 1);
	
	dfs(root);
	cout << ans;
}


















