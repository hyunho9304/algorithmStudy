#include<bits/stdc++.h>
using namespace std ;

const int max_n = 100004 ;

int N, K ;
int visited[max_n] ;
int cnt[max_n] ;

void bfs() {

    visited[N] = 1 ;
    cnt[N] = 1 ;
    queue<int> q ;
    q.push( N );

    while( !q.empty() ) {

        int X = q.front() ; q.pop() ;

        for( int nx : { X - 1 , X + 1 , 2 * X}) {

            if( nx < 0 || nx >= max_n ) continue ;

            if( visited[nx] == visited[X] + 1 ) cnt[nx] += cnt[X] ;

            if( visited[nx] == 0 ) {
                visited[nx] = visited[X] + 1;
                cnt[nx] += cnt[X] ;
                q.push( nx ) ;
            }
        }
    }
}

int main() {

    cin >> N >> K ;

    bfs() ;

    cout << visited[K] - 1 << "\n" ;
    cout << cnt[K] << "\n" ;

    return 0 ;
}