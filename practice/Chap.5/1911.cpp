#include<bits/stdc++.h>
using namespace std ;

int N, L ;
vector<pair<int,int>> v ;

long long ret ;

int main() {

    cin >> N >> L ;
    for( int i = 0 ; i < N ; i++ ) {
        int a, b ;
        cin >> a >> b;

        v.push_back({a, b}) ;
    }

    sort( v.begin(), v.end() ) ;

    long long pos = 0 ;
    for( pair<int,int> p : v ) {

        int from = p.first ;
        int to = p.second ;

        if( pos < from ) pos = from ;
        if( pos >= to ) continue ;

        long long need = ( to - pos + L - 1 ) / L ;
        
        ret += need ;
        pos += need * L ;

        
    }

    cout << ret << "\n" ;
    return 0 ;
}