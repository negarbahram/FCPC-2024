#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
pair<int,int> w[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string c[MAXN];
bool mark[MAXN][MAXN];
int comp[MAXN][MAXN], res[MAXN * MAXN], ans[10];
int n;

void dfs(int x, int y, int component)
{
    comp[x][y] = component;
    mark[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = x+ w[i].first, yy = y + w[i].second;
        if(xx < 0 or yy < 0 or xx >= n or yy >= n)
            continue;
        if(!mark[xx][yy] and c[xx][yy] == '.')
            dfs(xx, yy, component);
        if(c[xx][yy] == 'B')
            res[component] |= 1;
        else if(c[xx][yy] == 'W')
            res[component] |= 2;
    }
}

void bfs(int x, int y, int component)
{
    comp[x][y] = component;
    mark[x][y] = true;
    queue <pair<int,int> > q;
    q.push({x,y});
    while(q.size())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int xx = x + w[i].first, yy = y + w[i].second;
            if(xx < 0 or yy < 0 or xx >= n or yy >= n)
                continue;
            if(!mark[xx][yy] and c[xx][yy] == '.')
            {
                q.push({xx,yy});
                mark[xx][yy] = true;
                comp[xx][yy] = component;
            }
            if(c[xx][yy] == 'B')
                res[component] |= 1;
            else if(c[xx][yy] == 'W')
                res[component] |= 2;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            {
                if(c[i][j] == '.' and !mark[i][j])
                    bfs(i, j, ++cnt);
                if(c[i][j] == '.')
                    ans[res[comp[i][j]]]++;
            }
    cout << ans[1] << " " << ans[2] << endl;
    return 0;
}
