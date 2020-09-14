#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void find(string s, int left, int right)
{
	if(left == 0 && right == 0)
	{
		cout << s << endl;
		return;
	}
	
	if(left == right)
	{
		s.push_back('(');
		find(s, left - 1, right);
//		s = s.substr(0, s.length() - 1);
	}
	else
	{
		if(left != 0)
		{
			s.push_back('(');
			find(s, left - 1, right);
			s = s.substr(0, s.length() - 1);
		}
		s.push_back(')');
		find(s, left, right - 1);
		s = s.substr(0, s.length() - 1);
	}
}

int main()
{
	ll n;
	cin >> n;
	
	find("", n/2, n/2);
}
