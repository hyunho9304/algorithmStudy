#include<bits/stdc++.h>
using namespace std ;

const int max_n = 24 ;

int N ;
int a[max_n][max_n];
vector<int> v ;

int ret = 987654321 ;

int go( vector<int> teamA, vector<int> teamB ) {

    pair<int,int> p ;
    for( int i = 0 ; i < teamA.size() ; i++ ) {
        for( int j = 0 ; j < teamB.size() ; j++ ) {

            if( i == j ) continue ;

            p.first += a[teamA[i]][teamA[j]] ;
            p.second += a[teamB[i]][teamB[j]] ;
        }
    }

    return abs( p.first - p.second ) ;
    
}

int main() {

    cin >> N ;
    for( int i = 1 ; i <= N ; i++ ) {

        v.push_back( i ) ;
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> a[i][j] ;
        }
    }

    
    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) != N / 2) continue;

        vector<int> teamA, teamB;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) teamA.push_back(v[j]);
            else teamB.push_back(v[j]);
        }
        
        ret = min ( ret, go( teamA, teamB ) );
    }

    cout << ret << "\n" ;

    return 0 ;

    
}


//  Combi풀이
// int visited[max_n] ;

// int go( vector<int> teamA, vector<int> teamB ) {

//     pair<int,int> p ;
//     for( int i = 0 ; i < teamA.size() ; i++ ) {
//         for( int j = 0 ; j < teamB.size() ; j++ ) {

//             if( i == j ) continue ;

//             p.first += a[teamA[i]][teamA[j]] ;
//             p.second += a[teamB[i]][teamB[j]] ;
//         }
//     }

//     return abs( p.first - p.second ) ;
    
// }

// void combi( int start, vector<int> & b ) {

//     if( b.size() == N / 2 ) {

//         vector<int> teamA, teamB ;
//         for( int i = 1 ; i <= N ; i++ ) {
//             if( visited[i] == 1 ) teamA.push_back(i) ;
//             else teamB.push_back(i) ;
//         }

//         ret = min( ret, go( teamA, teamB ) ) ;

//     } else {

//         for( int i = start + 1 ; i <= N ; i++ ) {

//             visited[i] = 1 ;
//             b.push_back(i) ;

//             combi( i, b ) ;

//             visited[i] = 0 ;
//             b.pop_back() ;
//         }
//     }
// }

// int main() {

//     cin >> N ;
//     for( int i = 1 ; i <= N ; i++ ) {

//         v.push_back( i ) ;
//         for( int j = 1 ; j <= N ; j++ ) {
//             cin >> a[i][j] ;
//         }
//     }
    
//     vector<int> b;
//     combi( 0, b ) ;

//     cout << ret << "\n" ;

//     return 0 ;


// }