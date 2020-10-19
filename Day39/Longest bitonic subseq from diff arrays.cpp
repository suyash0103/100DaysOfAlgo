#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v1(n);
	vector<int> v2(n);
	
	for(int i = 0; i < n; i++)
		cin >> v1[i];
		
	for(int i = 0; i < n; i++)
		cin >> v2[i];
	
	vector<int> lis1(n, 1);
	vector<int> lis2(n, 1);
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v1[i] > v1[j] && lis1[i] < lis1[j] + 1)
			{
				lis1[i] = lis1[j] + 1;
			}
		}
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = n - 1; j > i; j--)
		{
			if(v2[i] > v2[j] && lis2[i] < lis2[j] + 1)
			{
				lis2[i]=  lis2[j] + 1;
			}
		}
	}
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			ans = max(ans, lis1[i] + lis2[j]);
		}
	}
	
	cout << ans;
}




