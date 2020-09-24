#include<bits/stdc++.h>

using namespace std;

int isPalin(string s, int start, int end)
{
	while(start < end)
	{
		if(s[start] != s[end])
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}

map<pair<int, int>, int> mp;

int count(string s, int start, int end)
{
//	cout << start << " " << end << endl;
	if(start > end)
	{
		return 0;
	}
	
	if(start == end)
	{
		return 0;
	}
	
	if(mp.find({start, end}) != mp.end())
	{
		
		return 0;
	}
	
	int a = isPalin(s, start, end);
	
	int ans =  count(s, start + 1, end) + count(s, start, end - 1) + a;
	mp[{start, end}] = ans;
	cout << start << " " << end << " " << ans << endl;
	return ans;
}

int main()
{
	string s;
	cin >> s;
	
	cout << count(s, 0, s.length() - 1) + s.length();
}
