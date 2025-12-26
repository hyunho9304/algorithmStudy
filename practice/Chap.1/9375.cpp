//  g++ -std=c++14 -Wall 9375.cpp -o test.out
#include<bits/stdc++.h>
using namespace std ;

int testNum, N ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testNum ;

    for( int i = 0 ; i < testNum ; i++ ) {
        
        cin >> N ;

        map<string,int> c;
        for( int i = 0 ; i < N ; i++ ) {

            string name, type ;
            cin >> name >> type ;
            c[type] += 1 ;
        }

        long long result = 1 ;
        for( auto each : c ) {
            result *= ( each.second + 1 ) ;
        }
        cout << result - 1 << "\n" ;
    }
    return 0 ;
}