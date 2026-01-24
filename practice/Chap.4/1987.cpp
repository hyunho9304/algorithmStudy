// #include<bits/stdc++.h>
// using namespace std ;

// const int max_n = 24 ;

// int R, C ;
// char a[max_n][max_n] ;
// int visited[30] ;

// const int dy[] = { -1, 0 , 1 , 0 } ;
// const int dx[] = { 0, 1, 0 , -1 } ;

// int ret = 0 ;

// void go( int y , int x , int cnt ) {

//     ret = max( ret, cnt ) ;

//     for( int dir = 0 ; dir < 4 ; dir++ ) {

//         int ny = y + dy[dir] ;
//         int nx = x + dx[dir] ;

//         if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;
//         if( visited[ a[ny][nx] - 'A' ] ) continue ;

//         visited[ a[ny][nx] - 'A' ] = 1 ;
//         go( ny, nx, cnt + 1 ) ;
//         visited[ a[ny][nx] - 'A' ] = 0 ;
//     }
//     return ;
// }

// int main() {

//     cin >> R >> C ;

//     for( int i = 0 ; i < R ; i++ ) {
//         string s ;
//         cin >> s ;
//         for( int j = 0 ; j < C ; j++ ) {
//             a[i][j] = s[j] ;
//         }
//     }

//     visited[ a[0][0] - 'A' ] = 1 ;
//     go( 0, 0, 1 ) ;

//     cout << ret << "\n" ;
// }


//  비트마스킹 통한 풀이
#include<bits/stdc++.h>
using namespace std ;

const int max_n = 24 ;

int R, C ;
char a[max_n][max_n] ;
int visited[30] ;

const int dy[] = { -1, 0 , 1 , 0 } ;
const int dx[] = { 0, 1, 0 , -1 } ;

int ret ;

void go( int y , int x , int num , int cnt ) {

    ret = max( ret, cnt ) ;

    for( int dir = 0 ; dir < 4 ; dir++ ) {

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= R || nx >= C ) continue ;

        int _next = ( 1 << (int)( a[ny][nx] - 'A' ) );

        if( ( num & _next ) == 0 ) {
            go( ny, nx, num | _next , cnt + 1 ) ;
        }
    }
    return ;
}

int main() {

    cin >> R >> C ;

    for( int i = 0 ; i < R ; i++ ) {
        string s ;
        cin >> s ;
        for( int j = 0 ; j < C ; j++ ) {
            a[i][j] = s[j] ;
        }
    }

    go( 0, 0, 1 << ( int )( a[0][0] - 'A' ), 1 ) ;

    cout << ret << "\n" ;
    return 0 ;
}