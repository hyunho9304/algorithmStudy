/*
Title : 누적합
Desc : prefix sum 하는거
        psum[n] = psum[n-1] + a[n]
*/

#include<bits/stdc++.h>
using namespace std ;

int a[1000], N , M , psum[1000], A , B ;

int main() {
    
    cin >> N >> M ;
    for( int i = 1 ; i <= N ; i++ ) {
        cin >> a[i] ;
        psum[i] = psum[i-1] + a[i] ;
    }

    for( int i = 0 ; i < M ; i++ ) {
        cin >> A >> B ;
        cout << psum[B] - psum[A-1] << "\n" ;
    }
    return 0 ;
}