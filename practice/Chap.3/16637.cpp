#include<bits/stdc++.h>
using namespace std ;

int N ;
string s;
vector<int> numList;
vector<char> oper ;
int ret = -987654321;

int calc( char ch , int num1, int num2 ) {
    if( ch == '+') return num1 + num2 ;
    else if( ch == '-') return num1 - num2 ;
    else if( ch == '*') return num1 * num2 ;
    else return -1 ;
}

void go( int here, int currentNum ) {

    if( here == numList.size() - 1 ) {
        ret = max( ret, currentNum ) ;
        return ;
    }

    go( here + 1 , calc( oper[here], currentNum , numList[here+1] ));

    if( here + 2  <= numList.size() - 1 ) {
        int tmp = calc( oper[here+1], numList[here+1], numList[here+2] ) ;
        go( here + 2 , calc( oper[here] , currentNum, tmp ) ) ;
    }

    return ;
}

int main() {

    cin >> N ;
    cin >> s ;

    for( int i = 0 ; i < s.size() ; i++ ) {
        if( i % 2 == 0 ) numList.push_back( s[i] - '0');
        else oper.push_back( s[i] ) ;
    }

    go( 0, numList[0] ) ;

    cout << ret << "\n" ;
    return 0 ;
    
}