#include<bits/stdc++.h>
using namespace std ;

#define time tt

const int max_n = 104 ;

int N, K, L ;
int a[max_n][max_n] ;
int visited[max_n][max_n] ;

int y, x ;
int t ;
char c ;

deque<pair<int,int>> dq ;
vector<pair<int,int>>  _time ;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int time ;


int main() {

    cin >> N >> K ;

    for( int i = 0 ; i < K ; i++ ) {
        cin >> y >> x ;
        a[--y][--x] = 1 ;
    }

    cin >> L ;

    for( int i = 0 ; i < L ; i++ ) {
        cin >> t >> c ;

        if( c == 'D' ) _time.push_back( {t,1}) ;
        else _time.push_back( {t,3}) ;

    }

    dq.push_back( { 0,0}) ;

    int dir = 1 ;
    int idx = 0 ;
    while( dq.size() ) {

        time++ ;
        tie( y, x ) = dq.front() ;

        int ny = y + dy[dir] ;
        int nx = x + dx[dir] ;

        if( ny < 0 || nx < 0 || ny >= N || nx >= N ) break ;
        if( visited[ny][nx] ) break;

        if( a[ny][nx] ) {
            a[ny][nx] = 0 ;
        } else {
            visited[dq.back().first][dq.back().second] = 0 ;
            dq.pop_back() ;
        }


        visited[ny][nx] = 1 ;
        dq.push_front({ny,nx}) ;

        if( time == _time[idx].first ) {
            dir = ( dir + _time[idx].second ) % 4 ;
            idx++ ;
        }
        
    }

    cout << time << "\n";
    return 0 ;

}