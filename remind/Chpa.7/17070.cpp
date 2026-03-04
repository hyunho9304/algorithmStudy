/*
    DP - 바텀업
    차근차근 하나씩 진행
*/
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

const int max_n = 20 ;

int N ;
int a[max_n][max_n];
ll dp[max_n][max_n][3];

ll ret ;

bool check( int y, int x, int d ) {

    if( d == 0 || d == 2 ) {
        if( a[y][x] == 0 ) return true ;
    } else if( d == 1 ) {
        if( a[y][x] == 0 && a[y-1][x] == 0 && a[y][x-1] == 0 ) return true ;
    }

    return false ;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    dp[1][2][0] = 1 ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {

            if( check( i, j+1, 0 ) ) dp[i][j+1][0] += dp[i][j][0] ;
            if( check( i+1, j+1, 1) ) dp[i+1][j+1][1] += dp[i][j][0] ;

            if( check( i+1, j, 2 ) ) dp[i+1][j][2] += dp[i][j][2] ;
            if( check( i+1, j+1, 1 ) ) dp[i+1][j+1][1] += dp[i][j][2] ;

            if( check( i, j+1, 0 ) ) dp[i][j+1][0] += dp[i][j][1] ;
            if( check( i+1, j+1, 1 ) ) dp[i+1][j+1][1] += dp[i][j][1] ;
            if( check( i+1, j, 2 ) ) dp[i+1][j][2] += dp[i][j][1] ;
        }
    }

    ret = dp[N][N][0] + dp[N][N][1] + dp[N][N][2] ;
    cout << ret << "\n" ;
    return 0 ;
}