#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1000004 ;

int N ;
int dp[max_n] ;

// int go( int num ) {

//     if( num == 1 ) return 0 ;


//     int &ret = dp[num] ;
//     if( ret != 0 ) return ret ;

//     ret = go( num - 1 ) + 1 ;

//     if( num % 3 == 0 ) {
//         int tmp = go( num/3 ) + 1 ;
//         ret = min( ret, tmp ) ;
//     }
    
//     if( num % 2 == 0 ) {
//         int tmp = go( num/2 ) + 1 ;
//         ret = min( ret, tmp ) ;
//     } 

//     return ret ;
// }

// int main() {

//     cin >> N ;

//     cout << go( N ) << "\n" ;
//     return 0 ;

// }


int main() {

    cin >> N ;

    for( int i = 2 ; i <= N ; i++ ) {

        dp[i] = dp[ i - 1 ] + 1 ;

        if( i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1 ;
        }

        if( i % 3 == 0 && dp[i] > dp[i/3] + 1 ) {
            dp[i] = dp[i/3] + 1 ;
        }
    }

    cout << dp[N] << "\n" ;
    return 0 ;
}