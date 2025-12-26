// #include<bits/stdc++.h>
// using namespace std ;

// int N, M ;
// vector<int> v ;
// int ret ;

// void solve() {

//     for( int i = 0 ; i < N ; i++ ) {
//         for( int j = i + 1 ; j < N ; j++ ) {
            
//             if( v[i] + v[j] == M ) ret++ ;
//         }
//     }
// }

// int main() {

//     cin >> N >> M ;

//     for( int i = 0 ; i < N ; i++ ) {
//         int tmp ;
//         cin >> tmp ;
//         v.push_back(tmp);
//     }

//     sort( v.begin(), v.end() );
//     solve() ;
//     cout << ret << "\n" ;

//     return 0 ;

// }

#include<bits/stdc++.h>
using namespace std ;

int N, M ;
vector<int> v ;
int ret ;


void combi( int start , vector<int> &b) {
    if( b.size() == 2 ) {
        if( v[b[0]] + v[b[1]] == M) {
            ret++ ;
        }
        return ;
    }
    for( int i = start + 1 ; i < N ; i++ ) {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
    return ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M ;

    if( M > 200000) {
        cout << 0 << "\n" ;
    } else {
        for( int i = 0 ; i < N ; i++ ) {
            int tmp ;
            cin >> tmp ;
            v.push_back(tmp);
        }

        sort( v.begin(), v.end() );

        vector<int> b ;
        combi( -1, b ) ;

        cout << ret << "\n" ;
    }
    return 0 ;
}