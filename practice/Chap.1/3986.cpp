// #include<bits/stdc++.h>
// using namespace std ;

// int N ;
// vector<string> str ;
// int ret ;

// void solve() {

//     for( string s : str ) {

//         string tmp = "" ;
//         for( char c : s ) {

//             if( tmp.size() == 0 ) {
//                 tmp += c ;
//             } else {
//                 if( tmp[tmp.size() - 1 ] != c) tmp += c ;
//                 else {
//                     tmp.erase(tmp.size()-1 , 1) ;
//                 }
//             }
//         }
        
//         if( tmp.size() == 0 ) ret++ ;
//     }
// }

// int main() {

//     cin >> N ;

//     for( int i = 0 ; i < N ; i++ ) {

//         string tmp ;
//         cin >> tmp ;
//         str.push_back(tmp ) ;
//     }

//     solve() ;

//     cout << ret << "\n" ;
//     return 0 ;

// }

#include<bits/stdc++.h>
using namespace std;

int N ;
int ret ;

void solve( string &tmp ) {

    stack<char> str ;
    for( char ch : tmp ) {

        if( str.size() && str.top() == ch ) str.pop() ;
        else
            str.push(ch);
    }

    if( str.size() == 0 ) ret++ ;
}

int main() {

    cin >> N ;

    for( int i = 0 ; i < N ; i++ ) {
        string tmp ;
        cin >> tmp ;

        solve( tmp ) ;
    }

    cout << ret << "\n" ;
    return 0 ;

}