#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int ans = 0;

void dfs(int i, int j, int m, int n, set<pair<int, int> > block)
{
    if(i == m && j == n)
    {
        ans = 1;
        return;
    }

    if(i < 0 || j < 0 || i > m || j > n)
    {
        return;
    }

    pair<int, int> p;
    p.first = i;
    p.second = j;

    if(block.find(p) != block.end())
    {
        return;
    }

    dfs(i + 1, j, m, n, block);
    dfs(i, j + 1, m, n, block);
}

int main()
{
    int m, n, k, r;
    cin >> m >> n >> k >> r;

    set<pair<int, int> > block;

    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> p;
        p.first = a;
        p.second = b;
        block.insert(p);

        for(int j = 1; j <= r; j++)
        {
            int x1 = a + j;
            int x2 = a - j;
            int y1 = b + j;
            int y2 = b - j;

            p.first = x1;
            p.second = b;
            block.insert(p);

            p.first = x2;
            p.second = b;
            block.insert(p);

            p.first = a;
            p.second = y1;
            block.insert(p);

            p.first = a;
            p.second = y2;
            block.insert(p);
        }
    }

    dfs(1, 1, m, n, block);

    if(ans == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}