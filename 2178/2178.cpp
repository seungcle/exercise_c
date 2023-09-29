#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int arr[101][101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

struct point
{
    int x;
    int y;
};
queue<point> q;

int bfs(int N,int M)
{
    point tmp;
    tmp.x = 0;
    tmp.y = 0;
    q.push(tmp);
    while(!q.empty())
    {
        point tmp2;
        tmp2 = q.front();
        int x = tmp2.x;
        int y = tmp2.y;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(0 <= new_x && new_x < N && 0 <= new_y && new_y < M)
            {
                if(arr[new_x][new_y] == 1)
                {
                    tmp2.x = new_x;
                    tmp2.y = new_y;
                    q.push(tmp2);
                    arr[new_x][new_y] = arr[x][y] + 1;
                }
            } 
        }
    }
    return arr[N-1][M-1];
}

int main()
{
    int N,M;
    cin>> N>> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
    cout << bfs(N,M) << endl;
}