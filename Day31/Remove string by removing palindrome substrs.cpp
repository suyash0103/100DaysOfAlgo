#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int palin(string s, int i, int& l, int& r)
{
	int len = 1;
	while(l >= 0 && r < s.length())
	{
		if(s[l] != s[r])
		{
			break;
		}
		len += 2;
		l--;
		r++;
	}
	
	if(i + 1 < s.length() && s[i] == s[i + 1])
	{
		int len2 = 2;
		l = i - 1;
		r = i + 2;
		while(l >= 0 && r < s.length())
		{
			if(s[l] != s[r])
			{
				break;
			}
			len2 += 2;
			l--;
			r++;
		}
		len = max(len, len2);
	}
	
	return len;
}

int find(string s, int i, int t)
{
//	cout << i << " " << t << endl;
	if(s.length() == 0)
	{
		ans = min(ans, t);
		return t;
	}
	
	if(i == s.length())
	{
		return INT_MAX;
	}
	
	int left = i - 1, right = i + 1;
	int x = palin(s, i, left, right);
	if(x != 1)
	{
		left++;
		right--;
		
		string scopy = s.substr(0, left);
		scopy += s.substr(right + 1);
		find(scopy, 0, t + 1);
	}
	find(s, i + 1, t);
	string scopy = s.substr(0, i);
	scopy += s.substr(i + 1);
	find(scopy, 0, t + 1);
}

int main()
{
	string s;
	cin >> s;
	
	find(s, 0, 0);
	cout << ans;
}
