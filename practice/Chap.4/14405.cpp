#include<bits/stdc++.h>
using namespace std ;

string S ;

void func( ) {

    string str1 = "pi";
    string str2 = "ka" ;
    string str3 = "chu" ;

    size_t idx = 0 ;
    int flag = true ;
    while( idx < S.size() ) {

       if( idx + 2 <= S.size() && !S.compare( idx, 2 , str1 ) ) idx += 2 ;
       else if( idx + 2 <= S.size() && !S.compare( idx, 2, str2 ) ) idx += 2 ;
       else if( idx + 3 <= S.size() && !S.compare( idx, 3, str3 ) ) idx += 3 ;
       else {
         flag = false ; break ;
       }
    }

    if( flag ) cout << "YES\n";
    else cout << "NO\n" ;
}

int main() {

    cin >> S ;

    func() ;

    return 0 ;
}