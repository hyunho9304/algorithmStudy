//  g++ -std=c++14 -Wall 9996.cpp -o test.out
#include<bits/stdc++.h>
using namespace std ;

int N ;
string pattern;
vector<string> quiz;

void solve() {

    auto delimeter = pattern.find( '*' ) ;
    string pre = pattern.substr( 0 , delimeter ) ;
    string post = pattern.substr( delimeter + 1 ) ;

    for( string q : quiz ) {
        if( q.length() < pre.length() + post.length() ) {
            cout << "NE" << "\n" ;
        } else {
            if( q.substr( 0, pre.length() ) == pre && q.substr( q.length() - post.length() ) == post ) cout << "DA" << "\n" ;
            else cout << "NE" << "\n" ;
        }
    }
}

int main() {

    cin >> N ;
    cin >> pattern ;
    
    for( int i = 0 ; i < N ; i++ ) {
        string tmp ;
        cin >> tmp ;
        quiz.push_back(tmp) ;
    }

    solve() ;

    return 0 ;
    
}