#include<bits/stdc++.h>
using namespace std ;

int T ;

int main () {

    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> T ;

    for( int i = 0 ; i < T ; i++ ) {
        int num = 0 ;
        cin >> num ;

        int ret1 = 0; int ret2 = 0 ;
        for( int i = 2 ; i <= num ; i *= 2) {
            ret1 += num / i ;
        }

        for( int j = 5 ; j <= num ; j *= 5 ) {
            ret2 += num / j ;
        }

        cout << min( ret1, ret2 ) << "\n";
    }

    return 0 ;
}