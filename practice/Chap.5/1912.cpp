#include<bits/stdc++.h>
using namespace std ;

int N ;
long long sum ;

long long ret = LLONG_MIN ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {

        int num ;
        cin >> num ;

        sum += num ;
        ret = max( ret, sum ) ;

        if( sum < 0 ) sum = 0 ;
        
    }

    cout << ret << "\n" ;
    return 0 ;
}