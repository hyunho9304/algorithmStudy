#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;

ll N, cuH ;
ll t, a , h ;

struct Room {
    ll t ;
    ll a ;
    ll h ;
};

Room rooms[123456] ;


ll ret ;

bool check( ll mid ) {

    ll currentATK = cuH ;
    ll currentHP = mid ;
    for( int i = 0 ; i < N ; i++ ) {

        if( rooms[i].t == 1 ) {

            ll monsterATK = rooms[i].a ;
            ll monsterHP = rooms[i].h ;

            ll heroHits = ( monsterHP + currentATK - 1 ) / currentATK ;
            ll mosterHits = heroHits - 1 ;

            currentHP -= ( mosterHits * monsterATK ) ;

            if( currentHP <= 0 ) return false ;

        } else if( rooms[i].t == 2 ) {

            currentATK += rooms[i].a ;
            currentHP = min( mid, currentHP + rooms[i].h) ;
        }
    }

    return true ;
}

int main() {

    cin >> N >> cuH ;

    ll left = 1 ;
    ll right = (ll)1e18 ;
    ll mid = 0;

    for( int i = 0 ; i < N ; i++ ) {

        cin >> t >> a >> h ;
        rooms[i].t = t ;
        rooms[i].a = a ;
        rooms[i].h = h ;

    }

    while( left <= right ) {

        mid = ( left + right ) / 2 ;

        if( check( mid ) ) {
            
            right = mid - 1 ;
            ret = mid ;
        } else {
            left = mid + 1 ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;


}