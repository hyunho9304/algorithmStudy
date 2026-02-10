#include<bits/stdc++.h>
using namespace std ;

int T, M, N ;
int a[1004], b[1004] ;
int psumA[2008], psumB[2008] ;
map<int,int> mpA, mpB ;

int ret ;

void make( int count, int psum[] , map<int,int> &mp ) {

    for( int i = 1 ; i <= count ; i++ ) {
        for( int j = i ; j <= count + i -1 ; j++ ) {

            int sum = psum[j] - psum[j-i] ;
            mp[sum]++ ;

            if( i == count ) break ;
        }
    }
}

int main() {

    cin >> T >> M >> N ;
    for( int i = 1 ; i <= M ; i++ ){
        cin >> a[i] ;
        psumA[i] = psumA[i-1] + a[i] ;
    }
    for( int i = M + 1 ; i <= 2 * M ; i++ ) {
        psumA[i] = psumA[i-1] + a[i-M] ;
    }

    for( int i = 1 ; i <= N ; i++ ) {
        cin >> b[i] ;
        psumB[i] = psumB[i-1] + b[i] ;
    }
    for( int i = N + 1 ; i <= N * 2 ; i++ ) {
        psumB[i] = psumB[i-1] + b[i-N] ;
    }

    make( M, psumA, mpA ) ;
    make( N, psumB, mpB ) ;

    ret = mpA[T] + mpB[T] ;
    for( int i = 1 ; i <= T ; i++ ) {
        ret += mpA[i] * mpB[T-i] ;
    }

    cout << ret << "\n" ;
    return 0 ;
}