#include<iostream>

using namespace std;

int N,M,d,r,c;
int arr[50][50];
int vs[50][50];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int clean(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(arr[nx][ny] == 0 && vs[nx][ny] ==0) return 0;
    }
    return 1;
}

void dfs()
{
    int x = r;
    int y = c;
    int cnt = 0;
    while(1)
    {
        if(vs[x][y] == 0 && arr[x][y] == 0)
        {
            cnt++;
            vs[x][y] = 1;
        }
        else if(clean(x,y))
        {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if(tx < 0 || tx >= N || ty < 0 || ty >= M) break;
            if(arr[tx][ty] == 1) break;
            if(arr[tx][ty] == 0)
            {
                x = tx;
                y = ty;
            }
        }
        else
        {
            d = (d+1)%4;
            int tx = x + dx[d];
            int ty = y + dy[d];
            if(tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
            if(arr[tx][ty] == 0 && vs[tx][ty] == 0)
            {
                x = tx;
                y = ty;
            }
        }
    }
    cout << cnt;
}

void Input()
{
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> arr[i][j];
}

int main()
{
    Input();
    dfs();
}

//다시..

