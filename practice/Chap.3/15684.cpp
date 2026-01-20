//  백트래킹
#include<bits/stdc++.h>
using namespace std ;

const int max_n = 34 ;
const int INF = 987654321 ;

int N, M, H ;
int visited[max_n][max_n] ;
 
int ret = INF ;

bool check() {

    for( int i = 1 ; i <= N ; i++ ) {

        int current = i ;
        for( int j = 1 ; j <= H ; j++ ) {
            if( visited[j][current] ) current++ ;
            else if( visited[j][current-1] ) current-- ;
        }
        if( current != i ) return false ;
    }

    return true ;
}

void go( int here, int cnt ) {

    if( cnt > 3 || cnt >= ret ) return ;
    if( check() ) {
        ret = min( ret, cnt ) ; return ;
    }

    for( int i = here ; i <= H ; i++ ) {
        for( int j = 1 ; j < N ; j++ ) {
            if( visited[i][j] || visited[i][j-1] || visited[i][j+1] ) continue ;

            visited[i][j] = 1 ;
            go( i, cnt + 1 ) ;
            visited[i][j] = 0 ;
        }
    }
}

int main() {
    cin >> N >> M >> H ;

    int a, b ;
    for( int i = 0 ; i < M ; i++ ) {
        cin >> a >> b ;
        visited[a][b] = 1 ;
    }

    go( 1, 0 ) ;

    cout << ( ret == INF  ? -1 : ret ) << "\n" ;
}
