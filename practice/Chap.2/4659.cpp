#include<bits/stdc++.h>
using namespace std ;

string str;

bool check1() {

    bool flag = false ;
    for( char ch : str ) {
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) {
            flag = true ;
            break ;
        } 
    }
    return flag ;
}

bool check2() {

    bool flag = true ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    for( char ch : str ) {

        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) {
            cnt2 = 0 ; cnt1++ ;
        } else {
            cnt1 = 0 ; cnt2++ ;
        }

        if( cnt1 == 3 || cnt2 == 3 ) {
            flag = false ;
            break ;
        }
    }
    return flag ;
}

bool check3() {

    bool flag = true ;
    char before_ch ;
    for( int i = 1 ; i < str.size() ; i++ ) {
        before_ch = str[i-1];
        if( before_ch == str[i] ) {

            if( str[i] == 'e' || str[i] == 'o' ) flag = true ;
            else {
                flag = false ;
                break ;
            }
        }
    }
    return flag ;
}

int main() {


    while(cin >> str && str != "end") {
        
        if( check1() && check2() && check3() )
            cout << "<" << str << "> is acceptable." << "\n";
        else
            cout << "<" << str << "> is not acceptable." << "\n" ;
    }
    return 0 ;

}