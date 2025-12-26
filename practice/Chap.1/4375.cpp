#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
int N ;

int main() {

    while( scanf( "%d" , &N ) != EOF ) {
        int cnt = 1 , ret = 1 ;

        while( true ) {

            if( cnt % N == 0 ) {
                cout << ret << "\n" ;
                break ;
            } else {
                cnt = cnt * 10  + 1 ;
                cnt %= N ;
                ret++ ;
            }
        }
    }
    return 0 ;
}