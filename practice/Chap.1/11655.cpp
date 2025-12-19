//  g++ -std=c++14 -Wall 11655.cpp -o test.out
#include<bits/stdc++.h>
using namespace std ;

string S ;
string result ;

void solve() {

    for( int i = 0 ; i < S.length() ; i++ ) {

        if( S[i] >= 'A' && S[i] <= 'Z') {
            if( (S[i] + 13) > 'Z') result += char( S[i] - 13 ) ;
            else result += char( S[i] + 13 ) ;
        } else if( S[i] >= 'a' && S[i] <= 'z' ) {
            if( (S[i] + 13) > 'z') result += char( S[i] - 13 ) ;
            else result += char( S[i] + 13 ) ;
        } else {
            result += S[i];
        }
    }
}

int main() {

    getline(cin, S);
    solve() ;
    cout << result << "\n" ;
    return 0 ;
    
}