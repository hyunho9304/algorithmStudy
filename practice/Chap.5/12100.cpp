#include<bits/stdc++.h>
using namespace std ;

const int max_n = 24 ;

int N ;
int a[max_n][max_n] ;

int sum ;

void slide( int board[max_n][max_n] ) {

    int temp[24][24];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;

            if (temp[i][cnt] == 0) {
                temp[i][cnt] = board[i][j];
            } else if (temp[i][cnt] == board[i][j]) {
                temp[i][cnt] *= 2;
                cnt++;
            } else {
                cnt++;
                temp[i][cnt] = board[i][j];
            }
        }
    } 
    memcpy(board, temp, sizeof(temp));
}

void rotate( int board[max_n][max_n] ) {

    int temp[24][24] = { {} } ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            temp[i][j] = board[N-1-j][i] ;
        }
    }
    memcpy( board, temp, sizeof( temp ) );
}

void go( int cnt , int board[max_n][max_n] ) {


    if( cnt == 5 ) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sum = max(sum, board[i][j]);
            }
        }

        return ;
    }

    
    for( int i = 0 ; i < 4 ; i++ ) {
        int tmp[max_n][max_n] ;
        memcpy( tmp, board, sizeof( tmp ) ) ;
        slide( tmp ) ;
        go( cnt + 1, tmp ) ;

        rotate( board ) ;
    }

}

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    go( 0, a ) ;

    cout << sum << "\n" ;
    return 0 ;
}