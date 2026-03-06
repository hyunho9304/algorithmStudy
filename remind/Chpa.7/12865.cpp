/*
    DP - 배낭 한개씩
*/
#include<bits/stdc++.h>
using namespace std ;

int N, K, W, V ;
int dp[100004] ;

int main() {

    cin >> N >> K ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> W >> V ;

        for( int j = K ; j >= W ; j-- ) {
            dp[j] = max( dp[j] , dp[ j - W ] + V ) ;
        }
        
    }

    cout << dp[K] << "\n";
    return 0 ;
}