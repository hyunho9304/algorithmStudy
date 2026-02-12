#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M, T ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;
int x,d,k ;

const int dy[] = { -1 , 0 , 1 , 0 } ;
const int dx[] = { 0, 1, 0 , -1 } ;

bool flag ;
int cnt ;

int ret ;

vector<int> move( vector<int> tmp, int k ) {

    vector<int> result ;

    for( int i = 0 ; i < tmp.size() ; i++ ) {
        result.push_back( tmp[ (i + k) % M ] ) ;
    }
    
    return result ;
}

void func( int x, int d, int k ) {

    int tmpK = k % M ;
    if( d == 0 ) tmpK = M - ( k % M ) ;

    for( int i = x ; i <= N ; i += x ) {
        
        vector<int> tmp ;
        tmp.clear() ;

        for( int j = 1 ; j <= M ; j++ ) tmp.push_back( a[i][j] ) ;

        tmp = move( tmp, tmpK ) ;
        for( int j = 1 ; j<= M ; j++ ) a[i][j] = tmp[j-1] ;
    }
}

void dfs(int y , int x , int num ) {

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir];
        int nx = x + dx[dir] ;

        if( ny < 1 || ny > N ) continue ;
        
        if( nx < 1 ) nx = M ;
        else if( nx > M ) nx = 1 ;
        
        if( visited[ny][nx] ) continue ;
        if( a[ny][nx] == 0 ) continue ;

        if( a[ny][nx] == num ) {

            flag = true ;
            visited[y][x] = 1 ;
            visited[ny][nx] = 1 ;

            dfs( ny,nx, num ) ;

        }
    }
    return ;
}

int main() {

    cin >> N >> M >> T ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j =1 ; j <= M ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    while( T > 0) {

        flag = false ;
        fill( &visited[0][0], &visited[0][0] + max_n * max_n, 0 ) ;
        cnt = 0 ;
        ret = 0 ;

        cin >> x >> d >> k ;
        func( x, d, k ) ;

        for( int i = 1 ; i <= N ; i++ ) {
            for( int j = 1 ; j <= M ; j++ ) {

                dfs( i, j, a[i][j] ) ;
            }
        }

        for( int i = 1 ; i <= N ; i++ ) {
            for( int j = 1 ; j <= M ; j++ ) {

                if( visited[i][j] == 0 ) {
                    ret += a[i][j] ;

                    if( a[i][j] ) cnt++ ;
                } else a[i][j] = 0 ;
            }
        }

        if( !flag ) {

            if( cnt > 0 ) {

                double avg = (double)ret / (double)cnt ;

                for( int i = 1 ; i <= N ; i++ ) {
                    for( int j =1 ; j <= M ; j++ ) {

                        if( a[i][j] != 0 ) {
                        
                            if( avg < (double)a[i][j] ) a[i][j] -= 1 ;
                            else if( avg > (double)a[i][j]) a[i][j] += 1 ;
                        }
                    }
                }
            }
        }

        T-- ;
    }

    ret = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= M ; j++ ) {
            ret += a[i][j] ;
        }
    }

    cout << ret << "\n" ;

    return 0 ;
}
