//  인접행렬
//  tmp이용해서 한번에 하는거

#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int R, C, T ;
int a[max_n][max_n] ;
int tmp[max_n][max_n];
queue<pair<int,int>> mise;
vector<pair<int,int>> v1 ;
vector<pair<int,int>> v2 ;

int y, x ;

const int dy[] = { 0,-1,0,1} ;
const int dx[] = { 1,0,-1,0} ;

const int dy2[] = {0, 1, 0, -1};
const int dx2[] = {1, 0, -1, 0};

int ret ;

void miseFunc() {

    fill(&tmp[0][0], &tmp[0][0] + 54 * 54 , 0) ;
    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0 ; j < C ; j++ ) {

            if( a[i][j] != -1 && a[i][j] != 0 ) {
                mise.push( {i,j}) ;
            }
        }
    }

    while( mise.size() ) {

        tie( y, x ) = mise.front(); mise.pop() ;

        int cnt = 0 ;
        int some = 0 ;
        for( int dir = 0 ; dir < 4 ; dir++ ) {
            int ny = y + dy[dir];
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
            if( a[ny][nx] == -1 ) continue ;
            
            some = a[y][x] / 5 ;
            tmp[ny][nx] += some ;
            cnt++ ;
        }
        a[y][x] -= ( some * cnt ) ;
    }

    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0 ; j < C ; j++ ) {
            a[i][j] += tmp[i][j] ;
        }
    }

}

vector<pair<int,int>> func( int sy, int sx, const int dy[], const int dx[] ) {
    
    vector<pair<int,int>> tmpV ;
    
    int y = sy ;
    int x = sx ;
    int cnt = 0 ;
    while( true ) {

        int ny = y + dy[cnt] ;
        int nx = x + dx[cnt] ;

        if( ny < 0 || nx < 0 || ny >= R || nx >= C ) {
            cnt++ ;
            ny = y + dy[cnt] ;
            nx = x + dx[cnt] ;
        }

        if( ny == sy && nx == sx ) break ;

        y = ny ;
        x = nx ;
        tmpV.push_back( {ny,nx} ) ;
    }
    return tmpV ;
}

void wind( vector<pair<int,int>> v) {

    for( int i = v.size() -1 ; i > 0 ; i-- ) {
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second] ;
    }
    a[v[0].first][v[0].second] = 0 ;
}

int main() {

    cin >> R >> C >> T ;
    int flag = 0 ;
    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0 ; j < C ; j++ ) {
            cin >> a[i][j] ;

            if( flag == 0 && a[i][j] == -1) {
                v1 = func( i, j , dy , dx ) ;
                flag = 1 ;
            }

            if( flag == 1 && a[i][j] == -1) {
                v2 = func( i, j, dy2, dx2 ) ;
            }
        }
    }

    while( T > 0 ) {
        miseFunc( ) ;
        wind(v1);
        wind(v2) ;

        T-- ;
    }


    for( int i = 0 ; i < R ; i++ ) {
        for( int j = 0 ; j < C ; j++ ) {
            if( a[i][j] != -1 ) ret += a[i][j] ;
        }
    }

    cout << ret << "\n"; 
    return 0 ;

}