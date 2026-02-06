//  구현

#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004 ;

int T, K ;
deque<int> adj[max_n];
int num, way ;
vector<pair<int,int>> tmp ;

void turn( vector<int> gg ) {

    for( int i = 1 ; i <= T ; i++ ) {
        
        if( gg[i] == -1 ) {
            adj[i].push_back( adj[i].front() ) ;
            adj[i].pop_front() ;
        } else if( gg[i] == 1 ) {
            adj[i].push_front( adj[i].back() ) ;
            adj[i].pop_back() ;
        } else continue ;
    }
}

void func( int num , int way ) {

    tmp.clear();
    tmp.push_back({0,0}) ;

    for( int i = 1 ; i <= T ; i++ ) {
        int right = adj[i][2];
        int left = adj[i][6] ;
        tmp.push_back( {left, right}) ;
    }

    
    vector<int> gg(T+1, 0) ;
    gg[num] = way ;

    for( int i = num ; i < T ; i++ ) {
        if( tmp[i].second == tmp[i+1].first ) break ;

        gg[i+1] = -gg[i] ;
    }

    for( int i = num -1 ; i >= 1 ; i-- ) {

        if( tmp[i].second == tmp[i+1].first ) break ;

        gg[i] = -gg[i+1];
    }
    
    turn( gg ) ;
}

int counting() {

    int sum = 0 ;
    for( int i = 1 ; i <= T ; i++ ) {
        if( adj[i][0] == 1 ) sum++ ;
    }

    return sum ;
}

int main() {

    cin >> T ;
    for( int i = 1 ; i <= T ; i++ ) {
        string s ;
        cin >> s;
        for( int j = 0 ; j < s.size() ; j++ ) {
            adj[i].push_back( s[j] - '0') ;
        }
    }

    cin >> K ;
    for( int i = 0 ; i < K ; i++ ) {
        cin >> num >> way ;
        func( num, way ) ;
    }

    cout << counting() << "\n" ;

    return 0;


}
