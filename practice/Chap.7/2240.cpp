#include<bits/stdc++.h>
using namespace std ;

int T, W ;
int a[1004] ;
int dp[1004][34][2] ;

int go( int idx, int cnt, int pos ) {

    if( idx == T ) return 0 ;

    int &ret = dp[idx][cnt][pos] ;
    if( ret != -1 ) return ret ;

    int up = ( pos == a[idx] - 1 ) ;
    if( cnt == 0) {
        ret = go( idx + 1, cnt, pos ) + up ;
    } else {
        ret = max( go( idx + 1 , cnt, pos ), go( idx + 1 , cnt - 1 , pos ^ 1 )) + up ;
    }

    return ret ;
}

int main() {

    cin >> T >> W ;
    for( int i = 0 ; i < T ; i++ ) {
        cin >> a[i] ;
    }

    memset( dp, -1, sizeof(dp) ) ;

    cout << max( go( 0, W, 0), go( 0, W-1, 1 ) ) << "\n" ;
    return 0 ;
}