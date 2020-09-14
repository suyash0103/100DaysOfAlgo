#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ans;

bool isPalin(string s, int st, int end)
{
	while(st < end)
	{
		if(s[st] != s[end])
			return false;
		st++;
		end--;
	}
	
	return true;
}

void find(string s, int start, int parts)
{
	if(isPalin(s, start, s.length() - 1))
	{
		ans = min(ans, parts);
		return;
	}
	
	if(start == s.length() - 1)
	{
		ans = min(ans, parts);
		return;
	}
	
	for(int i = start; i < s.length(); i++)
	{
		if(isPalin(s, start, i))
		{
			find(s, i + 1, parts + 1);
		}
	}
}

int main()
{
	string s;
	cin >> s;
	
	ans = s.length() - 1;
	
	find(s, 0, 0);
	
	cout << ans;
}
