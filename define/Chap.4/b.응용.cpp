#include<bits/stdc++.h>
using namespace std ;

const int max_n = 4 ;
string a[max_n] = { "1", "2", "3", "4" } ;


void go( int num ) {
    
    string ret = "" ;
    for( int i = 0 ; i < 4 ; i++ ) {
        if( num & ( 1 << i ) ) ret += a[i] + " " ;
    }
    cout << ret << "\n" ;
}

int main() {
    
    for( int i = 0 ; i < ( 1 << max_n ) ; i++ ) {
        string ret = "" ;
        for( int j = 0 ; j < max_n ; j++ ) {
            if( i & ( 1 << j ) ) {
                ret += ( a[j] + " " ) ;
            }
        }
        cout << ret << "\n" ;
    }

    
    cout << "\n" ;
//  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    cout << "\n" ;


    // for( int i = 0 ; i < max_n ; i++ ) {
    //     go( 1 | ( 1 << i ) ) ;
    // }

    // return 0 ;


}
