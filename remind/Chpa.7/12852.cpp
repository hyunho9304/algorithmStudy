/*
    DP - 바텀업
    트레이스
*/
#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1e6 + 4;
const int INF = 987654321 ;

int N ;
int DP[max_n] ;

void go( int here ) {

    if(here == 0) return;
    
    cout << here << " " ;

    if(here % 3 == 0 && DP[here] == (DP[here / 3] + 1)) go(here / 3);
    else if(here % 2 == 0 && DP[here] == (DP[here / 2] + 1))go(here / 2);
    else if((here - 1 >= 0) && (DP[here] == (DP[here - 1] + 1))) go(here - 1);
    
    return;
}

int main() {

    cin >> N ;

    fill( DP, DP + max_n , INF ) ;

    DP[1] = 0 ;
    for( int i = 2 ; i <= N ; i++ ) {

        if( i % 3 == 0 ) DP[i] = min( DP[i/3] + 1 , DP[i] ) ;

        if( i % 2 == 0 ) DP[i] = min( DP[i/2] + 1 , DP[i] ) ;

        DP[i] = min( DP[i-1] + 1 , DP[i] ) ;
    }

    cout << DP[N] << "\n" ;
    go( N ) ;

    return 0 ;
}