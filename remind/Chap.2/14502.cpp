#include<bits/stdc++.h>
using namespace std ;

const int max_n = 10;
int N, M ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<pair<int,int>> wall ;
vector<pair<int,int>> virus ;

int ret ;

void dfs(int y , int x ) {

    visited[y][x] = 1;

    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
        if( a[ny][nx] == 1) continue ;
        if( visited[ny][nx] == 1 ) continue ;

        dfs( ny, nx ) ;
    }
    return ;
}

int solve() {

    fill( &visited[0][0], &visited[0][0] + max_n * max_n, 0) ;

    for( pair<int,int> p : virus ) {
        dfs( p.first, p.second);
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
            if( a[i][j] == 0 ) wall.push_back( {i,j}) ;
            if( a[i][j] == 2 ) virus.push_back( {i,j} ) ;
        }
    }

    int wallSize = wall.size();
    for( int i = 0 ; i < wallSize ; i++ ) {
        for( int j = i + 1 ; j < wallSize  ; j++ ) {
            for( int k = j + 1 ; k < wallSize ; k++ ) {
               
                a[wall[i].first][wall[i].second ] = 1 ;
                a[wall[j].first][wall[j].second ] = 1 ;
                a[wall[k].first][wall[k].second ] = 1 ;
                ret = max( ret, solve() ) ;
                a[wall[i].first][wall[i].second ] = 0 ;
                a[wall[j].first][wall[j].second ] = 0 ;
                a[wall[k].first][wall[k].second ] = 0 ;
            }
        }
    }

    cout << ret << "\n" ;
    return 0;

}