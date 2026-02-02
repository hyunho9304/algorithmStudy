#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<pair<int,int>> v ;
int start , finish ;
int ret = 1 ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> start >> finish ;

        v.push_back( { finish, start }) ;
    }

    sort( v.begin() , v.end() ) ;


    int to = v[0].first ;

    for( int i = 1 ; i < N ; i++ ) {

        if( v[i].second < to ) continue ;

        to = v[i].first ;
        ret++ ;
    }

    cout << ret << "\n" ;

}