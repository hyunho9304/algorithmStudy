#include<bits/stdc++.h>
using namespace std ;

int N ;
string S ;
stack<int> stk ;

int ret ;

int main() {

    stk.push(-1 ) ;
    cin >> N ;
    cin >> S ;
    for( int i = 0 ; i < N ; i++ ) {

        if( S[i] == '(') stk.push(i) ;
        else {

            stk.pop() ;
            if( stk.empty() ) stk.push(i) ;
            else ret = max( ret , i - stk.top() ) ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}