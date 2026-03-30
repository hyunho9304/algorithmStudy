#include<bits/stdc++.h>
using namespace std ;

int T ;
string oper ;
int N ;
string str ;
deque<int> dq ;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T ;
    
    while( T > 0 ) {

        cin >> oper ;
        cin >> N ;
        cin >> str ;
        dq.clear() ;

        int x = 0 ;
        for( char ch : str ) {

            if( ch == '[' ) continue ;
            else if( ch >= '0' && ch <= '9' ){
                x = x * 10 + ( ch - '0' ) ;
            } else if( ch == ']') {
                if( x > 0 ) dq.push_back( x ) ;
                x = 0 ;
            } else {
                if( x > 0 ) dq.push_back( x ) ;
                x = 0 ;
            }
        }

        bool way = true ;
        bool flag = true ;
        for( char ch : oper ) {

            if( ch == 'R' ) way = !way ;

            if( ch == 'D' ) {

                if( dq.empty() ) {
                    cout << "error" << "\n" ;
                    flag = false ;
                    break ;
                } else {

                    if( way ) dq.pop_front() ;
                    else dq.pop_back() ;
                }
            }
        }

        if( flag ) {

            if( !way ) {
                reverse( dq.begin(), dq.end() ) ;
            }

            cout << '[' ;
            for( int i = 0 ; i < (int)dq.size() ; i++ ) {

                cout << dq[i] ;

                if( i != (int)dq.size() - 1 ) cout << ',' ;
            }
            cout << ']' << "\n" ;

        }
        

        T-- ;
    }

    return 0 ;
}