#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;

ll S , C, num ;
vector<ll> v ;

ll ret ;

bool check( ll mid ) {

    ll cnt = 0 ;
    for( ll i = 0 ; i < S ; i++ ) {
        
        cnt += v[i] / mid ;

        if( cnt >= C ) return true ;
    }

    return false ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> C ;

    ll left = 1 ;
    ll right = 0 ;
    ll mid = 0 ;

    ll sum = 0 ;

    for( ll i = 0 ; i < S ; i++ ) {
        cin >> num ;
        v.push_back(num);
        right = max(right, num);
        sum += num ;
    }

    ll result = 0 ;

    while( left <= right ) {

        mid = ( left + right ) / 2 ;

        if( check(mid) ) {
            result = max( result, mid ) ;
            left = mid + 1 ;
        } else {
            right = mid - 1 ;
        }
    }

    ret = sum - C * result ;

    cout << ret << "\n" ;
    return 0 ;

    
}