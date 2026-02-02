#include<bits/stdc++.h>
using namespace std ;

int N, P, D ;
vector<pair<int,int>> v ;
int day, money ;
priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙(가장 작은 돈이 위)

long long ret ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> money >> day ;
        v.push_back( { day, money }) ;
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
    return 0 ;
}