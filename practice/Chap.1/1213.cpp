#include<bits/stdc++.h>
using namespace std ;

string str ;
int alphaSum[26] ;
string result ;


bool check() {

    if( str.length() % 2 == 0 ) {
        for( int n : alphaSum ) {
            if( n % 2 == 1 && n != 0 ) {
                return false ;
            }
        } 
    } else {
        int oddSum = 0 ;
        for( int n : alphaSum) {
            if( n % 2 == 1 && n != 0 ) {
                oddSum += 1 ;
                if( oddSum == 2) return false ;
            }
        }
    }

    return true ;
}

void solve() {

    char mid = 'a' ;
    for( int i = 25 ; i >= 0 ; i-- ) {
        if( alphaSum[i] ) {

            if( alphaSum[i] % 2 == 1 ) {
                mid = char(i + 'A') ;
                alphaSum[i]--;
            }

            for( int j = 0 ; j < alphaSum[i] ; j += 2  ) {
                result = char( i + 'A' ) + result ;
                result += char( i + 'A' ) ;
            }
        }
    }
 
    if( mid != 'a') {
        result.insert(result.begin() + result.length() / 2, mid) ;
    }

}

int main() {

    cin >> str ;
    for( char c : str ) {
        alphaSum[c - 'A']++ ;
    }

    bool isGo = check() ;

    if( isGo ) {
        solve();
    } else {
        cout << "I'm Sorry Hansoo" << "\n" ;
    }

    cout << result << "\n" ;

    return 0 ;

}