//  구현
//  dy,dx 개념 이용
//  sort 중복 제거 스킬
//  백트래킹 ( 쓸모없는 반복 )

#include<bits/stdc++.h>
using namespace std ;

struct Shark {
    int r ;
    int c ;
    int s ;
    int d ;
    int z ;
};

int R , C, M ;
vector<Shark> v ;

const int dy[] = { -1, 1 , 0 , 0 } ;
const int dx[] = { 0, 0, 1, -1 } ;

int ret ;

void man( int column ) {

    int row = INT_MAX ;
    int idx = -1 ;
    for( int i = 0 ; i < v.size() ; i++ ) {
        if( v[i].c == column) {
            
            if( row > v[i].r) {
                row = v[i].r ;
                idx = i ;
            }
        }
    }

    if( row != INT_MAX ) {
        ret += v[idx].z;
        v.erase( v.begin() + idx ) ;
    }
}

void moveShark() {

    for( int i = 0 ; i < v.size() ; i++ ) {

        Shark tmp = v[i] ;

        // 왕복 주기로 실제 이동 횟수 줄이기
        int period = (tmp.d <= 2 ? 2 * (R - 1) : 2 * (C - 1));
        int steps  = (period > 0 ? tmp.s % period : 0);

        for( int j = 0 ; j < steps ; j++ ) {

            int ny = tmp.r + dy[tmp.d - 1 ] ;
            int nx = tmp.c + dx[tmp.d - 1 ] ;

            if( ny <= 0 || nx <= 0 || ny > R || nx > C ) {
                
                if( tmp.d == 1 ) tmp.d = 2 ;
                else if( tmp.d == 2 ) tmp.d = 1 ;
                else if( tmp.d == 3 ) tmp.d = 4 ;
                else if( tmp.d == 4 ) tmp.d = 3 ;

                ny = tmp.r + dy[tmp.d - 1 ] ;
                nx = tmp.c + dx[tmp.d - 1 ] ;
            }
            tmp.r = ny ;
            tmp.c = nx ;
        }
        v[i] = tmp ;
    }

    sort(v.begin(), v.end(), [](const Shark& a, const Shark& b){
        if (a.r != b.r) return a.r < b.r;
        if (a.c != b.c) return a.c < b.c;
        return a.z > b.z; // 같은 칸이면 큰 z 우선
    });
    vector<Shark> nv;
    for (int i = 0; i < (int)v.size(); i++) {

        if (i == 0 || v[i].r != v[i-1].r || v[i].c != v[i-1].c) {
            nv.push_back(v[i]); // 같은 칸의 최대 z만 유지
        }
    }
    v.swap(nv);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> R >> C >> M ;
    for( int i = 0 ; i < M ; i++ ) {
        Shark tmp ;
        cin >> tmp.r >> tmp.c >> tmp.s >> tmp.d >> tmp.z ;
        v.push_back( tmp ) ;
    }

    for( int i = 1 ; i <= C ; i++ ) {

        man(i) ;
        moveShark() ;
    }

    cout << ret << "\n" ;
    return 0 ;
}