#include<bits/stdc++.h>
using namespace std ;

int N;
int a[1000004] ;
stack<int> s ;
int ret[1000004] ;

int main() {

    cin >> N ;

    memset( ret, -1 , sizeof(a) ) ;
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
    cout << "\n";
    return 0 ;
}