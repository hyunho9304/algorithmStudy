#include<bits/stdc++.h>
using namespace std ;

const int maxN = 104 ;

int N, M ;
int sy, sx;
int ey, ex;
int y , x ;

int a[maxN][maxN];
int visited[maxN][maxN] ;
vector<int> adj[maxN];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {

    cin >> N >> M ;
    cin >> sy >> sx ;
    cin >> ey >> ex ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    queue<pair<int,int>> q ;
    visited[sy][sx] = 1 ;
    q.push( {sy,sx}) ;

    while( q.size() ) {
        tie( y, x ) = q.front() ; q.pop();
        
        for( int i = 0 ; i < 4 ; i++ ) {
            int ny = y + dy[i] ;
            int nx = x + dx[i] ;

            if( ny < 0 || nx < 0 || ny >= N || nx >= M ) continue ;
            if( a[ny][nx] == 0 ) continue ;
            if( visited[ny][nx] ) continue ;

            visited[ny][nx] = visited[y][x] + 1 ;
            q.push({ny, nx}) ;
        }
    }

    cout << visited[ey][ex] << "\n" ;

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cout << visited[i][j] << " " ;
        }
        cout << "\n" ;
    }
    return 0 ;
}