#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int ans = 0;

void dfs(vector<vector<int> >& g, vector<vector<int> >& vis, int sx, int sy, int dx, int dy)
{
    vis[sx][sy] = 1;

    if(sx == dx and sy == dy)
    {
        ans = 1;
        return;
    }

    if(sx - 1 >= 0 && vis[sx - 1][sy] == 0)
    {
        dfs(g, vis, sx - 1, sy, dx, dy);
    }

    if(sy - 1 >= 0 && vis[sx][sy - 1] == 0)
    {
        dfs(g, vis, sx, sy - 1, dx, dy);
    }

    if(sx + 1 < g.size() && vis[sx + 1][sy] == 0)
    {
        dfs(g, vis, sx + 1, sy, dx, dy);
    }

    if(sy + 1 < g.size() && vis[sx][sy + 1] == 0)
    {
        dfs(g, vis, sx, sy + 1, dx, dy);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > g(n, vector<int>(n, 0));

    int sx, sy, dx, dy;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
            else if(g[i][j] == 2)
            {
                dx = i;
                dy = j;
            }
        }
    }

    vector<vector<int> > vis(n, vector<int>(n, 0));

    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(sx, sy), 0));

    // cout << sx << " " << sy << endl;
    // cout << dx << " " << dy << endl;

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        int x = p.first.first;
        int y = p.first.second;

        int d = p.second;

        // cout << "x: " << x << " y: " << y << " d: " << d << endl;

        if(x == dx && y == dy)
        {
            cout << d << endl;
            break;   
        }

        vis[x][y] = 1;

        d += 1;

        if(x - 1 >= 0 && vis[x - 1][y] == 0 && g[x - 1][y] != 0)
        {
            q.push(make_pair(make_pair(x - 1, y), d));
        }

        if(x + 1 < n && vis[x + 1][y] == 0 && g[x + 1][y] != 0)
        {
            q.push(make_pair(make_pair(x + 1, y), d));
        }

        if(y - 1 >= 0 && vis[x][y - 1] == 0 && g[x][y - 1] != 0)
        {
            q.push(make_pair(make_pair(x, y - 1), d));
        }

        if(y + 1 < n && vis[x][y + 1] == 0 && g[x][y + 1] != 0)
        {
            q.push(make_pair(make_pair(x, y + 1), d));
        }
    }
    

    // dfs(g, vis, sx, sy, dx, dy);

    // cout << ans << endl;

}