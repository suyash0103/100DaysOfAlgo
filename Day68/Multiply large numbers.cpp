#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<string> v;

    int z = 0;

    for(int i = s2.length() - 1; i >= 0; i--)
    {
        string s = "";
        for(int k = 0; k < z; k++)
        {
            s.push_back('0');
        }

        int m = (s2[i] - '0');
        int c = 0;
        for(int j = s1.length() - 1; j >= 0; j--)
        {
            int n = (s1[j] - '0');
            int prod = m * n + c;
            int units = prod % 10;
            c = prod / 10;

            s.push_back((units + '0'));
        }

        if(c > 0)
        {
            s.push_back((c + '0'));
        }

        reverse(s.begin(), s.end());
        v.push_back(s);

        z++;
    }

    cout << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;

    string sum1 = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        string sum2 = v[i];

        cout << sum1 << " " << sum2 << endl;

        int j = sum1.length() - 1;
        int k = sum2.length() - 1;

        string temp = "";
        
        int c = 0;
        while(j >= 0 && k >= 0)
        {
            // cout << j << " " << k << endl;
            int d1 = sum1[j] - '0';
            int d2 = sum2[k] - '0';

            int add = d1 + d2 + c;
            int units = add % 10;
            c = add / 10;

            // cout << "units: " << units << endl;

            temp.push_back((units + '0'));

            j--;
            k--;
        }

        // cout << "h: " << temp << endl;

        while(k >= 0)
        {
            int d = sum2[k] - '0';
            d += c;

            int add = d + c;
            int units = add % 10;
            c = add / 10;

            temp.push_back((units + '0'));

            k--;
        }

        while(j >= 0)
        {
            int d = sum1[j] - '0';
            d += c;

            int add = d + c;
            int units = add % 10;
            c = add / 10;

            temp.push_back((units + '0'));

            j--;
        }

        if(c > 0)
        {
            temp.push_back((c + '0'));
        }

        reverse(temp.begin(), temp.end());
        cout << "Temp: " << temp << endl;
        sum1 = temp;
    }
}