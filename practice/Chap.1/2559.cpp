//  g++ -std=c++14 -Wall 2559.cpp -o test.out
#include<bits/stdc++.h>
using namespace std ;

int N, K ;
int retMax = -100 * 100000 ;
int arr[100000] ;
int psum[100001] ;

void solve() {
    for( int i = 1 ; i <= N ; i++ ) {
        psum[i] = psum[i-1] + arr[i-1] ;
    }

    for( int i = K ; i <= N ; i++ ) {
        retMax = max( retMax, psum[i] - psum[i-K] );
    }
}
int main() {

    cin >> N >> K ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> arr[i] ;
    }
    solve() ;

    cout << retMax << "\n" ;
    return 0 ;
}