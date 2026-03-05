/*
    DP - 바텀업
    경우의 수니까 누적해서 진행
*/
#include<bits/stdc++.h>
using namespace std ;

int N , K ;
int dp[10004] ;
int tmp ;

int main() {

    cin >> N >> K ;

    dp[0] = 1 ;
    for( int i = 1 ; i <= N ; i++ ) {
        cin >> tmp ;
        for( int j = tmp ; j <= K ; j++ ) {
            dp[j] = dp[j] + dp[j-tmp ] ;
        }
    }

    cout << dp[K] << "\n";
    return 0 ;
}