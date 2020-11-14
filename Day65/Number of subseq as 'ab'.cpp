#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int factor = (k * (k + 1)) / 2;

    int a = 0;
    int ans = 0;

    for(char c : s) 
    {
        if(c == 'a')
        {
            a++;
        }
        else if(c == 'b')
        {
            ans += (a * factor);
        }
    }

    cout << ans << endl;
}