#include<iostream>
#include<queue>
using namespace std;

int arr[101][101][101] = {0};
int cnt_arr[101][101][101] = {0};
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct point
{
    int x;
    int y;
    int z;
};

queue<point> q;

point tmp;

int main()
{
    int M,N,H;
    cin>>M>>N>>H;
    for(int i=0;i<H;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<M;k++)
            {
                cin>>arr[i][j][k];
                if(arr[i][j][k] == 1)
                {
                    tmp.x = k;
                    tmp.y = j;
                    tmp.z = i;
                    q.push(tmp);
                }
                arr[i][j][k]++;
            }
    point cnt;
    cnt.x = -1;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        int nx,ny,nz;
        for(int i=0;i<6;i++)
        {
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            nz = tmp.z + dz[i];
            if(0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H)
            {
                if(arr[nz][ny][nx] == 1)
                {
                    arr[nz][ny][nx] = 2;
                    point tmp2;
                    tmp2.x = nx;
                    tmp2.y = ny;
                    tmp2.z = nz;
                    q.push(tmp2);
                    cnt_arr[nz][ny][nx] = cnt_arr[tmp.x][tmp.y][tmp.z] + 1;
                    cnt.x = nx;
                    cnt.y = ny;
                    cnt.z = nz;
                }
            }
        }
    }
    for(int i=0;i<H;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<M;k++)
            {
                if(arr[i][j][k] == 1)
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
    if(cnt.x == -1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<cnt_arr[cnt.z][cnt.y][cnt.x]<<endl;
}