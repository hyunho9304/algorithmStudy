#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M ;
string str ;
char a[max_n][max_n];
int visited[max_n][max_n] ;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 } ;

int ret ;

void bfs( int y, int x ) {

    queue<pair<int,int>> q ;
    q.push( {y,x}) ;

    fill( &visited[0][0] , &visited[0][0] + max_n * max_n , 0 ) ;
    visited[y][x] = 1 ;

    while( !q.empty() ) {

        tie( y, x ) = q.front() ; q.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            
            int ny = y + dy[dir];
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
            if( visited[ny][nx] ) continue ;
            if( a[ny][nx] == 'W' ) continue ;

            visited[ny][nx] = visited[y][x] + 1 ;
            q.push( { ny, nx } ) ;

            ret = max( ret, visited[ny][nx] ) ;
        }
    }
}

int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> str ;
        for( int j = 0 ; j < M ; j++ ) {
            a[i][j] = str[j] ;
        }
    }

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            if( a[i][j] == 'L') bfs( i, j ) ;
        }
    }

    cout << ret - 1 << "\n" ;
    return 0 ;
    
}