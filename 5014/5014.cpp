#include<iostream>
#include<queue>

using namespace std;

int vs[1000001] = {0};

struct dt
{
    int x;
    int time;
};

queue<dt> q;

int main()
{
    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;
    dt tmp;
    int t = -1;
    tmp.x = S;
    tmp.time = 0;
    q.push(tmp);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        if(tmp.x == G)
        {
            t = tmp.time;
            break;
        }
        int ux = tmp.x + U;
        int dx = tmp.x - D;
        if(ux <= F && vs[ux] == 0)
        {
            dt tmp2;
            tmp2.x = ux;
            tmp2.time = tmp.time + 1;
            q.push(tmp2);
            vs[ux] = 1;
        }
        if(0 < dx && vs[dx] == 0)
        {
            dt tmp2;
            tmp2.x = dx;
            tmp2.time = tmp.time + 1;
            q.push(tmp2);
            vs[dx] = 1;
        }
    }
    if(t == -1)
        cout<<"use the stairs"<<endl;
    else
        cout<< t << endl;
}