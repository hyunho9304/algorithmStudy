#include<bits/stdc++.h>
using namespace std ;

int N ;
double score ;
priority_queue<double> pq ;
vector<double> v; 

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> score ;
        
        if( pq.size() >= 5 ) pq.pop() ;

        pq.push( score ) ;
    }

    while( !pq.empty() ) {
        
        v.push_back( pq.top() ) ;
        pq.pop() ;
    }

    sort( v.begin() , v.end() ) ;

    for( double num : v ) {
        cout << num << "\n" ;
    }

    return 0 ;
    
}