#include<bits/stdc++.h>
using namespace std;

const int max_n = 20004 ;

int T , N, M ;
int arr1[max_n] ;
int arr2[max_n] ;

int ret ; 

int main() {

    cin >> T ;

    while( T > 0 ) {

        fill( arr1, arr1 + N , 0 ) ;
        fill( arr2, arr2 + M , 0 ) ;
        ret = 0 ;

        cin >> N >> M ;

        for( int i = 0 ; i < N ; i++ ) {
            cin >> arr1[i] ;
        }

        for( int i = 0 ; i < M ; i++ ) {
            cin >> arr2[i] ;
        }

        sort( arr1, arr1 + N ) ;
        sort( arr2, arr2 + M ) ;

        for( int i = 0 ; i < N ; i++ ) {
            auto pos = lower_bound( arr2, arr2 + M , arr1[i] ) ;
            ret += (int)(pos - arr2 ) ;
        }

        cout << ret << "\n" ;


        T-- ;
    }

    return 0 ;
}