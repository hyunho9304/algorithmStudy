#include<bits/stdc++.h>
using namespace std ;

int X ;
int N ;
int a, b ;

int main() {

    cin >> X >> N ;
    for( int i = 0 ; i < N ; i++ ) {

        cin >> a >> b ;
        X -= ( a * b ) ;
    }

    if( X == 0 ) cout << "Yes" << "\n" ;
    else cout << "No" << "\n" ;

    return 0 ;
}