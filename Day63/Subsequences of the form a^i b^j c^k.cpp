// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int a = 0;
    int b = 0;
    int c = 0;

    int ans = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a')
        {
            a++;
        }
        else if(s[i] == 'b')
        {
            b = 2 * b + pow(2, a) - 1;
        }
        else
        {
            c = 2 * c + b;
        }
    }

    cout << c << endl;
}