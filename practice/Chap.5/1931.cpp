#include<bits/stdc++.h>
using namespace std ;

int N ;
int from , to ;
vector<pair<int,int>> v ;
int l, r ;
int ret ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> from >> to ;
        v.push_back( { to, from } ) ;
    }

    sort( v.begin(), v.end() ) ;

    l = v[0].second ;
    r = v[0].first ;
    ret += 1 ;
    for( int i = 1 ; i < N ; i++ ) {

        if( v[i].second < r ) continue ;

        if( r <= v[i].second) {
            l = v[i].second ;
            r = v[i].first ;
            ret++ ;
        }
    }

    cout << ret << "\n" ;
    return 0;
}