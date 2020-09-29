#include<bits/stdc++.h>

using namespace std;

void find(int n, int x, int y, int ch)
{
	if(n <= x || n <= y || n == 1)
	{
		cout << "Winner is: " << ch << endl;
		return;
	}
	
	find(n - x, x, y, !ch);
	find(n - y, x, y, !ch);
	find(n - 1, x, y, !ch);
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i = 2; i <= n; i++)
	{
		if(dp[i - 1] == 0)
		{
			dp[i] = 1;
		}
		else if(i - x >= 0 && dp[i - x] == 0)
		{
			dp[i] = 1;
		}
		else if(i - y >= 0 && dp[i - y] == 0)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}
	
	cout << dp[n];
	
//	find(n, x, y, 0);
}













