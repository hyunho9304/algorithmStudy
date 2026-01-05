//  BFS
#include<bits/stdc++.h>
using namespace std ;

const int maxN= 104;

int N, M ;
int y, x ;

int a[maxN][maxN] ;
int visited[maxN][maxN] ;

const int dy[] = {-1, 0, 1, 0} ;
const int dx[] = {0, 1, 0, -1} ;

int main() {

    cin >> N >> M ;
    for (int i = 1; i <= N; i++) {
        string row;
        cin >> row;                   // 한 줄 문자열로 입력
        for (int j = 1; j <= M; j++) {
            a[i][j] = row[j-1] - '0'; // '0'/'1'을 정수로 변환
        }
    }

    queue<pair<int,int>> q ;
    visited[1][1] = 1 ;
    q.push( {1,1} ) ;

    while( q.size() ) {
        tie( y, x ) = q.front(); q.pop() ;

        for( int i = 0 ; i < 4 ; i++ ) {
            int ny = y + dy[i] ;
            int nx = x + dx[i] ;

            if( ny < 0 || nx < 0 || ny > N|| nx > M ) continue ;
            if( a[ny][nx] == 0 ) continue ;
            if( visited[ny][nx] ) continue ;

            visited[ny][nx] = visited[y][x] + 1 ;
            q.push( {ny, nx} ) ;
        }
    }

    cout << visited[N][M] << "\n" ;

    return 0 ;
}