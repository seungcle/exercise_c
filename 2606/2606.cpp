#include<iostream>
#include<queue>

using namespace std;

int arr[101][101];
int check_cnt[101] = {0};

struct point
{
    int x;
    int y;
};

queue<int> q;

int bfs(int n)
{
    int cnt = 0;
    q.push(1);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(arr[tmp][i] == 1)
            {
                q.push(i);
                arr[tmp][i] = 0;
                arr[i][tmp] = 0;
                check_cnt[i] = 1;
            }
        }
    }
    for(int i=1;i<101;i++)
    {
        if(check_cnt[i] == 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    int n,r;
    cin >> n >> r;
    int x,y;
    for(int i=0;i<r;i++)
    {
        cin>>x>>y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    cout<<bfs(n)<<endl;
}