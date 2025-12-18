//  g++ -std=c++14 -Wall ./10808.cpp -o ./10808.out 
#include<bits/stdc++.h>
using namespace std;

string S ;
int psum[26];
void solve() {
    
    for( char ch : S ) {
        psum[ ch - 'a']++ ;
    }
}

void print() {
    for( int i = 0 ; i < 26 ; i++ ) {
        cout << psum[i] << " " ;
    }
    cout << "\n" ;
}

int main() {

    cin >> S ;
    solve();
    print();
    return 0;
}