#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;
int compId[max_n][max_n] ;


const int dy[] = {-1, 0, 1, 0};   // 북, 동, 남, 서
const int dx[] = { 0, 1, 0,-1};
const int wallBit[] = {2, 4, 8, 1}; // 북(2), 동(4), 남(8), 서(1)

int cnt ;
vector<int> v ;
int maxBreak ;

int dfs( int y , int x, int cid ) {

    visited[y][x] = 1 ;
    int sz = 1 ;
    compId[y][x] = cid ;


    for( int dir = 0 ; dir < 4 ; dir++ ) {
        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= M || nx >= N ) continue ;
        if (a[y][x] & wallBit[dir]) continue;  // 벽이면 못 감
        if( visited[ny][nx] ) continue ;

        sz += dfs( ny, nx, cid ) ;
    }
    return sz ;

}

int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    int cid = 0 ;
    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            if( a[i][j] && visited[i][j] == 0 ) {
                cnt++ ;
                int size = dfs( i, j, cid ) ;
                v.push_back( size ) ;
                cid++ ;
            }
        }
    }

    // 현재 최대 컴포넌트 크기
    int maxCurrent = v.empty() ? 0 : *max_element(v.begin(), v.end());

    int maxBreak = maxCurrent;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            for (int dir = 0; dir < 4; dir++) {
                
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
                if (!(a[i][j] & wallBit[dir])) continue;     // 벽 있는 방향만
                
                int c1 = compId[i][j];
                int c2 = compId[ny][nx];

                if (c1 == c2) continue;             // 같은 컴포넌트면 이미 연결됨

                maxBreak = max(maxBreak, v[c1] + v[c2]);
            }
        }
    }

    cout << cnt << "\n" ;
    cout << maxCurrent << "\n" ;
    cout << maxBreak << "\n" ;


    return 0 ;

}