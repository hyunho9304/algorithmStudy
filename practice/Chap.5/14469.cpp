#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<pair<int,int>> v ;
int from, to ;
int r ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> from >> to ;
        v.push_back( { from, from + to } ) ;
    }

    sort( v.begin(), v.end() ) ;

    int r = v[0].second ;
    for( int i = 1 ; i < N ; i++ ) {

        if( v[i].first <= r ) {
            r = r + ( v[i].second - v[i].first ) ;
        } else {
            r = v[i].second ;
        }
    }

    cout << r << "\n" ;
    return 0 ;
}