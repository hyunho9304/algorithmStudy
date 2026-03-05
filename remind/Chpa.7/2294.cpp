/*
    DP - 바텀업으로 갱신하면서 min값 저장
*/
#include<bits/stdc++.h>
using namespace std ;

const int INF = 987654321 ;

int N , K ;
int dp[10004] ;
int num ;

int main() {

    cin >> N >> K ;

    fill( dp, dp + 10004, INF ) ;
    dp[0] = 0 ;

    for( int i = 0 ; i < N ; i++ ) {

        cin >> num ;
        for( int j = num ; j <= K ; j++ ) {

            dp[j] = min( dp[j] , dp[j-num] + 1 ) ;
        }
    }

    if( dp[K] == INF ) cout << -1 << "\n" ;
    else cout << dp[K] << "\n";
    return 0 ;
}