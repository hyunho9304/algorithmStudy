// //  g++ -std=c++14 -Wall ./10988.cpp -o 10988.out
// #include<bits/stdc++.h>
// using namespace std ;

// string S ;
// bool flag = true ;

// void solve() {

//     for( int i = 0 ; i < S.length() ; i++ ) {

//         int j = S.length() - 1 - i ;

//         if( i == j ) return ;
//         if( S[i] != S[j] ) { flag = false ; }
//     }
// }

// int main() {

//     cin >> S ;
//     solve() ;

//     cout << (int)flag << "\n" ;

//     return 0 ;
// }

#include<bits/stdc++.h>
using namespace std ;

string S ;

int main() {

    cin >> S ;

    string tmpS = S ;
    reverse( S.begin() , S.end() ) ;

    if( tmpS == S )
        cout << "1" << "\n" ;
    else
        cout << "0" << "\n" ;

    return 0;
}