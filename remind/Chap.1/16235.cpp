/*
    구현 - 시물레이션
*/
#include<bits/stdc++.h>
using namespace std ;

int N, M, K ;
int ground[104][104] ;
int a[104][104];
int aa,bb,cc;

struct Tree {
    int z;
    int y;
    int x;
    bool operator <(const Tree& other) const {
        return z < other.z; // 나이 기준 정렬
    }
};

vector<Tree> v ;
vector<Tree> die ;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 } ;
const int dx[] = { 0, 1, 1, 1, 0, -1 ,-1, -1 } ;

void spring() {

    sort( v.begin(), v.end() ) ;

    vector<Tree> alive;

    for( int i = 0 ; i < (int)v.size() ; i++ ) {

        if( ground[v[i].y][v[i].x] >= v[i].z ) {

            ground[v[i].y][v[i].x] -= v[i].z ;
            alive.push_back( { v[i].z + 1 , v[i].y , v[i].x } ) ;
        } else {
            die.push_back( v[i] ) ;
        }
    }

    v.swap( alive ) ;
}

void summer() {

    for( int i = 0 ; i < (int)die.size() ; i++ ) {
        ground[die[i].y][die[i].x] += ( die[i].z / 2 ) ;
    }
    
}

void fall() {

    int tmpSize = (int)v.size() ;

    for( int i = 0 ; i < tmpSize ; i++ ) {

        if( v[i].z % 5 == 0 ) {

            int y = v[i].y ;
            int x = v[i].x ;

            for( int dir = 0 ; dir < 8 ; dir++ ) {
                int ny = y + dy[dir] ;
                int nx = x + dx[dir] ;

                if( ny < 1 || nx < 1 || ny > N || nx > N ) continue ;

                v.push_back( { 1, ny, nx} ) ;
            }
        }
    }
}

void winter() {

    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            ground[i][j] += a[i][j] ;
        }
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   

    cin >> N >> M >> K ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    for( int i = 0 ; i < M ; i++ ) {
        cin >> aa >> bb >> cc ;
        v.push_back( { cc, aa, bb }) ;
    }

    fill( &ground[0][0] , &ground[0][0] + 104 * 104 , 5  ) ;

    while( K > 0 ) {

        die.clear() ;

        spring() ;
        summer() ;
        fall() ;
        winter() ;

        K-- ;
    }

    cout << (int)v.size() << "\n" ;
    return 0 ;

}