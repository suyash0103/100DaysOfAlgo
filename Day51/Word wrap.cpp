#include<iostream>
#include<vector>
#include<cmath>
#include<string>

//#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int find(string s, int m, int line, int i, int sum)
{
    cout << i << " " << line << " " << sum << endl;
    if(i >= s.length())
    {
//    	cout << "HERE";
        ans = min(ans, sum);
        return 1;
    }

    int filled = 0;
    int a = INT_MAX;
    while(i < s.length() && filled <= m)
    {
//        cout << "A ";
        if(s[i] == ' ' || i == s.length() - 1)
        {
        	if(i == s.length() - 1)
        	{
        		filled++;
			}
            int q = pow((m - filled), 3);
            cout << "q: " << q << endl;
            a = min(a, find(s, m, line + 1, i + 1, sum + q));
        }
//        if(i == s.length() - 1)
//        {
//        	find()
//		}
        i++;
        filled++;
    }
    
    if(i == s.length())
    {
//    	find(s, m, i, )
	}

    return a;
}

int main()
{
    string s;
    getline(cin, s);
    
	int m;
    cin >> m;   

    cout << find(s, m, 1, 0, 0) << endl;
    cout << ans;
}
