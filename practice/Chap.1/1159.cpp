//  g++ -std=c++14 -Wall 1159.cpp -o 1159.out
#include<bits/stdc++.h>
using namespace std ;

int N, sum[26] ;
string str ;
string result ;

void solve() {

    for( int i = 0 ; i < 26 ; i++ ) {
        if( sum[i] >= 5 ) {
            result += ( i + 'a' ) ;
        }
    }
}

void print() {

    if( result == "" ) {
        cout << "PREDAJA" << "\n" ;
    } else {
        cout << result << "\n" ;
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> str ;
        sum[ str[0] - 'a']++ ;
    }

    solve() ;
    print() ;

    return 0 ;
    
}