#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;
const int mod = 1000007 ;

int N, M, C, y, x ;
int dp[max_n][max_n][max_n][max_n];
int a[max_n][max_n];

int go( int y , int x, int k, int prev ) {

    if( y > N || x > M ) return 0 ;

    if( y == N && x == M ) {

        if( k == 0 && a[y][x] == 0 ) return 1 ;
        if( k == 1 && a[y][x] > prev ) return 1 ;

        return 0;
    }

    int &ret = dp[y][x][k][prev] ;
    if( ret != -1 ) return ret ;

    ret = 0 ;
    if( a[y][x] == 0 ) {
        ret = ( go( y, x+1, k, prev) + go( y+1, x, k, prev) ) % mod ; 
    } else if( a[y][x] > prev && k > 0 ) {
        ret = ( go( y, x+1, k-1, a[y][x] ) + go( y+1, x, k-1, a[y][x] ) ) % mod ;
    }

    return ret ;
    
}

int main() {

    cin >> N >> M >> C ;
    for( int i = 1 ; i <= C ; i++ ) {
        cin >> y >> x ;
        a[y][x] = i ;
    }

   memset( dp, -1 , sizeof( dp ) ) ;

    for( int i = 0 ; i <= C ; i++ ) {
        cout << go( 1, 1, i, 0 ) << " " ;
    }
    cout << "\n" ;

    return 0 ;
}