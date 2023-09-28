#include <iostream>
#include <queue>
#define MAX 50

using namespace std;

int r,c;

int cabbage_field[MAX][MAX];

void BFS(int in_x, int in_y){

    queue<pair<int,int> > adj_queue;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    adj_queue.push(make_pair(in_x,in_y));    

    cabbage_field[in_x][in_y] = 0;

    while(!adj_queue.empty()){

        int x = adj_queue.front().first;
        int y = adj_queue.front().second;

        adj_queue.pop();

        for (int i=0; i<4; ++i){

            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (0<= new_x && new_x < r && 0 <= new_y && new_y < c){

                if (cabbage_field[new_x][new_y]==1){

                    cabbage_field[new_x][new_y] = 0;
                    adj_queue.push(make_pair(new_x, new_y));
                }
            }
        }
    }
}
int main(){

    int testcase;
    int x,y;
    int cabbage_count;

    cin >> testcase;

    for (int t=0 ; t<testcase; ++t)
    {
        cin >> r >> c >> cabbage_count;
        for (int i=0; i<cabbage_count; ++i){
            cin >> x >> y;
            cabbage_field[x][y] = 1;
        }
        int worm = 0;
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                if (cabbage_field[i][j]==1){
                    BFS(i,j);
                    worm++;
                }
            }
        }
        cout << worm << endl;
    }
}