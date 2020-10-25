#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	set<char> st;
	int start = 0;
	st.insert(s[0]);
	int end = 1;
	int ans = 0;
	
	while(end < s.length())
	{
		int l = st.size();
		ans = max(ans, l);
		while(st.find(s[end]) != st.end())
		{
			st.erase(s[start]);
			start++;
		}
		st.insert(s[end]);
		end++;
	}
	
	cout << ans;
}
