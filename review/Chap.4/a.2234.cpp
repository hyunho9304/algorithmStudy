#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M ;
int a[max_n][max_n];
int visited[max_n][max_n];

const int dy[] = { -1, 0, 1, 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;
int wall[] = { 2, 4, 8, 1 } ;

int cntRoom ;
vector<int> roomCntList ;
int maxCntRoom ;
int maxBreak ;


int dfs( int y, int x, int roomNum) {

    visited[y][x] = roomNum ;
    int cnt = 1 ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny <= 0 || nx <= 0 || ny > M || nx > N ) continue ;
        if( a[y][x] & wall[dir] ) continue ;
        if( visited[ny][nx] != -1 ) continue ;

        visited[ny][nx] = roomNum ;
        cnt += dfs( ny, nx, roomNum ) ;
    }

    return cnt ;
}

int main() {

    cin >> N >> M ;
    for( int i = 1 ; i <= M ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    fill( &visited[0][0] , &visited[0][0] + max_n * max_n , -1 ) ;

    for( int i = 1 ; i <= M ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            
            if( visited[i][j] == -1 ) {
                roomCntList.push_back( dfs(i, j, cntRoom ) ) ;
                cntRoom++ ;           
            }
        }
    }

    maxCntRoom = roomCntList.empty() ? 0 : *max_element( roomCntList.begin(), roomCntList.end() ) ;

    for( int i = 1 ; i <= M ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {

            for( int dir = 0 ; dir < 4 ; dir++ ) {

                int ny = i + dy[dir] ;
                int nx = j + dx[dir] ;

                if( ny <= 0 || nx <= 0 || ny > M || nx > N ) continue ;
                if( !( a[i][j] & wall[dir] ) ) continue ;

                int c1 = visited[i][j] ;
                int c2 = visited[ny][nx] ;

                if( c1 == c2 ) continue ;

                maxBreak = max( maxBreak , roomCntList[c1] + roomCntList[c2] ) ;
            }

        }
    }

    cout << cntRoom << "\n" ;
    cout << maxCntRoom << "\n" ;
    cout << maxBreak << "\n" ;

    return 0 ;
    
}