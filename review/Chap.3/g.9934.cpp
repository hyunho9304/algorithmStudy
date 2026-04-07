#include<bits/stdc++.h>
using namespace std ;

int K ;
int maxNum ;
int a[1023] ;
vector<int> ret[14] ;

void go( int s, int e, int level ) {

    if( s > e ) return ;

    if( s == e ) {
        ret[level].push_back( a[s] ) ;
        return ;
    }

    int mid = ( s + e ) / 2 ;
    ret[level].push_back( a[mid] ) ;

    go( s, mid - 1 , level + 1 ) ;
    go( mid + 1 , e , level + 1 ) ;
}

int main() {

    cin >> K ;
    maxNum = (int)pow( 2, K ) -1 ;

    for( int i = 0 ; i < maxNum ; i++ ) {
        cin >> a[i] ;
    }

    go( 0, maxNum, 1 ) ;

    for( int i = 1 ; i <= K ; i++ ) {
        for( int num : ret[i] ) {
            cout << num << " " ;
        }
        cout << "\n" ;
    }

    return 0 ;

}