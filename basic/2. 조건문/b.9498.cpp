#include<bits/stdc++.h>
using namespace std ;

int num ;

int main() {

    cin >> num ;

    if( num >= 90 && num <= 100 ) cout << "A" << "\n" ;
    else if( num >= 80 && num <= 89 ) cout << "B" << "\n" ;
    else if( num >= 70 && num <= 79 ) cout << "C" << "\n" ;
    else if( num >= 60 && num <= 69 ) cout << "D" << "\n" ;
    else cout << "F" << "\n" ;

    return 0 ;
}