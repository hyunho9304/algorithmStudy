#include<bits/stdc++.h>
using namespace std ;

int N, M ;
int result = 987654321 ;
int arr[300000];

bool search( int idx ) {

    int ret = 0 ;
    for( int i = 0 ; i < M ; i++ ) {
        ret += ( arr[i] / idx ) ;
        if( arr[i] % idx ) ret++ ;
    }

    return ret <= N ;
}

int main() {

    cin >> N >> M ;

    int left = 1 ;
    int right = 0 ;
    int mid ;

    for( int i = 0 ; i < M ; i++ ) {
        cin >> arr[i] ;
        right = max( right, arr[i] ) ;
    }

    while( left <= right ) {

        mid = ( left + right ) / 2 ;

        if( search( mid ) ) {
            result = min( result, mid ) ;
            right = mid - 1 ;
        } else {
            left = mid + 1 ;
        }
    }

    cout << result << "\n" ;
    return 0 ;
}