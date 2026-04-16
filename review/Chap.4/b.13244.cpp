#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;

int T ;
int V ;
int E ;
vector<int> adj[max_n] ;
int visited[max_n] ;

int cnt ;

void dfs( int here ) {

    visited[here] = 1 ;

    for( int next : adj[here] ) {

        if( visited[next] ) continue ;

        dfs( next ) ;
    }
}

int main() {

    cin >> T ;
    while( T > 0 ) {

        cin >> V >> E ;

        fill( &visited[0] , &visited[0] + max_n, 0 ) ;
        for( int i = 0 ; i < 1004 ; i++ ) adj[i].clear() ;
        cnt = 0 ;

        int a, b ;
        for( int i = 1 ; i <= E ; i++ ) {
            cin >> a >> b ;
            adj[a].push_back(b) ;
            adj[b].push_back(a) ;
        }

        for( int i = 1 ; i <= V ; i++ ) {

            if( visited[i] == 0 ) {
                dfs( i ) ;
                cnt++ ;
            }
        }

        if( E == V - 1 && cnt == 1 ) cout << "tree" << "\n" ;
        else cout << "graph" << "\n" ;

        T-- ;
    }

    return 0 ;
}