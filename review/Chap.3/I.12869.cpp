#include<bits/stdc++.h>
using namespace std ;

const int max_n = 65 ;

int N ;
int a[3] ;
int visited[max_n][max_n][max_n] ;
vector<vector<int>> perms ;

struct A {
    int x ;
    int y ;
    int z ;
} ;

void go( int x, int y , int z ) {

    queue<A> q ;
    q.push( { x , y , z } ) ;

    visited[x][y][z] = 1 ;

    while( !q.empty() ) {

        A tmp = q.front() ; q.pop() ;
        int x = tmp.x ;
        int y = tmp.y ;
        int z = tmp.z ;

        if( visited[0][0][0] ) break ;

        for( vector<int> v : perms ) {
            int nx = max( 0, x - v[0] ) ;
            int ny = max( 0, y - v[1] ) ;
            int nz = max( 0, z - v[2] ) ; 

            if( visited[nx][ny][nz] ) continue ;

            visited[nx][ny][nz] = visited[x][y][z] + 1 ;
            q.push( { nx, ny, nz } ) ;
        }
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i] ;
    }

    vector<int> v = { 1, 3, 9 } ;

    do{

        perms.push_back( v ) ;

    } while( next_permutation( v.begin(), v.end() ) ) ;

    go( a[0], a[1], a[2] ) ;

    cout << visited[0][0][0] - 1 << "\n" ;
    return 0 ;
}