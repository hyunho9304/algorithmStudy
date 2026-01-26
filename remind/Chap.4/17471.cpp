#include<bits/stdc++.h>
using namespace std ;

const int INF = 987654321 ;

int N ;
int a[11] ;
int visited[11] ;
int comp[11] ;

vector<int> adj[11];
int ret = INF ;

pair<int,int> dfs(  int here, int value ) {
    
    visited[here] = 1 ;

    pair<int,int> ret = { 1, a[here] } ;

    for( int there : adj[here] ) {

        if( comp[there] != value ) continue ;
        if( visited[there] ) continue ;

        pair<int,int> _temp = dfs( there, value ) ;
        ret.first += _temp.first ;
        ret.second += _temp.second ;
    }

    return ret ;
}

int main() {

    cin >> N ;

    for( int i = 1 ; i <= N ; i++ ) {
        cin >> a[i] ;
    }

    for( int i = 1 ; i <= N ; i++ ) {
        int num ;
        cin >> num ;
        for( int j = 0 ; j < num ; j++ ) {
            int tmp ;
            cin >> tmp ;
            adj[i].push_back( tmp ) ;
            adj[tmp].push_back(i ) ;
        }
    }

    for( int i = 1 ; i < ( 1 << N ) - 1 ; i++ ) {

        fill( comp, comp + 11 , 0 ) ;
        fill( visited, visited + 11 , 0 ) ;
        int idx1 = -1 ;
        int idx2 = - 1 ;
        for( int j = 0 ; j < N ; j++ ) {

            if( i & ( 1 << j ) ) {
                comp[ j + 1 ] = 1 ;
                idx1 = j + 1 ;
            } else {
                comp[ j + 1 ] = 0 ;
                idx2 = j + 1 ;
            }
        }

        pair<int,int> comp1 = dfs( idx1, 1 ) ;
        pair<int,int> comp2 = dfs( idx2, 0 ) ;

        if( comp1.first + comp2.first == N ) {
            ret = min( ret, abs( comp1.second - comp2.second ) ) ;
        }
    }

    cout << ( ret == INF ? -1 : ret ) << "\n" ;

    return 0 ;
}