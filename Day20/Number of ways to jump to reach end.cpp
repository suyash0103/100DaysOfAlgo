#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> ans(n, 0);
	ans[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--)
	{
		int jumps = v[i];
		int j = i + 1;
		while(jumps > 0 && j < n)
		{
			ans[i] += ans[j];
			j++;
			jumps--;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}
