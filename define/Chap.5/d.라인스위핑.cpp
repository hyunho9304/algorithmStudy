#include<bits/stdc++.h>
using namespace std ;

typedef pair<long long, long long> P ;

int N ;
P L[1000004];
long long from, to, l , r ;
long long ret ;


int main() {
    cin >> N ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> from >> to ;
        L[i] = P( from, to ) ;
    }

    sort( L, L + N ) ;

    l = L[0].first ;
    r = L[0].second ;
    for( int i = 1 ; i < N ; i++ ) {

        if( L[i].first <= r && L[i].second >= r ) {
            r = L[i].second ;
        } else if( L[i].first > r ) {
            ret += abs( r - l ) ;
            l = L[i].first ;
            r = L[i].second ;
        }
    }

    ret += abs( r - l ) ;

    cout << ret << "\n" ;
    return 0 ;
}