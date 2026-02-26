#include<bits/stdc++.h>
using namespace std ;

const int max_n = 100004 ;

int N, M ;
int arr[max_n] ;

int ret  ;

bool check( int mid ) {

    int tmp = mid ;

    int cnt = 1 ;
    for( int i = 0 ; i < N ; i++ ) {

        if( arr[i] > mid ) return false ;

        if( tmp - arr[i] < 0 ) {  // 돈 부족하면 새로 인출
            tmp = mid ;
            cnt++ ;
        }

        tmp -= arr[i] ;  // 인출 후 지출
    }

    return cnt <= M ;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M ;

    int left = 0 ;
    int right = 0 ;
    int mid = 0 ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> arr[i] ;
        right += arr[i] ;
        left = max( left, arr[i] ) ;
    }

    while( left <= right ) {

        mid = ( left + right ) /2 ;

        if( check( mid ) ) {
            right = mid - 1 ;
            ret = mid ;
        }else {
            left = mid + 1 ;
        }
    }

    cout << ret << "\n";
    return 0 ;
}
