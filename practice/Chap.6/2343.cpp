#include<bits/stdc++.h>
using namespace std ;

const int max_n = 100004 ;

int N, M ;
int arr[max_n] ;
int mx ;

int ret ;

bool check( int mid ) {

    if( mx > mid ) return false ;

    int tmp = mid ;
    
    int cnt = 1 ;
    for( int i = 0 ; i < N ; i++ ) {

        if( tmp - arr[i] < 0 ) {

            tmp = mid ;
            cnt++ ;
        }

        tmp -= arr[i] ;
    }

    return cnt <= M ;

}

int main() {

    cin >> N >> M ;

    int left = 0 ;
    int right = 0 ;
    int mid = 0 ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> arr[i] ;
        right += arr[i] ;
        mx = max( mx, arr[i] ) ;
    }


    while( left <= right ) {

        mid = ( left + right ) / 2 ;

        if( check( mid ) ) {

            right = mid - 1 ;
            ret = mid ;
        } else {

            left = mid + 1 ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}