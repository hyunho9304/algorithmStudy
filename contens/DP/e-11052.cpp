#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;

int N ;
int P[max_n] ;
int dp[max_n] ;

int main() {

    cin >> N ;
    for( int i = 1 ; i <= N ; i++ ) {
        cin >> P[i] ;
    }

    for( int i = 1 ; i <= N ; i++ ) {

        for( int j = i ; j <= N ; j++ ) {

            dp[j] = max( dp[j] , dp[ j - i] + P[i] ) ;
        }
    }

    cout << dp[N] << "\n" ;
    return 0 ;
}