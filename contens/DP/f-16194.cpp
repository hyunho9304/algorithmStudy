#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;
const int INF = 987654321 ;

int N ;
int P[max_n] ;
int dp[max_n] ;

int main() {

    cin >> N ;
    for( int i = 1 ; i <= N ; i++ ) {
        cin >> P[i] ;
    }

    fill( &dp[0] , &dp[0] + max_n , INF ) ;
    dp[0] = 0 ;

    for( int i = 1 ; i <= N ; i++ ) {

        for( int j = i ; j <= N ; j++ ) {

            dp[j] = min( dp[j] , dp[ j - i] + P[i] ) ;
        }
    }

    cout << dp[N] << "\n" ;
    return 0 ;
}