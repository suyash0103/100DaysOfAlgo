#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	
	vector<int> v1(n1);
	vector<int> v2(n2);
	
	for(int i = 0; i < n1; i++)
		cin >> v1[i];
		
	for(int i = 0; i < n2; i++)
		cin >> v2[i];
	
	vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
	
	vector<int> lis1(n1, 1);
	vector<int> lis2(n2, 1);
	
	for(int i = 0; i <= n1; i++)
	{
		for(int j = 0; j <= n2; j++)
		{
			if(j < i)
			{
				if(v1[j] < v1[i] && lis1[j] + 1 > lis1[i])
				{
					lis1[i] = lis1[j] + 1;
				}
				if(v2[j] < v2[i] && lis2[j] + 1 > lis2[i])
				{
					lis2[i] = lis2[j] + 1;
				}
			}
			
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			
			if(v1[i - 1] == v2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
//				if(i == 1 || j == 1)
//				{
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					if(dp[i - 1][j - 1] == dp[i - 2][j - 2] + 1)
//					{
//						if(v1[i - 2] < v1[i - 1])
//						{
//							dp[i][j] = dp[i - 1][j - 1] + 1;
//						}
//						else
//						{
//							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//						}
//					}
//					else
//					{
//						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//					}
//				}
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= n1; i++)
	{
		for(int j = 0; j <= n2; j++)
		{
			ans = max(ans, min(dp[i][j], min(lis1[i], lis2[j])));
		}
//		cout << endl;
	}
	
	cout << ans;
}

//4
//7
//3 4 9 1
//5 3 8 9 10 2 1
