#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N, M, K ;
int a[max_n][max_n] ;
int origin[max_n][max_n] ;

int r, c, s ;

const int dy[] = {0,1,0, -1};
const int dx[] = {1,0,-1, 0};

struct Op { int r, c, s ; } ;
vector<Op> ops ;

int ret = 987654321 ;

void func( int sy, int sx, int ey, int ex ) {

    int prev = a[sy][sx];
    vector<pair<int,int>> tmpV;

    int y = sy ;
    int x = sx ;
    int way = 0 ;


    while( true ) {

        int ny = y + dy[way] ;
        int nx = x + dx[way] ;


        if( ny < sy || nx < sx || ny > ey || nx > ex ) {
            way = (way + 1) % 4; 
            ny = y + dy[way] ;
            nx = x + dx[way] ;
        }

        if( ny == sy && nx == sx ) {
            tmpV.push_back( {ny,nx}) ;
            break ;
        }

        y = ny ;
        x = nx ;

        tmpV.push_back( { ny, nx }) ;
    }
    

    for( int i = tmpV.size() - 1 ; i > 0 ; i-- ) {
        a[tmpV[i].first][tmpV[i].second] = a[tmpV[i-1].first][tmpV[i-1].second] ;
    }

    a[tmpV[0].first][tmpV[0].second] = prev ;
    
}

int main() {

    cin >> N >> M >> K ;

    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= M ; j++ ) {
            cin >> a[i][j] ;
            origin[i][j] = a[i][j];   // 입력을 origin에 복사
        }
    }

    

    // 연산 입력
    for( int i = 0 ; i < K ; i++ ) {
        cin >> r >> c >> s ;
        ops.push_back( {r,c,s} ) ;
    }

    // 인덱스 순열 준비(정렬 필수)
    vector<int> idx(K);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end());

    do {
        memcpy( a, origin, sizeof(origin) );

        for( int t = 0 ; t < K ; t++ ) {
            auto [rr,cc,ss] = ops[idx[t]] ;

            int y1 = rr - ss, x1 = cc - ss ;
            int y2 = rr + ss, x2 = cc + ss ;

            while( y1 < y2 && x1 < x2 ) {
                func( y1++, x1++, y2--, x2-- ) ;
            }
        }

        for( int i = 1 ; i <= N ; i++ ) {
            int sum = 0 ;
            for( int j = 1 ; j <= M ; j++ ) sum += a[i][j] ;
            ret = min( ret, sum ) ;
        }

    } while( next_permutation(idx.begin(), idx.end()) );

    cout << ret << "\n" ;
    return 0 ;
}