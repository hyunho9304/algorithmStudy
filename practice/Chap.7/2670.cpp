#include<bits/stdc++.h>
using namespace std ;

int N ;
double num ;
vector<double> v ;
double dp[10004] ;

double ret ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> num ;
        v.push_back( num ) ;
    }

    dp[0] = v[0] ;
    ret = dp[0] ;

    for( int i = 1 ; i < N ; i++ ) {

        dp[i] = max( v[i], dp[i-1] * v[i] ) ;
        ret = max( ret, dp[i] ) ;
    }

    cout.setf(ios::fixed);
    cout.precision(3);

    printf( "%.3lf" , ret  ) ;
    return 0;
}