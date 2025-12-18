//  g++ -std=c++14 -Wall ./2979.cpp -o 2979.out 
#include<bits/stdc++.h>
using namespace std ;

int A,B,C ;
int aa[100], bb[100],cc[100] ;
int result ;

void solve() {

    for( int i = 0 ; i < 100 ; i++ ) {
        int cnt = 0 ;
        if( aa[i] != 0) cnt++ ;
        if( bb[i] != 0) cnt++ ;
        if( cc[i] != 0) cnt++ ;

        int cost = 0 ;
        switch( cnt ) {
            case 1 :
                cost = A ; break ;
            case 2 :
                cost = B ; break ;
            case 3 :
                cost = C ; break ;
        }
        int tmp = cnt * cost ;
        result += tmp ;
    }
}

int main() {

    cin >> A >> B >> C ;

    int startaa, endaa = 0 ;
    int startbb, endbb = 0 ;
    int startcc, endcc = 0;
    cin >> startaa >> endaa ;
    cin >> startbb >> endbb;
    cin >> startcc >> endcc ;

    for( int i = startaa ; i < endaa ; i++ ) aa[i]++ ;
    for( int i = startbb ; i < endbb ; i++ ) bb[i]++ ;
    for( int i = startcc ; i < endcc ; i++ ) cc[i]++ ;

    solve() ;

    cout << result << "\n" ;

    return 0 ;   
}