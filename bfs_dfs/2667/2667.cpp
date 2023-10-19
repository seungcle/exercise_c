#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[26][26] = {0};
vector<int> result;
int cnt = 0;

struct point
{
    int x;
    int y;
};

queue<point> q;

void bfs(int x,int y,int n)
{
    point tmp;  
    tmp.x = x;
    tmp.y = y;
    arr[x][y] = 0;
    q.push(tmp);
    cnt++;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int new_x = tmp.x + dx[i];
            int new_y = tmp.y + dy[i];
            if(0 <= new_x && new_x < n && 0 <= new_y && new_y <= n)
            {
                if(arr[new_x][new_y] == 1)
                {
                    arr[new_x][new_y] = 0;
                    point tmp2;
                    tmp2.x = new_x;
                    tmp2.y = new_y;
                    q.push(tmp2);
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%1d",&arr[i][j]);
    }
    int x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] == 1)
            {
                cnt = 0;
                bfs(i,j,n);
                result.push_back(cnt);
            }
        }
    
    sort(result.begin(),result.end());

    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
}
