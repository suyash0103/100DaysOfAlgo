#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n = 8;

    vector<vector<int> > vis(n, vector<int>(n, 0));

    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(sx, sy), 0));

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        int x = p.first.first;
        int y = p.first.second;

        int d = p.second;

        if(x == dx && y == dy)
        {
            cout << d << endl;
            break;
        }

        vis[x][y] = 1;

        if(x - 1 >= 0 && y - 2 >= 0 && vis[x - 1][y - 2] == 0)
        {
            q.push(make_pair(make_pair(x - 1, y - 2), d + 1));
        }

        if(x - 2 >= 0 && y - 1 >= 0 && vis[x - 2][y - 1] == 0)
        {
            q.push(make_pair(make_pair(x - 2, y - 1), d + 1));
        }

        if(x - 1 >= 0 && y + 2 < n && vis[x - 1][y + 2]  == 0)
        {
            q.push(make_pair(make_pair(x - 1, y + 2), d + 1));
        }

        if(x - 2 >= 0 && y + 1 < n && vis[x - 2][y + 1] == 0)
        {
            q.push(make_pair(make_pair(x - 2, y + 1), d + 1));
        }

        if(x + 1 < n && y - 2 >= 0 && vis[x + 1][y - 2] == 0)
        {
            q.push(make_pair(make_pair(x + 1, y - 2), d + 1));
        }

        if(x + 2 < n && y - 1 >= 0 && vis[x + 2][y - 1] == 0)
        {
            q.push(make_pair(make_pair(x + 2, y - 1), d + 1));
        }

        if(x + 1 < n && y + 2 < n && vis[x + 1][y + 2] == 0)
        {
            q.push(make_pair(make_pair(x + 1, y + 2), d + 1));
        }

        if(x + 2 < n && y + 1 < n && vis[x + 2][y + 1] == 0)
        {
            q.push(make_pair(make_pair(x + 2, y + 1), d + 1));
        }
    }
    
}