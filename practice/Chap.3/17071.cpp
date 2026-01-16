#include<bits/stdc++.h>
using namespace std ;

const int max_n = 500004;

int N, K ;
int visited[2][max_n] ;
bool flag = false ;
int turn = 1;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   
}

void bfs() {
    
    queue<int> q ;
    visited[0][N] = 1 ;
    q.push( N ) ;

    while( q.size() ) {
        K += turn ;
        if( K >= max_n ) break ;

        if( visited[turn%2][K] ) {
            flag = true ; break ;
        }

        int qsize = q.size() ;

        for( int i = 0 ; i < qsize ; i++ ) {

            int x = q.front() ; q.pop() ;

            for( int nx : { x-1, x+1 , x * 2 } ) {

                if( nx < 0 || nx >= max_n ) continue ;
                if( visited[turn % 2 ][nx] ) continue ;

                visited[turn % 2][nx] = visited[ (turn + 1)%2][x] + 1 ;

                if( nx == K ) {
                    flag = true ; break ;
                }

                q.push( nx ) ;
            }
            if( flag ) break ;
        }

        if( flag ) break ;
        turn++ ;
    }
    return ;
}


int main() {
    
    fastIO();

    cin >> N >> K ;

    if(N == K){
        cout << 0 << "\n"; 
        return 0;
    }

    bfs() ;
    if( flag ) cout << turn << "\n" ;
    else cout << -1 << "\n" ;
    return 0;

}