#include<bits/stdc++.h>
using namespace std ;

const int max_n = 104 ;

int N, L ;
int a[max_n][max_n];
int b[max_n][max_n] ;

int ret ;

void solve( int tmp[max_n][max_n] ) {

    for( int i = 0 ; i < N ; i++ ) {

        int cnt = 1 ;
        int j ;
        for( j = 0 ; j < N - 1 ; j++ ) {

            if( tmp[i][j] == tmp[i][j+1] ) cnt++ ;
            else if( tmp[i][j] + 1 == tmp[i][j+1] && cnt >= L ) cnt = 1 ;
            else if( tmp[i][j] - 1 == tmp[i][j+1] && cnt >= 0 ) cnt = -L + 1 ;
            else break ;
        }

        if( j == N - 1 && cnt >= 0 ) ret++ ;
    }
}

int main() {

    cin >> N >> L ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
            b[j][i] = a[i][j] ;
        }
    }

    solve(a);
    solve(b) ;

    cout << ret << "\n" ;
    return 0 ;
}