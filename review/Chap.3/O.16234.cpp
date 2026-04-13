#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N , L , R ;
int a[max_n][max_n];
int visited[max_n][max_n] ;
vector<pair<int,int>> area ;

const int dy[] = { -1, 0, 1, 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;

int sum ;

int ret ;

void dfs( int y , int x ) {

    visited[y][x] = 1 ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue ;
        if( visited[ny][nx] ) continue ;
        if( abs( a[ny][nx] - a[y][x] ) < L || abs( a[ny][nx] - a[y][x] ) > R  ) continue ;

        sum += a[ny][nx] ;
        area.push_back( {ny,nx} ) ;

        dfs(ny,nx ) ;
    }
}

int main() {

    cin >> N >> L >> R ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
        }
    }


    while( true ) {

        bool flag = false ;
        fill( &visited[0][0] , &visited[0][0] + max_n * max_n , 0 ) ;

        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {

                if( visited[i][j] != 0 ) continue ;


                sum = a[i][j] ;

                area.clear();
                area.push_back( {i,j}) ;
                
                dfs( i, j ) ;

                if( area.size() == 1 ) continue ;

                for( pair<int,int> p : area ) {
                    a[p.first][p.second] = sum / area.size() ;
                    flag = true ;
                }
            }
        }

        if( flag ) ret++ ;
        else break ;

    }
    
    cout << ret << "\n" ;
    return 0 ;
}