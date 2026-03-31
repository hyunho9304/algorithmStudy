#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1000004;

int N ;
int a[max_n] ;
int ret[max_n] ;
stack<int> s ;

int main() {

    fill( &ret[0] , &ret[0] + max_n , -1 ) ;

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {

        cin >> a[i] ;

        while( !s.empty() && a[s.top()] < a[i] ) {
            ret[s.top()] = a[i] ; s.pop() ;
        }

        s.push(i);
    }

    for( int i = 0 ; i < N ; i++ ) {
        cout << ret[i] << " " ;
    }
    cout << "\n" ;
    return 0 ;
}