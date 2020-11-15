#include <iostream>

using namespace std;

int find(string s1, string s2, int i, int j)
{
    if(i == s1.length())
    {
        return INT32_MAX;
    }

    if(j == s2.length())
    {
        return 1;
    }

    int k = j;
    for(k = j; k < s2.length(); k++)
    {
        if(s1[i] == s2[k])
        {
            break;
        }
    }

    if(k == s2.length())
    {
        return 1;
    }

    return min(find(s1, s2, i + 1, k + 1) + 1, find(s1, s2, i + 1, j));
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << find(s1, s2, 0, 0) << endl;
}