// #include<bits/stdc++.h>
// using namespace std ;

// int T;

// void func(string &s ) {

//     if( s.find("()") != std::string::npos ) {
//         s = s.erase(s.find("()"),2) ;
//         func(s);
//     } else {
//         return ;
//     }
// }

// int main() {

//     cin >> T ;

//     for( int i = 0 ; i < T ; i++ ) {

//         string s;
//         cin >> s;

//         func( s ) ;
//         if( s.size() == 0 ) cout << "YES" << "\n" ;
//         else cout << "NO" << "\n" ;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std ;

int T ;


int main() {

    cin >> T ;

    for( int i = 0 ; i < T ; i++ ) {

        string str ;
        cin >> str ;
        stack<char> s ;
        for( int j = 0 ; j < str.size() ; j++ ) {
            
            if( j == 0 ) {
                s.push(str[j]);
                if( str[j] == ')' ) break;
                
            } else {
                if( !s.empty() && s.top() == '(' && str[j] == ')' ) {
                    s.pop() ;
                } else {
                    s.push(str[j]);
                    if( s.empty() && str[j] == ')' ) break ;
                } 
            }
        }

        if( s.empty() ) cout << "YES" << "\n" ;
        else cout << "NO" << "\n" ;

    }
    return 0;
}