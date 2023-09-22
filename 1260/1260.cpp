#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int vs1[1001] = {0};
int vs2[1001] = {0};
int arr1[1001][1001]={0};
int arr2[1001][1001]={0};
stack<int> s;
queue<int> q;

void dfs(int v,int n)
{
    s.push(v);
    while(!s.empty())
    {
        if(!vs1[s.top()])
        {
            cout<<s.top();
            vs1[s.top()] = 1;
        }
        int j = s.top();
        s.pop();
        for(int i = n; i > 0; i--)
        {
            if(arr1[j][i])
            {
                s.push(i);
                arr1[j][i] = 0;
            }
        }
    }
}


void bfs(int v,int n)
{
    q.push(v);
    while(!q.empty())
    {
        if(!vs2[q.front()])
        {
            cout<<q.front();
            vs2[q.front()] = 1;
        }
        int j = q.front();
        q.pop();
        for(int i=0;i<=n;i++)
        {
            if(arr2[j][i])
            {
                q.push(i);
                arr2[j][i] = 0;
            }
        }
    }
}

int main()
{
    int n,m,v;
    cin >> n >> m >> v;
    int x,y;
    for(int i=0;i < m; i++)
    {
        cin >> x >> y;
        arr1[x][y] = 1;
        arr2[x][y] = 1;
        arr1[y][x] = 1;
        arr2[y][x] = 1;
    }
    dfs(v,n);
    cout<<endl;
    bfs(v,n);
}