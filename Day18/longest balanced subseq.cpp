#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int open = 0;
	int close = 0;
	int bal = 0;
	
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(')
		{
			open++;
		}
		else
		{
			if(open > 0)
			{
				open--;
				bal += 2;
			}
			close++;
		}
	}
	
	cout << bal;
}
