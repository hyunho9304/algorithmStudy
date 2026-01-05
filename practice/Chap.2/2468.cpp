//  DFS
#include<bits/stdc++.h>
using namespace std ;

const int max_n = 104 ;
int N, cnt ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret ;
int maxRain ;

void dfs( int y , int x, int rain ) {
    
    visited[y][x] = 1 ;

    for( int i = 0 ; i < 4 ; i++ ) {
        int ny = y + dy[i] ;
        int nx = x + dx[i] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue ;
        if( a[ny][nx] <= rain ) continue ;
        if( visited[ny][nx] ) continue ;

        dfs( ny, nx, rain ) ;
    }
    return ;
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
            maxRain = max( maxRain, a[i][j] ) ;
        }
    }

    int rain = 0;
    while( rain <= maxRain ) {

        fill( &visited[0][0] , &visited[0][0] + max_n * max_n, 0 );
        cnt = 0 ;

        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                if( a[i][j] > rain && !visited[i][j] ) {
                    dfs(i,j, rain);
                    cnt++;
                }
            }
        }
        ret = max( ret, cnt );
        rain++ ;
    }

    cout << ret << "\n";
    return 0 ;
}