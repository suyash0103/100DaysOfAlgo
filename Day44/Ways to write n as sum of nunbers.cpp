#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<int> v;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int i)
{
//	cout << n << " " << i << endl;
	if(n < 0)
	{
		return 0;
	}
	
	if(n == 0)
	{
//		ans++;
		for(int j = 0; j < v.size(); j++)
			cout << v[j] << " ";
		cout << endl;
		return 1;
	}
	
	if(i > n)
	{
		return 0;
	}
	
	if(dp[n][i] != -1)
	{
		return dp[n][i];
	}
	
	int a = 0;
	
	v.push_back(i);
	a += find(n - i, i);
	v.pop_back();
	a += find(n, i + 1);
	
	dp[n][i] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	cout << find(n, 1) << endl;
//	cout << ans;
}
