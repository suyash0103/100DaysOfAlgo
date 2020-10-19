#include<bits/stdc++.h>

using namespace std;

int ans = 0;

bool find(string s, string pat, int i, int j)
{
	if(i == s.length())
	{
		ans = 1;
		return true;
	}
	
	if(j == pat.length())
	{
		return false;
	}
	
	bool a = false;
	
	if(pat[j] != '*' && pat[j] != '?')
	{
		if(s[i] == pat[j])
		{
			a = a || find(s, pat, i + 1, j + 1);
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(pat[j] == '*')
		{
			a = a || find(s, pat, i, j + 1);
			a = a || find(s, pat, i + 1, j + 1);
			a = a || find(s, pat, i + 1, j);
		}
		else
		{
			a = a || find(s, pat, i + 1, j + 1);
		}
	}
	
	return a;
}

int main()
{
	string s, pat;
	cin >> s >> pat;
	
	cout << find(s, pat, 0, 0) << endl;
	cout << ans;
}
