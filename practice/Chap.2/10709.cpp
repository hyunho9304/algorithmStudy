// #include<bits/stdc++.h>
// using namespace std ;

// int W, H;
// vector<int> ret ;

// int main() {

//     cin >> W >> H ;

//     for( int i = 0 ; i < W ; i++ ) {
//         string tmps ;
//         cin >> tmps;
        
//         int last = -1 ;
//         for( int i = 0 ; i < tmps.size() ; i++ ) {
            
//             if( tmps[i] == 'c') {
//                 last = i ;
//                 ret.push_back(0);
//             } else {
//                 if( last == -1 ) ret.push_back(-1);
//                 else {
//                     ret.push_back(i-last);
//                 }
//             }
//         }
//     }

//     for( int i = 1 ; i <= ret.size() ; i++ ) {

//         cout << ret[i-1] << " " ;
//         if( i % H == 0) cout << "\n" ;

//     }

//     return 0 ;
// }


#include<bits/stdc++.h>
using namespace std ;

int W, H ;
int a[104][104] ;
int ret[104][104] ;

int main() {

    cin >> W >> H ;

    for( int i = 0 ; i < W ; i++ ) {
        string s ;
        cin >> s ;
        for( int j = 0 ; j < H ; j++ ){
            if( s[j] == 'c') a[i][j] = 1 ;
            else a[i][j] = 0 ;
        }
    }

    for( int i = 0 ; i < W ; i++ ) {
        
        int last = - 1 ;
        for( int j = 0 ; j < H ; j++ ) {

            if( a[i][j] == 1) {
                ret[i][j] = 0 ;
                last = j ;
            } else {
                if( last != -1 ) ret[i][j] = j-last ;
                else ret[i][j] = last ;
            }
        }
    }

    for( int i = 0 ; i < W ; i++ ) {
        for( int j = 0 ; j < H ; j++ ) cout << ret[i][j] << " " ;
        cout << "\n" ;
    }
    
    return 0 ;
}