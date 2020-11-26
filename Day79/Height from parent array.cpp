#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void find(vector<int>& par, vector<int>& ht, int i)
{
    if(ht[i] == -2)
    {
        find(par, ht, par[i]);
    }

    if(i != 0)
    {
        ht[i] = ht[par[i]] + 1;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> par(n);
    vector<int> ht(n, -2);

    for(int i = 0; i < n; i++)
    {
        cin >> par[i];
        if(par[i] == -1)
        {
            ht[i] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int j = i;
        int l = 0;
        int heightPar = 0;

        if(ht[j] == -2)
        {
            find(par, ht, j);
        }

        // while(ht[j] == -2)
        // {
        //     j = par[j];
        //     l++;
        //     heightPar = ht[j];
        // }

        // ht[i] = heightPar + l;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ht[i] << " ";
    }
}