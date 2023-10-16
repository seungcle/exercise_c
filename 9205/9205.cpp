#include <iostream>
#include <queue>
using namespace std;

struct point
{
    int x; int y;
};

point store[100];   
point festival;     
point home;         
int n;              
int vs[100] ={0};

int abs(int n)
{
    if(n > 0) return n;
    else return -n;
}

bool bfs()
{
    queue<point> q;
    q.push(home);
    while(!q.empty())
    {
        point tmp;
        tmp = q.front();
        q.pop();
        if((abs(tmp.x - festival.x) + abs(tmp.y - festival.y)) <= 1000) return true;
        for(int i=0;i<n;i++)
        {
            if(vs[i] == 1) continue;
            if((abs(tmp.x - store[i].x) + abs(tmp.y - store[i].y)) <= 1000)
            {
                vs[i] = 1;
                q.push(store[i]);
            }       
        }
    }
    return false;
}

void reset()
{
    for(int i=0;i<n;i++)
    {
        vs[i] = 0;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        cin >> home.x >> home.y;
        for(int j=0;j<n;j++)
            cin >> store[j].x >> store[j].y;
        cin >> festival.x >> festival.y;

        if(bfs()) cout << "happy" << endl;
        else cout << "sad" << endl;

        reset();
    }   
}

// 습관처럼 q를 전역으로 선언했더니 첫번째 케이스에서 happy가 되는 경우에, q가 비어있지 않아서 다음 케이스에 영향을 준다.