#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M ;
string S ;
char a[max_n][max_n];
int visited[max_n][max_n] ;
int dp[max_n][max_n] ;

const int dy[] = { -1, 0, 1 , 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;


int go( int y, int x ) {

    if( y < 1 || x < 1 || y > N || x > M || a[y][x] == 'H' ) return 0 ;

    if( visited[y][x] ) {
        cout << -1 << "\n";
        exit(0);
    }

    int &ret = dp[y][x] ;
    if( ret ) return ret ;

    visited[y][x] = 1 ;
    int value = a[y][x] - '0' ;
    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + ( dy[dir] * value );
        int nx = x + ( dx[dir] * value ) ;
        
        ret = max( ret, go( ny,nx ) + 1 ) ;
    }
    visited[y][x] = 0 ;

    return ret ;
}

int main() {

    cin >> N >> M ;
    for( int i = 1 ; i <= N ; i++ ) {
        cin >> S ;
        for( int j = 1 ; j <= M ; j++ ) {
            a[i][j] = (char)S[j-1]; 
        }
    }

    cout << go( 1, 1 )  << "\n";
    return 0 ;
}