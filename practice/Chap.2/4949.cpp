#include<bits/stdc++.h>
using namespace std ;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    
    string str;
    while(getline(cin, str) && str != ".") {

        stack<char> stk ;
        for( int i = 0 ; i < str.size() ; i++ ) {

            if( str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']') {
                if( !stk.empty() ) {
                    if( stk.top() == '(' ) {
                        if( str[i] == ')') stk.pop() ;
                        else stk.push(str[i]);
                    }
                    else if( stk.top() == '[') {
                        if( str[i] == ']' ) stk.pop() ;
                        else stk.push( str[i] ) ;
                    }
                } else {
                    stk.push( str[i] ) ;
                    if( str[i] == ')' || str[i] == ']') break ;
                }
            }
            
        }

        if( stk.empty()) cout << "yes" << "\n" ;
        else cout << "no" << "\n" ;
    }

    return 0 ;

}