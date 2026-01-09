#include<bits/stdc++.h>
using namespace std ;

vector<int> ret;
int N ;

bool check(int i) {

    string s = to_string(i);

    int cnt = 0 ;
    for( char c : s ) {
        if( c == '6' ) {
            if( ++cnt == 3 ) break ;
        } else cnt = 0 ;
    }

    if( cnt == 3 ) return true ;
    else return false ;
}

int main() {

    int N ;
    cin >> N ;

    int number = 666 ;
    int find = 0 ;
    while( true ) {

        if( check(number)) {
            if( ++find == N ) {
                cout << number << "\n" ;
                break ;
            }
        }

        number++ ;
    }
    return 0;
}