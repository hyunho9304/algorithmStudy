#include<bits/stdc++.h>
using namespace std ;

const int max_n = 10 ;

int N ;
int a[max_n][max_n] ;
int visited[max_n][max_n];

const int dy[] = { -1,0,1,0 } ;
const int dx[] = { 0,1,0,-1 } ;

int ret = 987654321;

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

int setFlower( int y , int x ) {

    visited[y][x] = 1 ;

    int sum = a[y][x] ;
    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir];
        int nx = x + dx[dir] ;

        visited[ny][nx] = 1 ;
        sum += a[ny][nx] ;
    }

    return sum ;
}

void eraseFlower( int y , int x ) {

    visited[y][x] = 0 ;
    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        visited[ny][nx] = 0 ;
    }
}

void flower( int cntFlower, int total ) {

    if( cntFlower == 3 ) {
        ret = min( ret, total ) ;
        return ;
    }

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {

            if( check( i, j) ) {
                flower( cntFlower+1, total + setFlower( i, j ) ) ;
                eraseFlower(i, j ) ;
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

    flower(0,0);

    cout << ret << "\n" ;
}