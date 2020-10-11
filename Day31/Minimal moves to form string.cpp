#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<int> dp(100, INT_MAX);

int find(string s, string st, int i, int t)
{
//	cout << s << " " << st << " " << i << " " << t << endl;
	
	if(st.length() > s.length())
	{
		return INT_MAX;
	}
	
	if(st.length() == s.length())
	{
		if(s == st)
		{
			ans = min(ans, t);
			return t;
		}
		return INT_MAX;
	}
	
	int a = INT_MAX;
	
	string stcopy = st;
	stcopy.push_back(s[i]);
	a = min(a, find(s, stcopy, i + 1, t + 1));
	stcopy = st;
	int x = stcopy.length();
	stcopy += stcopy;
	a = min(a, find(s, stcopy, i + x, t + 1));
	
	return a;
}

int main()
{
	string s;
	cin >> s;
	
	string st;
	st.push_back(s[0]);
	
	dp[0] = 1;
	
	for(int i = 1; i < s.length(); i++)
	{
		st.push_back(s[i]);
		
		string s2 = s.substr(i + 1, i + 1);
		
		dp[i] = min(dp[i], dp[i - 1] + 1);
		
		if(s2 == st)
		{
			dp[i * 2 + 1] = min(dp[i * 2 + 1], dp[i] + 1);
		}
	}
	
	cout << dp[s.length() - 1] << endl;
	
	st = "";
	st.push_back(s[0]);
	
	cout << find(s, st, 1, 1) << endl;
	cout << ans;
}
