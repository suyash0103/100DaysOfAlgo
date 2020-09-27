#include<bits/stdc++.h>

using namespace std;

int fact(int n)
{
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans = ans * i;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int k;
	cin >> k;
	
	vector<int> lis(n, 0);
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j])
			{
				lis[i]++;
				if(lis[i] == k - 1)
				{
					ans++;
				}
				else if(lis[i] == k)
				{
					ans += k;
				}
				else if(lis[i] > k)
				{
					ans += (fact(lis[i]) / fact(k - 1));
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << lis[i] << " ";
	}
	cout << endl;
	cout << ans;
}
