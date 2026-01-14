#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N , L , R ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret ;
int sum ;
vector<pair<int,int>> area;

void dfs( int y , int x ) {

    visited[y][x] = 1 ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue ;
        if( visited[ny][nx] ) continue ;
        if( abs( a[ny][nx] - a[y][x] ) < L || abs( a[ny][nx] - a[y][x] ) > R ) continue ;

        sum += a[ny][nx];
        area.push_back({ny,nx});
        dfs( ny, nx ) ;
    }
    return ;
}

int main() {

    cin >> N >> L >> R ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    bool flag = false ;
    while( true ) {

        memset( visited, 0 , sizeof( visited) ) ;

        flag = false ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                if( visited[i][j] == 0 ) {
                    area.clear();
                    sum = a[i][j] ;
                    area.push_back({i,j});
                    dfs( i,j ) ;

                    if( area.size() == 1 ) continue ;
                    for( pair<int,int> p : area ) {
                        a[p.first][p.second] = sum / area.size() ;
                        flag = true ;
                    }

                }
            }
        }

        if( flag ) {
            ret++ ;
        } else {
            break ;
        }
    }

    cout << ret << "\n" ;
    

    return 0;
}
