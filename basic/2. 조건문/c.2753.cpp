#include<bits/stdc++.h>
using namespace std ;

int year ;

int main() {

    cin >> year ;

    if( year % 4 == 0 ) {
        if( year % 100 != 0 || year % 400 == 0 ) cout << "1" << "\n" ;
        else cout << "0" << "\n" ;
    } else cout << "0" << "\n" ;

    return 0 ;
}