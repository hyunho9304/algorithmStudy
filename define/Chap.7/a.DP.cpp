#include<bits/stdc++.h>
using namespace std ;

const int max_n = 16 ;
const int INF = 987654321 ;

int N ;
int dp[max_n][ 1 << max_n ] ;
int dist[max_n][max_n] ;

int tsp( int here, int visited ) {

    //  기저사례
    if( visited == ( 1 << N ) - 1 ) {
        return dist[here][0] ? dist[here][0] : INF ;
    }

    //  메모이제이션
    int &ret = dp[here][visited] ;
    if( ret != -1 ) return ret ;

    //  로직
    ret = INF ;
    for( int i = 0 ; i < N ; i++ ) {

        if( dist[here][i] == 0 ) continue ;
        if( visited & ( 1 << i ) ) continue ;

        ret = min( ret, tsp( i, visited | ( 1 << i ) ) + dist[here][i]  ) ;
    }

    return ret ;
}

int main() {

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> dist[i][j] ;
        }
    }

    //  초기화
    memset( dp, -1 , sizeof( dp ) ) ;

    cout << tsp( 0, 1 ) << "\n" ;
    return 0 ;

    
}