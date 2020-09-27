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
	
	vector<int> lis(n, 1);
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] % 2 == 0 && v[j] % 2 == 1 && lis[j] + 1 > lis[i] && v[i] > v[j])
			{
				lis[i] = lis[j] + 1;
			}
			else if(v[i] % 2 == 1 && v[j] % 2 == 0 && lis[j] + 1 > lis[i] && v[i] > v[j])
			{
				lis[i] = lis[j] + 1;
			}
		}
	}
	
	int ans = lis[0];
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, lis[i]);
	}
	
	cout << ans;
}
