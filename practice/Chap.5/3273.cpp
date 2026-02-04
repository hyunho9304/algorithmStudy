#include<bits/stdc++.h>
using namespace std ;

int N, X, num ;
vector<int> v ;
int l, r ;

int ret ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> num ;
        v.push_back( num ) ;
    }

    cin >> X ;

    sort( v.begin(), v.end() ) ;

    l = 0 ;
    r = N - 1 ;

    while( l < r ) {
        int sum = v[l] + v[r] ;
        if( sum == X ) {
            ret++ ;
            r-- ;
        } else if( sum < X ) l++ ;
        else if( sum > X ) r-- ;
    }

    cout << ret << "\n" ;
    return 0 ;
    
}