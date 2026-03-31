#include<bits/stdc++.h>
using namespace std ;

const int max_n = 104 ;

int N, M ;
int a[max_n][max_n];
int visited[max_n][max_n] ;
vector<pair<int,int>> melt ;

const int dy[] = { -1 , 0 , 1 , 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;

int hours ;
int cnt ;

void dfs( int y, int x ) {

    visited[y][x] = 1 ;
    
    if( a[y][x] == 1 ) {
        melt.push_back( {y, x}) ;
        return ;
    }

    for( int dir = 0 ; dir < 4 ; dir++  ){

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
        if( visited[ny][nx] ) continue ;

        dfs( ny, nx ) ;
    }

    return ;
}

int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cin >> a[i][j] ;
        }
    }


    while( true ) {

        bool flag = false ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < M ; j++ ) {

                if( a[i][j] == 1 ) {
                    flag = true ;
                    break ;
                }
            }

            if( flag ) break ;
        }

        if( !flag ) break ;

        melt.clear() ;
        fill( &visited[0][0] , &visited[0][0] + max_n * max_n , 0 ) ;

        dfs( 0, 0 ) ;

        cnt = melt.size() ;

        for( pair<int,int> p : melt ) {
            a[p.first][p.second] = 0 ;
        }
        

        hours++ ;
        
    }

    cout << hours << "\n" ;
    cout << cnt << "\n";

    return 0 ;

    
}