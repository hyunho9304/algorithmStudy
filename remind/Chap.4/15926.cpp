#include<bits/stdc++.h>
using namespace std ;

int n ;
string str ;
stack<int> s ;
int D[200004] ;
int ret ;

int main() {

    cin >> n >> str ;
    for( int i = 0 ; i < n ; i++ ) {

        if( str[i] == '(') s.push(i) ;
        else {

            if( !s.empty() ) {
                D[i] = D[ s.top() ] = 1 ;
                s.pop() ;
            }
        }
    }

    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
        if( D[i] == 1 ) {
            cnt++ ;
            ret = max( ret , cnt ) ;
        } else {
            cnt = 0 ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}