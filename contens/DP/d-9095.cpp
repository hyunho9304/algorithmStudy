#include<bits/stdc++.h>
using namespace std ;

const int max_n = 15 ;
int N, T ;
int dp[max_n] ;

int go( int n) {

    if( n == 1 ) return 1 ;
    if( n == 2 ) return 2 ;
    if( n == 3 ) return 4 ;
   
    int &ret = dp[n] ;
    if( ret != 0 ) return ret ;

    ret = go( n -1 ) + go ( n - 2 ) + go( n - 3 ) ;
    return ret ;
}

int main() {

    cin >> T ;

    while( T > 0 ) {

        memset( dp, 0, sizeof(dp) ) ;

        cin >> N ;

        cout << go( N ) << "\n" ;

        T-- ;
    }
    return 0 ;
}