#include<bits/stdc++.h>
using namespace std ;

int N, M, J ;
int ret ;
int l, r ;

int main() {

    cin >> N >> M >> J ;

    l = 1 ;
    r = l + M - 1 ;

    for( int i = 0 ; i < J ; i++ ) {
        int num ;
        cin >> num ;

       if( r < num ) {

        ret += ( num - r ) ;
        r = num ;
        l = r - M + 1 ;
       } else if( num < l ) {

        ret += ( l - num ) ;
        l = num ;
        r = l + M - 1 ;
       }

    }

    cout << ret << "\n" ;
    return 0 ;

}