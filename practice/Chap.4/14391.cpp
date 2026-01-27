#include<bits/stdc++.h>
using namespace std ;

const int max_n = 4;

int N , M ;
int a[max_n][max_n] ;
int ret ;

int main() {
    cin >> N >> M ;
    
    for( int i = 0 ; i < N ; i++ ) {
        string s ;
        cin >> s ;
        for( int j = 0 ; j < M ; j++ ) {
            a[i][j] = s[j] - '0' ;
        }
    }

    for (int s = 0; s < (1 << (N * M)); s++) {
        int sum = 0;

        // 가로 조각(비트 0)
        for (int i = 0; i < N; i++) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                int k = i * M + j;
                if ((s & (1 << k)) == 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        // 세로 조각(비트 1)
        for (int j = 0; j < M; j++) {
            int cur = 0;
            for (int i = 0; i < N; i++) {
                int k = i * M + j;
                if (s & (1 << k)) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ret = max(ret, sum);
    }

    cout << ret << "\n";
    return 0 ;

}