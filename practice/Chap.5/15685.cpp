#include<bits/stdc++.h>
using namespace std ;

int N ;
int a[104][104] ;
int x,y,d,g ;

vector<int> way ;

const int dy[] = {0,-1,0,1};
const int dx[] = {1,0,-1,0};

int ret ;


void func(int d, int g, int current, vector<int> before ) {

    if( g < current ) return ;

    if( current == 0 ) {
        way.push_back( d ) ;
        before.push_back(d) ;
        func( d, g, current + 1, before ) ;
    } else {
        
        vector<int> next = before ;
        for( int i = before.size() - 1 ; i >= 0 ; i-- ) {
            next.push_back( ( before[i] + 1 ) % 4 ) ;
        }
        way = next ;
        func( d, g, current + 1 , next ) ;
    }
}

void go( int r , int c ) {

    int y = r ;
    int x = c ;
    
    a[y][x] = 1 ;

    for( int i = 0 ; i < way.size() ; i++ ) {

        int ny = y + dy[way[i]] ;
        int nx = x + dx[way[i]] ;

        a[ny][nx] = 1 ;

        y = ny ;
        x = nx ; 
    }
}

void counting() {

    for( int i = 0 ; i < 103 ; i++ ) {
        for( int j = 0 ; j < 103 ; j++ ) {

            if( a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1] ) ret++ ;
        }
    }
}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> x >> y >> d >> g ;
        
        vector<int> before ;
        func(d, g, 0 , before) ;
        go( y, x ) ;
        way.clear();
    }
    
    counting() ;

    cout << ret << "\n";

    return 0 ;
    
}