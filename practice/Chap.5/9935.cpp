// #include<bits/stdc++.h>
// using namespace std ;

// string str ;
// string bomb ;

// string ret ;

// int main() {

//     cin >> str >> bomb ;

//     for( int i = 0 ; i < str.size() ; i++ ) {
//         ret += str[i] ;

//         if( ret.size() >= bomb.size() && ret.substr( ret.size() - bomb.size() , bomb.size() ) == bomb ) {
//             ret.erase( ret.size() - bomb.size() ,bomb.size() ) ;
//         }
//     }

//     if( ret == "" ) {
//         cout << "FRULA" << "\n" ;
//     } else {
//         cout << ret << "\n" ;
//     }    
//     return 0 ;
// }

//  벡터를 스택처럼
#include<bits/stdc++.h>
using namespace std ;

string str ;
string bomb ;
vector<char> stk ;

int main() {

    cin >> str >> bomb ;


    for( int i = 0 ; i < str.size() ; i++ ) {
        
        stk.push_back( str[i] ) ;

        if( str[i] == bomb[bomb.size()-1] ) {
            
            bool flag = true ;
            for( int j = 0 ; j < bomb.size() - 1 ; j++ ) {
                if( stk[ stk.size() - bomb.size() + j ] != bomb[j] ) {
                    flag = false ; break ;
                }
            }

            if( flag ) {
                for( int j = 0 ; j < bomb.size() ; j++ ) {
                    stk.pop_back() ;
                }
            }
        }
    }

    if( !stk.empty() ) {
        cout << string( stk.begin(), stk.end() ) << "\n" ;
    } else {
        cout << "FRULA" << "\n" ;
    }

    return 0 ;
}


//  스택 사용
// #include<bits/stdc++.h>
// using namespace std ;

// string str ;
// string bomb ;
// stack<char> stk ;

// string ret ;

// int main() {

//     cin >> str >> bomb ;

//     for( int i = 0 ; i < str.size() ; i++ ) {
//         stk.push( str[i] ) ;

//         if( stk.size() >= bomb.size() && stk.top() == bomb[bomb.size() - 1 ] ) {
            
//             string tmp = "" ;
//             for( int j = 0 ; j < bomb.size() ; j++ ) {
//                 tmp += stk.top() ;
//                 stk.pop() ;
//             }

//             reverse( tmp.begin(), tmp.end() );

//             if( tmp != bomb ) {
//                 for( int j = 0 ; j < tmp.size() ; j++ ) {
//                     stk.push( tmp[j] ) ;
//                 }
//             }
//         }
//     }

//     if( !stk.empty() ) {
        
//         while( !stk.empty() ) {
//             ret += stk.top() ; stk.pop() ;
//         }

//         reverse( ret.begin(), ret.end() ) ;
//         cout << ret << "\n" ;
//     } else {
//         cout << "FRULA" << "\n" ;
//     }

//     return 0 ;

// }