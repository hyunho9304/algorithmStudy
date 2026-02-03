#include<bits/stdc++.h>
using namespace std ;

int N, K ;
int m, v, c ;
vector<pair<int,int>> jewels ;
vector<int> bag;
priority_queue<int> pq ;

long long ret ;

int main() {

    cin >> N >> K ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> m >> v;
        jewels.push_back( { m, v}) ;
    }

    for( int i = 0 ; i < K ; i++ ) {
        cin >> c;
        bag.push_back( c ) ;
    }

    sort( jewels.begin(), jewels.end() );
    sort( bag.begin(), bag.end() ) ;

    int j = 0 ;
    for( int i = 0 ; i < K ; i++ ) {

        while( j < N && jewels[j].first <= bag[i] ) {
            pq.push( jewels[j++].second ) ;
        }

        if( !pq.empty() ) {
            ret += pq.top() ;
            pq.pop() ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}