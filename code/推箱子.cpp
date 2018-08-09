#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char mp[10][10];
int vis[10][10][10][10];
int data[4][2] = {0,1,0,-1,1,0,-1,0};
int n,m;
struct node
{
    int x,y,step;
    int xx,yy;
    node(int _x,int _y,int _step,int _xx,int _yy):x(_x),y(_y),step(_step),xx(_xx),yy(_yy){ }
};

int bfs(int sxx, int syy, int sx, int sy)
{
    queue<node> q;
    q.push(node(sx,sy,0,sxx,syy));
    while(!q.empty())
    {
        node s = q.front();
        q.pop();
        vis[s.x][s.y][s.xx][s.yy] = 1;
        if(mp[s.xx][s.yy] == '@') 
            return s.step;

        for(int i = 0; i < 4; i++)
        {
            node tmp = s;
            tmp.step++;
            tmp.x += data[i][0];
            tmp.y += data[i][1];

            if(tmp.x > n || tmp.y > m || tmp.x < 1 || tmp.y < 1)
                continue;

            if(mp[tmp.x][tmp.y] == '#')
                continue;

            if(tmp.x == tmp.xx && tmp.y == tmp.yy)
            {
                tmp.xx += data[i][0];
                tmp.yy += data[i][1];
            }

            if(tmp.xx > n || tmp.yy > m || tmp.xx < 1 || tmp.yy < 1)
                continue;

            if(mp[tmp.xx][tmp.yy] == '#')
                continue;

            if(vis[tmp.x][tmp.y][tmp.xx][tmp.yy] != 1)
                q.push(tmp);
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        cin >> &mp[i][1];       //这里每次都输入一串字符串
    }
    int sx,sy,xx,yy;
    for (int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(mp[i][j] == 'X')
            {
                sx = i;
                xy = j;
            }
            if(mp[i][j] == '*')
            {
                xx = i;
                yy = j;
            }
        }
    }
    cout << bfs(xx,yy,sx,sy)<<endl;
    return 0;
}