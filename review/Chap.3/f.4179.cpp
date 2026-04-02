#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;

int R, C ; string str ;
int a[max_n][max_n] ;
int fireVisited[max_n][max_n];
int personVisited[max_n][max_n] ;

queue<pair<int,int>> fireQ ;
queue<pair<int,int>> personQ ;

const int dy[] = { -1, 0, 1, 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;

int sy, sx ;
int ret ;

void bfsFire() {

    int y, x ;
    while( !fireQ.empty() ) {

        tie( y, x ) = fireQ.front() ; fireQ.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {

            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
            if( a[ny][nx] == '#' ) continue ;
            if( fireVisited[ny][nx] ) continue ;

            fireVisited[ny][nx] = fireVisited[y][x] + 1 ;
            fireQ.push( {ny,nx} ) ;
        }
    }
}

void bfsPerson( int y, int x ) {

    personVisited[y][x] = 1 ;
    personQ.push( {y, x} ) ;

    while( !personQ.empty() ) {

        tie( y, x ) = personQ.front() ; personQ.pop() ;

        if( y == 0 || x == 0 || y == R - 1 || x == C - 1 ) {
            ret = personVisited[y][x] ;
            break ;
        }

        for( int dir = 0 ; dir < 4 ; dir++ ) {

            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
            if( a[ny][nx] == '#' ) continue ;
            if( personVisited[ny][nx] ) continue ;
            if( fireVisited[ny][nx] != 0 && fireVisited[ny][nx] <= personVisited[y][x] + 1 ) continue ;

            personVisited[ny][nx] = personVisited[y][x] + 1 ;
            personQ.push( {ny, nx} ) ;
        }
    }
}

int main() {

    cin >> R >> C ;
    for( int i = 0 ; i < R ; i++ ) {
        cin >> str ;
        for( int j = 0 ; j < C ; j++ ) {
            a[i][j] = str[j] ;

            if( a[i][j] == 'J' ) {
                sy = i ;
                sx = j ;
            }

            if( a[i][j] == 'F' ) {
                fireVisited[i][j] = 1 ;
                fireQ.push( {i,j} ) ;
            }
        }
    }

    bfsFire() ;
    bfsPerson( sy, sx ) ;

    if( ret != 0 ) cout << ret << "\n" ;
    else cout << "IMPOSSIBLE" << "\n" ;

    return 0 ;
}