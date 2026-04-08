#include<bits/stdc++.h>
using namespace std ;

const int max_n = 100004 ;

int N, K ;
int visited[max_n];
int parent[max_n*2] ;
vector<int> ret ;

void bfs() {

    queue<int> q ;
    q.push( N ) ;
    visited[N] = 1 ;

    while( !q.empty() ) {

        int X = q.front() ; q.pop() ;

        if( X == K ) break ;

        for( int nx : { X -1 , X + 1 , 2 * X } ) {

            if( nx < 0 || nx >= max_n ) continue ;
            if( visited[nx] ) continue ;

            visited[nx] = visited[X] + 1 ;
            q.push( nx ) ;
            parent[nx] = X ;

        }
    }

}

int main() {

    cin >> N >> K ;

    bfs();

    cout << visited[K] - 1 << "\n" ;

    for( int i = K ; i != N ; i = parent[i] ) {
        ret.push_back( i ) ;
    }

    ret.push_back( N ) ;

    reverse( ret.begin() , ret.end() ) ;

    for( int num : ret ) {
        cout << num << " " ;
    }


    cout << "\n" ;


    return 0 ;
}
