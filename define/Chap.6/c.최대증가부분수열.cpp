#include<bits/stdc++.h>
using namespace std ;

int N, ret ;
int a[1001];
int cnt[1001] ;

/*
10 20 10 30 20 50
 1  2  1  3  2  4
*/

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i] ;
    }

    for( int i = 0 ; i < N ; i++ ) {

        int maxValue = 0 ;

        for( int j = 0 ; j < i ; j++ ) {
            if( a[j] < a[i] && maxValue < cnt[j] ) maxValue = cnt[j] ;
        }

        cnt[i] = maxValue + 1 ;
        ret = max( ret, cnt[i] ) ;
    }

    cout << ret << "\n" ;
    return 0 ;
}


