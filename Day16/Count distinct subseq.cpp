#include<bits/stdc++.h>

using namespace std;

set<string> st;

map<pair<string, int>, int> mp;

int find(string s, string sub, int i)
{
	if(i == s.length())
	{
		if(st.find(sub) == st.end())
		{
			st.insert(sub);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	if(mp.find({sub, i}) != mp.end())
	{
		return mp[{sub, i}];
	}
	
	sub.push_back(s[i]);
	int a = find(s, sub, i + 1);
	sub = sub.substr(0, sub.length() - 1);
	int b = find(s, sub, i + 1);
	
	mp[{sub, i}] = a + b;
	return a + b;
}

int main()
{
	string s;
	cin >> s;
	
	string sub = "";
//	auto start = high_resolution_clock::now();
	cout << find(s, sub, 0);
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stop - start);
//	cout << duration.count() << endl; 
}
