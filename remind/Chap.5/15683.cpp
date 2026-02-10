//  DFS
//  한칸한칸이동
//  꼬아진 DFS

#include<bits/stdc++.h>
using namespace std ;

const int max_n = 10 ;

int N, M ;
int a[max_n][max_n] ;
vector<pair<int,int>> cam ;

const int dy[] = { -1, 0, 1, 0 } ;
const int dx[] = { 0, 1, 0 , -1 } ;

int ret = INT_MAX ;

vector<pair<int,int>> go( int here , int dir ) {

    vector<pair<int,int>> tmpA ;

    int y = cam[here].first ;
    int x = cam[here].second ; 

    if( a[y][x] == 1 ) {

        while( true ) {

            int ny = y + dy[dir] ;
            int nx = x + dx[dir] ;

            if( ny < 0 || nx < 0 || ny >= N || nx >= M ) break ;
            if( a[ny][nx] == 6 ) break ;

            if( a[ny][nx] == 0 ) {
                a[ny][nx] = 7 ;
                tmpA.push_back( { ny, nx } ) ;
            }

            y = ny ;
            x = nx ;
        }
    } else if( a[y][x] == 2 ) {

        for( int i = 0 ; i <= 2 ; i += 2 ) {

            int _y = y ;
            int _x = x ;

            while( true ) {

                int ny = _y + dy[ ( dir + i ) % 4 ] ;
                int nx = _x + dx[ ( dir + i ) % 4 ] ;

                if( ny < 0 || nx < 0 || ny >= N || nx >= M ) break ;
                if( a[ny][nx] == 6 ) break ;

                if( a[ny][nx] == 0 ) {
                    a[ny][nx] = 7 ;
                    tmpA.push_back( { ny, nx } ) ;
                }

                _y = ny ;
                _x = nx ;

            }
        }
    } else if( a[y][x] == 3 ) {

        for( int i = 0 ; i < 2 ; i++ ) {
           
            int _y = y ;
            int _x = x ;

            while( true ) {

                int ny = _y + dy[ ( dir + i ) % 4 ] ;
                int nx = _x + dx[ ( dir + i ) % 4 ] ;

                if( ny < 0 || nx < 0 || ny >= N || nx >= M ) break ;
                if( a[ny][nx] == 6 ) break ;

                if( a[ny][nx] == 0 ) {
                    a[ny][nx] = 7 ;
                    tmpA.push_back( { ny, nx } ) ;
                }

                _y = ny ;
                _x = nx ;
            }

        }
    } else if( a[y][x] == 4 ) {

        for( int i = 0 ; i < 3 ; i++ ) {

            int _y = y ;
            int _x = x ;

            while( true ) {

                int ny = _y + dy[ ( dir + i ) % 4 ] ;
                int nx = _x + dx[ ( dir + i ) % 4 ] ;

                if( ny < 0 || nx < 0 || ny >= N || nx >= M ) break ;
                if( a[ny][nx] == 6 ) break ;

                if( a[ny][nx] == 0 ) {
                    a[ny][nx] = 7 ;
                    tmpA.push_back( { ny, nx } ) ;
                }

                _y = ny ;
                _x = nx ;
            }
        }
    } else if( a[y][x] == 5 ) {

        for( int i = 0 ; i < 4 ; i++ ) {

            int _y = y ;
            int _x = x ;
                
            while( true ) {

                int ny = _y + dy[ ( dir + i ) % 4 ] ;
                int nx = _x + dx[ ( dir + i ) % 4 ] ;

                if( ny < 0 || nx < 0 || ny >= N || nx >= M ) break ;
                if( a[ny][nx] == 6 ) break ;

                if( a[ny][nx] == 0 ) {
                    a[ny][nx] = 7 ;
                    tmpA.push_back( { ny, nx } ) ;
                }

                _y = ny ;
                _x = nx ;
            }
        }
    }
    return tmpA ;
}

void dfs( int here ) {

    if( here == cam.size() ) {
       
        int cnt = 0 ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < M ; j++ ) {

                if( a[i][j] == 0 ) cnt++ ;
            }
        }

        ret = min( ret, cnt ) ;

        return ;
    }

    for( int i = 0 ; i < 4 ; i++ ) {
        vector<pair<int,int>> tmpA = go( here, i ) ;
        dfs( here + 1 ) ;

        for( auto p : tmpA ) a[p.first][p.second] = 0 ;
    }

}


int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cin >> a[i][j] ;

            if( a[i][j] != 6 && a[i][j] != 0 ) {
                cam.push_back( { i, j}) ;
            }
        }
    }
    
    dfs( 0 ) ;

    cout << ret << "\n" ;
    return 0 ;
}