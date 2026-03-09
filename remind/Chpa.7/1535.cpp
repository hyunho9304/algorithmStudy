/*
    DP - 배낭( 한개 ) - 내림차순
*/
#include<bits/stdc++.h>
using namespace std ;

int N ;
int L[104], J[104] ;
int dp[104] ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> L[i] ;
    }

    for( int i = 0 ; i < N ; i++ ) {
        cin >> J[i] ;
    }

    for( int i = 0 ; i < N ; i++ ) {

        int a = L[i] ;
        int b = J[i] ;
        
        for( int j = 99 ; j >= a ; j-- ) {
            dp[j] = max( dp[j], dp[j - a] + b ) ;
        }
    }

    cout << dp[99] << "\n" ;
    return 0 ;
}