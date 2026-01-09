#include<bits/stdc++.h>
using namespace std ;

const int V = 54;
vector<int> adj[V];
int visited[V] ;

int N , cut ;
int ret ;
int root ;

void dfs( int u ) {

    visited[u] = 1 ;
    for( int v : adj[u] ) {
        if( !visited[v] ) dfs(v);
    }
}

void cntLeaf() {

    if( visited[root] ) {
        ret = 0 ; return ;
    }
    
    for( int i = 0 ; i < N ; i++ ) {

        if( visited[i] ) continue ;

        int aliveChild = 0 ;
        for( int num : adj[i] ) {
            if( !visited[num]) aliveChild++ ;
        }
        if( aliveChild == 0 ) ret++ ;
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        int node ;
        cin >> node ;
        
        if( node == -1 ) {
            root = i ;
            continue ;
        } 
        
        adj[node].push_back(i);
    }

    cin >> cut ;

    dfs( cut ) ;
    cntLeaf() ;
    cout << ret << "\n";

    return 0;


}