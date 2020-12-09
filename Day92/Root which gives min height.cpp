#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> deg(n, 0);
    int maxDeg = 0;
    int root = 0;

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        deg[a]++;
        deg[b]++;

        if(maxDeg < deg[a])
        {
            maxDeg = deg[a];
            root = a;
        }

        if(maxDeg < deg[b])
        {
            maxDeg = deg[b];
            root = b;
        }
    }

    cout << root << endl;
}