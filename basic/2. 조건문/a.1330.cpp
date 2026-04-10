#include<bits/stdc++.h>
using namespace std ;

int A, B ;

int main() {

    cin >> A >> B ;

    if( A > B ) cout << ">" << "\n";
    else if( A < B ) cout << "<" << "\n" ;
    else cout << "==" << "\n" ;

    return 0 ;
}