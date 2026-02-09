#include<bits/stdc++.h>
using namespace std ;

vector<int> adj[32] ;
int v[104] ;
int a[14] ;
int mal[4] ;

void add( int here, int there ) {
    adj[here].push_back( there ) ;
}
void setMap() {

    for( int i = 0 ; i <= 19 ; i++ ) {
        add( i, i+1 ) ;
        v[i+1] = ( i+1) * 2 ;
    }
    add( 5, 21 ) ; add( 21, 22 ) ; add( 22, 23 ) ; add( 23, 29 ) ;
    add( 10,24 ) ; add( 24, 25 ) ; add( 25, 29 ) ;
    add( 15, 26 ) ; add( 26, 27 ) ; add( 27, 28 ) ; add( 28, 29 ) ;
    add( 29, 30 ) ; add( 30, 31 ) ; add( 31, 20 ) ; add ( 20, 100 ) ;

    v[21] = 13 ; v[22] = 16 ; v[23] = 19 ;
    v[24] = 22 ; v[25] = 24 ;
    v[26] = 28 ; v[27] = 27 ; v[28] = 26 ;
    v[29] = 25 ; v[30] = 30 ; v[31] = 35 ;
}

int move( int here, int cnt ) {

    if( here == 100 ) return 100 ;

    if( adj[here].size() >= 2 ) {
        here = adj[here][1]; cnt-- ;
    }

    if( cnt ) {

        queue<int> q ;
        q.push( here ) ;

        int there ;

        while( q.size() ) {

            if( cnt == 0 ) break ;

            int x = q.front() ; q.pop() ;
            there = adj[x][0] ;

            if( there == 100 ) break ;

            q.push( there ) ;
            cnt-- ;
        }
        
        return there ;

    } else {
        return here ;
    }
}

bool isMal( int to_idx, int idx ) {

    if( to_idx == 100 ) return true ;  //  100은 겹쳐도 상관없어서 이동

    for( int i = 0 ; i < 4 ; i++ ) {

        if( i == idx ) continue ;   //  자기 자신확인 X
        
        if( mal[i] == to_idx ) return false ;    // 겹쳐서 이동 불가능
    }

    return true ;  //  고고
}

int go( int here ) {

    if( here == 10 ) return 0 ;

    int ret = 0 ;
    for( int i = 0 ; i < 4 ; i++ ) {
        int current_idx = mal[i] ;
        int to_idx = move( current_idx, a[here] ) ;

        if( !isMal( to_idx, i ) ) continue ;

        mal[i] = to_idx ;
        ret = max( ret, go( here + 1 ) + v[to_idx] ) ;

        mal[i] = current_idx; 
    }

    return ret ;
}

int main() {

    setMap() ;

    for( int i = 0 ; i < 10 ; i++ ) {
        cin >> a[i] ;
    }

    cout << go( 0 ) << "\n" ;
    return 0 ;
}