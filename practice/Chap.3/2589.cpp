#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54;
int N , M ;
int a[max_n][max_n];
int visited[max_n][max_n];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int ret = -1 ;

void bfs( int y , int x ) {

    memset( visited, 0 , sizeof(visited));
    queue<pair<int,int>> q ;
    visited[y][x] = 1 ;
    q.push( {y,x});

    while( q.size() ) {
        tie( y,x) = q.front() ; q.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
            if( a[ny][nx] == 'W') continue ;
            if( visited[ny][nx] ) continue ;

            visited[ny][nx] = visited[y][x] + 1 ;
            q.push( {ny,nx});

            ret = max( ret, visited[ny][nx] ) ;
        }
    }
}

int main() {
    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        string s ;
        cin >> s;
        for( int j = 0 ; j < M ; j++ ) {
            a[i][j] = s[j] ;
        }
    }

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            if( a[i][j] == 'L' ) bfs( i,j ) ;
        }
    }

    cout << ret - 1 << "\n" ;
    return 0 ;
    
}