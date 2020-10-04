#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int find(vector<int>& v, int n, int i, int sz, int sum)
{
	if(sum == 0)
	{
		ans = max(ans, sz);
		return sz;
	}
	
	if(i == n)
	{
		return 0;
	}
	
	if(sum < 0)
	{
		return 0;
	}
	
	int a = 0;
	
	a = max(a, find(v, n, i + 1, sz, sum));
	a = max(a, find(v, n, i + 1, sz + 1, sum - v[i]));
	
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)	
		cin >> v[i];
	
	int sum;
	cin >> sum;
	
	cout << find(v, n, 0, 0, sum) << endl;
	cout << ans;
}
