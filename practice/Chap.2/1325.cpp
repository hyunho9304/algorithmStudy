#include<bits/stdc++.h>
using namespace std ;

int N, M;
vector<int> adj[10004] ;
int visited[10004];

int ret[10004];
int mx ;

int dfs( int here ) {

    visited[here] = 1 ;
    int cnt = 1 ;
    for( int v : adj[here] ) {
        if( visited[v] == 1 ) continue ;
        cnt += dfs(v);
    }

    return cnt ;
}

int main() {

    cin >> N >> M ;

    for( int i = 0 ; i < M ; i++ ) {
        int x ;
        int y ;
        cin >> x >> y ;
        adj[y].push_back(x);
    }

    for( int i = 1 ; i <= N ; i++ ) {
        memset( visited, 0 , sizeof( visited ) ) ;
        
        ret[i] = dfs(i) ;
        mx = max(ret[i], mx);
    }

    for( int i = 1 ; i <= N ; i++ ) {
        if( ret[i] == mx )
            cout << i << " " ;
    }
    cout << "\n" ;

    return 0 ;

}