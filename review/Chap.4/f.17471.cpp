#include<bits/stdc++.h>
using namespace std ;

const int max_n = 14 ;

int N ;
int a[max_n] ;
int visited[max_n];
int comp[max_n] ;

vector<int> adj[max_n] ;

int ret = 987654321 ;

pair<int,int> dfs( int here, int value ) {

    visited[here] = 1 ;

    pair<int,int> result = { 1, a[here] } ;

    for( int there : adj[here] ) {

        if( comp[there] != value ) continue ;
        if( visited[there] ) continue ;

        pair<int,int> _tmp = dfs( there, value ) ;

        result.first += _tmp.first ;
        result.second += _tmp.second ;
    }

    return result ;
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
            adj[tmp].push_back(i) ;
        }
    }

    for( int i = 1 ; i < ( 1 << N ) - 1 ; i++ ) {

        fill( &comp[0] , &comp[0] + max_n , 0 ) ;
        fill( &visited[0], &visited[0] + max_n, 0 ) ;

        int idx1 = -1 ;
        int idx2 = -1 ;

        for( int j = 0 ; j < N ; j++ ) {

            if( i & ( 1 << j )) {
                comp[j+1] = 1 ;
                idx1 = j+1;
            } else {
                comp[j+1] = 0 ;
                idx2 = j+1 ;
            }
        }

        pair<int,int> comp1 = dfs( idx1, 1 ) ;
        pair<int,int> comp2 = dfs( idx2, 0 ) ;

        if( comp1.first + comp2.first == N ) {
            ret = min( ret , abs( comp1.second - comp2.second ) ) ;
        }
    }

    cout << ( ret == 987654321 ?  -1 : ret )  << "\n" ;
    return 0 ;
}