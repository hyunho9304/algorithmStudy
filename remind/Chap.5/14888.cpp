//  구현
//  완점탐색, 백트래킹
#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<int> v;
int a[4] ;

int retMax = INT_MIN ;
int retMin = INT_MAX ;

int func( int num1, int num2 , char ch ) {

    if( ch == '+' ) return num1 + num2 ;
    else if( ch == '-' ) return num1 - num2 ;
    else if( ch == '*' ) return num1 * num2 ;
    else if( ch == '/' ) return num1 / num2 ;
    else return 0 ;
}

void go( int num, int current ) {

    if( num == N - 1 ) {
        retMax = max( retMax, current ) ;
        retMin = min( retMin , current ) ;
        return ;
    }

    for( int i = 0 ; i < 4 ; i++ ) {

        if( a[i] == 0 ) continue ;

        char ch ;
        if( i == 0 ) ch = '+' ;
        if( i == 1 ) ch = '-' ;
        if( i == 2 ) ch = '*' ;
        if( i == 3 ) ch = '/' ;

        a[i]-- ;

        int toNum = func( current , v[num+1], ch ) ;
        go( num + 1 , toNum ) ;

        a[i]++;
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        int num ;
        cin >> num ;
        v.push_back( num ) ;
    }

    for( int i = 0 ; i < 4 ; i++ ) {
        int num ;
        cin >> num ;
        a[i] = num ;
    }

    go( 0, v[0] ) ;

    cout << retMax << "\n" << retMin << "\n" ;
    return 0 ;
}