#include<bits/stdc++.h>
using namespace std ;

const int max_n = 14 ;

int N ;
int a[max_n][max_n];
int visited[max_n][max_n] ;

const int dy[] = { -1, 0 , 1, 0 } ;
const int dx[] = { 0, 1, 0, -1 } ;

int ret = 987654321 ;

bool check( int y, int x ) {

    if( visited[y][x] ) return false ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) return false ;
        if( visited[ny][nx] ) return false ;

    }

    return true ;
}

int getGround( int y , int x ) {

    int sum = 0 ;
    visited[y][x] = 1 ;
    sum += a[y][x] ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        visited[ny][nx] = 1 ;
        sum += a[ny][nx] ;
    }

    return sum ;
}

void eraseGround( int y, int x ) {

    visited[y][x] = 0 ;
    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        visited[ny][nx] = 0 ;
    }
}

void go( int cntFlower, int totalMoney ) {

    if( cntFlower == 3 ) {
        ret = min( ret, totalMoney ) ;
        return ;
    }

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {

            if( check( i,j ) ) {
                go( cntFlower + 1 , totalMoney + getGround(i,j) ) ;
                eraseGround( i, j ) ;
                
            }
        }
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    go(0, 0 ) ;
    
    cout << ret << "\n" ;
    return 0 ;
}