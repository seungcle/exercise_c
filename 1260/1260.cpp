#include<iostream>
#include<stack>
#include<queue>

int vs[1001] = {0};
int arr[1001][1001]={0};

stack<int> s;
queue<int> q;

void dfs(int v,int n)
{
    if(vs[v]!=0)
    {
        s.push(v);
        vs[v] = 1;
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
            for(int i = 0; i < n; i++)
            {
                if(!vs[i] && )
            }
        }
    }
}

void bfs(int n)
{

}

int main()
{
    int n,m,v;
    cin >> n >> m >> v;
    int x,y;
    for(int i=0;i < m; i++)
    {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    dfs(v,n);
    bfs(v,n);
}