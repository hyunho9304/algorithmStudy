#include<bits/stdc++.h>
using namespace std;

int N, M, num ;
map<int,int> mp ;

int ret ;

int main() {

    cin >> N >> M ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> num ;
        mp[num]++ ;
    }

    for( int i = 0 ; i < M ; i++ ) {
        cin >> num ;
        mp[num]++ ;
    }

    for( auto it : mp ) {
        if( it.second == 1 )ret++ ;
    }

    cout << ret << "\n" ;
    return 0 ;
}