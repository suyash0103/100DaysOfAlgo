#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int find(int i, int j, int zero, vector<int>& a, vector<int>& b, int sum)
{
	cout << i << " " << j << " " << zero << " " << sum << endl;
	if(i == -1 && j == -1)
	{
		ans = max(ans, sum);
		return sum;
	}
	
	if(zero > 0)
	{
		find(i - 1, j, zero - 1, a, b, sum + a[i] * 0);
		if(j >= 0)
		{
			find(i - 1, j - 1, zero, a, b, sum + a[i] * b[j]);
		}
	}
	else
	{
		find(i - 1, j - 1, zero, a, b, sum + a[i] * b[j]);
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<int> a(m);
	vector<int> b(n);
	
	for(int i = 0; i < m; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	find(m - 1, n - 1, m - n, a, b, 0);
	cout << ans;
}
