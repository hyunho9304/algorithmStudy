#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<int> v ;
int X ;

int ret ;

int main() {

    cin >> N ;
    v.resize(N);
    for( int i = 0 ; i < N ; i++ ) {
        cin >> v[i] ;
    }

    cin >> X ;

    sort( v.begin(), v.end() );
    
    int l = 0 ;
    int r = N - 1 ;

    while( l < r ) {
        
        if( v[l] + v[r] == X ) {
            ret++ ;
            r-- ;
        } else if( v[l] + v[r] < X ) {
            l++ ;
        } else if( v[l] + v[r] > X ) {
            r-- ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}