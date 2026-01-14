#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;
int R, C;
int a[max_n][max_n];
int visitedFire[max_n][max_n] ;
int visitedPerson[max_n][max_n] ;

int sy, sx ;
int x, y;
queue<pair<int,int>> qFire ;
queue<pair<int,int>> qPerson ;

int ret ;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfsFire() {

    while( qFire.size() ) {
        tie( y, x) = qFire.front() ; qFire.pop() ;

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir];
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
            if( a[ny][nx] == '#') continue;
            if( visitedFire[ny][nx]) continue ;

            visitedFire[ny][nx] = visitedFire[y][x] + 1 ;
            qFire.push( {ny,nx}) ;
        }
    }
}

void bfsPerson( int y , int x ) {

    visitedPerson[y][x] = 1 ;
    qPerson.push( {y,x}) ;

    while( qPerson.size() ) {

        tie(y,x) = qPerson.front() ; qPerson.pop();

        if(y == R - 1 || x == C - 1 || x == 0 || y == 0){
            ret = visitedPerson[y][x];
            break;
		}

        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir];
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
            if( a[ny][nx] == '#' ) continue ;
            if( visitedPerson[ny][nx] ) continue ;
            if( visitedFire[ny][nx] != 0 && visitedFire[ny][nx] <= visitedPerson[y][x] + 1) continue;

            visitedPerson[ny][nx] = visitedPerson[y][x] + 1;
            qPerson.push({ny, nx});
        }
    }
}

int main() {

    cin >> R >> C ;
    for( int i = 0 ; i < R ; i++ ) {
        string s ;
        cin >> s;
        for( int j = 0 ; j < s.size() ; j++ ) {
            a[i][j] = s[j] ;

            if( s[j] == 'F') {
                visitedFire[i][j] = 1 ;
                qFire.push( { i, j} ) ;
            }
            if( s[j] == 'J') {
                sy = i ; sx = j ;
            }
        }
    }

    bfsFire() ;
    bfsPerson(sy,sx);

    if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
    
    return 0;

}