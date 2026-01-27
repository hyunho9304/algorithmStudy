#include<bits/stdc++.h>
using namespace std ;

int T ;
vector<int> adj[1004] ;    
int visited[1004] ;
int cnt ;

void dfs( int here ) {
    
    visited[here] = 1 ;

    for( int there : adj[here]) {
        if( visited[there] == 0 ) dfs(there) ;
    }

    return ;
}

int main() {

    cin >> T ;

    int V ;
    int E ;
    while( T != 0 ) {

        for( int i = 0 ; i < 1004 ; i++ ) adj[i].clear() ;
        fill( visited, visited + 1004, 0 ) ;
        cnt = 0 ;

        cin >> V ;
        cin >> E ;

        int a, b; 
        for( int i = 0 ; i < E ; i++ ) {
            cin >> a >> b ;
            adj[a].push_back(b) ;
            adj[b].push_back(a) ;
        }

        for( int i = 1 ; i <= V ; i++ ) {
            if( visited[i] == 0 ) {
                dfs(i ) ;
                cnt++ ;
            }
        }

        if( ( E == V - 1 ) && ( cnt == 1 ) ) cout << "tree\n" ;
        else cout << "graph\n" ;

        T-- ;
    }

    return 0 ;
}