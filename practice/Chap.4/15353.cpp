#include<bits/stdc++.h>
using namespace std ;

string A, B ;
string ret ;

int main() {
    
    cin >> A >> B ;
    
    int idx1 = A.size() - 1 ;
    int idx2 = B.size() - 1 ;

    int up = 0 ;
    int eachA = 0 ;
    int eachB = 0 ;
    int sum = 0 ;
    string tmp = "" ;

    while( true ) {

        if( idx1 < 0 && idx2 < 0 ) {

            if( up == 1 ) {
                ret += "1" ;
            }
            break ;
        }

        if( idx1 >= 0 ) eachA = A[idx1] - '0' ;
        else eachA = 0 ;

        if( idx2 >= 0 ) eachB = B[idx2] - '0' ;
        else eachB = 0 ;

        sum = eachA + eachB + up ;

        tmp = to_string( sum ) ;

        if( tmp.size() >= 2 ) {
            up = 1 ;
            ret += tmp[1] ;
        } else {
            up = 0 ;
            ret += tmp ;
        }

        idx1-- ;
        idx2-- ;
    }

    reverse( ret.begin(), ret.end() );

    cout << ret << "\n" ;
    

    return 0 ;
}  