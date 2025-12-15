// //   g++ -std=c++14 -Wall 2309.cpp -o 2309.out 
// //  순열 next_permutation 사용 정답
// #include<bits/stdc++.h>
// using namespace std ;

// vector<int> v ;
// int n = 9 , r = 7 ;

// int main() {

//     for( int i = 0 ; i < n ; i++) {
//         int tmpNum ;
//         cin >> tmpNum ;
//         v.push_back(tmpNum);
//     }

//     sort( v.begin() , v.end() ) ;

//     do{
//         int sum = 0 ;
//         for( int i = 0 ; i < r ; i++ ){
//             sum += v[i] ;
//         }

//         if( sum == 100) {
//             for( int i = 0 ; i < r ; i++ ) {
//                 cout << v[i] << " " ;
//             }
//             cout << "\n" ;
//             break ;
//         }

//     } while( next_permutation(v.begin(), v.end() ) );
    
//     return 0 ;
// }

// //  순열(재귀)
// #include<bits/stdc++.h>
// using namespace std ;

// vector<int> v(9) ;
// int n = 9 , r = 7 ;

// void solve() {

//     int sum = 0;
//     for( int i = 0 ; i < r ; i++ ) {
//         sum += v[i] ;
//     }

//     if( sum == 100 ) {
//         vector<int> result( v.begin() , v.begin() + r) ;
//         sort( result.begin(), result.end()) ;
//         for( int sv : result )
//             cout << sv << "\n" ;
//         exit(0);
//     }
// }

// void makepermutation( int n , int r , int depth ) {

//     if( r == depth ) {
//         solve() ;
//         return ;
//     }

//     for( int i = depth ; i < n ; i++ ) {
//         swap( v[i], v[depth] );
//         makepermutation( n , r , depth + 1) ;
//         swap( v[i], v[depth] ) ;
//     }
//     return ;
// }

// int main() {

//     for( int i = 0 ; i < n ; i++) 
//         cin >> v[i] ;

//     sort( v.begin() , v.end() );

//     makepermutation( 9 , 7 , 0 ) ;
//     return 0 ;
// }

// //  조합( 재귀 )
// #include<bits/stdc++.h>
// using namespace std ;

// vector<int> inputV ;

// void show( vector<int> &c ) {
//     int sum = 0 ;
//     for( int v : c ) {
//         sum += inputV[v] ;
//     }

//     if( sum == 100 ) {
//         for( int v : c ) {
//             cout <<  inputV[v] << "\n" ;
//         }
//         exit(0);
//     }
// }

// void combi( int start , vector<int> &b ) {

//     if( b.size() == 7 ) {
//         show( b ) ;
//         return ;
//     }

//     for( int i = start+1 ; i < 9  ; i++ ) {
//         b.push_back(i);
//         combi(i, b) ;
//         b.pop_back();
//     }
// }

// int main() {

//     for( int i = 0 ; i < 9 ; i++ ){
//         int tmpNum ;
//         cin >> tmpNum ;
//         inputV.push_back( tmpNum ) ;
//     }

//     sort( inputV.begin(), inputV.end() );

//     vector<int> result ;
//     combi( -1, result ) ;
//     return 0 ;
// }

//  조합( 반복문 )
#include<bits/stdc++.h>
using namespace std ;

vector<int> v ;
int S ;
int n = 9, r = 7 ;

void solve() { 
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = i + 1 ; j < n ; j++ ) {

            if( S - v[i] - v[j] == 100 ) {
                for( int sv : v) {
                    if( sv == v[i] || sv == v[j] ) continue ;
                    cout << sv << "\n" ;
                }
                return ;
            }
        }
    }
}

int main() {

    for( int i = 0 ; i < n ; i++ ) {
        int iNum ;
        cin >> iNum ;
        v.push_back(iNum);
    }
    sort( v.begin(), v.end() ) ;
    S = accumulate(v.begin(), v.end(), 0);

    solve();
    return 0 ;
}