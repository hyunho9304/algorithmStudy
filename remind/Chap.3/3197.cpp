#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1501 ;
int R, C ;
char a[max_n][max_n];
bool visitedWater[max_n][max_n] ;
bool visitedSwan[max_n][max_n] ;
queue<pair<int,int>> waterQ , waterTempQ;
queue<pair<int,int>> swanQ, swanTempQ;
string s ;
int y , x, sy, sx ;

const int dy[] = { -1,0,1,0};
const int dx[] = { 0,1,0,-1};
int cnt ;

void Qclear( queue<pair<int,int>> &q) {
    queue<pair<int,int>> emptyQ ;
    swap( q, emptyQ ) ;
}

void waterMelting() {

    while( waterQ.size() ) {
        tie( y, x ) = waterQ.front() ; waterQ.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= max_n || nx >= max_n ) continue ;
            if( visitedWater[ny][nx] ) continue ;

            if( a[ny][nx] == 'X') {
                visitedWater[ny][nx] = 1 ;
                waterTempQ.push( {ny,nx} ) ;
                a[ny][nx] = '.' ;
            }
        }
    }
}

bool moveSwan() {

    while( swanQ.size() ) {
        tie( y, x) = swanQ.front() ; swanQ.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= max_n || nx >= max_n ) continue ;
            if( visitedSwan[ny][nx] ) continue ;

            
            if( a[ny][nx] == '.') {
                visitedSwan[ny][nx] = 1 ;
                swanQ.push( {ny,nx}) ;
            }
            else if( a[ny][nx] == 'X' ) {
                visitedSwan[ny][nx] = 1 ;
                swanTempQ.push( {ny,nx}) ;
            } 
            else if( a[ny][nx] == 'L' ) return true ; 

        }
    }
    return false ;
}

void bfs() {
    swanQ.push({sy,sx}) ;
    visitedSwan[sy][sx] = 1 ;

    while( true ) {

        if( moveSwan() ) break ;

        waterMelting() ;

        swap( swanQ, swanTempQ ) ;
        Qclear( swanTempQ ) ;

        swap( waterQ, waterTempQ ) ;
        Qclear( waterTempQ ) ;

        cnt++ ;
    }
    
}

int main() {

    cin >> R >> C;
    for( int i = 0 ; i < R ; i++ ) {
        cin >> s ;
        for( int j = 0 ; j < C ; j++ ) {

            a[i][j] = s[j] ;

            if( s[j] == 'L') {
                sy = i ;
                sx = j ;
            }
            if(a[i][j] == '.' || a[i][j] == 'L') {
                visitedWater[i][j] = 1;
                waterQ.push({i, j});
            }
            
        }
    }

    bfs() ;

    cout << cnt << "\n" ;
    return 0 ;
}