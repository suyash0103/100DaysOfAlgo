#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<int, int>, int> mp;

int find(string s, int i, int sum)
{
	if(sum % 8 == 0 && sum != 0)
	{
		ans = 1;
		return 1;
	}
	
	if(i == s.length())
	{
		return 0;
	}
	
	if(mp.find({i, sum}) != mp.end())
	{
		return mp[{i, sum}];
	}
	
	int a = 0;
	
	a = a || find(s, i + 1, sum);
	sum = sum * 10 + (s[i] - '0');
	a = a || find(s, i + 1, sum);
	
	mp[{i, sum}] = a;
	return a;
}

int main()
{
	string s;
	cin >> s;
	
	cout << find(s, 0, 0) << endl;
	cout << ans;
}
