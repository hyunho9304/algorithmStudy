#include<bits/stdc++.h>
using namespace std ;

const int max_n = 10 ;

int K ;
char a[max_n] ;
int visited[max_n] ;

vector<string> ret ;

bool confirm( char c1, char c2, char op ) {

    if( op == '<' ) return c1 < c2 ;

    if( op == '>' ) return c1 > c2 ;

    return false ;
}

void go( int idx, string str ) {

    if( idx == K + 1 ) {
        ret.push_back( str ) ;
        return ;
    }

    for( int i = 0 ; i <= 9 ; i++ ) {

        if( visited[i] ) continue ;
        if( idx == 0 || confirm( str[idx-1], i + '0' , a[idx - 1] ) ) {
            visited[i] = 1 ;
            go( idx + 1 , str + to_string(i ) ) ;
            visited[i] = 0 ;            
        }
    }
    return ;
    
}

int main() {

    cin >> K ;
    for( int i = 0 ; i < K ; i++ ) {
        cin >> a[i] ;
    }

    
    go( 0, "" ) ;
    sort( ret.begin(), ret.end() );
    cout << ret[ret.size() - 1 ] << "\n" ;
    cout << ret[0] << "\n" ;
    
    return 0 ;
}