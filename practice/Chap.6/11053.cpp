#include<bits/stdc++.h>
using namespace std ;

const int max_n = 1004;

int N ;
int a[max_n];
int cnt[max_n];
int prevList[max_n] ;

int ret , idx ;
vector<int> v ;

// void go( int idx ) {

//     if( idx  == -1 ) return ;

//     v.push_back( a[idx] ) ;
//     go( prevList[idx] ) ;

//     return ;
// }

int main() {

    fill( cnt, cnt + max_n , 1 ) ;
    fill( prevList, prevList + max_n , -1 ) ;

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i] ;
    }

    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < i ; j++ ) {

            if( a[j] < a[i] && cnt[i] < cnt[j] + 1 ) {

                cnt[i] = cnt[j] + 1 ;
                prevList[i] = j ;

                
            }
        }

        if( ret < cnt[i] ) {
            ret = cnt[i] ;
            idx = i ;
        }
    }

    // go( idx ) ;

    cout << ret << "\n";
    // for( int i = v.size() -1 ; i >= 0 ; i-- ) {
    //     cout << v[i] << " " ;
    // }
    // cout << "\n" ;
    return 0 ;
}
