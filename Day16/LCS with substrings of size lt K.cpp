#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s1, string s2, int i, int j, int k)
{
	if(i == s1.length() || j == s2.length())
	{
		return 0;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	if(s1[i] == s2[j])
	{
		int l = 1;
		int pi = i;
		int pj = j;
		i++;
		j++;
		while(i < s1.length() && j < s2.length() && s1[i] == s2[j])
		{
			i++;
			j++;
			l++;
		}
		if(l >= k)
		{
			dp[pi][pj] = find(s1, s2, i, j, k) + l;
			return dp[pi][pj];
		}
		else
		{
			dp[pi][pj] = max(find(s1, s2, pi + 1, pj, k), find(s1, s2, pi, pj + 1, k));
			return dp[pi][pj];
		}
	}
	else
	{
		dp[i][j] = max(find(s1, s2, i + 1, j, k), find(s1, s2, i, j + 1, k));
		return dp[i][j];
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int k;
	cin >> k;
	
	cout << find(s1, s2, 0, 0, k) << endl;
	
//	vector<int> v(s1.length(), 0);
//	
//	for(int i = 0; i < s1.length(); i++)
//	{
//		for(int j = 0; j < s2.length(); j++)
//		{
//			if(s1[i] == s2[j])
//			{
//				if(i == 0 || j == 0)
//				{
//					v[i] = 1;
//				}
//				else
//				{
//					v[i] = max(v[i - 1] + 1, v[i]);
//				}
//			}
//			else
//			{
//				v[i] = max(0, v[i]);
//			}
//		}
//	}
//	
//	int ans = 0;
//	for(int i = 0; i < s1.length(); i++)
//	{
//		cout << v[i] << " ";
//		if(i == s1.length() - 1)
//		{
//			if(v[i] > v[i - 1] && v[i] >= k)
//			{
//				ans += v[i];
//			}
//		}
//		else
//		{
//			if(v[i] < v[i + 1])
//			{
//				continue;
//			}
//			else
//			{
//				if(v[i] >= k)
//				{
//					ans += v[i];
//				}
//			}
//		}
//	}
//	
//	cout << endl << ans;
}
