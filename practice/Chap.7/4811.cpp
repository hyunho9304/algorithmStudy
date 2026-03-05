#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
const int max_n = 34 ;

int N ;
ll DP[max_n][max_n] ;


ll go( int W , int H ) {

    if( W == 0 && H == 0 ) return 1 ;

    ll &ret = DP[W][H] ;
    if( ret != 0 ) return ret ;

    if( W > 0) ret += go( W-1, H+1) ;

    if( H > 0) ret += go( W, H-1) ;

    return ret ;
}

int main() {

    while( true ) {

        cin >> N ;
        if( N == 0 ) break ;

        cout << go( N, 0 ) << "\n" ;
    }

    return 0 ;

}