#include<bits/stdc++.h>
using namespace std ;

int N ;
int ret ;

int main() {

    cin >> N ;
    for( int i = 1 ; i <= N ; i++ ) {
        ret += i ;
    }

    cout << ret << "\n" ;
    return 0 ;
}