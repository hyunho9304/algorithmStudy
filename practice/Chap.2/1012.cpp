//  DFS
#include<bits/stdc++.h>
using namespace std ;

const int max_n = 51 ;
int N, M, K, T;
int cnt ;
int a[max_n][max_n];
int visited[max_n][max_n];
const int dy[] = { -1, 0 , 1 ,0 } ;
const int dx[] = { 0, 1 , 0, -1 } ;

void dfs( int y , int x ) {

    visited[y][x] = 1 ;

    for( int i = 0 ; i < 4 ; i++ ) {
        int ny = y + dy[i] ;
        int nx = x + dx[i] ;

        if( ny < 0 || nx < 0 || ny >= M || nx >= N ) continue ;
        if( a[ny][nx] == 0 ) continue ;
        if( visited[ny][nx] ) continue ;

        dfs( ny, nx ) ;
    }
    return ;
}


int main() {

    cin >> T ;

    while( T-- ) {
        fill( &a[0][0] , &a[0][0] + max_n * max_n , 0);
        fill( &visited[0][0] , &visited[0][0] + max_n * max_n , 0);
        cnt = 0;

        cin >> M >> N >> K ;
        for( int i = 0 ; i < K ; i++ ) {
            int x, y ;
            cin >> x >> y ;
            a[y][x] = 1 ;
        }

        for( int i = 0 ; i < M ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                if( a[i][j] && visited[i][j] == false ) {
                    
                    dfs(i,j);
                    cnt++ ;
                }
            }
        }

        cout << cnt << "\n" ;
    }

    return 0 ;


}