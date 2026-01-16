#include<bits/stdc++.h>
using namespace std ;

const int max_n = 200004 ;
int N, K ;
int visited[max_n] ;
int loadNum[max_n] ;
int ret ;
vector<int> v ;

void bfs() {
    queue<int> q ;
    visited[N] = 1 ;
    q.push( N ) ;

    while( q.size() ) {
        int x = q.front() ; q.pop() ;

        if( x == K ) {
            ret = visited[K] ; break ;
        }
        for( int nx : { x-1, x+1, 2*x }) {
            if( nx < 0 || nx >= max_n ) continue ;

            if( visited[nx] == 0 ) {
                visited[nx] = visited[x] + 1 ;
                q.push( nx ) ;
                loadNum[nx] = x ;
            }
        }
    }

    return ;
}

int main() {
    cin >> N >> K ;

    bfs() ;

    for( int i = K ; i != N ; i = loadNum[i] ) {
        v.push_back( i ) ;
    }
    v.push_back( N ) ;

    reverse( v.begin(), v.end());

    cout << ret -1  << "\n" ;
    for( int num : v ) cout << num << " " ;
    cout << "\n" ;
    return 0 ;


}