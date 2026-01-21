#include<bits/stdc++.h>
using namespace std ;

const int max_n = 5 ;

int R, C, K ;
char a[max_n][max_n];
int visited[max_n][max_n] ;

const int dy[] = { -1, 0 , 1 , 0} ;
const int dx[] = { 0, 1, 0 , -1 } ;

int sy, sx, ey, ex ;
int cnt ;
int ret ;

void go( int y , int x, int cnt ) {

    if( cnt > K ) return ;

    if( y == ey && x == ex && cnt == K ){
        ret++ ; return ;
    }

    for( int dir = 0 ; dir < 4 ; dir ++ ) {
        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
        if( visited[ny][nx] ) continue ;

        if( a[ny][nx] != 'T' ) {
            visited[ny][nx] = 1 ;
            go( ny, nx, cnt+ 1 ) ;
            visited[ny][nx] = 0 ;
        }
        
    }
    return ;
}

int main() {

    cin >> R >> C >> K ;

    sy = R - 1 ; sx = 0 ;
    ey = 0 ; ex = C - 1 ;

    for( int i = 0 ; i < R ; i++ ) {
        string s ;
        cin >> s ;
        for( int j = 0 ; j < C ; j++ ) {
            a[i][j] = s[j] ;
        }
    }

    visited[sy][sx] = 1 ;
    go( sy, sx , 1 ) ;

    cout << ret << "\n" ;
    return 0 ;

    
}