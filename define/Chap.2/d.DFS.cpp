//  g++ -std=c++14 -Wall ./d.DFS.cpp -o ./test.out
// #include<bits/stdc++.h>
// using namespace std ;

// const int N = 6;
// vector<int> adj[N];
// int visited[N] ;

// void dfs(int u ) {

//     visited[u] = 1;
//     cout << u << "\n" ;

//     for( int v : adj[u] ) {
//         if( visited[v] == false ) dfs( v ) ;
//     }
//     cout << u << " 로 부터 시작된 함수가 종료 되었습니다." << "\n" ;
//     return ;
// }

// int main() {

//     adj[1].push_back(2);
//     adj[1].push_back(3);
//     adj[2].push_back(4);
//     adj[2].push_back(5);
//     adj[4].push_back(2);

//     dfs(1);
//     return 0;
// }

//  DFS는 연결된 컴포넌트 이다.

#include<bits/stdc++.h>
using namespace std;

int N, M ;
int cnt ;
int a[104][104];
bool visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs( int y , int x ) {
    
    visited[y][x] = 1 ;

    for( int i = 0 ; i < 4 ; i++ ) {
        int ny = y + dy[i] ;
        int nx = x + dx[i] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue;
        if( a[ny][nx] == 0 ) continue ;
        if( visited[ny][nx] ) continue ;

        dfs( ny, nx );
    }
    return ;
}
int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            if( a[i][j] && visited[i][j] == false ) {
                cnt++ ;
                dfs(i,j);
            }
        }
    }

    cout << cnt << "\n" ;
    return 0 ;

}