#include<bits/stdc++.h>
using namespace std ;

const int max_n = 14 ;

int N, M, K ;
int ground[max_n][max_n] ;
int base[max_n][max_n] ;
int y , x , z ;

struct Tree {
    int y;
    int x;
    int z;

    bool operator < ( const Tree & other ) const {
        return z < other.z ;
    }
};

vector<Tree> tree ;
vector<Tree> die ;


const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 } ;

void spring() {

    sort( tree.begin(), tree.end() ) ;

    vector<Tree> alive ;
    for( int i = 0 ; i < (int)tree.size() ; i++ ) {

        int y = tree[i].y ;
        int x = tree[i].x ;
        int z = tree[i].z ;

        if( ground[y][x] >= z ) {
            ground[y][x] -= z ;
            alive.push_back( { y, x, z + 1} ) ;
        } else {
            die.push_back( { y, x, z} ) ;
        }
    }

    tree.swap( alive ) ;
}

void summer() {

    for( int i = 0 ; i < (int)die.size() ; i++ ) {

        int y = die[i].y;
        int x = die[i].x ;
        int age = die[i].z ;
        
        ground[y][x] += ( age / 2 ) ;
    }

    die.clear() ;

}

void fall() {

    int tmpSize = (int)tree.size() ;

    for( int i = 0 ; i < tmpSize ; i++ ) {

        if( tree[i].z % 5 == 0 ) {

            int y = tree[i].y ;
            int x = tree[i].x ;

            for( int dir = 0 ; dir < 8 ; dir++ ) {

                int ny = y + dy[dir] ;
                int nx = x + dx[dir] ;

                if( ny < 1 || nx < 1 || ny > N || nx > N ) continue ;

                tree.push_back( { ny, nx, 1 } ) ;
            }
        }
    }
}

void winter() {

    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {

            ground[i][j] += base[i][j] ;
        }
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
 
    cin >> N >> M >> K ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> base[i][j] ;
        }
    }

    for( int i = 0 ; i < M ; i++ ) {
        cin >> y >> x >> z ;
        tree.push_back( { y, x, z} ) ;
    }

    fill( &ground[0][0] , &ground[0][0] + max_n * max_n , 5 ) ;

    while( K > 0 ) {

        spring() ;
        summer() ;
        fall() ;
        winter() ;

        K-- ;
    }

    cout << (int)tree.size() << "\n" ;

    return 0 ;

}

