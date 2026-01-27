#include<bits/stdc++.h>
using namespace std ;

int T ;
string oper ;
int ssize ;
string str ;
deque<int> D ;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T ;

    while( T != 0 ) {

        oper = "" ;
        ssize = 0 ;
        D.clear() ;

        cin >> oper ;
        cin >> ssize ;
        cin >> str ;


        int x = 0 ;
        for( char c : str ) {
            if( c == '[' || c == ']' ) continue ;

            if( c >= '0' && c <= '9' ) x = x * 10 + ( c - '0' ) ;
            else {
                if( x > 0 ) D.push_back(x ) ;

                x = 0 ;
            }
        }
        if(x > 0) D.push_back(x);


        
        bool rev = false ;
        bool error = false ;
        for( char c : oper ) {

            if( c == 'R') rev = !rev ;
            else {

                if( D.empty() ) {
                    error = true ; break ;
                }

                if( rev ) D.pop_back() ;
                else D.pop_front() ;
            }
        }

        if( error ) cout << "error\n" ;
        else {
            string str = "[" ;

            if( rev ) reverse( D.begin(), D.end() ) ;

            for( int i = 0 ; i < D.size() ; i++ ) {
                
                str += to_string(D[i] ) ;

                if( i != D.size() -1 ) str += "," ;
            }
            str += "]" ;

            cout << str << "\n" ;
        }
        

        T-- ;
    }

    return 0 ;
}