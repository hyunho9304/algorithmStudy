#include<bits/stdc++.h>
using namespace std ;

int T, N, M, num ;
map<int,int> mp ;

int main() {

    cin >> T ;

    while( T > 0 ) {

        cin >> N ;
        for( int i = 0 ; i < N ; i++ ) {
            cin >> num ;
            mp[num]++ ;
        }

        cin >> M ;
        for( int i = 0 ; i < M ; i++ ) {
            cin >> num ;

            if( mp[num] != 0 ) cout << "1" << "\n" ;
            else cout << "0" << "\n" ;
        }

        T--;
    }
    return 0;
}