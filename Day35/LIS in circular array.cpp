#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n + n);
	for(int j = 0; j < n; j++)
	{
		cin >> v[j];
	}
	
	for(int i = n; i < 2 * n; i++)
	{
		v[i] = v[i - n];
	}
	
	int ans = 1;
	for(int j = 0; j < n; j++)
	{
		vector<int> lis(n, 1);
		int x = 0;
		for(int i = j + 1; i < j + n; i++)
		{
			for(int k = j; k < i; k++)
			{
				if(v[i] > v[k] && lis[k - j] + 1 > lis[i - j])
				{
					lis[i - j] = lis[k - j] + 1;
					ans = max(ans, lis[i - j]);
				}
			}
		}
	}
	
	cout << ans;
}

