#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int find(vector<int>& v, int n, int i, int sum1, int sum2)
{
	if(i == v.size())
	{
		ans = min(ans, abs(sum1 - sum2));
		return ans;
	}
	
	int a = INT_MAX;
	
	a = min(a, find(v, n, i + 1, sum1 + v[i], sum2));
	a = min(a, find(v, n, i + 1, sum1, sum2 + v[i]));
	
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, n, 0, 0, 0) << endl;
	cout << ans;
}
