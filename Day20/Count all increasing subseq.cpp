#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	int ans = 0;
	vector<int> lis(11, 0);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < v[i]; j++)
		{
			lis[v[i]] += lis[j];
		}
		lis[v[i]]++;
	}
	
	for(int i = 0; i < 10; i++)
		ans += lis[i];
	
	cout << ans;
}
