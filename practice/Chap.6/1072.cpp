#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;

ll X, Y, Z ;
ll ret = -1 ;

bool check( ll mid ) {
    
    ll games = X + mid ;
    ll win = Y + mid ;
    ll percent = (ll)(( win * 100 ) / games ) ;

    if( Z != percent )
        return true ;
    else
        return false ;
}

int main() {

    cin >> X >> Y ;

    Z = (ll)(( Y * 100 ) / X ) ;

    ll left = 1 ;
    ll right = 1e9;

    while( left <= right ) {

        ll mid = ( left + right ) / 2 ;

        if( check(mid) ) {
            ret = mid ;
            right = mid - 1 ;
        } else {
            left = mid + 1 ;
        }
    }

    cout << ret << "\n";
    return 0 ;
    
}