#include<bits/stdc++.h>
using namespace std ;

int A, B ;
vector<int> tmp ;
vector<int> tmp2;
int ret ;

int main() {

    cin >> A >> B ;

    string s = to_string(B);
    for( int i = (int)(s.size() - 1 ) ; i >= 0 ; i-- ) {
        int num = s[i] - '0' ;
        tmp.push_back( A * num ) ;
    }

    for( int i = 0 ; i < (int)tmp.size() ; i++ ) {
        if( i == 0 ) tmp2.push_back(tmp[i]) ;
        else tmp2.push_back( tmp[i] * ( i == 1 ? 10 : 100) ) ;    
    }

    for( int num : tmp2 ) {
        ret += num ;
    }

    for( int num : tmp ) {
        cout << num << "\n" ;
    }
    cout << ret << "\n" ;

    return 0 ;

    
}