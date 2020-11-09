#include <iostream>

using namespace std;

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    if(s1.length() > s2.length())
    {
        cout << "FALSE";
        return 1;
    }

    if(s1.length() == s2.length())
    {
        if(s1 == s2)
        {
            cout << "TRUE";
        }
        else
        {
            cout << "FALSE";
        }
        return 1;
    }
    
    int i = 0;
    int j = 0;

    while(i < s1.length() && j < s2.length())
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }

        else
        {
            j++;
        }
    }

    if(i == s1.length())
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
    
}