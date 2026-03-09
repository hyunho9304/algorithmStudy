#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;

int N ;
int dp[max_n] ;

int go( int n) {

    if( n == 1 ) return 1 ;
    if( n == 2 ) return 3 ;

    int &ret = dp[n];
    if( ret != 0 ) return ret ;

    ret = ( go( n- 1 ) + (go( n - 2 ) * 2 ) ) % 10007 ;

    return ret  ;
}

int main() {

    cin >> N ;
    cout << go(N) << "\n";
    return 0 ;
}