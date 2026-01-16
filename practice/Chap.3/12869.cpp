#include<bits/stdc++.h>
using namespace std ;

const int max_n = 65 ;

int N ;
int a[3] ;
int visited[max_n][max_n][max_n] ;
vector<vector<int>> perms;

struct A{
    int a, b, c; 
}; 

int solve( int z, int y, int x ) {

    queue<A>q; 
    visited[z][y][x] = 1 ;
    q.push( { z, y, x} );

    while( q.size() ) { 

        z= q.front().a;
        y= q.front().b;
        x= q.front().c;
        q.pop();

        if( visited[0][0][0] ) break ;

        for( vector<int> pp : perms ) {
            int nz = max( 0, z - pp[0] ) ;
            int ny = max( 0, y - pp[1] ) ;
            int nx = max( 0, x - pp[2] ) ;

            if(visited[nz][ny][nx]) continue ;
            
            visited[nz][ny][nx] = visited[z][y][x] + 1 ;
            q.push( { nz, ny, nx} ) ;
        }
    }

    return visited[0][0][0] - 1 ;
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i] ;
    }

    vector<int> v = {1,3,9};
    sort(v.begin(), v.end());
    do {
        perms.push_back(v);
    } while (next_permutation(v.begin(), v.end()));


    cout << solve( a[0], a[1] , a[2] ) << "\n" ;
    return 0 ;
}