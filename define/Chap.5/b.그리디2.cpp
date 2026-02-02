#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

int N , K ;
vector<ll> v ;
vector<pair<int,int>> vv ;
priority_queue<ll> pq ;
ll ret ;

int main() {

    cin >> N >> K ;

    vv.resize(N);
    v.resize(K);
    for( int i = 0 ; i < N ; i++ ) {
        cin >> vv[i].first >> vv[i].second ;
    }

    for( int i = 0 ; i < K ; i++ ) {
        cin >> v[i] ;
    }

    sort( vv.begin(), vv.end() ) ;
    sort( v.begin(), v.end() ) ;

    int j = 0 ;
    for( int i = 0 ; i < K ; i++ ) {

        while( j < N && v[i] >= vv[j].first ) {
            pq.push( vv[j++].second ) ;
        }

        if( !pq.empty() ) {
            ret += pq.top() ;
            pq.pop() ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
    
}