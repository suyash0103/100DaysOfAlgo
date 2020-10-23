#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int find(string s, int i, int sum)
{
	if(i == s.length())
	{
		return 0;
	}
	
	if(sum != 0 && sum % 8 == 0 && sum % 3 != 0)
	{
		ans++;
	}
	
	find(s, i + 1, sum);
	sum = sum * 10 + (s[i] - '0');
	find(s, i + 1, sum);
}

int main()
{
	string s;
	cin >> s;
	
	for(int i = 0; i < s.length(); i++)
	{
		int sum = s[i] - '0';
		if(sum % 3 != 0 && sum % 8 == 0)
		{
			ans++;
		}
		cout << "Out: " << sum << endl;
		for(int j = i + 1; j < s.length(); j++)
		{
			sum += (s[j] - '0');
			cout << "In: " << sum << endl;
			if(sum % 3 == 0)
			{
				continue;
			}
			else
			{
				if(sum % 8 == 0)
				{
					ans++;
				}
			}
		}
	}
	
	cout << ans;
	
//	find(s, 0, 0);
//	cout << ans;
}
