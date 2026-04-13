#include<bits/stdc++.h>
using namespace std ;

const int max_n = 304 ;

int N, M ;
int a[max_n][max_n];
int visited[max_n][max_n];
int sy , sx, ey, ex ;

const int dy[] = { -1, 0, 1 , 0 } ;
const int dx[] = { 0, 1, 0, - 1 } ;

void bfs() {

    queue<pair<int,int>> q ;
    q.push( { sy, sx } ) ;
    visited[sy][sx] = 1 ;

    int cnt = 0 ;
    while( a[ey][ex] != '0' ) {

        cnt++ ;

        queue<pair<int,int>> temp ;

        while( !q.empty() ) {

            int y; int x ;
            tie( y , x ) = q.front() ; q.pop() ;

            for( int dir = 0 ; dir < 4 ; dir++ ) {
                int ny = y + dy[dir] ;
                int nx = x + dx[dir] ;

                if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
                if( visited[ny][nx] ) continue ;

                visited[ny][nx] = cnt ;

                if( a[ny][nx] != '0' ) {
                    a[ny][nx] = '0' ;
                    temp.push( { ny, nx } ) ;
                } else {
                    q.push( {ny, nx} ) ;
                }
            }
        }

        q = temp ;
    }
}

int main() {

    cin >> N >> M ;
    cin >> sy >> sx >> ey >> ex ;

    sy-- ; sx-- ;
    ey-- ; ex-- ;

    for( int i = 0 ; i < N ; i++ ) {
        string s ;
        cin >> s ;
        for( int j = 0 ; j < M ; j++ ) {
            a[i][j] = s[j] ;
        }
    }

    bfs() ;

    cout << visited[ey][ex] << "\n" ;

    return 0 ;
    
}
