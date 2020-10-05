#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	vector<int> pre(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(i == 0)
		{
			pre[i] = v[i];
		}
		else
		{
			pre[i] = pre[i - 1] + v[i];
		}
	}
	
	int minsum = pre[0];
	int ans = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, pre[i] - minsum);
		minsum = min(minsum, pre[i]);
	}
	
	cout << ans;
}
