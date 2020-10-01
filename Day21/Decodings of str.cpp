#include<bits/stdc++.h>

using namespace std;

map<int, char> mp;

set<string> st;

int find(string s, string newstr, int i)
{
    // cout << newstr << endl;
	if(i >= s.length())
	{
	   // cout << newstr;
		if(st.find(newstr) == st.end())
		{
			st.insert(newstr);
			cout << newstr << endl;
			return 1;
		}
		return 0;
	}
	
	int a = 0;
	
	if(i + 1 < s.length())
	{
		string ss = "";
		ss.push_back(s[i]);
		ss.push_back(s[i + 1]);
		int t = stoi(ss);
// 		cout << t << endl;
		if(t <= 26)
		{
			string n = newstr;
			n.push_back(mp[t]);
// 			cout << n << endl;
			a += find(s, n, i + 2);
		}
	}
	
	string sss = "";
	sss.push_back(s[i]);
	int a = stoi(sss);
	string n = newstr;
	n.push_back(mp[a]);
// 	cout << n << endl;
// 	cout << a << endl;
	a += find(s, n, i + 1);
	
	return a;
}

int main()
{
	string s;
	cin >> s;
	
	mp[1] = 'A';
	mp[2] = 'B';
	mp[3] = 'C';
	mp[4] = 'D';
	mp[5] = 'E';
	mp[6] = 'F';
	mp[7] = 'G';
	mp[8] = 'H';
	mp[9] = 'I';
	mp[10] = 'J';
	mp[11] = 'K';
	mp[12] = 'L';
	mp[13] = 'M';
	mp[14] = 'N';
	mp[15] = 'O';
	mp[16] = 'P';
	mp[17] = 'Q';
	mp[18] = 'R';
	mp[19] = 'S';
	mp[20] = 'T';
	mp[21] = 'U';
	mp[22] = 'V';
	mp[23] = 'W';
	mp[24] = 'X';
	mp[25] = 'Y';
	mp[26] = 'Z';
	
	find(s, "", 0);
	cout << st.size();
}
