#include<bits/stdc++.h>
using namespace std ;

const int max_n = 104 ;
int M, N, K ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;
const int dy[] = { -1,0,1,0};
const int dx[] = { 0,1,0,-1};
vector<int> area ;

int dfs( int y , int x ) {

    visited[y][x] = 1 ;

    int ret = 1 ;
    for( int i = 0 ; i < 4 ; i++ ) {
        int ny = y + dy[i] ;
        int nx = x + dx[i] ;

        if( ny < 0 || nx < 0 || ny >= M || nx >= N ) continue ;
        if( a[ny][nx] == 1 ) continue ;
        if( visited[ny][nx] ) continue ;

       ret += dfs( ny, nx ) ;
    }
    return ret ;
}

int main() {

    cin >> M >> N >> K ;
    for( int i = 0 ; i < K ; i++ ) {
        int x1, y1, x2, y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;

        int retx1 = y1 ; int rety1 = x1 ;
        int retx2 = y2-1 ; int rety2 = x2-1 ;
        
        for( int i = retx1 ; i <= retx2 ; i++ ) {
            for( int j = rety1 ; j <= rety2 ; j++ ) {
                a[i][j] = 1 ;
            }
        }
    }

    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            if( !a[i][j] && !visited[i][j] ) {
                area.push_back( dfs( i, j ) ) ;
            }
        }
    }

    sort( area.begin(), area.end() ) ;
    cout << area.size() << "\n" ;
    for( int each : area )
        cout << each << " " ;
    cout << "\n" ;
    return 0 ;
}