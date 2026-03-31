#include<bits/stdc++.h>
using namespace std ;

const int max_n = 10 ;

int N, M ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;

vector<pair<int,int>> virus ;
vector<pair<int,int>> zero ;

const int dy[] = { -1, 0, 1, 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;

int ret = -1 ;

void dfs( int y, int x ) {

    visited[y][x] = 1 ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
        if( visited[ny][nx] ) continue ;
        if( a[ny][nx] == 1 ) continue ;

        dfs( ny, nx ) ;
    }

    return ;

}

int solve() {

    fill( &visited[0][0] , &visited[0][0] + max_n * max_n , 0 ) ;

    for( pair<int,int> p : virus ) {
        dfs( p.first, p.second ) ;
    }

    int cnt = 0 ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            if( a[i][j] == 0 && !visited[i][j] ) cnt++ ;
        }
    }

    return cnt ;
}

int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cin >> a[i][j] ;

            if( a[i][j] == 0 ) zero.push_back( {i,j} ) ;
            else if( a[i][j] == 2 ) virus.push_back( { i,j } ) ;
        }
    }

    int tmpSize = zero.size() ;
    for( int i = 0 ; i < tmpSize ; i++ ) {
        for( int j = i + 1 ; j < tmpSize ; j++ ) {
            for( int k = j + 1 ; k < tmpSize ; k++ ) {

                a[zero[i].first][zero[i].second] = 1 ;
                a[zero[j].first][zero[j].second] = 1 ;
                a[zero[k].first][zero[k].second] = 1 ;
                ret = max( ret, solve() ) ;
                a[zero[i].first][zero[i].second] = 0 ;
                a[zero[j].first][zero[j].second] = 0 ;
                a[zero[k].first][zero[k].second] = 0 ;
            }
        }
    }

    cout << ret << "\n";
    return 0 ;
}
