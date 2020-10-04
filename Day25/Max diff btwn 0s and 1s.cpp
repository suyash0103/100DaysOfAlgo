#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	vector<int> v(s.length());
	
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '1')
		{
			v.push_back(-1);
		}
		else
		{
			v.push_back(1);
		}
	}
	
	int maxhere = 0;
	int maxfinal = 0;
	int flag = 0;
	
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == 1)
		{
			flag = 1;
		}
		maxhere += v[i];
		maxfinal = max(maxfinal, maxhere);
		
		if(maxhere < 0)
		{
			maxhere = 0;
		}
	}
	
	if(flag == 0)
	{
		maxfinal = -1;
	}
	
	cout << maxfinal;
}




