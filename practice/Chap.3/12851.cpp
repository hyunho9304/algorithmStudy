#include<bits/stdc++.h>
using namespace std ;

const int max_n = 200004 ;
int N, K ;
int visited[max_n] ;
int cnt[max_n];
int ret ;

void bfs() { 
    queue<int> q ;
    visited[N] = 1 ;
    q.push( N ) ;

    cnt[N] = 1 ;

    while( q.size() ) {
        int x = q.front() ; q.pop();
        
        if( x == K ) {
            ret = visited[K] ; break ;
        }

        for( int nx : { x - 1 , x + 1 , 2 * x } ) {

            if( nx < 0 || nx >= max_n ) continue ;

            if( visited[nx] == 0 ) {
                visited[nx] = visited[x] + 1 ;
                cnt[nx] += cnt[x] ;
                q.push( nx ) ;
            } else if( visited[nx] == visited[x] + 1 ) cnt[nx] += cnt[x] ;
        }
    }

    return ;
}

int main() {
    cin >> N >> K ;

    if( N == K ) {
        cout << "0" << "\n" << "1" << "\n" ;
        return 0;
    }

    bfs() ;
    cout << ret - 1 << "\n" ;
    cout << cnt[K] << "\n" ;
    
    return 0 ;
}