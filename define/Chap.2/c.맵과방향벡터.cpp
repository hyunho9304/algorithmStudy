#include<bits/stdc++.h>
using namespace std;
const int N = 3;
int a[N][N], visited[N][N];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
/*
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
*/

void go(int y, int x){

    visited[y][x] = 1;
    cout << y << " : " << x << "\n";

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;

        go(ny, nx);
    }
    return;
}

int main(){
/*
1 0 1
1 0 1
0 1 1
*/
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    go(0, 0);
}