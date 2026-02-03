//  최소 우선순위 큐
#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<pair<int,int>> v ;
int day, cup ;
priority_queue<int, vector<int>, greater<int>> pq ;

int ret ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> day >> cup ;
        v.push_back( { day, cup }) ;
    }

    sort( v.begin(), v.end() ) ;

    for( int i = 0 ; i < N ; i++ ) {

        pq.push( v[i].second ) ;
        ret += v[i].second ;

        if( pq.size() > v[i].first ) {
            ret -= pq.top() ;
            pq.pop() ;
        }
    }

    cout << ret << "\n" ;
    return 0;
}