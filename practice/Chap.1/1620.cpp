//  g++ -std=c++14 -Wall 1620.cpp -o test.out
#include<bits/stdc++.h>
using namespace std ;

int N, M ;
map<int,string> text ;
map<string,int> reverse_text;
string quiz[100001];

void solve() {

    for( int i = 1 ; i <= M ; i++ ) {
        string str = quiz[i];

        if( atoi(str.c_str() ) == 0 ) {
            cout << reverse_text[str] << "\n" ;
        } else {
            cout << text[atoi(str.c_str() )] << "\n" ;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M ;
    
    for( int i = 1 ; i <= N ; i++ ) {
        string tmp ;
        cin >> tmp ;
        text[i] = tmp ;
        reverse_text[tmp] = i ;
    }
    
    for( int i = 1 ; i <= M ; i++ )
        cin >> quiz[i] ;

    solve() ;

    return 0;
}