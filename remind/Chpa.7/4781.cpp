/*
    DP - 오름차순( 배낭 )
*/
#include<bits/stdc++.h>
using namespace std ;

int N, cal;
double tmpM, tmpP ;
int money , cost ;
int dp[10004] ;

int main() {

    while( true ) {

        cin >> N >> tmpM ;

        if( N == 0 && tmpM == 0.00 ) break ;

        fill(dp, dp + 10004 , 0);

        money = (int)( tmpM * 100 + 0.5 ) ;
        for( int i = 0 ; i < N ; i++ ) {
            cin >> cal >> tmpP ;

            cost = (int)( tmpP * 100 + 0.5 ) ;

            for( int j = cost ; j <= money ; j++ ) {
                dp[j] = max( dp[j], dp[ j - cost ] + cal ) ;
            }
            
        }

        cout << dp[money] << "\n" ;
    }
    
    return 0 ;
}