#include<bits/stdc++.h>
using namespace std ;

int num ;
int sum[7] ;
int ret ;
int countNum ;

int main() {

    for( int i = 0 ; i < 3 ; i++ ) {
        cin >> num ;
        countNum = max( countNum, num ) ;
        sum[num]++ ;
    }

    bool flag = false ;
    for( int i = 1 ; i <= 6 ; i++ ) {
        if( sum[i] == 3 ) {
            flag = true ;
            ret = 10000 + i * 1000 ;
        } else if( sum[i] == 2 ) {
            flag = true ;
            ret = 1000 + i * 100 ;
        }
    }

    if( flag ) cout << ret << "\n" ;
    else {

        ret = countNum * 100 ;
        cout << ret << "\n" ;
    }

    return 0 ;

}